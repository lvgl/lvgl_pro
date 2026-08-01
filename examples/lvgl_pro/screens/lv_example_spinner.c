/**
 * @file lv_example_spinner.c
 */

#include "../lv_examples.h"

/**
 * @title Spinner
 * @brief Two spinners with different speeds, sweeps and arc styling.
 *
 * `anim_duration` is the time for one full turn and `arc_sweep` is the
 * length of the moving arc (180–360 works best). The two spinners use
 * different values and style the MAIN ring and INDICATOR arc independently.
 */
void lv_example_spinner(void)
{
    static lv_style_t style_track;
    static lv_style_t style_ind;
    static lv_style_t style_ind2;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_track);
        lv_style_set_arc_color(&style_track, lv_color_hex(0x334155));
        lv_style_set_arc_width(&style_track, 8);

        lv_style_init(&style_ind);
        lv_style_set_arc_color(&style_ind, lv_color_hex(0x3b82f6));
        lv_style_set_arc_width(&style_ind, 8);

        lv_style_init(&style_ind2);
        lv_style_set_arc_color(&style_ind2, lv_color_hex(0xf59e0b));
        lv_style_set_arc_width(&style_ind2, 12);
        lv_style_set_pad_all(&style_ind2, -2);

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    /* Slow, long sweep */
    lv_obj_t * lv_spinner_0 = lv_spinner_create(screen);
    lv_obj_set_size(lv_spinner_0, 80, 80);
    lv_spinner_set_anim_duration(lv_spinner_0, 2000);
    lv_spinner_set_arc_sweep(lv_spinner_0, 270);
    lv_obj_add_style(lv_spinner_0, &style_track, 0);
    lv_obj_add_style(lv_spinner_0, &style_ind, LV_PART_INDICATOR);

    /* Fast, short sweep */
    lv_obj_t * lv_spinner_1 = lv_spinner_create(screen);
    lv_obj_set_size(lv_spinner_1, 80, 80);
    lv_spinner_set_anim_duration(lv_spinner_1, 700);
    lv_spinner_set_arc_sweep(lv_spinner_1, 220);
    lv_obj_add_style(lv_spinner_1, &style_track, 0);
    lv_obj_add_style(lv_spinner_1, &style_ind2, LV_PART_INDICATOR);
}

