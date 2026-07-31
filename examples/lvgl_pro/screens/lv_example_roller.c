/**
 * @file lv_example_roller.c
 */

#include "../lv_examples.h"

/**
 * @title Roller
 * @brief Infinite scrolling, a visible row count, and subject binding.
 *
 * `options` takes the list plus a mode parameter (`options-mode="infinite"`)
 * so it loops endlessly. `visible_row_count` sets how many rows are shown,
 * and `bind_value="subject_index"` keeps the selection in a subject that the
 * label below mirrors.
 */
void lv_example_roller(void)
{
    static lv_style_t style_roller;
    static lv_style_t style_roller_sel;

    static lv_subject_t subject_index;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_roller);
        lv_style_set_bg_color(&style_roller, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_roller, (255 * 100 / 100));
        lv_style_set_text_color(&style_roller, lv_color_hex(0x94a3b8));
        lv_style_set_radius(&style_roller, 8);
        lv_style_set_pad_all(&style_roller, 6);

        lv_style_init(&style_roller_sel);
        lv_style_set_bg_color(&style_roller_sel, lv_color_hex(0x3b82f6));
        lv_style_set_text_color(&style_roller_sel, lv_color_hex(0xffffff));

        lv_subject_init_int(&subject_index, 0);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    lv_obj_t * lv_roller_0 = lv_roller_create(screen);
    lv_obj_set_align(lv_roller_0, LV_ALIGN_CENTER);
    lv_roller_set_options(lv_roller_0, "January\nFebruary\nMarch\nApril\nMay\nJune\nJuly\nAugust\nSeptember\nOctober\nNovember", LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(lv_roller_0, 3);
    lv_roller_bind_value(lv_roller_0, &subject_index);
    lv_obj_add_style(lv_roller_0, &style_roller, 0);
    lv_obj_add_style(lv_roller_0, &style_roller_sel, LV_PART_SELECTED);

    lv_obj_t * lv_label_0 = lv_label_create(screen);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_obj_set_y(lv_label_0, -70);
    lv_label_bind_text(lv_label_0, &subject_index, "Month index: %d");
}

