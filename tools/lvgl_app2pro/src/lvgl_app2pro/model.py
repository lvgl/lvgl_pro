"""The dump, turned into a tree the emitter can walk.

This is where theme styles are discarded and where each remaining style slot is
decided to be inline or named. Nothing here writes XML.
"""

from dataclasses import dataclass, field

from .mapping import (
    DROPPED_SLOT_FLAGS,
    FLAG_ALIASES,
    FLAGS_DEFAULT_ON,
    SELF_MANAGED,
    SKIP_CLASSES,
    removal_selector,
    selector_to_xml,
)


def _flag_name(reported):
    """The XML name of a flag the plugin reported."""
    name = reported.lower()
    return FLAG_ALIASES.get(name, name)


# The other states - pressed, hovered, focused, scrolled, edited - describe
# what the user was doing at the moment of the dump, not how the UI was built.
AUTHORED_STATES = frozenset({"checked", "disabled"})


@dataclass
class StyleSlot:
    """One entry of obj->styles[], already filtered down to what XML can carry."""

    selector: str
    props: tuple  # ((xml_name, value_str), ...) sorted, so it can be a dict key
    is_local: bool

    @property
    def inlinable(self) -> bool:
        """Local styles on the default selector become style_* attributes.

        Everything else needs a named <style>, because an inline attribute has
        nowhere to put a part or a state.
        """
        return self.is_local and not self.selector

    def key(self):
        """Identity for deduplication.

        The selector is not part of it: in XML a <style> holds only properties
        and the selector lives on the reference, so one definition serves every
        selector it is applied with.
        """
        return self.props


@dataclass
class Node:
    cls: str
    name: "str | None"
    coords: dict
    addr: "str | None"
    flags: frozenset
    states: frozenset
    theme_styled: bool
    theme_selectors: frozenset
    slots: list
    widget_data: dict
    events: list = field(default_factory=list)
    series: list = field(default_factory=list)
    sections: list = field(default_factory=list)
    children: list = field(default_factory=list)
    notes: list = field(default_factory=list)
    # Both filled by resolve_flags().
    flag_attrs: dict = field(default_factory=dict)
    remove_style_all: bool = False
    removed_selectors: list = field(default_factory=list)


@dataclass
class Screen:
    name: str
    layer: "str | None"
    root: Node


def _slots(raw_node, prop_filter, notes):
    """Keep the app's own style slots, drop the theme's."""
    out = []
    themed = False
    selectors = set()
    for slot in raw_node.get("styles") or []:
        if "error" in slot:
            notes.append(f"unreadable style slot: {slot.get('error')}")
            continue
        flags = (slot.get("flags_str") or "").split(",")
        if "theme" in flags:
            themed = True
            selectors.add(slot.get("selector_str") or "")
        if any(dropped in flags for dropped in DROPPED_SLOT_FLAGS):
            continue
        props = []
        for prop in slot.get("properties") or []:
            pair = prop_filter(prop, notes)
            if pair:
                props.append(pair)
        if not props:
            continue
        out.append(StyleSlot(
            selector=selector_to_xml(slot.get("selector_str") or ""),
            props=tuple(sorted(props)),
            is_local="local" in flags,
        ))
    return out, themed, frozenset(selectors)


#: The section styles XML can set, in the order they read best.
SECTION_STYLES = ("style_main", "style_indicator", "style_items")


def _sections(raw_node, prop_filter, notes):
    """A scale's sections, with each style turned into a slot to be named.

    The styles are shared lv_style_t the application owns, so they can only
    become named styles - there is no attribute form for a section's style.
    """
    out = []
    for raw in raw_node.get("sections") or []:
        section = {"min_value": raw.get("min_value"),
                   "max_value": raw.get("max_value"), "styles": {}}
        for key in SECTION_STYLES:
            props = []
            for prop in raw.get(key) or []:
                pair = prop_filter(prop, notes)
                if pair:
                    props.append(pair)
            if props:
                section["styles"][key] = StyleSlot(
                    selector="", props=tuple(sorted(props)), is_local=False)
        out.append(section)
    return out


def build_node(raw, prop_filter, widget_filter):
    """Turn one dumped object, and its children, into Nodes."""
    notes = []
    cls = raw.get("class_name") or "?"
    slots, themed, selectors = _slots(raw, prop_filter, notes)
    node = Node(
        cls=cls,
        name=raw.get("name"),
        coords=raw.get("coords") or {},
        addr=raw.get("addr"),
        # The plugin reports flag names uppercase (HIDDEN), XML wants hidden.
        flags=frozenset(_flag_name(f) for f in raw.get("flags_list") or []),
        states=frozenset(
            st.lower() for st in raw.get("state_list") or []
            if st.lower() in AUTHORED_STATES
        ),
        theme_styled=themed,
        theme_selectors=selectors,
        slots=slots,
        widget_data=widget_filter(cls, raw.get("widget_data") or {}, notes),
        events=list(raw.get("events") or []),
        series=list(raw.get("series") or []),
        sections=_sections(raw, prop_filter, notes),
        notes=notes,
    )
    if cls not in SELF_MANAGED:
        for child in raw.get("children") or []:
            if "error" in child:
                notes.append(f"unreadable child: {child.get('error')}")
                continue
            if child.get("class_name") in SKIP_CLASSES:
                continue
            node.children.append(build_node(child, prop_filter, widget_filter))

    transform = TRANSFORMS.get(cls)
    if transform:
        transform(node)
    return node


def _tabview(node):
    """Rebuild a tabview's internals as <lv_tabview-tab> elements.

    At runtime a tabview is a tab bar plus a content container, and a tab is a
    button in one and a page in the other. XML says it the other way round: one
    element per tab, holding the page's content and the button's text. Child
    order is fixed by the constructor and by lv_tabview_get_tab_bar(), which is
    lv_obj_get_child(tv, 0).
    """
    if len(node.children) < 2:
        node.notes.append("tabview has no tab bar and content, left as-is")
        return

    bar, content = node.children[0], node.children[1]

    # The constructor makes exactly those two. Anything after them the app
    # added to the tabview itself - the widgets demo floats its colour changer
    # there - and it stays a child of the tabview, after the tabs.
    own = node.children[2:]

    # lv_tabview_add_tab() appends one button per tab, in order, so the first
    # N children of the bar are the tabs. Anything after them the app put
    # there itself - the widgets demo adds a logo and two labels - and it has
    # to survive as a child of <lv_tabview-tab_bar>.
    tab_count = len(content.children)
    buttons, extras = bar.children[:tab_count], bar.children[tab_count:]

    names = []
    for button in buttons:
        label = next((c for c in button.children if c.cls == "lv_label"), None)
        names.append(label.widget_data.get("text") if label else None)

    if len(names) != len(content.children):
        node.notes.append(
            f"tabview has {len(names)} buttons but {len(content.children)} pages"
        )

    tabs = []
    # The bar carries styling of its own (the demo pads it to clear a logo),
    # and <lv_tabview-tab_bar> is where that and its extra children belong.
    if bar.slots or extras:
        tabs.append(Node(
            cls="lv_tabview-tab_bar", name=None, coords=bar.coords,
            addr=bar.addr,
            flags=bar.flags, states=bar.states, theme_styled=bar.theme_styled,
            theme_selectors=bar.theme_selectors, slots=bar.slots,
            widget_data={}, events=bar.events, children=extras,
        ))

    for index, page in enumerate(content.children):
        text = names[index] if index < len(names) else None
        tabs.append(Node(
            cls="lv_tabview-tab",
            name=page.name,
            coords=page.coords,
            addr=page.addr,
            flags=page.flags,
            states=page.states,
            theme_styled=page.theme_styled,
            theme_selectors=page.theme_selectors,
            # The page is the tab's `main` part, so its styles belong here.
            slots=page.slots,
            widget_data={"text": text} if text else {},
            events=page.events,
            children=page.children,
            notes=page.notes,
        ))
    node.children = tabs + own


# Widgets whose runtime children do not match their XML children.
TRANSFORMS = {"lv_tabview": _tabview}


def build_screens(dump, prop_filter, widget_filter, include_layers=False):
    """Every screen of every display, in the order LVGL stores them.

    disp->screens[] also holds the bottom, top and system layers. They are
    LVGL's own furniture, not screens of the UI, so they are left out unless
    asked for.
    """
    screens = []
    for display in dump.get("displays") or []:
        for index, raw in enumerate(display.get("screens") or []):
            layer = raw.get("layer")
            if layer and layer != "act_scr" and not include_layers:
                continue
            root = build_node(raw, prop_filter, widget_filter)
            name = root.name or _default_name(display, index, layer)
            screens.append(Screen(name=name, layer=layer, root=root))
    return screens


# lv_obj_constructor() only sets these when the object has a parent, so a
# screen root is missing them for a reason that is not the app's doing.
PARENT_ONLY = frozenset(
    {"press_lock", "scroll_chain_hor", "scroll_chain_ver", "gesture_bubble"}
)


def _diff_flags(flags, base):
    """Only what differs from a freshly created widget of the same class."""
    attrs = {}
    for flag in sorted(base - flags):
        attrs[flag] = "false"
    for flag in sorted(flags - base):
        attrs[flag] = "true"
    return attrs


def _flag_attrs(flags, parented=True):
    """Flags that differ from what lv_obj_constructor() leaves behind.

    Compared against the base defaults rather than against sibling widgets:
    a whole class can deviate at once - every arc in the widgets demo has
    lv_obj_set_clickable(arc, false) - and comparing instances to each other
    cannot see that. A widget class that sets its own default will produce a
    redundant attribute, which is harmless because the XML rebuilds the same
    widget and applies the same value.
    """
    attrs = {}
    for flag in sorted(FLAGS_DEFAULT_ON):
        if not parented and flag in PARENT_ONLY:
            continue
        if flag not in flags:
            attrs[flag] = "false"
    for flag in sorted(flags):
        if flag not in FLAGS_DEFAULT_ON:
            attrs[flag] = "true"
    return attrs


def _writable_flags(attrs, schema, report):
    """Drop the flags XML has no attribute for.

    Most of LV_OBJ_FLAG_* is a property in the schema, but the ones an
    application is free to define for itself - layout_1, widget_2, user_3 -
    are only enum members, so writing them produces XML that does not
    validate. What they mean is the app's business anyway.
    """
    if not schema or not schema.props:
        return attrs
    kept = {}
    for name, value in attrs.items():
        if schema.prop_type("lv_obj", name) is not None:
            kept[name] = value
        elif value == "true" and report:
            report.warn(f"{name} is an application-defined object flag, which "
                        "XML cannot set; it was left out")
    return kept


def _resolve_style_removal(node, theme_reference, theme_styles_this_class):
    """Decide what the application removed, by asking what it was given.

    Nothing in LVGL records that a style was removed: lv_obj_remove_style()
    just compacts the object's style list. So the only way to see a removal is
    to know what the theme put there, and the theme's answer depends on the
    individual object - its parent, and sometimes its index among the parent's
    children - not on its class. `theme_reference` holds that per-object answer,
    read back from the theme itself.

    "Has no theme styles" is not a usable test on its own, in either direction.
    The theme gives some objects nothing at all, so an empty list is not a
    removal; and a partial removal leaves other parts behind, so a non-empty
    list is not proof that nothing was removed. The widgets demo has both: the
    content area of an lv_tabview is styled with nothing, and its chart wrappers
    remove only LV_PART_MAIN and keep the scrollbar the theme gave them.
    """
    given = theme_reference.get(node.addr) if theme_reference else None
    if given is None:
        # No per-object answer available: fall back to the weaker test, which
        # can at least see a wholesale removal.
        node.remove_style_all = theme_styles_this_class and not node.theme_styled
        return

    given = set(given)
    removed = given - set(node.theme_selectors)
    if not removed:
        return
    if removed == given:
        node.remove_style_all = True
    else:
        node.removed_selectors = sorted(
            {removal_selector(sel) for sel in removed}
        )


def resolve_flags(screens, class_defaults=None, schema=None, report=None,
                  theme_reference=None):
    """Decide which object flags are worth writing, per widget class.

    Every widget class sets its own defaults in its constructor, so there is no
    fixed list of what to expect. The defaults are learned from the project
    instead: a flag that differs between two instances of the same class cannot
    be a constructor default, so it is written out on the instances that have
    it. A flag that never varies is assumed to be the class default and left
    alone, which keeps `clickable="false"` off every label.

    With a single instance of a class there is nothing to compare against, so
    it falls back to what lv_obj_constructor() sets: a flag outside that set is
    the app's doing and is written; nothing is written as false, because that
    could not be told apart from a class default.
    """
    # lv_obj_constructor() sets press_lock, scroll_chain_* and gesture_bubble
    # only when the object has a parent, so a screen root differs from every
    # other object of its class for reasons that have nothing to do with the
    # app. Learning defaults from the roots would put those four flags on every
    # widget, so they are left out of the comparison.
    class_defaults = class_defaults or {}
    roots = {id(screen.root) for screen in screens}

    by_class = {}
    for screen in screens:
        for node in walk(screen.root):
            if id(node) not in roots:
                by_class.setdefault(node.cls, []).append(node)

    for cls, nodes in by_class.items():
        seen = [n.flags for n in nodes]
        varying = set()
        if len(nodes) > 1:
            everywhere = set.intersection(*(set(f) for f in seen))
            anywhere = set.union(*(set(f) for f in seen))
            varying = anywhere - everywhere

        # The theme does not style every class, so a bare object is not proof
        # that lv_obj_remove_style_all() was called. It is only evidence when
        # another object of the same class did get theme styles.
        theme_styles_this_class = any(n.theme_styled for n in nodes)

        reference = class_defaults.get(cls)
        for node in nodes:
            if reference:
                # LVGL itself said what a fresh one of these looks like.
                base = frozenset(_flag_name(f) for f in reference.get("flags") or [])
                attrs = _diff_flags(node.flags, base)
            else:
                attrs = _flag_attrs(node.flags)
            node.flag_attrs = _writable_flags(attrs, schema, report)
            _resolve_style_removal(node, theme_reference, theme_styles_this_class)

    for screen in screens:
        root = screen.root
        root.flag_attrs = _writable_flags(
            _flag_attrs(root.flags, parented=False), schema, report)
        # A screen gets theme styles of its own, and can have them removed.
        _resolve_style_removal(root, theme_reference, False)


def _default_name(display, index, layer):
    """Screens are unnamed unless the app called lv_obj_set_name()."""
    prefix = "screen" if display.get("index", 0) == 0 else f"d{display['index']}_screen"
    return layer if layer and layer != "act_scr" else f"{prefix}_{index}"


def walk(node):
    yield node
    for child in node.children:
        yield from walk(child)
