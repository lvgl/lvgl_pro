/**
 * @file lv_example_textarea.c
 */

#include "../lv_examples.h"

/**
 * @title Text area
 * @brief A one-line field, a password field, and a multi-line area.
 *
 * The first uses `one_line="true"` with `placeholder_text` shown while
 * empty. The second adds `password_mode="true"` so characters are masked
 * (briefly revealed for `password_show_time` ms). The third is a normal
 * multi-line area with starting `text` that wraps and scrolls.
 */
void lv_example_textarea(void)
{
    static lv_style_t style_ta;
    static lv_style_t style_cursor;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_ta);
        lv_style_set_bg_color(&style_ta, lv_color_hex(0x111827));
        lv_style_set_bg_opa(&style_ta, (255 * 100 / 100));
        lv_style_set_text_color(&style_ta, lv_color_hex(0xf3f4f6));
        lv_style_set_radius(&style_ta, 8);
        lv_style_set_pad_all(&style_ta, 10);
        lv_style_set_border_color(&style_ta, lv_color_hex(0x3b82f6));
        lv_style_set_border_width(&style_ta, 1);

        lv_style_init(&style_cursor);
        lv_style_set_border_color(&style_cursor, lv_color_hex(0xf3f4f6));

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(screen, 12, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    /* 💡 The middle field masks input; the others show plain and wrapped text. */
    lv_obj_t * lv_textarea_0 = lv_textarea_create(screen);
    lv_obj_set_width(lv_textarea_0, 240);
    lv_textarea_set_one_line(lv_textarea_0, true);
    lv_textarea_set_placeholder_text(lv_textarea_0, "Type your name ...");
    lv_obj_add_style(lv_textarea_0, &style_ta, 0);
    lv_obj_add_style(lv_textarea_0, &style_cursor, LV_PART_CURSOR | LV_STATE_FOCUSED);

    lv_obj_t * lv_textarea_1 = lv_textarea_create(screen);
    lv_obj_set_width(lv_textarea_1, 240);
    lv_textarea_set_one_line(lv_textarea_1, true);
    lv_textarea_set_password_mode(lv_textarea_1, true);
    lv_textarea_set_password_show_time(lv_textarea_1, 500);
    lv_textarea_set_text(lv_textarea_1, "secret");
    lv_obj_add_style(lv_textarea_1, &style_ta, 0);
    lv_obj_add_style(lv_textarea_1, &style_cursor, LV_PART_CURSOR | LV_STATE_FOCUSED);

    lv_obj_t * lv_textarea_2 = lv_textarea_create(screen);
    lv_obj_set_size(lv_textarea_2, 240, 64);
    lv_textarea_set_text(lv_textarea_2, "A multi-line text area wraps long lines and scrolls when the content grows.");
    lv_obj_add_style(lv_textarea_2, &style_ta, 0);
    lv_obj_add_style(lv_textarea_2, &style_cursor, LV_PART_CURSOR | LV_STATE_FOCUSED);
}

