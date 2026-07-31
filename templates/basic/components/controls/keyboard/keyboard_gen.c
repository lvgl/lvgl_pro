/**
 * @file keyboard_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "keyboard_gen.h"
#include "../../../lvgl_open_template.h"

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

lv_obj_t * keyboard_create(lv_obj_t * parent, lv_obj_t * textarea, lv_keyboard_mode_t mode)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_kb_key_light;
    static lv_style_t style_kb_key_dark;
    static lv_style_t style_kb_key_accent;
    static lv_style_t style_kb_key_pressed;
    static lv_style_t style_keyboard;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_kb_key_light);
        lv_style_init(&style_kb_key_dark);
        lv_style_init(&style_kb_key_accent);
        lv_style_init(&style_kb_key_pressed);
        lv_style_init(&style_keyboard);

        lv_style_set_bg_color(&style_kb_key_light, COLOR_LIGHT_BG);
        lv_style_set_text_color(&style_kb_key_light, COLOR_LIGHT_TEXT);
        lv_style_set_radius(&style_kb_key_light, RADIUS_DEFAULT);
        lv_style_set_border_width(&style_kb_key_light, 0);
        lv_style_set_bg_color(&style_kb_key_dark, COLOR_DARK_BG);
        lv_style_set_text_color(&style_kb_key_dark, COLOR_DARK_TEXT);
        lv_style_set_radius(&style_kb_key_dark, RADIUS_DEFAULT);
        lv_style_set_border_width(&style_kb_key_dark, 0);
        lv_style_set_bg_color(&style_kb_key_accent, COLOR_ACCENT);
        lv_style_set_text_color(&style_kb_key_accent, COLOR_ACCENT_TEXT);
        lv_style_set_recolor(&style_kb_key_pressed, COLOR_TRACK);
        lv_style_set_recolor_opa(&style_kb_key_pressed, (255 * 40 / 100));
        lv_style_set_pad_gap(&style_keyboard, SPACE_XS);
        lv_style_set_pad_all(&style_keyboard, SPACE_MD);
        lv_style_set_radius(&style_keyboard, 0);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_keyboard_0 = lv_keyboard_create(parent);
        lv_obj_set_name_static(lv_keyboard_0, "keyboard_#");
        lv_keyboard_set_mode(lv_keyboard_0, mode);
        lv_keyboard_set_textarea(lv_keyboard_0, textarea);
        lv_obj_set_width(lv_keyboard_0, lv_pct(100));
        lv_obj_set_height(lv_keyboard_0, lv_pct(50));
        lv_obj_set_align(lv_keyboard_0, LV_ALIGN_BOTTOM_MID);

        lv_obj_add_style(lv_keyboard_0, &style_keyboard, 0);
        lv_obj_add_style(lv_keyboard_0, &style_panel_light, 0);
        lv_obj_bind_style(lv_keyboard_0, &style_panel_dark, 0, &subject_theme_dark, 1);
        lv_obj_add_style(lv_keyboard_0, &style_kb_key_light, LV_PART_ITEMS);
        lv_obj_bind_style(lv_keyboard_0, &style_kb_key_dark, LV_PART_ITEMS, &subject_theme_dark, 1);
        lv_obj_add_style(lv_keyboard_0, &style_kb_key_accent, LV_PART_ITEMS | LV_STATE_CHECKED);
        lv_obj_add_style(lv_keyboard_0, &style_kb_key_pressed, LV_PART_ITEMS | LV_STATE_PRESSED);

        the_root = lv_keyboard_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

