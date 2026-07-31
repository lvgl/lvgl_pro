/**
 * @file lv_example_checkbox_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_checkbox_styling_gen.h"
#include "../../../lvgl_open_examples.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * lv_example_checkbox_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_cb_indicator;
    static lv_style_t style_cb_indicator_checked;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_cb_indicator);
            lv_style_set_bg_opa(&style_cb_indicator, (255 * 100 / 100));
            lv_style_set_bg_color(&style_cb_indicator, lv_color_hex(0xf9fafb));
            lv_style_set_radius(&style_cb_indicator, 6);
            lv_style_set_border_color(&style_cb_indicator, lv_color_hex(0x9ca3af));
            lv_style_set_border_width(&style_cb_indicator, 2);
            lv_style_set_pad_all(&style_cb_indicator, 4);

            lv_style_init(&style_cb_indicator_checked);
            lv_style_set_bg_color(&style_cb_indicator_checked, lv_color_hex(0x16a34a));
            lv_style_set_border_color(&style_cb_indicator_checked, lv_color_hex(0x14532d));
            lv_style_set_outline_color(&style_cb_indicator_checked, lv_color_hex(0x16a34a));
            lv_style_set_outline_width(&style_cb_indicator_checked, 4);
            lv_style_set_outline_pad(&style_cb_indicator_checked, 2);
            lv_style_set_outline_opa(&style_cb_indicator_checked, 80);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_checkbox_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 14, 0);

        lv_obj_t * checkbox_1 = lv_checkbox_create(lv_obj_0);
        lv_obj_set_name(checkbox_1, "checkbox_1");
        lv_checkbox_set_text(checkbox_1, "Default look");
        lv_obj_set_style_text_color(checkbox_1, lv_color_hex(0x111827), 0);
        lv_obj_set_style_pad_column(checkbox_1, 10, 0);
        lv_obj_add_style(checkbox_1, &style_cb_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(checkbox_1, &style_cb_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

        lv_obj_t * checkbox_2 = lv_checkbox_create(lv_obj_0);
        lv_obj_set_name(checkbox_2, "checkbox_2");
        lv_checkbox_set_text(checkbox_2, "Pre-checked");
        lv_obj_set_state(checkbox_2, LV_STATE_CHECKED, true);
        lv_obj_set_style_text_color(checkbox_2, lv_color_hex(0x111827), 0);
        lv_obj_set_style_pad_column(checkbox_2, 10, 0);
        lv_obj_add_style(checkbox_2, &style_cb_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(checkbox_2, &style_cb_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

