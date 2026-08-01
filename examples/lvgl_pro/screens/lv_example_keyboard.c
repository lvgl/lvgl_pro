/**
 * @file lv_example_keyboard.c
 */

#include "../lv_examples.h"

/**
 * @title Keyboard
 * @brief A keyboard paired with a text area, with key popovers enabled.
 *
 * Keyboard and Text Area share the screen; LVGL's default focus group
 * routes key presses to the focused input, so typing lands in the field
 * above. `mode` selects the starting layout and `popovers="true"` shows the
 * enlarged key preview while a key is pressed.
 */
void lv_example_keyboard(void)
{
    static lv_style_t style_bg;
    static lv_style_t style_btn_normal;
    static lv_style_t style_btn_checked;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_bg);
        lv_style_set_bg_color(&style_bg, lv_color_hex(0x111827));
        lv_style_set_text_color(&style_bg, lv_color_hex(0xf3f4f6));
        lv_style_set_radius(&style_bg, 8);
        lv_style_set_pad_all(&style_bg, 8);
        lv_style_set_border_color(&style_bg, lv_color_hex(0x3b82f6));
        lv_style_set_border_width(&style_bg, 1);

        lv_style_init(&style_btn_normal);
        lv_style_set_bg_color(&style_btn_normal, lv_color_hex(0x515e7b));
        lv_style_set_text_color(&style_btn_normal, lv_color_hex(0xf3f4f6));
        lv_style_set_radius(&style_btn_normal, 6);

        lv_style_init(&style_btn_checked);
        lv_style_set_bg_color(&style_btn_checked, lv_color_hex(0x3b82f6));
        lv_style_set_text_color(&style_btn_checked, lv_color_hex(0xf3f4f6));
        lv_style_set_radius(&style_btn_checked, 6);

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    /* 💡 Tap keys — they type into the field above and show a popover preview. */
    lv_obj_t * ta_input = lv_textarea_create(screen);
    lv_obj_set_width(ta_input, 300);
    lv_textarea_set_one_line(ta_input, true);
    lv_textarea_set_placeholder_text(ta_input, "Tap the keyboard ...");
    lv_obj_set_align(ta_input, LV_ALIGN_TOP_MID);
    lv_obj_set_y(ta_input, 30);
    lv_obj_add_style(ta_input, &style_bg, 0);

    lv_obj_t * lv_keyboard_0 = lv_keyboard_create(screen);
    lv_obj_set_size(lv_keyboard_0, 320, 160);
    lv_keyboard_set_mode(lv_keyboard_0, LV_KEYBOARD_MODE_TEXT_LOWER);
    lv_keyboard_set_popovers(lv_keyboard_0, true);
    lv_keyboard_set_textarea(lv_keyboard_0, ta_input);
    lv_obj_set_align(lv_keyboard_0, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_style(lv_keyboard_0, &style_bg, 0);
    lv_obj_add_style(lv_keyboard_0, &style_btn_normal, LV_PART_ITEMS);
    lv_obj_add_style(lv_keyboard_0, &style_btn_checked, LV_PART_ITEMS | LV_STATE_CHECKED);
}

