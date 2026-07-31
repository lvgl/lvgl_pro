/**
 * @file lv_example_style_blur_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_blur_gen.h"
#include "../../lvgl_open_examples.h"

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

lv_obj_t * lv_example_style_blur_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_glass;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_glass);
            lv_style_set_radius(&style_glass, 40);
            lv_style_set_bg_opa(&style_glass, (255 * 40 / 100));
            lv_style_set_bg_color(&style_glass, lv_color_hex(0xffffff));
            lv_style_set_border_width(&style_glass, 1);
            lv_style_set_border_color(&style_glass, lv_color_hex(0xffffff));
            lv_style_set_border_opa(&style_glass, (255 * 60 / 100));
            lv_style_set_blur_backdrop(&style_glass, true);
            lv_style_set_blur_radius(&style_glass, 18);
            lv_style_set_text_color(&style_glass, lv_color_hex(0xffffff));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_blur_#");
        lv_obj_set_style_bg_opa(lv_obj_0, (255 * 100 / 100), 0);
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x6366f1), 0);
        lv_obj_set_style_bg_grad_color(lv_obj_0, lv_color_hex(0xec4899), 0);
        lv_obj_set_style_bg_grad_dir(lv_obj_0, LV_GRAD_DIR_VER, 0);
        lv_obj_set_style_pad_all(lv_obj_0, 10, 0);

        lv_obj_t * label_1 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_obj_set_width(label_1, lv_pct(100));
        lv_obj_set_style_text_align(label_1, LV_TEXT_ALIGN_CENTER, 0);
        lv_label_set_text(label_1, "Hey there, I'm a little text in the background which is blurred. You might seem that some of parts are sharp, but other under the glass cannot be read. ");

        lv_obj_t * button = lv_button_create(lv_obj_0);
        lv_obj_set_name(button, "button");
        lv_obj_set_align(button, LV_ALIGN_CENTER);
        lv_obj_set_style_pad_all(button, 16, 0);
        lv_obj_set_y(button, 55);
        lv_obj_t * label_2 = lv_label_create(button);
        lv_obj_set_name(label_2, "label_2");
        lv_label_set_text(label_2, "Click me");

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_width(container, 210);
        lv_obj_set_height(container, 110);
        lv_obj_set_align(container, LV_ALIGN_CENTER);
        lv_obj_add_style(container, &style_glass, 0);
        lv_obj_t * label_3 = lv_label_create(container);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "Frosted glass");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

