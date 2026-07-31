/**
 * @file lv_example_led_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_led_styling_gen.h"
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

lv_obj_t * lv_example_led_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_led_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * led_1 = lv_led_create(lv_obj_0);
        lv_obj_set_name(led_1, "led_1");
        lv_obj_set_width(led_1, 50);
        lv_obj_set_height(led_1, 50);
        lv_led_set_color(led_1, lv_color_hex(0x22c55e));
        lv_obj_set_style_border_color(led_1, lv_color_hex(0x14532d), 0);
        lv_obj_set_style_border_width(led_1, 2, 0);
        lv_obj_set_style_outline_color(led_1, lv_color_hex(0x22c55e), 0);
        lv_obj_set_style_outline_width(led_1, 6, 0);
        lv_obj_set_style_outline_pad(led_1, 4, 0);
        lv_obj_set_style_outline_opa(led_1, 80, 0);
        lv_obj_set_style_shadow_color(led_1, lv_color_hex(0x22c55e), 0);
        lv_obj_set_style_shadow_width(led_1, 20, 0);
        lv_obj_set_style_shadow_opa(led_1, 200, 0);

        lv_obj_t * led_2 = lv_led_create(lv_obj_0);
        lv_obj_set_name(led_2, "led_2");
        lv_obj_set_width(led_2, 50);
        lv_obj_set_height(led_2, 50);
        lv_led_set_color(led_2, lv_color_hex(0xef4444));
        lv_obj_set_style_radius(led_2, 6, 0);
        lv_obj_set_style_border_color(led_2, lv_color_hex(0x7f1d1d), 0);
        lv_obj_set_style_border_width(led_2, 3, 0);
        lv_obj_set_style_shadow_width(led_2, 0, 0);

        lv_obj_t * led_3 = lv_led_create(lv_obj_0);
        lv_obj_set_name(led_3, "led_3");
        lv_obj_set_width(led_3, 50);
        lv_obj_set_height(led_3, 50);
        lv_led_set_color(led_3, lv_color_hex(0xf59e0b));
        lv_led_set_brightness(led_3, 120);
        lv_obj_set_style_outline_color(led_3, lv_color_hex(0xf59e0b), 0);
        lv_obj_set_style_outline_width(led_3, 3, 0);
        lv_obj_set_style_outline_pad(led_3, 6, 0);
        lv_obj_set_style_outline_opa(led_3, 180, 0);
        lv_obj_set_style_shadow_width(led_3, 0, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

