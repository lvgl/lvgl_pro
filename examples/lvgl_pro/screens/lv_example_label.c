/**
 * @file lv_example_label.c
 */

#include "../lv_examples.h"

/**
 * @title Label
 * @brief Recoloring, a long-text mode and a value bound to a subject.
 *
 * A plain heading sits on top. Below it, one label uses `recolor="true"` so
 * `#hex text#` spans change colour inline. The next is given a fixed width with
 * `long_mode="scroll_circular"` so the over-long text scrolls continuously. The
 * last uses `bind_text` with a `bind_text-fmt` printf string to track
 * `subject_value` live.
 */
void lv_example_label(void)
{
    static lv_style_t style_box;

    static lv_subject_t subject_value;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_box);
        lv_style_set_bg_color(&style_box, lv_color_hex(0x1f2937));
        lv_style_set_bg_opa(&style_box, (255 * 100 / 100));
        lv_style_set_radius(&style_box, 8);
        lv_style_set_pad_all(&style_box, 10);
        lv_style_set_text_color(&style_box, lv_color_hex(0xe5e7eb));
        lv_style_set_width(&style_box, 260);

        lv_subject_init_int(&subject_value, 50);
        lv_subject_set_min_value_int(&subject_value, 0);
        lv_subject_set_max_value_int(&subject_value, 100);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(screen, 12, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    /* Per-word recoloring */
    lv_obj_t * lv_label_0 = lv_label_create(screen);
    lv_label_set_recolor(lv_label_0, true);
    lv_label_set_text(lv_label_0, "Status: #16a34a OK# / #dc2626 ERROR#");
    lv_obj_add_style(lv_label_0, &style_box, 0);

    /* Fixed width + circular scroll for overflow */
    lv_obj_t * lv_label_1 = lv_label_create(screen);
    lv_obj_set_width(lv_label_1, 200);
    lv_label_set_long_mode(lv_label_1, LV_LABEL_LONG_MODE_SCROLL_CIRCULAR);
    lv_label_set_text(lv_label_1, "This text is too long to fit so it scrolls around.");
    lv_obj_add_style(lv_label_1, &style_box, 0);

    /* Live value bound to a subject */
    lv_obj_t * lv_label_2 = lv_label_create(screen);
    lv_label_bind_text(lv_label_2, &subject_value, "Bound value: %d %%");
    lv_obj_add_style(lv_label_2, &style_box, 0);
}

