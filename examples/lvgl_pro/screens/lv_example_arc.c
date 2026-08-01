/**
 * @file lv_example_arc.c
 */

#include "../lv_examples.h"

/**
 * @title Arc
 * @brief A bound arc with named styles on its main, indicator and knob parts.
 *
 * The arc uses `bind_value` so dragging it updates `subject_value`, which the
 * centered label reads back live. Named styles target the MAIN ring, the
 * INDICATOR sweep and the KNOB separately via the `selector` attribute.
 */
void lv_example_arc(void)
{
    static lv_style_t style_arc_main;
    static lv_style_t style_arc_ind;
    static lv_style_t style_arc_knob;

    static lv_subject_t subject_value;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_arc_main);
        lv_style_set_arc_color(&style_arc_main, lv_color_hex(0x334155));
        lv_style_set_arc_width(&style_arc_main, 10);

        lv_style_init(&style_arc_ind);
        lv_style_set_arc_color(&style_arc_ind, lv_color_hex(0x3b82f6));
        lv_style_set_arc_width(&style_arc_ind, 10);

        lv_style_init(&style_arc_knob);
        lv_style_set_bg_color(&style_arc_knob, lv_color_hex(0x3b82f6));
        lv_style_set_pad_all(&style_arc_knob, 6);
        lv_style_set_border_width(&style_arc_knob, 2);
        lv_style_set_border_color(&style_arc_knob, lv_color_hex3(0xfff));
        lv_style_set_shadow_offset_y(&style_arc_knob, 2);
        lv_style_set_shadow_opa(&style_arc_knob, (255 * 50 / 100));
        lv_style_set_shadow_width(&style_arc_knob, 10);

        lv_subject_init_int(&subject_value, 50);
        lv_subject_set_min_value_int(&subject_value, 0);
        lv_subject_set_max_value_int(&subject_value, 100);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    /* 💡 Drag the arc — the label tracks subject_value live. */
    lv_obj_t * lv_arc_0 = lv_arc_create(screen);
    lv_obj_set_size(lv_arc_0, 120, 120);
    lv_obj_set_align(lv_arc_0, LV_ALIGN_CENTER);
    lv_arc_bind_value(lv_arc_0, &subject_value);
    lv_obj_add_style(lv_arc_0, &style_arc_main, 0);
    lv_obj_add_style(lv_arc_0, &style_arc_ind, LV_PART_INDICATOR);
    lv_obj_add_style(lv_arc_0, &style_arc_knob, LV_PART_KNOB);
    lv_obj_t * lv_label_0 = lv_label_create(lv_arc_0);
    lv_label_bind_text(lv_label_0, &subject_value, "value: %d");
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
}

