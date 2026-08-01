/**
 * @file screen_about_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_about_gen.h"
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

lv_obj_t * screen_about_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_about_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x041d3a), 0);
        lv_obj_set_style_text_color(lv_obj_0, lv_color_hex3(0xfff), 0);

        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_0, "About screen (dynamically created)");
        lv_obj_set_align(lv_label_0, LV_ALIGN_TOP_MID);
        lv_obj_set_y(lv_label_0, 10);

        lv_obj_t * lv_slider_0 = lv_slider_create(lv_obj_0);
        lv_obj_set_align(lv_slider_0, LV_ALIGN_CENTER);

        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_1, "I'm NOT on a permanent screen,\n so my state will be lost");
        lv_obj_set_y(lv_label_1, -30);
        lv_obj_set_align(lv_label_1, LV_ALIGN_CENTER);
        lv_obj_set_style_text_align(lv_label_1, LV_TEXT_ALIGN_CENTER, 0);

        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_0);
        lv_obj_set_align(lv_button_0, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_y(lv_button_0, -10);
        lv_obj_t * lv_label_2 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_2, "Back");

        lv_obj_add_screen_load_event(lv_button_0, LV_EVENT_CLICKED, screen_main, LV_SCREEN_LOAD_ANIM_MOVE_BOTTOM, 500, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

