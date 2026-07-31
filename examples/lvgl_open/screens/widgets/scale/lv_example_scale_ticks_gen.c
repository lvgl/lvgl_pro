/**
 * @file lv_example_scale_ticks_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_scale_ticks_gen.h"
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

lv_obj_t * lv_example_scale_ticks_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_major;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_major);
            lv_style_set_length(&style_major, 8);
            lv_style_set_line_width(&style_major, 3);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_scale_ticks_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 20, 0);

        lv_obj_t * scale_1 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_1, "scale_1");
        lv_obj_set_width(scale_1, 260);
        lv_obj_set_height(scale_1, 30);
        lv_scale_set_mode(scale_1, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
        lv_scale_set_total_tick_count(scale_1, 5);
        lv_scale_set_major_tick_every(scale_1, 2);
        lv_scale_set_label_show(scale_1, true);
        lv_scale_set_min_value(scale_1, 0);
        lv_scale_set_max_value(scale_1, 100);
        lv_obj_add_style(scale_1, &style_major, LV_PART_INDICATOR);

        lv_obj_t * scale_2 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_2, "scale_2");
        lv_obj_set_width(scale_2, 260);
        lv_obj_set_height(scale_2, 30);
        lv_scale_set_mode(scale_2, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
        lv_scale_set_total_tick_count(scale_2, 11);
        lv_scale_set_major_tick_every(scale_2, 5);
        lv_scale_set_label_show(scale_2, true);
        lv_scale_set_min_value(scale_2, 0);
        lv_scale_set_max_value(scale_2, 100);
        lv_obj_add_style(scale_2, &style_major, LV_PART_INDICATOR);

        lv_obj_t * scale_3 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_3, "scale_3");
        lv_obj_set_width(scale_3, 260);
        lv_obj_set_height(scale_3, 30);
        lv_scale_set_mode(scale_3, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
        lv_scale_set_total_tick_count(scale_3, 21);
        lv_scale_set_major_tick_every(scale_3, 4);
        lv_scale_set_label_show(scale_3, true);
        lv_scale_set_min_value(scale_3, 0);
        lv_scale_set_max_value(scale_3, 100);
        lv_obj_add_style(scale_3, &style_major, LV_PART_INDICATOR);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

