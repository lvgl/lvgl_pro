"""Writes the LVGL Pro project: project.xml, globals.xml and screens/*.xml.

The XML dialect follows lv_xml: widget geometry is a plain attribute, other
style properties take a `style_` prefix inline, and anything with a part or a
state needs a named <style> because an attribute has nowhere to put a selector.
"""

import re

from .mapping import DIRECT_ONLY, DIRECT_PROPS, PSEUDO_TAGS, WIDGET_TAGS
from .model import SECTION_STYLES, walk

INDENT = "\t"


def escape(value):
    """Escape for an XML attribute. Newlines survive as entities, as lv_xml writes them."""
    return (str(value)
            .replace("&", "&amp;")
            .replace("<", "&lt;")
            .replace(">", "&gt;")
            .replace('"', "&quot;")
            .replace("\n", "&#10;")
            .replace("\r", ""))


def attrs(pairs):
    return "".join(f' {name}="{escape(value)}"' for name, value in pairs if value is not None)


class StyleBook:
    """Names the styles that cannot be inlined, and decides where they live.

    A style used by more than one screen goes to globals.xml; one used by a
    single screen stays in that screen, so a screen file stays readable on its own.
    """

    def __init__(self):
        self.names = {}       # props -> name
        self.props = {}       # name -> props
        self._screens = {}    # name -> set of screen names

    def register(self, slot, screen_name):
        key = slot.key()
        name = self.names.get(key)
        if name is None:
            name = f"style_{len(self.names) + 1}"
            self.names[key] = name
            self.props[name] = key
        self._screens.setdefault(name, set()).add(screen_name)
        return name

    def global_names(self):
        return sorted(n for n, s in self._screens.items() if len(s) > 1)

    def screen_names(self, screen_name):
        return sorted(n for n, s in self._screens.items()
                      if len(s) == 1 and screen_name in s)


def plan_styles(screens):
    """Assign a name to every non-inlinable slot, before anything is written.

    A widget that removes styles cannot keep its own as attributes. In C the
    order is `lv_obj_remove_style_all(o)` and then the local sets; in XML an
    element's attributes are applied with its start tag, before any child, so
    `<remove_style_all/>` would wipe them - taking `width` and `height` with
    it, since those are local style properties too. Children are processed in
    order, so the way to keep them is a named <style> referenced after the
    removal.
    """
    book = StyleBook()
    for screen in screens:
        for node in walk(screen.root):
            node.style_refs = []
            node.inline = []
            removes_styles = node.remove_style_all or node.removed_selectors
            for slot in node.slots:
                if slot.inlinable and not removes_styles:
                    node.inline.extend(slot.props)
                else:
                    name = book.register(slot, screen.name)
                    node.style_refs.append((name, slot.selector))
            # A scale section's styles have no attribute form, so they are
            # always named. Registering them here keeps one style definition
            # even when several sections share it.
            for section in node.sections:
                section["names"] = {
                    key: book.register(slot, screen.name)
                    for key, slot in section["styles"].items()
                }
    return book


def _node_attrs(node):
    """Split a node's properties into direct attributes and style_* attributes."""
    direct, styled = [], []
    for name, value in node.inline:
        (direct if name in DIRECT_PROPS else styled).append((name, value))
    pairs = []
    if node.name:
        pairs.append(("name", node.name))
    pairs.extend(sorted(direct))
    pairs.extend(sorted(node.widget_data.items()))
    pairs.extend(sorted(node.flag_attrs.items()))
    pairs.extend((state, "true") for state in sorted(node.states))
    pairs.extend((f"style_{name}", value) for name, value in sorted(styled))
    return pairs


def _tag(node, report):
    schema = report.schema
    known = (schema.tags | schema.pseudo_tags) if schema and schema.tags else (
        WIDGET_TAGS | PSEUDO_TAGS)
    if node.cls in known:
        return node.cls
    report.warn(f"{node.cls} has no XML widget and was written as lv_obj")
    return "lv_obj"


def render_events(node, report, pad):
    """Declare each attached callback, and say it still has to be written.

    The compiled callback cannot come across, but its name and trigger can, so
    the hook is preserved and only the body is left to the user.
    """
    lines = []
    for event in node.events:
        report.callbacks.setdefault(event["callback"], set()).add(
            event["trigger"])
        lines.append(f"{pad}<!-- TODO: implement {event['callback']}() -->")
        lines.append(
            f"{pad}<event_cb"
            f"{attrs([('callback', event['callback']), ('trigger', event['trigger'])])} />"
        )
    return lines


def render_node(node, report, depth):
    """One widget and everything under it."""
    pad = INDENT * depth
    lines = []
    for note in node.notes:
        lines.append(f"{pad}<!-- TODO: {note} -->")

    tag = _tag(node, report)
    body = []
    if node.remove_style_all:
        body.append(f"{pad}{INDENT}<remove_style_all />")
    for selector in node.removed_selectors:
        body.append(f'{pad}{INDENT}<remove_style selector="{selector}" />')
    body += [f"{pad}{INDENT}<style{attrs([('name', n), ('selector', s or None)])} />"
             for n, s in node.style_refs]
    for one in node.series:
        body.append(f"{pad}{INDENT}<lv_chart-series" + attrs([
            ("color", one["color"]),
            ("axis", one["axis"] if one["axis"] != "primary_y" else None),
            ("values", " ".join(str(v) for v in one["values"]) or None),
        ]) + " />")
    for one in node.sections:
        names = one.get("names") or {}
        body.append(f"{pad}{INDENT}<lv_scale-section" + attrs(
            [("min_value", one["min_value"]), ("max_value", one["max_value"])]
            + [(key, names.get(key)) for key in SECTION_STYLES]
        ) + " />")
    body += render_events(node, report, pad + INDENT)
    body += [line for child in node.children
             for line in render_node(child, report, depth + 1)]

    head = f"{pad}<{tag}{attrs(_node_attrs(node))}"
    lines.append(f"{head}>" if body else f"{head} />")
    if body:
        lines.extend(body)
        lines.append(f"{pad}</{tag}>")
    return lines


def render_style_defs(names, book, report, depth):
    lines = []
    for name in names:
        props = [(n, v) for n, v in book.props[name] if n not in DIRECT_ONLY]
        if report and len(props) != len(book.props[name]):
            report.warn(
                "x/y in a style with a part or state were dropped: "
                "lv_xml_style_prop_to_enum() does not accept the names"
            )
        lines.append(f"{INDENT * depth}<style{attrs([('name', name)] + props)} />")
    return lines


def render_screen(screen, book, report):
    """One screens/<name>.xml."""
    lines = ["<screen>"]
    own = book.screen_names(screen.name)
    if own:
        lines.append(f"{INDENT}<styles>")
        lines.extend(render_style_defs(own, book, report, 2))
        lines.append(f"{INDENT}</styles>")

    root = screen.root
    body = []
    if root.remove_style_all:
        body.append(f"{INDENT * 2}<remove_style_all />")
    body += [f"{INDENT * 2}<style{attrs([('name', n), ('selector', s or None)])} />"
             for n, s in root.style_refs]
    body += render_events(root, report, INDENT * 2)
    body += [line for child in root.children for line in render_node(child, report, 2)]

    view = f"{INDENT}<view{attrs(_node_attrs(root))}"
    if body:
        lines.append(f"{view}>")
        lines.extend(body)
        lines.append(f"{INDENT}</view>")
    else:
        lines.append(f"{view} />")
    lines.append("</screen>")
    return "\n".join(lines) + "\n"


def render_project(displays, lvgl_version):
    """project.xml, with one target per display the application has.

    The screens of every display are converted, so declaring only the first
    display would leave the rest sized by a resolution that is not theirs.
    """
    targets = []
    for index, display in enumerate(displays or [{}]):
        targets += [
            f'{INDENT * 2}<target name="target{index + 1}">',
            f'{INDENT * 3}<display width="{display.get("hor_res", 0)}"'
            f' height="{display.get("ver_res", 0)}" />',
            f"{INDENT * 2}</target>",
        ]
    return (
        f'<project lvgl_version="{lvgl_version}">\n'
        f"{INDENT}<targets>\n"
        + "\n".join(targets) + "\n"
        f"{INDENT}</targets>\n"
        "</project>\n"
    )


def render_globals(book, consts, report, exported):
    lines = ["<globals>"]

    lines.append(f"{INDENT}<consts>")
    for kind, name, value in consts.items():
        lines.append(f'{INDENT * 2}<{kind} name="{name}" value="{value}" />')
    lines.append(f"{INDENT}</consts>")
    lines.append("")

    lines.append(f"{INDENT}<styles>")
    lines.extend(render_style_defs(book.global_names(), book, report, 2))
    lines.append(f"{INDENT}</styles>")
    lines.append("")

    lines.append(f"{INDENT}<images>")
    for name in sorted(report.images):
        rebuilt = exported.get(name) or {}
        if "file" in rebuilt:
            pairs = [("name", name), ("src_path", f"images/{rebuilt['file']}")]
            if rebuilt.get("color_format"):
                pairs.append(("color_format", rebuilt["color_format"]))
            lines.append(f"{INDENT * 2}<data{attrs(pairs)} />")
        else:
            why = rebuilt.get("error", "no image data was found for it")
            lines.append(f"{INDENT * 2}<!-- TODO: supply a file for {name}: {why} -->")
    lines.append(f"{INDENT}</images>")
    lines.append("")

    lines.append(f"{INDENT}<fonts>")
    for name in sorted(report.fonts):
        lines.append(f"{INDENT * 2}<!-- TODO: supply a source for {name} -->")
    lines.append(f"{INDENT}</fonts>")

    lines.append("</globals>")
    return "\n".join(lines) + "\n"


def _safe_name(name, report):
    """A screen name that is safe as a file name and as a component name.

    The name comes from lv_obj_set_name(), so it is whatever the application
    passed: it can contain a path separator, which would write outside
    screens/, and Pro uses the file name as the component's name, which has to
    be an identifier.
    """
    safe = re.sub(r"[^A-Za-z0-9_]", "_", name or "").strip("_") or "screen"
    if safe[0].isdigit():
        safe = f"screen_{safe}"
    if safe != name:
        report.warn(f'the screen named "{name}" was written as "{safe}"')
    return safe


def write_project(out_dir, dump, screens, book, consts, report, lvgl_version):
    """Write the whole project and return the list of files written."""
    out_dir.mkdir(parents=True, exist_ok=True)
    (out_dir / "screens").mkdir(exist_ok=True)
    (out_dir / "components").mkdir(exist_ok=True)
    (out_dir / "images").mkdir(exist_ok=True)
    (out_dir / "fonts").mkdir(exist_ok=True)

    written = []
    project = out_dir / "project.xml"
    project.write_text(render_project(dump.get("displays"), lvgl_version))
    written.append(project)

    globals_file = out_dir / "globals.xml"
    globals_file.write_text(
        render_globals(book, consts, report, dump.get("images") or {}))
    written.append(globals_file)

    # Every emitted name, not a count per base: sanitising can make two screens
    # share a base, and a suffixed name can collide with a real one, so
    # "screen_1" twice plus a screen actually called "screen_1_2" must still be
    # three files.
    taken = set()
    for screen in screens:
        safe = _safe_name(screen.name, report)
        name, attempt = safe, 1
        while name in taken:
            attempt += 1
            name = f"{safe}_{attempt}"
        taken.add(name)
        path = out_dir / "screens" / f"{name}.xml"
        path.write_text(render_screen(screen, book, report))
        written.append(path)
    return written
