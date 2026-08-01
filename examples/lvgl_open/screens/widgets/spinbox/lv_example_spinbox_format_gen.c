/**
 * @file lv_example_spinbox_format_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_spinbox_format_gen.h"
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

lv_obj_t * lv_example_spinbox_format_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_spinbox_format_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * spinbox_1 = lv_spinbox_create(lv_obj_0);
        lv_obj_set_name(spinbox_1, "spinbox_1");
        lv_obj_set_width(spinbox_1, 160);
        lv_spinbox_set_digit_count(spinbox_1, 3);
        lv_spinbox_set_value(spinbox_1, 123);
        lv_spinbox_set_dec_point_pos(spinbox_1, 0);
        lv_spinbox_set_step(spinbox_1, 1);

        lv_obj_t * spinbox_2 = lv_spinbox_create(lv_obj_0);
        lv_obj_set_name(spinbox_2, "spinbox_2");
        lv_obj_set_width(spinbox_2, 160);
        lv_spinbox_set_digit_count(spinbox_2, 5);
        lv_spinbox_set_value(spinbox_2, 123);
        lv_spinbox_set_dec_point_pos(spinbox_2, 2);
        lv_spinbox_set_step(spinbox_2, 1);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

