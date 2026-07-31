/**
 * @file lv_example_scale_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_scale_styling_gen.h"
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

lv_obj_t * lv_example_scale_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_scale_main;
    static lv_style_t style_scale_items;
    static lv_style_t style_scale_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_scale_main);
            lv_style_set_line_color(&style_scale_main, lv_color_hex(0x6b7280));
            lv_style_set_line_width(&style_scale_main, 2);

            lv_style_init(&style_scale_items);
            lv_style_set_line_color(&style_scale_items, lv_color_hex(0x9ca3af));
            lv_style_set_line_width(&style_scale_items, 1);

            lv_style_init(&style_scale_indicator);
            lv_style_set_line_color(&style_scale_indicator, lv_color_hex(0x6366f1));
            lv_style_set_line_width(&style_scale_indicator, 3);
            lv_style_set_text_color(&style_scale_indicator, lv_color_hex(0x6366f1));
            lv_style_set_transform_rotation(&style_scale_indicator, 300);
            lv_style_set_pad_bottom(&style_scale_indicator, 8);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_scale_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * scale = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale, "scale");
        lv_obj_set_width(scale, 280);
        lv_obj_set_height(scale, 80);
        lv_scale_set_mode(scale, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
        lv_scale_set_total_tick_count(scale, 21);
        lv_scale_set_major_tick_every(scale, 4);
        lv_scale_set_label_show(scale, true);
        lv_scale_set_min_value(scale, 0);
        lv_scale_set_max_value(scale, 100);
        lv_obj_add_style(scale, &style_scale_main, LV_PART_MAIN);
        lv_obj_add_style(scale, &style_scale_items, LV_PART_ITEMS);
        lv_obj_add_style(scale, &style_scale_indicator, LV_PART_INDICATOR);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

