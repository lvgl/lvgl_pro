/**
 * @file lv_example_image_transformations_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_image_transformations_gen.h"
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

lv_obj_t * lv_example_image_transformations_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_image_transformations_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * image_1 = lv_image_create(lv_obj_0);
        lv_obj_set_name(image_1, "image_1");
        lv_image_set_src(image_1, img_example_lvgl_logo);

        lv_obj_t * image_2 = lv_image_create(lv_obj_0);
        lv_obj_set_name(image_2, "image_2");
        lv_image_set_src(image_2, img_example_lvgl_logo);
        lv_image_set_rotation(image_2, 450);

        lv_obj_t * image_3 = lv_image_create(lv_obj_0);
        lv_obj_set_name(image_3, "image_3");
        lv_image_set_src(image_3, img_example_lvgl_logo);
        lv_image_set_scale_x(image_3, 160);
        lv_image_set_scale_y(image_3, 160);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

