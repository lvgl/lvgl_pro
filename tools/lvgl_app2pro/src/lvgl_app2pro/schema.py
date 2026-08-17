"""Read the LVGL Pro widget schemas, so enum values are never guessed.

Each `<enumdef>` in lv_xml/xmls/widgets/ lists the names the XML parsers
accept, and now the runtime value of each one. That is both halves of the
translation in a single authoritative file, which is why this is preferred
over any table kept here: declaration order is not value order, and several
enums are bitmasks.

Falls back to the built-in tables when the schemas cannot be read, so the
converter still runs without them.
"""

import re
import xml.etree.ElementTree as ET
from pathlib import Path

# The schemas ship in this repository: src/lvgl_app2pro -> tools/<tool> -> tools.
SCHEMA_ROOT = Path(__file__).resolve().parents[4] / "lvgl_widgets_xml"

# Values LVGL sets itself, which therefore need not be written out.
IMPLICIT_DEFAULTS = {
    "lv_image_align": 0,        # LV_IMAGE_ALIGN_DEFAULT
    "lv_slider_orientation": 0,  # AUTO
    "lv_bar_orientation": 0,
}


class Schema:
    """What the widget XMLs declare.

    `enums`    {enumdef: {value: name}}
    `props`    {widget tag: {prop name: type}}
    `elements` {widget tag: [element name]} - the `<lv_tabview-tab>` forms
    """

    def __init__(self, enums=None, props=None, elements=None, source=None):
        self.enums = enums or {}
        self.props = props or {}
        self.elements = elements or {}
        self.source = source

    @property
    def tags(self):
        """Every widget that has a schema, so no list has to be kept here."""
        return set(self.props)

    @property
    def pseudo_tags(self):
        """`lv_tabview-tab` and friends, from each widget's <element> list."""
        return {f"{tag}-{name}"
                for tag, names in self.elements.items() for name in names}

    def prop_type(self, tag, name):
        return self.props.get(tag, {}).get(name)

    def value_name(self, enumdef, value):
        """XML name for a value, or None if the schema does not have it."""
        return self.enums.get(enumdef, {}).get(value)

    def is_default(self, enumdef, value):
        return IMPLICIT_DEFAULTS.get(enumdef) == value

    def __bool__(self):
        return bool(self.enums)


def parse_version(text):
    """"9.6.0-dev" or "v9.5.0" -> (9, 6, 0). None if it cannot be read."""
    if not text:
        return None
    match = re.match(r"v?(\d+)\.(\d+)(?:\.(\d+))?", str(text))
    if not match:
        return None
    return tuple(int(part or 0) for part in match.groups())


def available_versions():
    """The schema sets shipped here, oldest first."""
    if not SCHEMA_ROOT.is_dir():
        return []
    found = [(parse_version(p.name), p)
             for p in SCHEMA_ROOT.iterdir() if p.is_dir()]
    return [(version, path) for version, path in sorted(found) if version]


def find_schema_dir(version=None):
    """The schemas to use for an app built against `version`.

    An exact match if there is one. Otherwise the newest set that is not newer
    than the app, because a schema describes what that LVGL could do; and if
    the app is older than everything shipped, the oldest set. The caller is
    told which was picked so an inexact match can be reported.
    """
    available = available_versions()
    if not available:
        return None

    wanted = parse_version(version)
    if wanted is None:
        return available[-1][1]

    exact = [path for found, path in available if found == wanted]
    if exact:
        return exact[0]

    older = [path for found, path in available if found <= wanted]
    return older[-1] if older else available[0][1]


def load(directory=None, version=None):
    """Read the schemas from `directory`, or from the ones shipped here."""
    directory = Path(directory) if directory else find_schema_dir(version)
    if directory is None or not Path(directory).is_dir():
        return Schema()
    directory = Path(directory)

    enums, props, elements = {}, {}, {}
    for path in sorted(directory.glob("*.xml")):
        for name, entries in _parse(path):
            # Same enumdef can appear in several files; they agree, so first wins.
            enums.setdefault(name, {}).update(entries)

        tag = path.stem
        if tag == "globals":
            continue
        found_props, found_elements = _parse_api(path)
        # Every widget inherits lv_obj's properties.
        props[tag] = found_props
        elements[tag] = found_elements

    base = props.get("lv_obj", {})
    for tag, own in props.items():
        if tag != "lv_obj":
            props[tag] = {**base, **own}

    return Schema(enums, props, elements, directory if enums else None)


def _parse_api(path):
    """{prop: type} and [element] for one widget, read from its <api>.

    Only the direct children of <api> count. An <element> block has <prop> and
    <arg> tags of its own describing that element's arguments, and a flat
    search would hand every widget things like the `min_value` of lv_obj's
    subject_increment element.
    """
    try:
        root = ET.fromstring(path.read_text(errors="ignore"))
    except ET.ParseError:
        return {}, []

    api = root if root.tag == "api" else root.find("api")
    if api is None:
        return {}, []

    # A property with arguments has no type of its own; the value's type is on
    # its first <param>, as in lv_slider's `value` (value + anim).
    props = {}
    for prop in api.findall("prop"):
        name = prop.get("name")
        if not name:
            continue
        type_ = prop.get("type") or ""
        if not type_:
            params = prop.findall("param")
            match = next((p for p in params if p.get("name") == name), None)
            if match is None:
                match = params[0] if params else prop
            type_ = match.get("type") or ""
        props[name] = type_
    elements = sorted({e.get("name") for e in api.findall("element")
                       if e.get("name")})
    return props, elements


def _parse(path):
    text = path.read_text(errors="ignore")
    try:
        root = ET.fromstring(text)
        blocks = root.iter("enumdef")
    except ET.ParseError:
        # A schema that is not well-formed should not stop the others.
        return _parse_with_regex(text)

    out = []
    for block in blocks:
        name = block.get("name")
        if not name:
            continue
        entries = {}
        for item in block.findall("enum"):
            value, item_name = item.get("value"), item.get("name")
            if value is None or item_name is None:
                continue
            try:
                entries[int(value, 0)] = item_name
            except ValueError:
                continue
        if entries:
            out.append((name, entries))
    return out


_ENUMDEF = re.compile(r'<enumdef\s+name="([a-z0-9_]+)"(.*?)</enumdef>', re.S)
_ENUM = re.compile(r'<enum\s+name="([a-z0-9_]+)"\s+value="([^"]+)"')


def _parse_with_regex(text):
    out = []
    for name, body in _ENUMDEF.findall(text):
        entries = {}
        for item_name, value in _ENUM.findall(body):
            try:
                entries[int(value, 0)] = item_name
            except ValueError:
                continue
        if entries:
            out.append((name, entries))
    return out
