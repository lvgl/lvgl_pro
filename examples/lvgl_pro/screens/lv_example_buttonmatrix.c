/**
 * @file lv_example_buttonmatrix.c
 */

#include "../lv_examples.h"

/**
 * @title Button matrix
 * @brief A keypad from a single map, with per-button width and a disabled key.
 *
 * `map` lists the button labels; `'\n'` starts a new row. `ctrl_map` gives
 * one control entry per button (in order): here the last row's `0` takes
 * `width_2` to span double, and `Clear` is `disabled`. Buttons are drawn
 * virtually, so the whole pad is one lightweight widget.
 */
void lv_example_buttonmatrix(void)
{
    static lv_style_t style_bm;
    static lv_style_t style_keys;
    static lv_style_t style_keys_pr;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_bm);
        lv_style_set_bg_color(&style_bm, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_bm, (255 * 100 / 100));
        lv_style_set_radius(&style_bm, 8);
        lv_style_set_pad_all(&style_bm, 8);

        lv_style_init(&style_keys);
        lv_style_set_bg_color(&style_keys, lv_color_hex(0x313d51));
        lv_style_set_text_color(&style_keys, lv_color_hex(0xe2e8f0));
        lv_style_set_radius(&style_keys, 6);
        lv_style_set_shadow_width(&style_keys, 4);

        lv_style_init(&style_keys_pr);
        lv_style_set_bg_color(&style_keys_pr, lv_color_hex(0x3b82f6));

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_pad_all(screen, 14, 0);

    lv_obj_t * lv_buttonmatrix_0 = lv_buttonmatrix_create(screen);
    lv_obj_set_size(lv_buttonmatrix_0, 260, 170);
    lv_obj_set_align(lv_buttonmatrix_0, LV_ALIGN_CENTER);
    static const char *lv_buttonmatrix_0_map_0[] = {"7", "8", "9", "\n", "4", "5", "6", "\n", "1", "2", "3", "\n", "0", "Clear", NULL};
    lv_buttonmatrix_set_map(lv_buttonmatrix_0, lv_buttonmatrix_0_map_0);
    static const lv_buttonmatrix_ctrl_t lv_buttonmatrix_0_ctrl_map_1[] = {LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_WIDTH_2, LV_BUTTONMATRIX_CTRL_DISABLED};
    lv_buttonmatrix_set_ctrl_map(lv_buttonmatrix_0, lv_buttonmatrix_0_ctrl_map_1);
    lv_obj_add_style(lv_buttonmatrix_0, &style_bm, 0);
    lv_obj_add_style(lv_buttonmatrix_0, &style_keys, LV_PART_ITEMS);
    lv_obj_add_style(lv_buttonmatrix_0, &style_keys_pr, LV_PART_ITEMS | LV_STATE_PRESSED);
}

