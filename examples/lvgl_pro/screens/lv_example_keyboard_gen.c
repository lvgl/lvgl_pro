/**
 * @file lv_example_keyboard_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_keyboard_gen.h"
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

lv_obj_t * lv_example_keyboard_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bg;
    static lv_style_t style_btn_normal;
    static lv_style_t style_btn_checked;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_bg);
        lv_style_init(&style_btn_normal);
        lv_style_init(&style_btn_checked);

        lv_style_set_bg_color(&style_bg, lv_color_hex(0x111827));
        lv_style_set_text_color(&style_bg, lv_color_hex(0xf3f4f6));
        lv_style_set_radius(&style_bg, 8);
        lv_style_set_pad_all(&style_bg, 8);
        lv_style_set_border_color(&style_bg, lv_color_hex(0x3b82f6));
        lv_style_set_border_width(&style_bg, 1);
        lv_style_set_bg_color(&style_btn_normal, lv_color_hex(0x515e7b));
        lv_style_set_text_color(&style_btn_normal, lv_color_hex(0xf3f4f6));
        lv_style_set_radius(&style_btn_normal, 6);
        lv_style_set_bg_color(&style_btn_checked, lv_color_hex(0x3b82f6));
        lv_style_set_text_color(&style_btn_checked, lv_color_hex(0xf3f4f6));
        lv_style_set_radius(&style_btn_checked, 6);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_keyboard_#");

        lv_obj_t * ta_input = lv_textarea_create(lv_obj_0);
        lv_obj_set_name(ta_input, "ta_input");
        lv_obj_set_width(ta_input, 300);
        lv_textarea_set_one_line(ta_input, true);
        lv_textarea_set_placeholder_text(ta_input, "Tap the keyboard ...");
        lv_obj_set_align(ta_input, LV_ALIGN_TOP_MID);
        lv_obj_set_y(ta_input, 30);
        lv_obj_add_style(ta_input, &style_bg, 0);

        lv_obj_t * lv_keyboard_0 = lv_keyboard_create(lv_obj_0);
        lv_obj_set_width(lv_keyboard_0, 320);
        lv_obj_set_height(lv_keyboard_0, 160);
        lv_keyboard_set_mode(lv_keyboard_0, LV_KEYBOARD_MODE_TEXT_LOWER);
        lv_keyboard_set_popovers(lv_keyboard_0, true);
        lv_keyboard_set_textarea(lv_keyboard_0, ta_input);
        lv_obj_set_align(lv_keyboard_0, LV_ALIGN_BOTTOM_MID);
        lv_obj_add_style(lv_keyboard_0, &style_bg, 0);
        lv_obj_add_style(lv_keyboard_0, &style_btn_normal, LV_PART_ITEMS);
        lv_obj_add_style(lv_keyboard_0, &style_btn_checked, LV_PART_ITEMS | LV_STATE_CHECKED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

