/**
 * @file lv_example_led_brightness_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_led_brightness_gen.h"
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

lv_obj_t * lv_example_led_brightness_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_led_brightness_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * led_1 = lv_led_create(lv_obj_0);
        lv_obj_set_name(led_1, "led_1");
        lv_obj_set_width(led_1, 40);
        lv_obj_set_height(led_1, 40);
        lv_led_set_color(led_1, lv_color_hex(0xff8000));
        lv_led_set_brightness(led_1, 60);

        lv_obj_t * led_2 = lv_led_create(lv_obj_0);
        lv_obj_set_name(led_2, "led_2");
        lv_obj_set_width(led_2, 40);
        lv_obj_set_height(led_2, 40);
        lv_led_set_color(led_2, lv_color_hex(0xff8000));
        lv_led_set_brightness(led_2, 150);

        lv_obj_t * led_3 = lv_led_create(lv_obj_0);
        lv_obj_set_name(led_3, "led_3");
        lv_obj_set_width(led_3, 40);
        lv_obj_set_height(led_3, 40);
        lv_led_set_color(led_3, lv_color_hex(0xff8000));
        lv_led_set_brightness(led_3, 255);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

