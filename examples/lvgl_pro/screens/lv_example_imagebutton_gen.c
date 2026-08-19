/**
 * @file lv_example_imagebutton_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_imagebutton_gen.h"
#include "../lvgl_pro_examples.h"

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

lv_obj_t * lv_example_imagebutton_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_pressed);

        lv_style_set_transform_width(&style_pressed, 10);
        lv_style_set_image_recolor(&style_pressed, lv_color_hex3(0x000));
        lv_style_set_image_recolor_opa(&style_pressed, (255 * 20 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_imagebutton_#");

        lv_obj_t * lv_imagebutton_0 = lv_imagebutton_create(lv_obj_0);
        lv_obj_set_width(lv_imagebutton_0, 160);
        lv_obj_set_align(lv_imagebutton_0, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_imagebutton_0, &style_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_0 = lv_label_create(lv_imagebutton_0);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_0, "Press");
        lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0xffffff), 0);
        lv_obj_set_y(lv_label_0, -3);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

