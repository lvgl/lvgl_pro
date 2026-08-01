/**
 * @file lv_example_switch_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_switch_styling_gen.h"
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

lv_obj_t * lv_example_switch_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_switch_main;
    static lv_style_t style_switch_indicator_checked;
    static lv_style_t style_switch_knob;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_switch_main);
            lv_style_set_bg_color(&style_switch_main, lv_color_hex(0xc4d8cb));
            lv_style_set_bg_opa(&style_switch_main, (255 * 100 / 100));
            lv_style_set_radius(&style_switch_main, 999);
            lv_style_set_pad_all(&style_switch_main, 6);
            lv_style_set_border_width(&style_switch_main, 0);

            lv_style_init(&style_switch_indicator_checked);
            lv_style_set_bg_color(&style_switch_indicator_checked, lv_color_hex(0x22c55e));
            lv_style_set_bg_opa(&style_switch_indicator_checked, (255 * 100 / 100));

            lv_style_init(&style_switch_knob);
            lv_style_set_bg_color(&style_switch_knob, lv_color_hex(0xffffff));
            lv_style_set_bg_opa(&style_switch_knob, (255 * 100 / 100));
            lv_style_set_pad_all(&style_switch_knob, 2);
            lv_style_set_border_color(&style_switch_knob, lv_color_hex(0xd1d5db));
            lv_style_set_border_width(&style_switch_knob, 1);
            lv_style_set_shadow_color(&style_switch_knob, lv_color_hex(0x000000));
            lv_style_set_shadow_opa(&style_switch_knob, (255 * 40 / 100));
            lv_style_set_shadow_width(&style_switch_knob, 16);
            lv_style_set_shadow_offset_y(&style_switch_knob, 2);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_switch_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * sw_1 = lv_switch_create(lv_obj_0);
        lv_obj_set_name(sw_1, "sw_1");
        lv_obj_set_width(sw_1, 60);
        lv_obj_set_height(sw_1, 30);
        lv_obj_add_style(sw_1, &style_switch_main, LV_PART_MAIN);
        lv_obj_add_style(sw_1, &style_switch_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_add_style(sw_1, &style_switch_knob, LV_PART_KNOB);

        lv_obj_t * sw_2 = lv_switch_create(lv_obj_0);
        lv_obj_set_name(sw_2, "sw_2");
        lv_obj_set_width(sw_2, 60);
        lv_obj_set_height(sw_2, 30);
        lv_obj_set_state(sw_2, LV_STATE_CHECKED, true);
        lv_obj_add_style(sw_2, &style_switch_main, LV_PART_MAIN);
        lv_obj_add_style(sw_2, &style_switch_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_add_style(sw_2, &style_switch_knob, LV_PART_KNOB);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

