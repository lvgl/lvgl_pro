/**
 * @file lv_example_bar.c
 */

#include "../lv_examples.h"

/**
 * @title Bar
 * @brief Bound, range, reversed-with-gradient and vertical bars.
 *
 * The first bar is bound to `subject_value` and overlays a live readout. The
 * second uses `mode="range"` with a `start_value` and `value` to show a span.
 * The third sets `min_value` above `max_value` so it fills right-to-left, with
 * a gradient indicator. The last two are vertical, the second of them also
 * reversed.
 */
void lv_example_bar(void)
{
    static lv_style_t style_bar;
    static lv_style_t style_bar_ind;

    static lv_subject_t subject_value;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_bar);
        lv_style_set_bg_color(&style_bar, lv_color_hex(0xdee2e7));
        lv_style_set_bg_opa(&style_bar, (255 * 100 / 100));
        lv_style_set_radius(&style_bar, 8);
        lv_style_set_outline_width(&style_bar, 1);
        lv_style_set_outline_color(&style_bar, lv_color_hex(0x3b82f6));
        lv_style_set_outline_opa(&style_bar, (255 * 90 / 100));
        lv_style_set_pad_all(&style_bar, 3);

        lv_style_init(&style_bar_ind);
        lv_style_set_bg_color(&style_bar_ind, lv_color_hex(0x3b82f6));
        lv_style_set_radius(&style_bar_ind, 6);

        lv_subject_init_int(&subject_value, 50);
        lv_subject_set_min_value_int(&subject_value, 0);
        lv_subject_set_max_value_int(&subject_value, 100);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    /* Bound, normal mode, with an overlaid readout */
    lv_obj_t * lv_bar_0 = lv_bar_create(screen);
    lv_obj_set_size(lv_bar_0, 240, 22);
    lv_bar_bind_value(lv_bar_0, &subject_value);
    lv_obj_set_align(lv_bar_0, LV_ALIGN_LEFT_MID);
    lv_obj_set_y(lv_bar_0, -40);
    lv_obj_set_x(lv_bar_0, 20);
    lv_obj_add_style(lv_bar_0, &style_bar, 0);
    lv_obj_add_style(lv_bar_0, &style_bar_ind, LV_PART_INDICATOR);
    lv_obj_t * lv_label_0 = lv_label_create(lv_bar_0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_label_bind_text(lv_label_0, &subject_value, "%d %%");
    lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0x192e4f), 0);

    /* Range: indicator spans start_value..value */
    lv_obj_t * lv_bar_1 = lv_bar_create(screen);
    lv_obj_set_size(lv_bar_1, 240, 20);
    lv_bar_set_mode(lv_bar_1, LV_BAR_MODE_RANGE);
    lv_bar_set_value(lv_bar_1, 80, false);
    lv_bar_set_start_value(lv_bar_1, 10, false);
    lv_obj_set_align(lv_bar_1, LV_ALIGN_LEFT_MID);
    lv_obj_set_x(lv_bar_1, 20);
    lv_obj_add_style(lv_bar_1, &style_bar, 0);
    lv_obj_add_style(lv_bar_1, &style_bar_ind, LV_PART_INDICATOR);

    /* Right to left fill when max_value < min_value with gradient */
    lv_obj_t * lv_bar_2 = lv_bar_create(screen);
    lv_obj_set_size(lv_bar_2, 240, 20);
    lv_bar_set_min_value(lv_bar_2, 100);
    lv_bar_set_max_value(lv_bar_2, 0);
    lv_bar_set_value(lv_bar_2, 80, false);
    lv_obj_set_align(lv_bar_2, LV_ALIGN_LEFT_MID);
    lv_obj_set_pos(lv_bar_2, 20, 40);
    lv_obj_set_style_bg_color(lv_bar_2, lv_color_hex3(0x04f), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_color(lv_bar_2, lv_color_hex3(0xa8f), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_dir(lv_bar_2, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);
    lv_obj_add_style(lv_bar_2, &style_bar, 0);
    lv_obj_add_style(lv_bar_2, &style_bar_ind, LV_PART_INDICATOR);

    /* Vertical orientation */
    lv_obj_t * lv_bar_3 = lv_bar_create(screen);
    lv_obj_set_size(lv_bar_3, 20, 160);
    lv_bar_set_orientation(lv_bar_3, LV_BAR_ORIENTATION_VERTICAL);
    lv_bar_set_value(lv_bar_3, 65, false);
    lv_obj_set_align(lv_bar_3, LV_ALIGN_RIGHT_MID);
    lv_obj_set_y(lv_bar_3, 0);
    lv_obj_set_x(lv_bar_3, -60);
    lv_obj_add_style(lv_bar_3, &style_bar, 0);
    lv_obj_add_style(lv_bar_3, &style_bar_ind, LV_PART_INDICATOR);

    lv_obj_t * lv_bar_4 = lv_bar_create(screen);
    lv_obj_set_size(lv_bar_4, 20, 160);
    lv_bar_set_orientation(lv_bar_4, LV_BAR_ORIENTATION_VERTICAL);
    lv_bar_set_min_value(lv_bar_4, 100);
    lv_bar_set_max_value(lv_bar_4, 0);
    lv_bar_set_value(lv_bar_4, 65, false);
    lv_obj_set_align(lv_bar_4, LV_ALIGN_RIGHT_MID);
    lv_obj_set_y(lv_bar_4, 0);
    lv_obj_set_x(lv_bar_4, -20);
    lv_obj_add_style(lv_bar_4, &style_bar, 0);
    lv_obj_add_style(lv_bar_4, &style_bar_ind, LV_PART_INDICATOR);
}

