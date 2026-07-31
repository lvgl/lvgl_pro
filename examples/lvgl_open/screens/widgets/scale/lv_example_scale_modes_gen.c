/**
 * @file lv_example_scale_modes_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_scale_modes_gen.h"
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

lv_obj_t * lv_example_scale_modes_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_scale_modes_#");

        lv_obj_t * scale_1 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_1, "scale_1");
        lv_obj_set_width(scale_1, 120);
        lv_obj_set_height(scale_1, 30);
        lv_scale_set_mode(scale_1, LV_SCALE_MODE_HORIZONTAL_TOP);
        lv_scale_set_total_tick_count(scale_1, 11);
        lv_scale_set_major_tick_every(scale_1, 2);
        lv_scale_set_label_show(scale_1, true);
        lv_scale_set_min_value(scale_1, 0);
        lv_scale_set_max_value(scale_1, 100);
        lv_obj_set_align(scale_1, LV_ALIGN_LEFT_MID);
        lv_obj_set_y(scale_1, 20);
        lv_obj_set_x(scale_1, 20);

        lv_obj_t * scale_2 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_2, "scale_2");
        lv_obj_set_width(scale_2, 120);
        lv_obj_set_height(scale_2, 30);
        lv_scale_set_mode(scale_2, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
        lv_scale_set_total_tick_count(scale_2, 11);
        lv_scale_set_major_tick_every(scale_2, 2);
        lv_scale_set_label_show(scale_2, true);
        lv_scale_set_min_value(scale_2, 0);
        lv_scale_set_max_value(scale_2, 100);
        lv_obj_set_align(scale_2, LV_ALIGN_LEFT_MID);
        lv_obj_set_y(scale_2, -20);
        lv_obj_set_x(scale_2, 20);

        lv_obj_t * scale_3 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_3, "scale_3");
        lv_obj_set_width(scale_3, 120);
        lv_obj_set_height(scale_3, 120);
        lv_scale_set_mode(scale_3, LV_SCALE_MODE_ROUND_OUTER);
        lv_scale_set_total_tick_count(scale_3, 11);
        lv_scale_set_major_tick_every(scale_3, 2);
        lv_scale_set_label_show(scale_3, true);
        lv_scale_set_min_value(scale_3, 0);
        lv_scale_set_max_value(scale_3, 100);
        lv_obj_set_align(scale_3, LV_ALIGN_CENTER);

        lv_obj_t * scale_4 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_4, "scale_4");
        lv_obj_set_width(scale_4, 90);
        lv_obj_set_height(scale_4, 90);
        lv_scale_set_mode(scale_4, LV_SCALE_MODE_ROUND_INNER);
        lv_scale_set_total_tick_count(scale_4, 11);
        lv_scale_set_major_tick_every(scale_4, 2);
        lv_scale_set_label_show(scale_4, true);
        lv_scale_set_min_value(scale_4, 0);
        lv_scale_set_max_value(scale_4, 100);
        lv_obj_set_align(scale_4, LV_ALIGN_CENTER);

        lv_obj_t * scale_5 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_5, "scale_5");
        lv_obj_set_width(scale_5, 30);
        lv_obj_set_height(scale_5, 160);
        lv_scale_set_mode(scale_5, LV_SCALE_MODE_VERTICAL_LEFT);
        lv_scale_set_total_tick_count(scale_5, 11);
        lv_scale_set_major_tick_every(scale_5, 2);
        lv_scale_set_label_show(scale_5, true);
        lv_scale_set_min_value(scale_5, 0);
        lv_scale_set_max_value(scale_5, 100);
        lv_obj_set_align(scale_5, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(scale_5, -20);

        lv_obj_t * scale_6 = lv_scale_create(lv_obj_0);
        lv_obj_set_name(scale_6, "scale_6");
        lv_obj_set_width(scale_6, 30);
        lv_obj_set_height(scale_6, 160);
        lv_scale_set_mode(scale_6, LV_SCALE_MODE_VERTICAL_RIGHT);
        lv_scale_set_total_tick_count(scale_6, 11);
        lv_scale_set_major_tick_every(scale_6, 2);
        lv_scale_set_label_show(scale_6, true);
        lv_scale_set_min_value(scale_6, 0);
        lv_scale_set_max_value(scale_6, 100);
        lv_obj_set_align(scale_6, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(scale_6, -60);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

