/**
 * @file lv_example_dropdown.c
 */

#include "../lv_examples.h"

/**
 * @title Drop-down list
 * @brief Options, a preselected item, a styled list, and subject binding.
 *
 * `options` is a newline-separated string; `selected` picks the initial
 * index. `bind_value="subject_index"` two-ways the selection, and the label
 * below reads the same subject. The `<lv_dropdown-list>` element styles the
 * open list (the popup) separately from the closed button.
 */
void lv_example_dropdown(void)
{
    static lv_style_t style_dd;
    static lv_style_t style_dd_list;
    static lv_style_t style_dd_list_selected;
    static lv_style_t style_dd_list_pressed;

    static lv_subject_t subject_index;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_dd);
        lv_style_set_bg_color(&style_dd, lv_color_hex(0x1f2937));
        lv_style_set_bg_opa(&style_dd, (255 * 100 / 100));
        lv_style_set_text_color(&style_dd, lv_color_hex(0xf3f4f6));
        lv_style_set_radius(&style_dd, 8);
        lv_style_set_pad_all(&style_dd, 10);

        lv_style_init(&style_dd_list);
        lv_style_set_bg_color(&style_dd_list, lv_color_hex(0x111827));
        lv_style_set_text_color(&style_dd_list, lv_color_hex(0xe5e7eb));
        lv_style_set_border_color(&style_dd_list, lv_color_hex(0x3b82f6));
        lv_style_set_border_width(&style_dd_list, 1);

        lv_style_init(&style_dd_list_selected);
        lv_style_set_bg_color(&style_dd_list_selected, lv_color_hex(0xa93bf5));
        lv_style_set_text_color(&style_dd_list_selected, lv_color_hex(0xffffff));

        lv_style_init(&style_dd_list_pressed);
        lv_style_set_bg_color(&style_dd_list_pressed, lv_color_hex(0xcc98f1));
        lv_style_set_text_color(&style_dd_list_pressed, lv_color_hex(0xffffff));

        lv_subject_init_int(&subject_index, 0);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    lv_obj_t * lv_dropdown_0 = lv_dropdown_create(screen);
    lv_obj_set_width(lv_dropdown_0, 200);
    lv_obj_set_align(lv_dropdown_0, LV_ALIGN_CENTER);
    lv_dropdown_set_options(lv_dropdown_0, "Celsius\nFahrenheit\nKelvin");
    lv_dropdown_set_selected(lv_dropdown_0, 1);
    lv_dropdown_bind_value(lv_dropdown_0, &subject_index);
    lv_obj_add_style(lv_dropdown_0, &style_dd, 0);
    lv_obj_t * lv_dropdown_list_0 = lv_dropdown_get_list(lv_dropdown_0);
    lv_obj_add_style(lv_dropdown_list_0, &style_dd_list, 0);
    lv_obj_add_style(lv_dropdown_list_0, &style_dd_list_selected, LV_PART_SELECTED | LV_STATE_CHECKED);
    lv_obj_add_style(lv_dropdown_list_0, &style_dd_list_pressed, LV_PART_SELECTED | LV_STATE_PRESSED);

    lv_obj_t * lv_label_0 = lv_label_create(screen);
    lv_label_bind_text(lv_label_0, &subject_index, "Selected index: %d");
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_obj_set_y(lv_label_0, -40);
}

