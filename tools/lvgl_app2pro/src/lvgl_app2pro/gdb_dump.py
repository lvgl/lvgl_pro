"""Runs inside GDB. Stops the app once and writes the whole UI out as JSON.

Not importable outside GDB. The driver hands it its arguments through the
environment because `gdb -x` takes no script arguments.

Everything it reads comes from the lvglgdb plugin; the only work done here is
stopping in the right place, probing what the binary's debug info supports, and
resolving the pointers in widget_data that the plugin leaves raw.
"""

import json
import os
import sys

import gdb

# Run as a GDB script, not imported, so src/ has to be put on the path before
# the package's own modules - or the plugin next to it - can be used.
SRC_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, SRC_ROOT)

from lvgl_app2pro import images  # noqa: E402


# Where to stop when the caller does not say. The second call has run one
# full LVGL cycle.
DEFAULT_STOP = "lv_timer_handler"


def _fail(message):
    print(f"lvgl_app2pro: {message}", file=sys.stderr)
    raise SystemExit(1)


def _load_plugin():
    """Import lvglgdb: the copy shipped here unless another was asked for.

    The copy shipped here is the default because the converter depends on plugin
    features that are newer than any release, and because it must work against
    an application built with an older LVGL than the plugin - the plugin reads
    the application's own debug info, so that skew is fine.
    """
    lvgl_dir = os.environ.get("LVGL_APP2PRO_LVGL")
    if lvgl_dir:
        sys.path.insert(0, os.path.join(lvgl_dir, "scripts", "gdb"))
    else:
        sys.path.insert(0, os.path.join(SRC_ROOT, "gdb_plugin"))

    for path in json.loads(os.environ.get("LVGL_APP2PRO_SYSPATH", "[]")):
        if path not in sys.path:
            sys.path.append(path)
    try:
        import lvglgdb  # noqa: F401
    except ImportError as e:
        _fail(f"cannot import lvglgdb inside GDB ({e})")


def probe_version():
    """The target's LVGL version, as "9.6.0-dev", or None.

    lv_version_major() and friends are `static inline`, so whether each one
    survives into the binary depends on the build; the version macros cover
    what is missing but need -g3.
    """
    def read(expression):
        try:
            return gdb.parse_and_eval(expression)
        except gdb.error:
            return None

    parts = []
    for name in ("major", "minor", "patch"):
        value = read(f"lv_version_{name}()")
        if value is None:
            value = read(f"LVGL_VERSION_{name.upper()}")
        if value is None:
            return None
        parts.append(int(value))

    info = read("lv_version_info()") or read("LVGL_VERSION_INFO")
    try:
        suffix = f"-{info.string()}" if info is not None and info.string() else ""
    except gdb.error:
        suffix = ""
    return "%d.%d.%d%s" % (*parts, suffix)


def probe_capabilities():
    """Report what the binary's DWARF supports, before trusting any of it.

    lvglgdb's safe_field() returns a default for a missing struct field, so an
    absent flag is indistinguishable from a clear one. Anything this cannot
    confirm has to be said out loud rather than silently assumed.
    """
    def has_field(struct, field):
        # LVGL declares these as `struct _lv_x_t` with a `lv_x_t` typedef, and
        # which spelling lookup_type() accepts depends on the build, so try all.
        for name in (struct, f"struct {struct}", struct.lstrip("_")):
            try:
                return any(f.name == field for f in gdb.lookup_type(name).fields())
            except gdb.error:
                continue
        return False

    return {
        "is_theme": has_field("_lv_obj_style_t", "is_theme"),
        "screens": has_field("_lv_display_t", "screens"),
        "screen_cnt": has_field("_lv_display_t", "screen_cnt"),
    }


# lv_grid.h, in terms of LV_COORD_MAX
_COORD_MAX = (1 << 29) - 1
_GRID_TEMPLATE_LAST = _COORD_MAX
_GRID_CONTENT = _COORD_MAX - 101
_GRID_FR_BASE = _COORD_MAX - 100
_GRID_PROPS = ("GRID_COLUMN_DSC_ARRAY", "GRID_ROW_DSC_ARRAY")


def _read_grid_template(addr, limit=64):
    """Read an int32_t grid template into the space-separated form XML uses.

    The array is only reachable through its pointer, so without this a grid
    layout converts to a container with no tracks.
    """
    try:
        int32 = gdb.lookup_type("int32_t")
        array = gdb.Value(addr).cast(int32.pointer())
        out = []
        for i in range(limit):
            value = int(array[i])
            if value == _GRID_TEMPLATE_LAST:
                return " ".join(out)
            if value == _GRID_CONTENT:
                out.append("content")
            elif value >= _GRID_FR_BASE:
                out.append(f"{value - _GRID_FR_BASE}fr")
            else:
                out.append(str(value))
        return None  # no terminator within limit: not a template
    except (gdb.error, gdb.MemoryError):
        return None


def _resolve_grid_templates(node):
    """Replace grid template pointers with their contents, in place."""
    for slot in node.get("styles") or []:
        for prop in slot.get("properties") or []:
            if prop.get("prop_name") not in _GRID_PROPS:
                continue
            raw = prop.get("ptr") or prop.get("value_str") or ""
            if not raw.startswith("0x"):
                continue
            template = _read_grid_template(int(raw, 16))
            if template:
                prop["value_str"] = template
    for child in node.get("children") or []:
        _resolve_grid_templates(child)


def _resolve_asset(addr):
    """Name a widget_data pointer the way the plugin names style pointers."""
    from lvglgdb.lvgl.misc.lv_style import _read_image_src, _read_symbol

    if not addr:
        return None
    return _read_symbol(addr) or _read_image_src(addr)


# name -> {"file": ...} or {"error": ...}, filled as images are met
_exported = {}


def export_image(name, addr, out_dir):
    """Rebuild the image at `addr` as a PNG, once per name.

    Everything a PNG needs is in the lv_image_dsc_t: the header carries the
    color format and geometry, and `data` points at the pixels.
    """
    if name in _exported:
        return _exported[name]

    result = {}
    try:
        dsc = gdb.Value(addr).cast(gdb.lookup_type("lv_image_dsc_t").pointer())
        header = dsc["header"]
        cf = int(header["cf"])
        width, height = int(header["w"]), int(header["h"])
        stride = int(header["stride"]) or images.stride_for(cf, width)
        flags = int(header["flags"])
        data_ptr = int(dsc["data"])
        size = int(dsc["data_size"])

        if flags & images.FLAG_COMPRESSED:
            raise images.UnsupportedImage("the image is compressed in the binary")
        if not data_ptr:
            raise images.UnsupportedImage("the image has no data pointer")

        needed = images.expected_size(cf, width, height, stride)
        if size < needed:
            size = needed
        data = bytes(gdb.selected_inferior().read_memory(data_ptr, size))

        path = os.path.join(out_dir, f"{name}.png")
        images.to_png(cf, width, height, stride, data, path)
        result = {
            "file": os.path.basename(path),
            "width": width,
            "height": height,
            "color_format": images.CF_NAMES.get(cf, ""),
        }
    except images.UnsupportedImage as e:
        result = {"error": str(e)}
    except (gdb.error, gdb.MemoryError, IndexError, OSError) as e:
        result = {"error": f"{type(e).__name__}: {e}"}

    _exported[name] = result
    return result


def _collect_events(obj):
    """The event callbacks attached to one object.

    The callback itself cannot be converted - it is compiled code - but its
    name and trigger can, which is enough for XML to declare the hook and for
    the user to reimplement the body.
    """
    try:
        events = obj.event_list
        if events is None:
            return []
    except (gdb.error, gdb.MemoryError):
        return []

    out = []
    for dsc in events:
        try:
            d = dsc.snapshot().as_dict()
        except (gdb.error, gdb.MemoryError):
            continue
        name = _symbol_from_cb(d.get("cb") or "")
        if not name:
            continue
        # LVGL installs some itself - lv_keyboard_def_event_cb is added by the
        # keyboard constructor. The rebuilt widget gets them again on its own,
        # and they are not the app's code to reimplement.
        if name.startswith("lv_"):
            continue
        out.append({
            "callback": name,
            "trigger": (d.get("filter_name") or "ALL").lower(),
            "preprocess": bool(d.get("is_preprocess")),
        })
    return out


def _symbol_from_cb(formatted):
    """Pull the function name out of GDB's "0x… <name>" formatting."""
    if "<" in formatted and ">" in formatted:
        name = formatted[formatted.index("<") + 1:formatted.rindex(">")]
        return name.split("+")[0].strip() or None
    return None


def probe_class_defaults(classes):
    """Ask LVGL what a fresh widget of each class looks like.

    Every widget class sets its own flags in its constructor and gets its own
    styles from the theme, and neither is written down anywhere the converter
    can read. Guessing from the app's own widgets cannot work either: when a
    whole class deviates the same way - every arc in the widgets demo has
    lv_obj_set_clickable(arc, false) - there is nothing to compare against.

    So make one of each, in the running process, and look. The objects live on
    a throwaway screen that is deleted afterwards.
    """
    from lvglgdb.lvgl.core.lv_obj import LVObject

    defaults = {}
    try:
        scratch = gdb.parse_and_eval("lv_obj_create(0)")
    except gdb.error as e:
        print(f"lvgl_app2pro: cannot probe class defaults ({e})")
        return defaults

    for cls in sorted(classes):
        if not cls.startswith("lv_") or "-" in cls:
            continue
        try:
            obj = gdb.parse_and_eval(f"{cls}_create({int(scratch)})")
            if not int(obj):
                continue
            reference = LVObject(obj)
            selectors = sorted({
                slot.selector_str for slot in reference.obj_styles
                if "theme" in (slot.flags_str or "")
            })
            from lvglgdb.lvgl.widgets import wrap_widget

            widget = wrap_widget(reference) or reference
            defaults[cls] = {
                "flags": sorted(reference.flags_list),
                "theme_selectors": selectors,
                # What the widget's own fields look like untouched, so the
                # converter can leave LVGL's defaults out of the XML.
                "widget_data": widget.snapshot().as_dict().get("widget_data") or {},
            }
        except (gdb.error, gdb.MemoryError):
            continue

    try:
        gdb.parse_and_eval(f"lv_obj_delete({int(scratch)})")
    except gdb.error:
        pass
    return defaults


def _classes_in(node, out):
    out.add(node.get("class_name"))
    for child in node.get("children") or []:
        _classes_in(child, out)
    return out


def _extra_flags(obj):
    """Flags LVGL does not keep in the flag bitfields.

    lv_obj_set_flex_in_new_track() stores its bit in spec_attr->user_flags
    instead ("For backward compatibility ... It will have its own bit in
    lv_obj_t after v9.5"), so it never shows up in flags_list.
    """
    try:
        spec = obj.spec_attr
        if not spec or not int(spec):
            return []
        user_flags = spec.safe_field("user_flags")
        if user_flags is not None and int(user_flags) & 0x1:
            return ["FLEX_IN_NEW_TRACK"]
    except (gdb.error, gdb.MemoryError):
        pass
    return []


def _flag_map(obj, out):
    """Map object address -> extra flags, for the whole subtree."""
    try:
        extra = _extra_flags(obj)
        if extra:
            out[hex(int(obj))] = extra
        for child in obj.children:
            _flag_map(child, out)
    except (gdb.error, gdb.MemoryError):
        pass
    return out


def _apply_flags(node, mapping):
    extra = mapping.get(node.get("addr"))
    if extra:
        node["flags_list"] = list(node.get("flags_list") or []) + extra
    for child in node.get("children") or []:
        _apply_flags(child, mapping)


def _event_map(obj, out):
    """Map object address -> its events, for the whole subtree.

    Keyed by address rather than walked in parallel with the snapshot: if a
    child is ever dropped from the dump the two walks would fall out of step
    and hang events on the wrong widget.
    """
    try:
        out[hex(int(obj))] = _collect_events(obj)
        for child in obj.children:
            _event_map(child, out)
    except (gdb.error, gdb.MemoryError):
        pass
    return out


def _apply_events(node, mapping):
    node["events"] = mapping.get(node.get("addr")) or []
    for child in node.get("children") or []:
        _apply_events(child, mapping)


def _chart_series(obj):
    """The data series of a chart: colour, axis and the points themselves.

    A series is not a child object, it is an entry in the chart's linked list,
    so nothing in the object tree hints that it exists. Without this a
    converted chart is an empty frame.
    """
    from lvglgdb.lvgl.misc.lv_ll import LVList

    try:
        chart = gdb.Value(int(obj)).cast(gdb.lookup_type("lv_chart_t").pointer())
        point_cnt = int(chart["point_cnt"])
        series = []
        for entry in LVList(chart["series_ll"], "lv_chart_series_t"):
            colour = entry["color"]
            points = entry["y_points"]
            values = []
            if int(points):
                values = [int(points[i]) for i in range(point_cnt)]
            series.append({
                "color": "0x%02x%02x%02x" % (
                    int(colour["red"]) & 0xFF,
                    int(colour["green"]) & 0xFF,
                    int(colour["blue"]) & 0xFF,
                ),
                "axis": "secondary_y" if int(entry["y_axis_sec"]) else "primary_y",
                "hidden": bool(int(entry["hidden"])),
                "values": values,
            })
        return series
    except (gdb.error, gdb.MemoryError, IndexError):
        return []


def _roller_options(obj):
    """The roller's option list.

    lv_roller keeps its options as the text of an internal label rather than
    in its own struct, and that label is an lv_roller_label with no wrapper of
    its own, so widget_data has nothing to offer.
    """
    try:
        child = next(iter(obj.children), None)
        if child is None:
            return None
        label = gdb.Value(int(child)).cast(gdb.lookup_type("lv_label_t").pointer())
        text = label["text"]
        return text.string() if int(text) else None
    except (gdb.error, gdb.MemoryError, UnicodeDecodeError, StopIteration):
        return None


def _series_map(obj, out):
    try:
        if obj.class_name == "lv_chart":
            found = _chart_series(obj)
            if found:
                out[hex(int(obj))] = {"series": found}
        elif obj.class_name == "lv_roller":
            options = _roller_options(obj)
            if options:
                out[hex(int(obj))] = {"options": options}
        for child in obj.children:
            _series_map(child, out)
    except (gdb.error, gdb.MemoryError):
        pass
    return out


def _apply_series(node, mapping):
    extra = mapping.get(node.get("addr")) or {}
    if "series" in extra:
        node["series"] = extra["series"]
    if "options" in extra:
        node.setdefault("widget_data", {})["options"] = extra["options"]
    for child in node.get("children") or []:
        _apply_series(child, mapping)


def _is_dsc(addr):
    """lv_image_src_get_type(): a leading magic byte means an lv_image_dsc_t."""
    try:
        first = int(gdb.selected_inferior().read_memory(addr, 1)[0][0])
    except (gdb.error, gdb.MemoryError):
        return False
    return first in (0x19, 0x00)


def _maybe_export(name, addr, out_dir):
    """Export an image source, unless it is a file path or an LV_SYMBOL glyph."""
    if not out_dir or not name or name.startswith("0x") or not _is_dsc(addr):
        return
    export_image(name, addr, out_dir)


_IMAGE_STYLE_PROPS = ("BG_IMAGE_SRC", "ARC_IMAGE_SRC", "BITMAP_MASK_SRC")


def _read_string_array(addr, count):
    """Read `count` strings from a `const char **`, for lv_scale's text_src."""
    if not addr or count <= 0:
        return None
    try:
        pointers = gdb.Value(addr).cast(
            gdb.lookup_type("char").pointer().pointer()
        )
        out = []
        for i in range(count):
            item = pointers[i]
            if not int(item):
                break
            out.append(item.string())
        return out or None
    except (gdb.error, gdb.MemoryError, UnicodeDecodeError):
        return None


def _resolve_widget_data(node, out_dir):
    """Replace the raw pointers in widget_data with names, in place."""
    data = node.get("widget_data")
    if isinstance(data, dict):
        for key in ("src", "bitmap_mask_src"):
            raw = data.get(key)
            if isinstance(raw, str) and raw.startswith("0x"):
                addr = int(raw, 16)
                name = _resolve_asset(addr)
                data[key] = name if name else raw
                if name:
                    data[key + "_ptr"] = raw
                    _maybe_export(name, addr, out_dir)

        # A scale's custom labels are an array of strings the app owns, so the
        # count has to come from the widget itself.
        raw = data.get("txt_src")
        if isinstance(raw, str) and raw.startswith("0x"):
            labels = _read_string_array(int(raw, 16),
                                        int(data.get("custom_label_cnt") or 0))
            data["txt_src"] = labels if labels else None

    for slot in node.get("styles") or []:
        for prop in slot.get("properties") or []:
            if prop.get("prop_name") not in _IMAGE_STYLE_PROPS:
                continue
            raw = prop.get("ptr")
            if raw:
                _maybe_export(prop.get("value_str"), int(raw, 16), out_dir)

    for child in node.get("children") or []:
        _resolve_widget_data(child, out_dir)


def dump():
    _load_plugin()
    from lvglgdb.lvgl.core.lv_global import curr_inst

    gdb.execute("set pagination off")
    gdb.execute("set confirm off")

    stop_at = os.environ.get("LVGL_APP2PRO_BREAK", DEFAULT_STOP)
    gdb.execute(f"break {stop_at}")

    if stop_at == DEFAULT_STOP:
        # Stop on the second call, not the first. By then LVGL has run a full
        # cycle, so layouts are calculated and coordinates are real; at the
        # first call nothing has been laid out or drawn yet.
        number = gdb.breakpoints()[-1].number
        gdb.execute(f"ignore {number} 1")

    app_args = os.environ.get("LVGL_APP2PRO_ARGS")
    if app_args:
        gdb.execute(f"set args {app_args}")

    gdb.execute("run")

    lvgl = curr_inst()
    if not lvgl.ensure_init():
        _fail(f"LVGL is not initialised at {stop_at}; try a later stop point")

    capabilities = probe_capabilities()
    image_dir = os.environ.get("LVGL_APP2PRO_IMAGES") or None
    if image_dir:
        os.makedirs(image_dir, exist_ok=True)

    displays = []
    for index, display in enumerate(lvgl.displays()):
        info = display.snapshot().as_dict()
        layers = display.layer_addrs
        screens = []
        for screen in display.screens:
            node = screen.snapshot(
                include_children=True, include_styles=True
            ).as_dict()
            _resolve_widget_data(node, image_dir)
            _resolve_grid_templates(node)
            _apply_flags(node, _flag_map(screen, {}))
            _apply_events(node, _event_map(screen, {}))
            _apply_series(node, _series_map(screen, {}))
            node["layer"] = layers.get(int(screen))
            screens.append(node)
        info["index"] = index
        info["screens"] = screens
        displays.append(info)

    classes = set()
    for display in displays:
        for screen in display["screens"]:
            _classes_in(screen, classes)

    out = {"lvgl_version": probe_version(),
           "capabilities": capabilities, "displays": displays,
           "images": _exported,
           "class_defaults": probe_class_defaults(classes)}
    with open(os.environ["LVGL_APP2PRO_OUT"], "w") as f:
        json.dump(out, f)

    total = sum(len(d["screens"]) for d in displays)
    exported = sum(1 for v in _exported.values() if "file" in v)
    print(f"lvgl_app2pro: dumped {total} screen(s) from {len(displays)} display(s), "
          f"{exported}/{len(_exported)} images rebuilt")
    gdb.execute("kill")


dump()
