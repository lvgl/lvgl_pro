/**
 * @file lv_example_roller_visible_rows_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_roller_visible_rows_gen.h"
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

lv_obj_t * lv_example_roller_visible_rows_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_roller_visible_rows_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * roller_1 = lv_roller_create(lv_obj_0);
        lv_obj_set_name(roller_1, "roller_1");
        lv_obj_set_width(roller_1, 120);
        lv_roller_set_visible_row_count(roller_1, 3);
        lv_roller_set_options(roller_1, "Jan\nFeb\nMar\nApr\nMay\nJun\nJul", LV_ROLLER_MODE_NORMAL);
        lv_roller_set_selected(roller_1, 0, false);

        lv_obj_t * roller_2 = lv_roller_create(lv_obj_0);
        lv_obj_set_name(roller_2, "roller_2");
        lv_obj_set_width(roller_2, 120);
        lv_roller_set_visible_row_count(roller_2, 5);
        lv_roller_set_options(roller_2, "Jan\nFeb\nMar\nApr\nMay\nJun\nJul", LV_ROLLER_MODE_NORMAL);
        lv_roller_set_selected(roller_2, 3, false);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

