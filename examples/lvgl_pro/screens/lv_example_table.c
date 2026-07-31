/**
 * @file lv_example_table.c
 */

#include "../lv_examples.h"

/**
 * @title Table
 * @brief A small table with a header row, set column widths and a merged cell.
 *
 * `row_count`/`column_count` size the grid. `<lv_table-column>` sets a
 * column's width; `<lv_table-cell>` writes a cell's text by row/column and
 * can take `ctrl` flags — here `merge_right` spans the footer across two
 * columns.
 */
void lv_example_table(void)
{
    static lv_style_t style_table;
    static lv_style_t style_items;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_table);
        lv_style_set_bg_color(&style_table, lv_color_hex(0x111827));
        lv_style_set_bg_opa(&style_table, (255 * 100 / 100));
        lv_style_set_radius(&style_table, 8);
        lv_style_set_pad_all(&style_table, 8);

        lv_style_init(&style_items);
        lv_style_set_bg_opa(&style_items, (255 * 100 / 100));
        lv_style_set_bg_color(&style_items, lv_color_hex(0x4b5362));
        lv_style_set_border_side(&style_items, LV_BORDER_SIDE_FULL);
        lv_style_set_text_color(&style_items, lv_color_hex(0xe5e7eb));
        lv_style_set_border_color(&style_items, lv_color_hex(0x111827));

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    lv_obj_t * lv_table_0 = lv_table_create(screen);
    lv_table_set_row_count(lv_table_0, 4);
    lv_table_set_column_count(lv_table_0, 2);
    lv_obj_set_align(lv_table_0, LV_ALIGN_CENTER);
    lv_obj_add_style(lv_table_0, &style_table, 0);
    lv_obj_add_style(lv_table_0, &style_items, LV_PART_ITEMS);
    lv_table_set_column_width(lv_table_0, 0, 150);
    lv_table_set_column_width(lv_table_0, 1, 90);
    lv_table_set_cell_value(lv_table_0, 0, 0, "Sensor");
    lv_table_set_cell_value(lv_table_0, 0, 1, "Value");
    lv_table_set_cell_value(lv_table_0, 1, 0, "Temperature");
    lv_table_set_cell_value(lv_table_0, 1, 1, "22 °C");
    lv_table_set_cell_value(lv_table_0, 2, 0, "Humidity");
    lv_table_set_cell_value(lv_table_0, 2, 1, "48 %");
    lv_table_set_cell_value(lv_table_0, 3, 0, "All readings nominal");
    lv_table_set_cell_ctrl(lv_table_0, 3, 0, LV_TABLE_CELL_CTRL_MERGE_RIGHT);
}

