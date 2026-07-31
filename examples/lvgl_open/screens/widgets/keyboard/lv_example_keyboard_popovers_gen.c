/**
 * @file lv_example_keyboard_popovers_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_keyboard_popovers_gen.h"
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

lv_obj_t * lv_example_keyboard_popovers_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_keyboard_popovers_#");

        lv_obj_t * textarea = lv_textarea_create(lv_obj_0);
        lv_obj_set_name(textarea, "textarea");
        lv_obj_set_align(textarea, LV_ALIGN_TOP_MID);
        lv_obj_set_y(textarea, 10);
        lv_obj_set_width(textarea, lv_pct(90));
        lv_textarea_set_one_line(textarea, true);
        lv_textarea_set_placeholder_text(textarea, "Press and hold a key");

        lv_obj_t * keyboard = lv_keyboard_create(lv_obj_0);
        lv_obj_set_name(keyboard, "keyboard");
        lv_obj_set_align(keyboard, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_width(keyboard, lv_pct(100));
        lv_obj_set_height(keyboard, lv_pct(60));
        lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
        lv_keyboard_set_popovers(keyboard, true);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

