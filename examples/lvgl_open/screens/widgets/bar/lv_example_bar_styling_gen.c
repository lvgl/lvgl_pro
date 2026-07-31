/**
 * @file lv_example_bar_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_bar_styling_gen.h"
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

lv_obj_t * lv_example_bar_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bar_track;
    static lv_style_t style_bar_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_bar_track);
            lv_style_set_bg_opa(&style_bar_track, (255 * 100 / 100));
            lv_style_set_bg_color(&style_bar_track, lv_color_hex(0x1f2937));
            lv_style_set_radius(&style_bar_track, 12);
            lv_style_set_border_color(&style_bar_track, lv_color_hex(0x0f172a));
            lv_style_set_border_width(&style_bar_track, 1);

            lv_style_init(&style_bar_indicator);
            lv_style_set_bg_opa(&style_bar_indicator, (255 * 100 / 100));
            lv_style_set_bg_color(&style_bar_indicator, lv_color_hex(0x10b981));
            lv_style_set_bg_grad_color(&style_bar_indicator, lv_color_hex(0x06b6d4));
            lv_style_set_bg_grad_dir(&style_bar_indicator, LV_GRAD_DIR_HOR);
            lv_style_set_radius(&style_bar_indicator, 12);
            lv_style_set_shadow_color(&style_bar_indicator, lv_color_hex(0x064e3b));
            lv_style_set_shadow_width(&style_bar_indicator, 8);
            lv_style_set_shadow_spread(&style_bar_indicator, -2);
            lv_style_set_shadow_opa(&style_bar_indicator, 180);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_bar_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 20, 0);

        lv_obj_t * bar_1 = lv_bar_create(lv_obj_0);
        lv_obj_set_name(bar_1, "bar_1");
        lv_obj_set_width(bar_1, lv_pct(90));
        lv_obj_set_height(bar_1, 22);
        lv_bar_set_min_value(bar_1, 0);
        lv_bar_set_max_value(bar_1, 100);
        lv_bar_set_value(bar_1, 65, false);
        lv_obj_add_style(bar_1, &style_bar_track, LV_PART_MAIN);
        lv_obj_add_style(bar_1, &style_bar_indicator, LV_PART_INDICATOR);

        lv_obj_t * bar_2 = lv_bar_create(lv_obj_0);
        lv_obj_set_name(bar_2, "bar_2");
        lv_obj_set_width(bar_2, lv_pct(90));
        lv_obj_set_height(bar_2, 10);
        lv_bar_set_min_value(bar_2, 0);
        lv_bar_set_max_value(bar_2, 100);
        lv_bar_set_value(bar_2, 35, false);
        lv_obj_set_style_bg_color(bar_2, lv_color_hex(0xe5e7eb), 0);
        lv_obj_set_style_bg_opa(bar_2, (255 * 100 / 100), 0);
        lv_obj_set_style_radius(bar_2, 2, 0);
        lv_obj_set_style_border_color(bar_2, lv_color_hex(0xd1d5db), 0);
        lv_obj_set_style_border_width(bar_2, 1, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

