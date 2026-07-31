/**
 * @file lvgl_open_examples_gen.h
 */

#ifndef LVGL_OPEN_EXAMPLES_GEN_H
#define LVGL_OPEN_EXAMPLES_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#ifdef LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif



/* Prototypes for target functions, needed by responsive const definitions */

void lvgl_open_examples_set_target(uint32_t target);
uint32_t lvgl_open_examples_get_target(void);
bool lvgl_open_examples_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define LVGL_OPEN_EXAMPLES_TARGET_UNDEFINED  (0 << 1)
#define LVGL_OPEN_EXAMPLES_TARGET_LARGE      (1 << 1)
#define LVGL_OPEN_EXAMPLES_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef LVGL_OPEN_EXAMPLES_COMPILE_TARGET
#define LVGL_OPEN_EXAMPLES_COMPILE_TARGET LVGL_OPEN_EXAMPLES_TARGET_ALL
#endif

#define LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(target) (LVGL_OPEN_EXAMPLES_COMPILE_TARGET & (target) ? 1 : 0)

#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/* Targets: large */
extern lv_font_t * font_example_large;


/*----------------
 * Images
 *----------------*/

/* Targets: large */
extern const void * img_example_lvgl_logo;
extern const void * img_arc_bg;
extern const void * img_arc_indicator;
extern const void * img_bar_bg;
extern const void * img_bar_indicator;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_value;
extern lv_subject_t subject_value2;
extern lv_subject_t subject_opa;
extern lv_subject_t subject_index;
extern lv_subject_t subject_flag;
extern lv_subject_t subject_text;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void lvgl_open_examples_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "screens/layouts/flex/lv_example_flex_align_gen.h"
#include "screens/layouts/flex/lv_example_flex_flow_gen.h"
#include "screens/layouts/flex/lv_example_flex_grow_gen.h"
#include "screens/layouts/flex/lv_example_flex_ignore_layout_gen.h"
#include "screens/layouts/flex/lv_example_flex_internal_padding_gen.h"
#include "screens/layouts/flex/lv_example_flex_new_track_gen.h"
#include "screens/layouts/flex/lv_example_flex_rtl_gen.h"
#include "screens/layouts/grid/lv_example_grid_align_gen.h"
#include "screens/layouts/grid/lv_example_grid_cell_span_gen.h"
#include "screens/layouts/grid/lv_example_grid_descriptors_gen.h"
#include "screens/layouts/grid/lv_example_grid_fr_gen.h"
#include "screens/layouts/grid/lv_example_grid_ignore_layout_gen.h"
#include "screens/layouts/grid/lv_example_grid_internal_padding_gen.h"
#include "screens/layouts/grid/lv_example_grid_rtl_gen.h"
#include "screens/layouts/grid/lv_example_grid_subgrid_gen.h"
#include "screens/libs/qrcode/qrcode_basic/lv_example_qrcode_basic_gen.h"
#include "screens/scroll/lv_example_scroll_chain_gen.h"
#include "screens/scroll/lv_example_scroll_floating_gen.h"
#include "screens/scroll/lv_example_scroll_one_gen.h"
#include "screens/scroll/lv_example_scroll_overview_gen.h"
#include "screens/scroll/lv_example_scroll_rtl_gen.h"
#include "screens/scroll/lv_example_scroll_scrollable_gen.h"
#include "screens/scroll/lv_example_scroll_scrollbar_mode_gen.h"
#include "screens/scroll/lv_example_scroll_scrollbar_style_gen.h"
#include "screens/scroll/lv_example_scroll_snap_gen.h"
#include "screens/styles/lv_example_style_arc_gen.h"
#include "screens/styles/lv_example_style_background_gen.h"
#include "screens/styles/lv_example_style_blur_gen.h"
#include "screens/styles/lv_example_style_border_gen.h"
#include "screens/styles/lv_example_style_image_gen.h"
#include "screens/styles/lv_example_style_local_gen.h"
#include "screens/styles/lv_example_style_margin_gen.h"
#include "screens/styles/lv_example_style_multiple_gen.h"
#include "screens/styles/lv_example_style_opacity_transform_gen.h"
#include "screens/styles/lv_example_style_outline_gen.h"
#include "screens/styles/lv_example_style_padding_gen.h"
#include "screens/styles/lv_example_style_parts_states_gen.h"
#include "screens/styles/lv_example_style_shadow_gen.h"
#include "screens/styles/lv_example_style_size_position_gen.h"
#include "screens/styles/lv_example_style_text_gen.h"
#include "screens/widgets/arc/lv_example_arc_bind_value_gen.h"
#include "screens/widgets/arc/lv_example_arc_change_rate_gen.h"
#include "screens/widgets/arc/lv_example_arc_img_indicator_gen.h"
#include "screens/widgets/arc/lv_example_arc_mode_gen.h"
#include "screens/widgets/arc/lv_example_arc_pie_chart_gen.h"
#include "screens/widgets/arc/lv_example_arc_rotation_gen.h"
#include "screens/widgets/arc/lv_example_arc_set_angles_gen.h"
#include "screens/widgets/arc/lv_example_arc_styling_gen.h"
#include "screens/widgets/arc/lv_example_arc_value_range_gen.h"
#include "screens/widgets/bar/lv_example_bar_bind_value_gen.h"
#include "screens/widgets/bar/lv_example_bar_img_indicator_gen.h"
#include "screens/widgets/bar/lv_example_bar_modes_gen.h"
#include "screens/widgets/bar/lv_example_bar_orientation_gen.h"
#include "screens/widgets/bar/lv_example_bar_styling_gen.h"
#include "screens/widgets/bar/lv_example_bar_value_range_gen.h"
#include "screens/widgets/button/lv_example_button_basic_gen.h"
#include "screens/widgets/button/lv_example_button_states_gen.h"
#include "screens/widgets/button/lv_example_button_styling_gen.h"
#include "screens/widgets/buttonmatrix/lv_example_buttonmatrix_button_ctrl_gen.h"
#include "screens/widgets/buttonmatrix/lv_example_buttonmatrix_button_width_gen.h"
#include "screens/widgets/buttonmatrix/lv_example_buttonmatrix_map_gen.h"
#include "screens/widgets/buttonmatrix/lv_example_buttonmatrix_one_checked_gen.h"
#include "screens/widgets/buttonmatrix/lv_example_buttonmatrix_popover_gen.h"
#include "screens/widgets/buttonmatrix/lv_example_buttonmatrix_recolor_gen.h"
#include "screens/widgets/buttonmatrix/lv_example_buttonmatrix_styling_gen.h"
#include "screens/widgets/calendar/lv_example_calendar_basic_gen.h"
#include "screens/widgets/chart/lv_example_chart_cursor_gen.h"
#include "screens/widgets/chart/lv_example_chart_scrollable_gen.h"
#include "screens/widgets/chart/lv_example_chart_series_gen.h"
#include "screens/widgets/chart/lv_example_chart_ticks_labels_gen.h"
#include "screens/widgets/chart/lv_example_chart_types_gen.h"
#include "screens/widgets/checkbox/lv_example_checkbox_bind_checked_gen.h"
#include "screens/widgets/checkbox/lv_example_checkbox_states_gen.h"
#include "screens/widgets/checkbox/lv_example_checkbox_styling_gen.h"
#include "screens/widgets/checkbox/lv_example_checkbox_text_gen.h"
#include "screens/widgets/dropdown/lv_example_dropdown_bind_value_gen.h"
#include "screens/widgets/dropdown/lv_example_dropdown_direction_gen.h"
#include "screens/widgets/dropdown/lv_example_dropdown_styling_gen.h"
#include "screens/widgets/dropdown/lv_example_dropdown_text_gen.h"
#include "screens/widgets/image/lv_example_image_inner_align_gen.h"
#include "screens/widgets/image/lv_example_image_recolor_gen.h"
#include "screens/widgets/image/lv_example_image_src_gen.h"
#include "screens/widgets/image/lv_example_image_transformations_gen.h"
#include "screens/widgets/keyboard/lv_example_keyboard_modes_gen.h"
#include "screens/widgets/keyboard/lv_example_keyboard_popovers_gen.h"
#include "screens/widgets/keyboard/lv_example_keyboard_textarea_gen.h"
#include "screens/widgets/label/lv_example_label_bind_text_gen.h"
#include "screens/widgets/label/lv_example_label_long_mode_gen.h"
#include "screens/widgets/label/lv_example_label_recolor_gen.h"
#include "screens/widgets/label/lv_example_label_set_text_newline_gen.h"
#include "screens/widgets/label/lv_example_label_styling_gen.h"
#include "screens/widgets/label/lv_example_label_text_align_gen.h"
#include "screens/widgets/led/lv_example_led_brightness_gen.h"
#include "screens/widgets/led/lv_example_led_color_gen.h"
#include "screens/widgets/led/lv_example_led_styling_gen.h"
#include "screens/widgets/obj/lv_example_obj_bind_style_gen.h"
#include "screens/widgets/roller/lv_example_roller_bind_value_gen.h"
#include "screens/widgets/roller/lv_example_roller_options_gen.h"
#include "screens/widgets/roller/lv_example_roller_styling_gen.h"
#include "screens/widgets/roller/lv_example_roller_visible_rows_gen.h"
#include "screens/widgets/scale/lv_example_scale_bind_section_gen.h"
#include "screens/widgets/scale/lv_example_scale_modes_gen.h"
#include "screens/widgets/scale/lv_example_scale_range_gen.h"
#include "screens/widgets/scale/lv_example_scale_styling_gen.h"
#include "screens/widgets/scale/lv_example_scale_ticks_gen.h"
#include "screens/widgets/slider/lv_example_slider_bind_state_gen.h"
#include "screens/widgets/slider/lv_example_slider_bind_value_gen.h"
#include "screens/widgets/slider/lv_example_slider_img_indicator_gen.h"
#include "screens/widgets/slider/lv_example_slider_modes_gen.h"
#include "screens/widgets/slider/lv_example_slider_reversed_direction_gen.h"
#include "screens/widgets/slider/lv_example_slider_styling_gen.h"
#include "screens/widgets/slider/lv_example_slider_value_range_orientation_gen.h"
#include "screens/widgets/span/lv_example_span_styling_gen.h"
#include "screens/widgets/spinbox/lv_example_spinbox_bind_value_gen.h"
#include "screens/widgets/spinbox/lv_example_spinbox_format_gen.h"
#include "screens/widgets/spinbox/lv_example_spinbox_rollover_gen.h"
#include "screens/widgets/spinbox/lv_example_spinbox_styling_gen.h"
#include "screens/widgets/spinbox/lv_example_spinbox_value_gen.h"
#include "screens/widgets/spinner/lv_example_spinner_basic_gen.h"
#include "screens/widgets/switch/lv_example_switch_orientation_gen.h"
#include "screens/widgets/switch/lv_example_switch_state_gen.h"
#include "screens/widgets/switch/lv_example_switch_styling_gen.h"
#include "screens/widgets/table/lv_example_table_cells_gen.h"
#include "screens/widgets/table/lv_example_table_merge_cells_gen.h"
#include "screens/widgets/table/lv_example_table_rows_columns_gen.h"
#include "screens/widgets/table/lv_example_table_scroll_gen.h"
#include "screens/widgets/table/lv_example_table_styling_gen.h"
#include "screens/widgets/table/lv_example_table_width_gen.h"
#include "screens/widgets/tabview/lv_example_tabview_active_tab_gen.h"
#include "screens/widgets/tabview/lv_example_tabview_basic_gen.h"
#include "screens/widgets/tabview/lv_example_tabview_tab_bar_position_gen.h"
#include "screens/widgets/tabview/lv_example_tabview_tab_bar_style_gen.h"
#include "screens/widgets/tabview/lv_example_tabview_tab_button_content_gen.h"
#include "screens/widgets/textarea/lv_example_textarea_cursor_gen.h"
#include "screens/widgets/textarea/lv_example_textarea_placeholder_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_OPEN_EXAMPLES_GEN_H*/