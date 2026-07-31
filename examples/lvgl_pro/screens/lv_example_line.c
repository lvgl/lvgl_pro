/**
 * @file lv_example_line.c
 */

#include "../lv_examples.h"

/**
 * @title Line
 * @brief A styled poly-line, and the same points with y_invert.
 *
 * `points` is a list of coordinate pairs the Line connects in order. The
 * line look comes from the `line_*` style properties (width, colour,
 * rounded ends). The second Line uses the same points with `y_invert="true"`
 * so y=0 is the bottom, flipping the shape vertically.
 */
void lv_example_line(void)
{
    static lv_style_t style_line;
    static lv_style_t style_line2;
    static lv_style_t style_panel;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_line);
        lv_style_set_line_width(&style_line, 4);
        lv_style_set_line_color(&style_line, lv_color_hex(0x3b82f6));
        lv_style_set_line_rounded(&style_line, true);

        lv_style_init(&style_line2);
        lv_style_set_line_width(&style_line2, 4);
        lv_style_set_line_color(&style_line2, lv_color_hex(0xf59e0b));
        lv_style_set_line_rounded(&style_line2, true);

        lv_style_init(&style_panel);
        lv_style_set_bg_color(&style_panel, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_panel, (255 * 100 / 100));
        lv_style_set_radius(&style_panel, 8);

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(screen, 14, 0);
    lv_obj_set_style_pad_all(screen, 16, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
}

