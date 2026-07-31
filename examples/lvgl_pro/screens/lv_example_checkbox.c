/**
 * @file lv_example_checkbox.c
 */

#include "../lv_examples.h"

/**
 * @title Checkbox
 * @brief A checked and a disabled checkbox, plus a two-way bound pair.
 *
 * Each checkbox gets its caption from the `text` property. The first starts
 * `checked="true"`, the second is `disabled="true"`. The last two share
 * `bind_checked="subject_checked"`, so ticking one ticks the other.
 */
void lv_example_checkbox(void)
{
    static lv_style_t style_tick_checked;

    static lv_subject_t subject_checked;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_tick_checked);
        lv_style_set_bg_color(&style_tick_checked, lv_color_hex(0x16a34a));
        lv_style_set_border_color(&style_tick_checked, lv_color_hex(0x16a34a));

        lv_subject_init_int(&subject_checked, 0);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(screen, 14, 0);
    lv_obj_set_style_pad_all(screen, 18, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    /* Checked by default */
    lv_obj_t * lv_checkbox_0 = lv_checkbox_create(screen);
    lv_checkbox_set_text(lv_checkbox_0, "Enable feature");
    lv_obj_set_state(lv_checkbox_0, LV_STATE_CHECKED, true);
    lv_obj_add_style(lv_checkbox_0, &style_tick_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

    /* Disabled */
    lv_obj_t * lv_checkbox_1 = lv_checkbox_create(screen);
    lv_checkbox_set_text(lv_checkbox_1, "Unavailable option");
    lv_obj_set_state(lv_checkbox_1, LV_STATE_DISABLED, true);

    /* Two checkboxes bound to the same subject */
    lv_obj_t * lv_checkbox_2 = lv_checkbox_create(screen);
    lv_checkbox_set_text(lv_checkbox_2, "Sync A");
    lv_obj_bind_checked(lv_checkbox_2, &subject_checked);
    lv_obj_add_style(lv_checkbox_2, &style_tick_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_t * lv_checkbox_3 = lv_checkbox_create(screen);
    lv_checkbox_set_text(lv_checkbox_3, "Sync B");
    lv_obj_bind_checked(lv_checkbox_3, &subject_checked);
    lv_obj_add_style(lv_checkbox_3, &style_tick_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);
}

