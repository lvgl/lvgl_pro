/**
 * @file lv_example_dropdown_direction_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_dropdown_direction_gen.h"
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

lv_obj_t * lv_example_dropdown_direction_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_dropdown_direction_#");

        lv_obj_t * dropdown_1 = lv_dropdown_create(lv_obj_0);
        lv_obj_set_name(dropdown_1, "dropdown_1");
        lv_obj_set_align(dropdown_1, LV_ALIGN_TOP_MID);
        lv_obj_set_y(dropdown_1, 20);
        lv_dropdown_set_options(dropdown_1, "Apple\nBanana\nOrange\nMelon");

        lv_obj_t * dropdown_2 = lv_dropdown_create(lv_obj_0);
        lv_obj_set_name(dropdown_2, "dropdown_2");
        lv_obj_set_align(dropdown_2, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_y(dropdown_2, -20);
        lv_dropdown_set_dir(dropdown_2, LV_DIR_TOP);
        lv_dropdown_set_options(dropdown_2, "Apple\nBanana\nOrange\nMelon");

        lv_obj_t * dropdown_3 = lv_dropdown_create(lv_obj_0);
        lv_obj_set_name(dropdown_3, "dropdown_3");
        lv_obj_set_align(dropdown_3, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(dropdown_3, 20);
        lv_obj_set_width(dropdown_3, 80);
        lv_dropdown_set_dir(dropdown_3, LV_DIR_RIGHT);
        lv_dropdown_set_options(dropdown_3, "Apple\nBanana\nOrange\nMelon");

        lv_obj_t * dropdown_4 = lv_dropdown_create(lv_obj_0);
        lv_obj_set_name(dropdown_4, "dropdown_4");
        lv_obj_set_align(dropdown_4, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(dropdown_4, -20);
        lv_obj_set_width(dropdown_4, 80);
        lv_dropdown_set_dir(dropdown_4, LV_DIR_LEFT);
        lv_dropdown_set_options(dropdown_4, "Apple\nBanana\nOrange\nMelon");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

