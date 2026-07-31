/**
 * @file lv_example_button.c
 */

#include "../lv_examples.h"

/**
 * @title Button
 * @brief A normal, a toggleable and a disabled button with per-state styling.
 *
 * Button itself adds no properties over the Base Widget — its behaviour comes
 * from flags and styling. The middle button uses `checked="true"` so it stays
 * toggled, and a `selector="checked"` style recolours it. The third uses
 * `disabled="true"` to show the muted, non-interactive state.
 */
void lv_example_button(void)
{
    static lv_style_t style_btn;
    static lv_style_t style_btn_pressed;
    static lv_style_t style_btn_checked;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_btn);
        lv_style_set_bg_color(&style_btn, lv_color_hex(0x3b82f6));
        lv_style_set_bg_opa(&style_btn, (255 * 100 / 100));
        lv_style_set_radius(&style_btn, 8);
        lv_style_set_pad_hor(&style_btn, 18);
        lv_style_set_pad_ver(&style_btn, 10);
        lv_style_set_text_color(&style_btn, lv_color_hex(0xffffff));

        lv_style_init(&style_btn_pressed);
        lv_style_set_bg_color(&style_btn_pressed, lv_color_hex(0x1d4ed8));

        lv_style_init(&style_btn_checked);
        lv_style_set_bg_color(&style_btn_checked, lv_color_hex(0x16a34a));

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(screen, 14, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    /* Plain action button */
    lv_obj_t * lv_button_0 = lv_button_create(screen);
    lv_obj_add_style(lv_button_0, &style_btn, 0);
    lv_obj_add_style(lv_button_0, &style_btn_pressed, LV_STATE_PRESSED);
    lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
    lv_label_set_text(lv_label_0, "Action");

    /* Toggle button: starts checked, keeps its state */
    lv_obj_t * lv_button_1 = lv_button_create(screen);
    lv_obj_set_state(lv_button_1, LV_STATE_CHECKED, true);
    lv_obj_add_style(lv_button_1, &style_btn, 0);
    lv_obj_add_style(lv_button_1, &style_btn_pressed, LV_STATE_PRESSED);
    lv_obj_add_style(lv_button_1, &style_btn_checked, LV_STATE_CHECKED);
    lv_obj_t * lv_label_1 = lv_label_create(lv_button_1);
    lv_label_set_text(lv_label_1, "Toggle");

    /* Disabled button: not clickable, dimmed */
    lv_obj_t * lv_button_2 = lv_button_create(screen);
    lv_obj_set_state(lv_button_2, LV_STATE_DISABLED, true);
    lv_obj_set_style_bg_opa(lv_button_2, (255 * 40 / 100), 0);
    lv_obj_add_style(lv_button_2, &style_btn, 0);
    lv_obj_t * lv_label_2 = lv_label_create(lv_button_2);
    lv_label_set_text(lv_label_2, "Disabled");
}

