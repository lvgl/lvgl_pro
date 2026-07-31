/**
 * @file lv_example_calendar.c
 */

#include "../lv_examples.h"

/**
 * @title Calendar
 * @brief A month view with today highlighted and a dropdown month picker.
 *
 * `shown_year`/`shown_month` choose the visible month and
 * `today_year`/`today_month`/`today_day` highlight the current date. The
 * `<lv_calendar-header_dropdown>` element adds dropdowns for jumping to
 * another month or year.
 */
void lv_example_calendar(void)
{
    static lv_style_t style_cal;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_cal);
        lv_style_set_bg_color(&style_cal, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_cal, (255 * 100 / 100));
        lv_style_set_text_color(&style_cal, lv_color_hex(0xe2e8f0));
        lv_style_set_radius(&style_cal, 8);

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    /* 💡 Use the header dropdowns to change month or year. */
    lv_obj_t * lv_calendar_0 = lv_calendar_create(screen);
    lv_obj_set_size(lv_calendar_0, 260, 280);
    lv_calendar_set_shown_year(lv_calendar_0, 2026);
    lv_calendar_set_shown_month(lv_calendar_0, 5);
    lv_obj_set_align(lv_calendar_0, LV_ALIGN_CENTER);
    lv_calendar_set_today_year(lv_calendar_0, 2026);
    lv_calendar_set_today_month(lv_calendar_0, 5);
    lv_calendar_set_today_day(lv_calendar_0, 17);
    lv_obj_add_style(lv_calendar_0, &style_cal, 0);
    lv_calendar_add_header_dropdown(lv_calendar_0);
}

