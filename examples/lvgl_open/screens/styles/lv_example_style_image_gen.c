/**
 * @file lv_example_style_image_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_image_gen.h"
#include "../../lvgl_open_examples.h"

/*********************
 *      DEFINES
 *********************/

#define ACCENT lv_color_hex(0x2196f3)


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

lv_obj_t * lv_example_style_image_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_img;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_img);
            lv_style_set_radius(&style_img, 5);
            lv_style_set_bg_opa(&style_img, (255 * 100 / 100));
            lv_style_set_bg_color(&style_img, lv_color_hex(0xf5f5f5));
            lv_style_set_border_width(&style_img, 2);
            lv_style_set_border_color(&style_img, ACCENT);
            lv_style_set_image_recolor(&style_img, ACCENT);
            lv_style_set_image_recolor_opa(&style_img, (255 * 50 / 100));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_image_#");

        lv_obj_t * image = lv_image_create(lv_obj_0);
        lv_obj_set_name(image, "image");
        lv_image_set_src(image, img_example_lvgl_logo);
        lv_obj_set_align(image, LV_ALIGN_CENTER);
        lv_obj_add_style(image, &style_img, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

