/**
 * @file lv_example_image_recolor_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_image_recolor_gen.h"
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

lv_obj_t * lv_example_image_recolor_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_image_recolor_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * image = lv_image_create(lv_obj_0);
        lv_obj_set_name(image, "image");
        lv_image_set_src(image, img_example_lvgl_logo);
        lv_obj_set_style_image_recolor(image, lv_color_hex(0x6366f1), LV_PART_MAIN);
        lv_obj_bind_style_prop(image, LV_STYLE_IMAGE_RECOLOR_OPA, LV_PART_MAIN, &subject_opa);

        lv_obj_t * slider = lv_slider_create(lv_obj_0);
        lv_obj_set_name(slider, "slider");
        lv_obj_set_width(slider, 240);
        lv_slider_set_min_value(slider, 0);
        lv_slider_set_max_value(slider, 255);
        lv_slider_bind_value(slider, &subject_opa);

        lv_obj_t * label = lv_label_create(lv_obj_0);
        lv_obj_set_name(label, "label");
        lv_label_bind_text(label, &subject_opa, "recolor_opa = %d / 255");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

