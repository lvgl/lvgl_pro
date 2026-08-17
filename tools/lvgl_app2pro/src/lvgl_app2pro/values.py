"""Runtime values in, XML attribute values out.

The GDB plugin already decodes sizes, enums, colors and pointers, so the work
here is spelling: XML wants `0xrrggbb` for colors and lowercase for enums.
Anything that cannot be expressed is recorded rather than guessed at.
"""

import re

from .mapping import (
    LAYOUT_NAMES,
    NOT_FROM_WIDGET_DATA,
    RENAMES,
    UNCONVERTIBLE_TYPES,
    WIDGET_TAGS,
    style_prop_to_xml,
)

_ENUM_NAME = re.compile(r"^[A-Z][A-Z0-9_]*(\|[A-Z][A-Z0-9_]*)*$")

#: Style properties whose value is a C symbol rather than an enum member.
_SYMBOL_VALUED = frozenset({
    "text_font", "bg_image_src", "arc_image_src", "bitmap_mask_src",
})

# LV_SYMBOL_* are glyphs in a font's private use area, not image files.
_SYMBOL_RANGE = range(0xE000, 0xF900)

# LV_PCT() marks a percentage with a type tag in the top bits, the same way
# style coordinates do, so a widget property typed `px|%` can hold one.
_COORD_TYPE_SHIFT = 29
_COORD_TYPE_MASK = 3 << _COORD_TYPE_SHIFT
_COORD_TYPE_SPEC = 1 << _COORD_TYPE_SHIFT
_COORD_MAX = (1 << _COORD_TYPE_SHIFT) - 1
_PCT_POS_MAX = (_COORD_MAX - 1) // 2


def decode_coord(raw):
    """Render an int32 coordinate as the source wrote it: 12, 50% or content."""
    bits = raw & 0xFFFFFFFF
    if bits & _COORD_TYPE_MASK != _COORD_TYPE_SPEC:
        return str(raw)
    plain = bits & ~_COORD_TYPE_MASK
    if plain == _COORD_MAX:
        return "content"
    if plain > _COORD_MAX - 1:
        return str(raw)
    pct = plain if plain <= _PCT_POS_MAX else _PCT_POS_MAX - plain
    return f"{pct}%"


class Report:
    """Everything that did not convert cleanly, plus the assets to declare."""

    def __init__(self):
        self.schema = None
        self.class_defaults = {}
        self.keep_fonts = False
        self.warnings = []
        self.fonts = set()
        self.callbacks = {}   # name -> set of triggers it is attached to
        self.unmapped = {}    # 'lv_image.pivot' -> example value
        self.images = set()

    def warn(self, message):
        if message not in self.warnings:
            self.warnings.append(message)


def color_to_xml(value_str, rgb):
    return "0x%02x%02x%02x" % (rgb["r"], rgb["g"], rgb["b"])


def is_symbol(value):
    """True for an LV_SYMBOL_* glyph, which is text rather than an image file."""
    return bool(value) and any(ord(ch) in _SYMBOL_RANGE for ch in value)


def escape_literal(text):
    """Protect a string whose first character would be read as a reference.

    lv_xml treats a leading `$` as an API parameter and `#` as a const, so a
    price like "$27,123.25" has to be wrapped in the `{'...'}` expression form
    to stay a literal.
    """
    if text[:1] not in ("$", "#"):
        return text
    if "'" in text:
        # A quote would end the literal early, and there is no escape for it.
        return None
    return "{'%s'}" % text


def make_prop_filter(report):
    """Build the style-property translator the model calls for every property."""

    def prop_filter(prop, notes):
        runtime_name = prop.get("prop_name") or ""
        xml_name = style_prop_to_xml(runtime_name)
        if xml_name is None:
            report.warn(
                f"style property {runtime_name} has no XML equivalent and was dropped"
            )
            notes.append(f"unsupported style property {runtime_name}")
            return None

        value = prop.get("value_str")
        if value is None or value == "NULL":
            return None
        # lv_obj_align() writes a zero offset into x/y on every aligned widget.
        if xml_name in ("x", "y") and value == "0":
            return None

        if prop.get("color_rgb"):
            value = color_to_xml(value, prop["color_rgb"])
        elif xml_name == "layout":
            name = LAYOUT_NAMES.get(int(value)) if value.isdigit() else None
            if name is None:
                notes.append(f"unknown layout id {value}")
                return None
            value = name
        elif _ENUM_NAME.match(value) and xml_name not in _SYMBOL_VALUED:
            # An all-caps value is an enum member to lowercase - unless the
            # property holds a C symbol, where the name has to survive exactly
            # as the image was exported and declared.
            value = value.lower()

        if xml_name == "text_font":
            report.fonts.add(value)
            # A font must be declared in globals.xml with a source file, and a
            # font compiled into the binary has none: the glyph bitmaps are
            # there but the TTF is not. Referencing it by name produces a
            # project that does not build, so the name is left as a TODO.
            if not report.keep_fonts:
                notes.append(f"{xml_name} was {value}: declare it in "
                             "globals.xml and set the font here")
                return None
        elif xml_name in ("bg_image_src", "arc_image_src", "bitmap_mask_src"):
            if is_symbol(value):
                # A symbol is text drawn from a font, not an image, so there is
                # no image to declare and no name to point at. Writing the glyph
                # itself produces C that does not compile.
                glyph = next(c for c in value if ord(c) in _SYMBOL_RANGE)
                notes.append(f"{xml_name} was the symbol U+{ord(glyph):04X}: "
                             "set it as an image or a label here")
                return None
            report.images.add(value)

        return (xml_name, value)

    return prop_filter


def make_widget_filter(report):
    """Build the widget_data translator the model calls for every node.

    Driven by the schema: for each property a widget declares, find the
    matching runtime field and convert it according to the declared type. No
    per-widget list of properties is kept here.
    """

    def widget_filter(cls, data, notes):
        schema = report.schema
        declared = schema.props.get(cls) if schema else None
        if not declared:
            if data and cls not in WIDGET_TAGS:
                notes.append(f"no XML schema for {cls}")
            return {}

        renames = RENAMES.get(cls, {})
        reference = (report.class_defaults.get(cls) or {}).get("widget_data") or {}
        out = {}
        used = set()
        for xml_name, type_ in sorted(declared.items()):
            if xml_name in NOT_FROM_WIDGET_DATA or type_.startswith("flag:"):
                continue
            if any(type_.startswith(t) for t in UNCONVERTIBLE_TYPES):
                continue
            field = renames.get(xml_name, xml_name)
            raw = _lookup(data, field)
            if raw is None or raw == "":
                continue
            # Unchanged from a freshly created widget: LVGL's default, not the
            # app's decision, so there is nothing to write.
            if raw == _lookup(reference, field) and field in _flatten(reference):
                continue
            used.add(field)
            value = _convert_typed(type_, raw, xml_name, report, notes)
            if value is not None:
                out[xml_name] = value

        _note_unmapped(cls, data, reference, used, declared, report)
        return out

    return widget_filter


# Runtime bookkeeping: caches, in-progress gestures, resolved geometry. These
# differ from a fresh widget without the app having decided anything.
_INTERNAL_FIELDS = ("cache", "_area", "point", "dragging", "moved", "cnt_ori",
                    "_ori", "offset", "size", "inf_", "text_size", "dot_",
                    "invalid", "need_", "static", "sel_start", "sel_end",
                    "w", "h", "list", "symbol", "ser", "cursor", "series",
                    "last_", "_ll", "ctrl_bits", "label", "cf", "src_type",
                    "custom_label_cnt", "min_close", "in_out")


def _lookup(data, field):
    """data["pivot"]["x"] for a field written "pivot.x"."""
    for part in field.split("."):
        if not isinstance(data, dict) or part not in data:
            return None
        data = data[part]
    return data


def _flatten(data):
    """Field names including dotted paths into nested dicts."""
    names = set()
    for key, value in (data or {}).items():
        names.add(key)
        if isinstance(value, dict):
            names.update(f"{key}.{inner}" for inner in value)
    return names


def _note_unmapped(cls, data, reference, used, declared, report):
    """Record fields the app changed that no XML property can carry.

    lv_image_set_pivot() is the clearest case: the pivot is a real part of how
    the image looks, the runtime reports it, and lv_image.xml has no property
    for it. Staying quiet about that loses it without a trace.
    """
    consumed = {name.split(".")[0] for name in used}
    for field, value in sorted(data.items()):
        if field in consumed or field in declared:
            continue
        if any(part in field for part in _INTERNAL_FIELDS):
            continue
        if field not in reference or value == reference[field]:
            continue
        report.unmapped.setdefault(f"{cls}.{field}", str(value))


def _string_list(raw, xml_name, notes):
    """A list of strings, as lv_xml wants it: 'Jan' 'Feb' 'March'.

    The runtime splits on spaces and then strips one pair of quotes per token,
    so a label that contains a space or a quote of its own cannot be written.
    """
    if not isinstance(raw, (list, tuple)) or not raw:
        return None
    bad = [s for s in raw if " " in s or "'" in s]
    if bad:
        notes.append(f"{xml_name}: labels with a space or a quote cannot be "
                     f"written ({', '.join(bad[:3])})")
        return None
    return " ".join(f"'{s}'" for s in raw)


def _convert_typed(type_, raw, xml_name, report, notes):
    """Convert one value according to the type the schema declares for it."""
    if type_ == "string":
        return escape_literal(str(raw))
    if type_.startswith("string["):
        return _string_list(raw, xml_name, notes)
    if type_ in ("int", "opa", "deg", "px") or "|" in type_:
        try:
            return decode_coord(int(raw))
        except (TypeError, ValueError):
            return None
    if type_ == "bool":
        return "true" if int(raw) else None  # false is the default everywhere
    if type_ == "color":
        return raw.replace("#", "0x") if isinstance(raw, str) else None
    if type_ == "image":
        return _asset(raw, xml_name, report, notes)
    if type_.startswith("enum:"):
        return _enum(type_.removeprefix("enum:"), raw, xml_name, report, notes)
    notes.append(f"{xml_name}: no rule for schema type {type_!r}")
    return None


def _asset(raw, xml_name, report, notes):
    if isinstance(raw, str) and raw.startswith("0x"):
        notes.append(f"{xml_name} is an unresolved pointer {raw}")
        report.warn(f"an image source at {raw} has no symbol and was left as a TODO")
        return None
    if not is_symbol(str(raw)):
        report.images.add(str(raw))
    return str(raw)


def _enum(enumdef, raw, xml_name, report, notes):
    value = int(raw)
    if report.schema.is_default(enumdef, value):
        return None
    found = report.schema.value_name(enumdef, value)
    if found is None:
        notes.append(f"{xml_name}: {enumdef} has no name for value {value}")
    return found


def _convert(kind, raw, xml_name, report, notes):
    if kind == "str":
        return escape_literal(str(raw))
    if kind == "int":
        return str(int(raw))
    if kind == "bool":
        return "true" if int(raw) else None  # false is the default everywhere
    if kind == "color":
        return raw.replace("#", "0x") if isinstance(raw, str) else None
    if kind == "dir":
        return DIR_NAMES.get(int(raw))
    if kind == "asset":
        if isinstance(raw, str) and raw.startswith("0x"):
            notes.append(f"{xml_name} is an unresolved pointer {raw}")
            report.warn(
                f"an image source at {raw} has no symbol and was left as a TODO"
            )
            return None
        report.images.add(str(raw))
        return str(raw)
    if kind.startswith("enum:"):
        enumdef = kind.removeprefix("enum:")
        value = int(raw)
        if report.schema:
            if report.schema.is_default(enumdef, value):
                return None
            found = report.schema.value_name(enumdef, value)
            if found is not None:
                return found
            notes.append(f"{xml_name}: {enumdef} has no name for value {value}")
            return None
        name = widget_enum(kind, value)
        if name is DEFAULT_ENUM:
            return None
        if name is None:
            notes.append(f"{xml_name} has no XML spelling for value {raw}")
            return None
        return name
    return None
