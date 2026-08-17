"""What the LVGL runtime calls things, and what LVGL Pro XML calls them.

Every table here is copied from a source of truth in the LVGL repos, named
above the table. When the two disagree, the runtime is right.
"""

# Style properties the XML engine accepts, from lv_xml_style_prop_to_enum()
# in lv_xml/src/lv_xml_base_types.c. The XML name is the lowercased runtime
# name for all 105, so this set doubles as the whitelist: a property missing
# here cannot be expressed in XML and has to be reported instead of guessed.
STYLE_PROPS = frozenset("""
width min_width max_width height min_height max_height length radius
radial_offset align
pad_left pad_right pad_top pad_bottom pad_row pad_column pad_radial
margin_left margin_right margin_top margin_bottom
base_dir clip_corner
bg_opa bg_color bg_grad_dir bg_grad_color bg_main_stop bg_grad_stop bg_grad
bg_image_src bg_image_tiled bg_image_recolor bg_image_recolor_opa
border_color border_width border_opa border_side border_post
outline_color outline_width outline_opa outline_pad
shadow_width shadow_color shadow_offset_x shadow_offset_y shadow_spread
shadow_opa
text_color text_font text_opa text_align text_letter_space text_line_space
text_decor
image_opa image_recolor image_recolor_opa
line_color line_opa line_width line_dash_width line_dash_gap line_rounded
arc_color arc_opa arc_width arc_rounded arc_image_src
opa opa_layered color_filter_opa anim_duration blend_mode
transform_width transform_height translate_x translate_y translate_radial
transform_scale_x transform_scale_y transform_rotation
transform_pivot_x transform_pivot_y transform_skew_x transform_skew_y
bitmap_mask_src rotary_sensitivity recolor recolor_opa
layout flex_flow flex_grow flex_main_place flex_cross_place flex_track_place
grid_column_align grid_row_align
grid_cell_column_pos grid_cell_column_span grid_cell_x_align
grid_cell_row_pos grid_cell_row_span grid_cell_y_align
""".split())

# Set on the widget itself rather than through style_*, from the attribute
# list in lv_xml/src/parsers/lv_xml_obj_parser.c.
DIRECT_PROPS = {"width", "height", "x", "y", "align", "flex_grow"}

# x and y are style properties (LV_STYLE_X / LV_STYLE_Y); the XML attributes
# are wrappers around lv_obj_set_x/y. lv_xml_style_prop_to_enum() does not
# know the names though, so inside a <style> they would not parse and are
# dropped there with a note.
DIRECT_ONLY = {"x", "y"}

# Handled by lv_xml_style.c outside the property table, so they are valid XML
# even though lv_xml_style_prop_to_enum() does not know them.
EXTRA_STYLE_PROPS = {"grid_column_dsc_array", "grid_row_dsc_array"}

# Fallback only; normally taken from each widget's <element> declarations.
PSEUDO_TAGS = frozenset({"lv_tabview-tab", "lv_tabview-tab_bar"})

# Flags lv_obj_constructor() sets on every widget. Anything else starts clear,
# so a set flag outside this list was the app's doing and has to be written.
# The last four are only set when the object has a parent.
FLAGS_DEFAULT_ON = frozenset("""
clickable snappable click_focusable scrollable scroll_elastic scroll_momentum
scroll_with_arrow press_lock scroll_chain_hor scroll_chain_ver gesture_bubble
""".split())

# LV_OBJ_FLAG_FLEX_IN_NEW_TRACK *is* LV_OBJ_FLAG_LAYOUT_1 - the same bit 23 -
# so an app that calls lv_obj_add_flag(o, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK) is
# reported as layout_1, and only the XML spelling means anything here.
FLAG_ALIASES = {"layout_1": "flex_in_new_track"}

# lv_dir_t is a bitmask, so it cannot be indexed like the sequential enums.
# Names from lv_xml_dir_to_enum().
DIR_NAMES = {0: "none", 1: "left", 2: "right", 3: "hor", 4: "top", 8: "bottom",
             12: "ver", 15: "all"}

# Fallback only, for when the schemas cannot be read. Normally the set of
# widgets comes from the schema file names.
WIDGET_TAGS = frozenset("""
lv_obj lv_animimg lv_arc lv_bar lv_button lv_buttonmatrix lv_calendar
lv_canvas lv_chart lv_checkbox lv_dropdown lv_gif lv_image lv_imagebutton
lv_keyboard lv_label lv_led lv_line lv_qrcode lv_roller lv_scale lv_slider
lv_spangroup lv_spinbox lv_spinner lv_switch lv_table lv_tabview lv_textarea
""".split())

# Not part of the authored UI: LVGL creates the dropdown's open list as a
# separate object on the screen, not as a child of the dropdown.
SKIP_CLASSES = frozenset({"lv_dropdown-list", "lv_dropdown_list"})

# LAYOUT holds a registered layout id, not a fixed enum, so the plugin leaves
# it a number. These two are the built-ins, from lv_xml_layout_to_enum().
LAYOUT_NAMES = {1: "flex", 2: "grid"}

# Values LVGL sets itself. Writing them back would bury the handful of
# properties the author actually chose.
WIDGET_DEFAULTS = {
    "lv_image": {"rotation": "0", "scale_x": "256", "scale_y": "256"},
    "lv_label": {"long_mode": "wrap"},
    "lv_chart": {"type": "line"},
}

# Widgets that create child objects of their own. Only these are left
# unwalked, because the subtree is the widget's implementation rather than
# the app's UI: a textarea owns its label, a roller owns its option label.
#
# Every other widget can legitimately be given children - the widgets demo
# puts arcs, an image and labels inside an lv_scale - and skipping them would
# silently drop part of the UI.
SELF_MANAGED = frozenset("""
lv_calendar lv_dropdown lv_menu lv_msgbox lv_roller lv_spinbox lv_textarea
lv_tileview lv_win
""".split())

# The schema says which properties a widget has and what type each one is.
# All that is needed here is the runtime struct field behind a property when
# the two are not spelled the same. Anything absent is looked up by its own
# name, which is why lv_keyboard needs no entry at all: its `mode` and
# `popovers` fields are already called that.
RENAMES = {
    "lv_checkbox": {"text": "txt"},
    # A dotted name reaches into a struct the runtime reports as one value:
    # lv_image keeps a single `pivot` point, XML has pivot_x and pivot_y.
    "lv_image": {
        "inner_align": "align",
        "pivot_x": "pivot.x",
        "pivot_y": "pivot.y",
    },
    "lv_slider": {"value": "cur_value"},
    "lv_bar": {"value": "cur_value"},
    "lv_dropdown": {"selected": "sel_opt_id"},
    "lv_roller": {"selected": "sel_opt_id"},
    "lv_textarea": {"placeholder_text": "placeholder_txt"},
    "lv_spinbox": {"min_value": "range_min", "max_value": "range_max"},
    "lv_led": {"brightness": "bright"},
    "lv_tabview": {"active": "tab_cur", "tab_bar_position": "tab_pos"},
    "lv_arc": {
        "start_angle": "indic_angle_start",
        "end_angle": "indic_angle_end",
        "bg_start_angle": "bg_angle_start",
        "bg_end_angle": "bg_angle_end",
        "change_rate": "chg_rate",
        "mode": "type",
    },
    "lv_scale": {
        "min_value": "range_min",
        "max_value": "range_max",
        "label_show": "label_enabled",
        "text_src": "txt_src",
    },
    "lv_chart": {
        "point_count": "point_cnt",
        "hor_div_line_count": "hdiv_cnt",
        "ver_div_line_count": "vdiv_cnt",
    },
}

# Properties that exist in the schema but describe something the dump cannot
# supply: a binding to a subject, a reference to another widget, a style name.
UNCONVERTIBLE_TYPES = ("subject", "style", "lv_obj", "image_set")

# Geometry and flags reach XML through other paths: style slots and the flag
# diff. Reading them from widget_data as well would double them up.
NOT_FROM_WIDGET_DATA = frozenset(
    {"name", "x", "y", "width", "height", "align", "flex_grow", "flex_flow",
     "ext_click_area", "scroll_snap_x", "scroll_snap_y", "scrollbar_mode",
     "radio_button"}
)


# Style slot flags from _lv_obj_style_t. Only "local" and the unflagged
# shared slots describe the app; the rest belong to the theme or to a
# running transition.
DROPPED_SLOT_FLAGS = ("theme", "trans", "disabled")


def style_prop_to_xml(runtime_name: str) -> "str | None":
    """Map a runtime style property name to its XML name, or None if unsupported."""
    xml_name = runtime_name.lower()
    if xml_name in STYLE_PROPS or xml_name in EXTRA_STYLE_PROPS:
        return xml_name
    return xml_name if xml_name in DIRECT_ONLY else None


def selector_to_xml(selector_str: str) -> str:
    """Turn the plugin's "PART|STATE" into an XML selector, "" for main+default."""
    part, _, state = selector_str.partition("|")
    parts = []
    if part and part.lower() != "main":
        parts.append(part.lower())
    for one in state.split("|"):
        if one and one.lower() not in ("default", "any"):
            parts.append(one.lower())
    return "|".join(parts)
