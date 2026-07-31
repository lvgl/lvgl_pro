/**
 * @file lv_example_image_inner_align_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_image_inner_align_gen.h"
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

lv_obj_t * lv_example_image_inner_align_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_main);
            lv_style_set_bg_color(&style_main, lv_color_hex(0xd5d5d5));
            lv_style_set_bg_opa(&style_main, (255 * 100 / 100));
            lv_style_set_border_width(&style_main, 2);
            lv_style_set_border_color(&style_main, lv_color_hex(0x9429ff));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_image_inner_align_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_column(lv_obj_0, 16, 0);

        lv_obj_t * image_1 = lv_image_create(lv_obj_0);
        lv_obj_set_name(image_1, "image_1");
        lv_image_set_src(image_1, img_example_lvgl_logo);
        lv_obj_set_width(image_1, 80);
        lv_obj_set_height(image_1, 80);
        lv_image_set_inner_align(image_1, LV_IMAGE_ALIGN_TOP_LEFT);
        lv_obj_add_style(image_1, &style_main, 0);

        lv_obj_t * image_2 = lv_image_create(lv_obj_0);
        lv_obj_set_name(image_2, "image_2");
        lv_image_set_src(image_2, img_example_lvgl_logo);
        lv_obj_set_width(image_2, 80);
        lv_obj_set_height(image_2, 80);
        lv_image_set_inner_align(image_2, LV_IMAGE_ALIGN_CENTER);
        lv_obj_add_style(image_2, &style_main, 0);

        lv_obj_t * image_3 = lv_image_create(lv_obj_0);
        lv_obj_set_name(image_3, "image_3");
        lv_image_set_src(image_3, img_example_lvgl_logo);
        lv_obj_set_width(image_3, 80);
        lv_obj_set_height(image_3, 80);
        lv_image_set_inner_align(image_3, LV_IMAGE_ALIGN_BOTTOM_RIGHT);
        lv_obj_add_style(image_3, &style_main, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

