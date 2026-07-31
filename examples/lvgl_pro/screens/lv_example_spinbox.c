/**
 * @file lv_example_spinbox.c
 */

#include "../lv_examples.h"

/**
 * @title Spinbox
 * @brief A fixed-point spinbox and a bound one linked to a slider.
 *
 * The first spinbox sets `digit_count` and `dec_point_pos` for a fixed
 * decimal point, with a `min_value`/`max_value` range, a `step`, and
 * `rollover="true"` so it wraps at the limits. The second uses
 * `bind_value="subject_value"`; a slider bound to the same subject moves it.
 */
void lv_example_spinbox(void)
{
    LV_FONT_DECLARE(font_large);

    static lv_style_t style_sb;

    static lv_subject_t subject_value;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_sb);
        lv_style_set_bg_color(&style_sb, lv_color_hex(0x111827));
        lv_style_set_bg_opa(&style_sb, (255 * 100 / 100));
        lv_style_set_text_color(&style_sb, lv_color_hex(0xf9fafb));
        lv_style_set_radius(&style_sb, 8);
        lv_style_set_pad_all(&style_sb, 10);
        lv_style_set_text_font(&style_sb, &font_large);

        lv_subject_init_int(&subject_value, 50);
        lv_subject_set_min_value_int(&subject_value, 0);
        lv_subject_set_max_value_int(&subject_value, 100);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(screen, 16, 0);
    lv_obj_set_style_pad_all(screen, 16, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    /* Fixed-point: 4 digits, point 2 places from the right */
    lv_obj_t * lv_spinbox_0 = lv_spinbox_create(screen);
    lv_obj_set_width(lv_spinbox_0, 150);
    lv_spinbox_set_digit_count(lv_spinbox_0, 4);
    lv_spinbox_set_dec_point_pos(lv_spinbox_0, 2);
    lv_spinbox_set_min_value(lv_spinbox_0, 0);
    lv_spinbox_set_max_value(lv_spinbox_0, 9999);
    lv_spinbox_set_step(lv_spinbox_0, 25);
    lv_spinbox_set_rollover(lv_spinbox_0, true);
    lv_spinbox_set_value(lv_spinbox_0, 1250);
    lv_obj_add_style(lv_spinbox_0, &style_sb, 0);

    /* Bound to subject_value, driven by the slider below */
    lv_obj_t * lv_spinbox_1 = lv_spinbox_create(screen);
    lv_obj_set_width(lv_spinbox_1, 150);
    lv_spinbox_set_min_value(lv_spinbox_1, 0);
    lv_spinbox_set_max_value(lv_spinbox_1, 100);
    lv_spinbox_bind_value(lv_spinbox_1, &subject_value);
    lv_obj_add_style(lv_spinbox_1, &style_sb, 0);

    lv_obj_t * lv_slider_0 = lv_slider_create(screen);
    lv_obj_set_width(lv_slider_0, 220);
    lv_slider_bind_value(lv_slider_0, &subject_value);
}

