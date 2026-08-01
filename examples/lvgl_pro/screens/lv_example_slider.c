/**
 * @file lv_example_slider.c
 */

#include "../lv_examples.h"

#define THICKNESS 16

/**
 * @title Slider
 * @brief Bound, range, reversed-with-gradient and vertical sliders.
 *
 * Like a bar but draggable via its knob. The first slider is bound to
 * `subject_value` and overlays a live readout. The second uses `mode="range"`
 * with a `start_value` and `value` to show a span. The third sets `min_value`
 * above `max_value` so it fills right-to-left, with a gradient indicator. The
 * last two are vertical, the second of them also reversed.
 */
void lv_example_slider(void)
{
    static lv_style_t style_bar;
    static lv_style_t style_bar_ind;
    static lv_style_t style_bar_knob;

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

        lv_style_init(&style_bar_ind);
        lv_style_set_bg_color(&style_bar_ind, lv_color_hex(0x3b82f6));
        lv_style_set_radius(&style_bar_ind, 6);

        lv_style_init(&style_bar_knob);
        lv_style_set_bg_color(&style_bar_knob, lv_color_hex(0x3b82f6));
        lv_style_set_radius(&style_bar_knob, 100);
        lv_style_set_pad_all(&style_bar_knob, 8);
        lv_style_set_border_color(&style_bar_knob, lv_color_hex3(0xfff));
        lv_style_set_border_width(&style_bar_knob, 2);
        lv_style_set_shadow_width(&style_bar_knob, 8);
        lv_style_set_shadow_offset_y(&style_bar_knob, 4);
        lv_style_set_shadow_opa(&style_bar_knob, (255 * 30 / 100));

        lv_subject_init_int(&subject_value, 50);
        lv_subject_set_min_value_int(&subject_value, 0);
        lv_subject_set_max_value_int(&subject_value, 100);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    /* Bound, normal mode, with an overlaid readout */
    lv_obj_t * lv_label_0 = lv_label_create(screen);
    lv_obj_set_align(lv_label_0, LV_ALIGN_LEFT_MID);
    lv_obj_set_y(lv_label_0, -65);
    lv_obj_set_x(lv_label_0, 20);
    lv_label_bind_text(lv_label_0, &subject_value, "%d %%");
    lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0x192e4f), 0);

    lv_obj_t * lv_slider_0 = lv_slider_create(screen);
    lv_obj_set_size(lv_slider_0, 240, THICKNESS);
    lv_slider_bind_value(lv_slider_0, &subject_value);
    lv_obj_set_align(lv_slider_0, LV_ALIGN_LEFT_MID);
    lv_obj_set_y(lv_slider_0, -40);
    lv_obj_set_x(lv_slider_0, 20);
    lv_obj_set_ext_click_area(lv_slider_0, 8);
    lv_obj_add_style(lv_slider_0, &style_bar, 0);
    lv_obj_add_style(lv_slider_0, &style_bar_ind, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_0, &style_bar_knob, LV_PART_KNOB);

    /* Range: indicator spans start_value..value */
    lv_obj_t * lv_slider_1 = lv_slider_create(screen);
    lv_obj_set_size(lv_slider_1, 240, THICKNESS);
    lv_slider_set_mode(lv_slider_1, LV_SLIDER_MODE_RANGE);
    lv_slider_set_value(lv_slider_1, 80, false);
    lv_slider_set_start_value(lv_slider_1, 10, false);
    lv_obj_set_align(lv_slider_1, LV_ALIGN_LEFT_MID);
    lv_obj_set_x(lv_slider_1, 20);
    lv_obj_set_ext_click_area(lv_slider_1, 8);
    lv_obj_add_style(lv_slider_1, &style_bar, 0);
    lv_obj_add_style(lv_slider_1, &style_bar_ind, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_1, &style_bar_knob, LV_PART_KNOB);

    /* Right to left fill when max_value < min_value with gradient */
    lv_obj_t * lv_slider_2 = lv_slider_create(screen);
    lv_obj_set_size(lv_slider_2, 240, THICKNESS);
    lv_slider_set_min_value(lv_slider_2, 100);
    lv_slider_set_max_value(lv_slider_2, 0);
    lv_slider_set_value(lv_slider_2, 80, false);
    lv_obj_set_align(lv_slider_2, LV_ALIGN_LEFT_MID);
    lv_obj_set_pos(lv_slider_2, 20, 40);
    lv_obj_set_ext_click_area(lv_slider_2, 8);
    lv_obj_set_style_bg_color(lv_slider_2, lv_color_hex3(0x04f), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_color(lv_slider_2, lv_color_hex3(0xa8f), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_dir(lv_slider_2, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_2, &style_bar, 0);
    lv_obj_add_style(lv_slider_2, &style_bar_ind, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_2, &style_bar_knob, LV_PART_KNOB);

    /* Vertical orientation */
    lv_obj_t * lv_slider_3 = lv_slider_create(screen);
    lv_obj_set_size(lv_slider_3, THICKNESS, 160);
    lv_slider_set_orientation(lv_slider_3, LV_SLIDER_ORIENTATION_VERTICAL);
    lv_slider_set_value(lv_slider_3, 65, false);
    lv_obj_set_align(lv_slider_3, LV_ALIGN_RIGHT_MID);
    lv_obj_set_y(lv_slider_3, 0);
    lv_obj_set_x(lv_slider_3, -60);
    lv_obj_set_ext_click_area(lv_slider_3, 8);
    lv_obj_add_style(lv_slider_3, &style_bar, 0);
    lv_obj_add_style(lv_slider_3, &style_bar_ind, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_3, &style_bar_knob, LV_PART_KNOB);

    lv_obj_t * lv_slider_4 = lv_slider_create(screen);
    lv_obj_set_size(lv_slider_4, THICKNESS, 160);
    lv_slider_set_orientation(lv_slider_4, LV_SLIDER_ORIENTATION_VERTICAL);
    lv_slider_set_min_value(lv_slider_4, 100);
    lv_slider_set_max_value(lv_slider_4, 0);
    lv_slider_set_value(lv_slider_4, 65, false);
    lv_obj_set_align(lv_slider_4, LV_ALIGN_RIGHT_MID);
    lv_obj_set_y(lv_slider_4, 0);
    lv_obj_set_x(lv_slider_4, -20);
    lv_obj_set_ext_click_area(lv_slider_4, 8);
    lv_obj_add_style(lv_slider_4, &style_bar, 0);
    lv_obj_add_style(lv_slider_4, &style_bar_ind, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_4, &style_bar_knob, LV_PART_KNOB);
}

