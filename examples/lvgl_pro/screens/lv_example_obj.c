/**
 * @file lv_example_obj.c
 */

#include "../lv_examples.h"

/**
 * @title Base widget
 * @brief A plain lv_obj used as a styled, scrollable, flex container.
 *
 * lv_obj has no widget-specific properties — it is the styling, layout,
 * scrolling and state engine every widget inherits. Here one lv_obj is a flex
 * column with a scrollbar holding five rows; a `<bind_style>` swaps its look
 * when `subject_checked` is 1, and the switch above toggles that subject.
 */
void lv_example_obj(void)
{
    static lv_style_t style_box;
    static lv_style_t style_box_alt;
    static lv_style_t style_row;
    static lv_style_t style_scrollbar;

    static lv_subject_t subject_checked;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_box);
        lv_style_set_bg_color(&style_box, lv_color_hex(0x1e293b));
        lv_style_set_bg_opa(&style_box, (255 * 100 / 100));
        lv_style_set_radius(&style_box, 10);
        lv_style_set_pad_all(&style_box, 14);
        lv_style_set_text_color(&style_box, lv_color_hex(0xe2e8f0));

        lv_style_init(&style_box_alt);
        lv_style_set_bg_color(&style_box_alt, lv_color_hex(0x5b1db7));

        lv_style_init(&style_row);
        lv_style_set_bg_color(&style_row, lv_color_hex(0x334155));
        lv_style_set_border_color(&style_row, lv_color_hex(0x5a697e));
        lv_style_set_bg_opa(&style_row, (255 * 100 / 100));
        lv_style_set_radius(&style_row, 6);
        lv_style_set_pad_all(&style_row, 10);
        lv_style_set_height(&style_row, LV_SIZE_CONTENT);
        lv_style_set_width(&style_row, lv_pct(100));
        lv_style_set_text_color(&style_row, lv_color_hex(0xe2e8f0));

        lv_style_init(&style_scrollbar);
        lv_style_set_bg_color(&style_scrollbar, lv_color_hex(0x9a80c1));
        lv_style_set_bg_opa(&style_scrollbar, (255 * 100 / 100));
        lv_style_set_width(&style_scrollbar, 6);
        lv_style_set_pad_ver(&style_scrollbar, 14);

        lv_subject_init_int(&subject_checked, 0);
        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    lv_obj_t * lv_switch_0 = lv_switch_create(screen);
    lv_obj_bind_checked(lv_switch_0, &subject_checked);
    lv_obj_set_pos(lv_switch_0, 92, 11);

    lv_obj_t * lv_label_0 = lv_label_create(screen);
    lv_label_set_text(lv_label_0, "Switch theme");
    lv_obj_set_pos(lv_label_0, 163, 19);

    /* The base widget as a scrollable flex container */
    lv_obj_t * lv_obj_1 = lv_obj_create(screen);
    lv_obj_set_size(lv_obj_1, 300, 200);
    lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(lv_obj_1, 8, 0);
    lv_obj_set_scrollbar_mode(lv_obj_1, LV_SCROLLBAR_MODE_ACTIVE);
    lv_obj_add_style(lv_obj_1, &style_box, 0);
    lv_obj_bind_style(lv_obj_1, &style_box_alt, 0, &subject_checked, 1);
    lv_obj_add_style(lv_obj_1, &style_scrollbar, LV_PART_SCROLLBAR);
    lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_2, &style_row, 0);
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
    lv_label_set_text(lv_label_1, "Row 1 . Scroll down");

    lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_3, &style_row, 0);
    lv_obj_t * lv_label_2 = lv_label_create(lv_obj_3);
    lv_label_set_text(lv_label_2, "Row 2");

    lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_4, &style_row, 0);
    lv_obj_t * lv_label_3 = lv_label_create(lv_obj_4);
    lv_label_set_text(lv_label_3, "Row 3");

    lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_5, &style_row, 0);
    lv_obj_t * lv_label_4 = lv_label_create(lv_obj_5);
    lv_label_set_text(lv_label_4, "Row 4");

    lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_1);
    lv_obj_add_style(lv_obj_6, &style_row, 0);
    lv_obj_t * lv_label_5 = lv_label_create(lv_obj_6);
    lv_label_set_text(lv_label_5, "Row 5 - I'm the last");
}

