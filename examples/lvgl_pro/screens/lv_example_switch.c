/**
 * @file lv_example_switch.c
 */

#include "../lv_examples.h"

/**
 * @title Switch
 * @brief A checked and a disabled switch, plus a two-way bound pair.
 *
 * The first switch starts `checked="true"`, the second is `disabled="true"`.
 * The third uses `bind_checked="subject_checked"`; the fourth binds to the
 * same subject, so toggling either one moves both — the classic two-way
 * binding pattern.
 */
void lv_example_switch(void)
{
    static lv_style_t style_sw;
    static lv_style_t style_sw_on;
    static lv_style_t style_knob;

    static lv_subject_t subject_checked;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_sw);
        lv_style_set_bg_color(&style_sw, lv_color_hex(0xcbd5e1));
        lv_style_set_bg_opa(&style_sw, (255 * 100 / 100));

        lv_style_init(&style_sw_on);
        lv_style_set_bg_color(&style_sw_on, lv_color_hex(0x16a34a));

        lv_style_init(&style_knob);
        lv_style_set_bg_color(&style_knob, lv_color_hex(0xffffff));

        lv_subject_init_int(&subject_checked, 0);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(screen, 16, 0);
    lv_obj_set_style_pad_all(screen, 18, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    /* On by default */
    lv_obj_t * lv_switch_0 = lv_switch_create(screen);
    lv_obj_set_state(lv_switch_0, LV_STATE_CHECKED, true);
    lv_obj_add_style(lv_switch_0, &style_sw, 0);
    lv_obj_add_style(lv_switch_0, &style_sw_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_add_style(lv_switch_0, &style_knob, LV_PART_KNOB);

    /* Disabled */
    lv_obj_t * lv_switch_1 = lv_switch_create(screen);
    lv_obj_set_state(lv_switch_1, LV_STATE_DISABLED, true);
    lv_obj_set_style_bg_opa(lv_switch_1, (255 * 40 / 100), 0);
    lv_obj_add_style(lv_switch_1, &style_sw, 0);
    lv_obj_add_style(lv_switch_1, &style_knob, LV_PART_KNOB);

    /* Two switches bound to the same subject */
    lv_obj_t * lv_switch_2 = lv_switch_create(screen);
    lv_obj_bind_checked(lv_switch_2, &subject_checked);
    lv_obj_add_style(lv_switch_2, &style_sw, 0);
    lv_obj_add_style(lv_switch_2, &style_sw_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_add_style(lv_switch_2, &style_knob, LV_PART_KNOB);

    lv_obj_t * lv_switch_3 = lv_switch_create(screen);
    lv_obj_bind_checked(lv_switch_3, &subject_checked);
    lv_obj_add_style(lv_switch_3, &style_sw, 0);
    lv_obj_add_style(lv_switch_3, &style_sw_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_add_style(lv_switch_3, &style_knob, LV_PART_KNOB);
}

