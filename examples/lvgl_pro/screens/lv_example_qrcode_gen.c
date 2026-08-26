/**
 * @file lv_example_qrcode_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_qrcode_gen.h"
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

lv_obj_t * lv_example_qrcode_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_qrcode_#");

        lv_obj_t * lv_qrcode_0 = lv_qrcode_create(lv_obj_0);
        lv_qrcode_set_size(lv_qrcode_0, 120);
        lv_obj_set_align(lv_qrcode_0, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_qrcode_0, -100);
        lv_qrcode_set_dark_color(lv_qrcode_0, lv_color_hex(0x1f2937));
        lv_qrcode_set_light_color(lv_qrcode_0, lv_color_hex(0xffffff));
        lv_qrcode_set_quiet_zone(lv_qrcode_0, true);
        lv_qrcode_set_data(lv_qrcode_0, "https://lvgl.io");

        lv_obj_t * lv_qrcode_1 = lv_qrcode_create(lv_obj_0);
        lv_qrcode_set_size(lv_qrcode_1, 100);
        lv_obj_set_align(lv_qrcode_1, LV_ALIGN_CENTER);
        lv_obj_set_x(lv_qrcode_1, 100);
        lv_qrcode_set_dark_color(lv_qrcode_1, lv_color_hex(0x2563eb));
        lv_qrcode_set_light_color(lv_qrcode_1, lv_color_hex(0xeff6ff));
        lv_qrcode_set_quiet_zone(lv_qrcode_1, true);
        lv_qrcode_set_data(lv_qrcode_1, "https://lvgl.io");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

