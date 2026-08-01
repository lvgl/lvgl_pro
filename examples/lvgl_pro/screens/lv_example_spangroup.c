/**
 * @file lv_example_spangroup.c
 */

#include "../lv_examples.h"

/**
 * @title Span group
 * @brief Rich text built from spans with different fonts, colours and sizes.
 *
 * Each `<lv_spangroup-span>` element carries its own `text` and a named
 * `style`, so one paragraph mixes colours and sizes. `overflow="ellipsis"`
 * and `max_lines` clip the block gracefully, and `indent` offsets the first
 * line.
 */
void lv_example_spangroup(void)
{
    LV_FONT_DECLARE(font_large);

    static lv_style_t style_normal;
    static lv_style_t style_accent;
    static lv_style_t style_big;
    static lv_style_t style_panel;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_normal);
        lv_style_set_text_color(&style_normal, lv_color_hex(0xe5e7eb));

        lv_style_init(&style_accent);
        lv_style_set_text_color(&style_accent, lv_color_hex(0x3b82f6));

        lv_style_init(&style_big);
        lv_style_set_text_color(&style_big, lv_color_hex(0xf59e0b));
        lv_style_set_text_font(&style_big, &font_large);

        lv_style_init(&style_panel);
        lv_style_set_bg_color(&style_panel, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_panel, (255 * 100 / 100));
        lv_style_set_radius(&style_panel, 8);
        lv_style_set_pad_all(&style_panel, 12);

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    lv_obj_t * lv_spangroup_0 = lv_spangroup_create(screen);
    lv_obj_set_size(lv_spangroup_0, 260, LV_SIZE_CONTENT);
    lv_spangroup_set_overflow(lv_spangroup_0, LV_SPAN_OVERFLOW_ELLIPSIS);
    lv_spangroup_set_max_lines(lv_spangroup_0, 3);
    lv_spangroup_set_indent(lv_spangroup_0, 16);
    lv_obj_set_align(lv_spangroup_0, LV_ALIGN_CENTER);
    lv_obj_add_style(lv_spangroup_0, &style_panel, 0);
    lv_span_t * lv_spangroup_span_0 = lv_spangroup_add_span(lv_spangroup_0);
    lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_0, "LVGL ");
    lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_0, &style_normal);
    lv_span_t * lv_spangroup_span_1 = lv_spangroup_add_span(lv_spangroup_0);
    lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_1, "Pro");
    lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_1, &style_big);
    lv_span_t * lv_spangroup_span_2 = lv_spangroup_add_span(lv_spangroup_0);
    lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_2, " lets you mix ");
    lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_2, &style_normal);
    lv_span_t * lv_spangroup_span_3 = lv_spangroup_add_span(lv_spangroup_0);
    lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_3, "colours");
    lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_3, &style_accent);
    lv_span_t * lv_spangroup_span_4 = lv_spangroup_add_span(lv_spangroup_0);
    lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_4, " and sizes in a single block of text.");
    lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_4, &style_normal);
}

