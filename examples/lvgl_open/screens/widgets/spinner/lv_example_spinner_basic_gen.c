/**
 * @file lv_example_spinner_basic_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_spinner_basic_gen.h"
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

lv_obj_t * lv_example_spinner_basic_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_spinner_basic_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * spinner_1 = lv_spinner_create(lv_obj_0);
        lv_obj_set_name(spinner_1, "spinner_1");
        lv_obj_set_width(spinner_1, 80);
        lv_obj_set_height(spinner_1, 80);
        lv_spinner_set_anim_duration(spinner_1, 1500);
        lv_spinner_set_arc_sweep(spinner_1, 270);

        lv_obj_t * spinner_2 = lv_spinner_create(lv_obj_0);
        lv_obj_set_name(spinner_2, "spinner_2");
        lv_obj_set_width(spinner_2, 80);
        lv_obj_set_height(spinner_2, 80);
        lv_spinner_set_anim_duration(spinner_2, 600);
        lv_spinner_set_arc_sweep(spinner_2, 180);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

