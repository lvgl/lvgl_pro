/**
 * @file lv_example_led_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_led_gen.h"
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

lv_obj_t * lv_example_led_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_led_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_column(lv_obj_0, 32, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * lv_led_0 = lv_led_create(lv_obj_0);
        lv_obj_set_width(lv_led_0, 36);
        lv_obj_set_height(lv_led_0, 36);
        lv_led_set_color(lv_led_0, lv_color_hex(0x22c55e));
        lv_led_set_brightness(lv_led_0, 60);

        lv_obj_t * lv_led_1 = lv_led_create(lv_obj_0);
        lv_obj_set_width(lv_led_1, 36);
        lv_obj_set_height(lv_led_1, 36);
        lv_led_set_color(lv_led_1, lv_color_hex(0x22c55e));
        lv_led_set_brightness(lv_led_1, 180);

        lv_obj_t * lv_led_2 = lv_led_create(lv_obj_0);
        lv_obj_set_width(lv_led_2, 36);
        lv_obj_set_height(lv_led_2, 36);
        lv_led_set_color(lv_led_2, lv_color_hex(0x22c55e));
        lv_led_set_brightness(lv_led_2, 255);

        lv_obj_t * lv_led_3 = lv_led_create(lv_obj_0);
        lv_obj_set_width(lv_led_3, 36);
        lv_obj_set_height(lv_led_3, 36);
        lv_led_set_color(lv_led_3, lv_color_hex(0xef4444));
        lv_led_set_brightness(lv_led_3, 255);

        lv_obj_t * lv_led_4 = lv_led_create(lv_obj_0);
        lv_obj_set_width(lv_led_4, 36);
        lv_obj_set_height(lv_led_4, 36);
        lv_led_set_color(lv_led_4, lv_color_hex(0x3b82f6));
        lv_led_set_brightness(lv_led_4, 200);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

