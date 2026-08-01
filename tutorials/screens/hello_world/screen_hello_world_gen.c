/**
 * @file screen_hello_world_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_hello_world_gen.h"
#include "../../tutorials.h"

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

lv_obj_t * screen_hello_world_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;

    static bool style_inited = false;

    if (!style_inited) {
        #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
        if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
            lv_style_init(&style_main);
            lv_style_set_bg_color(&style_main, lv_color_hex(0x00688a));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_hello_world_#");

        lv_obj_add_style(lv_obj_0, &style_main, 0);
        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_0);
        lv_obj_set_align(lv_button_0, LV_ALIGN_CENTER);
        lv_obj_set_style_bg_color(lv_button_0, lv_color_hex3(0x111), 0);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "Hello world");
        lv_obj_set_style_text_font(lv_label_0, montserrat_16_bin_file, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

