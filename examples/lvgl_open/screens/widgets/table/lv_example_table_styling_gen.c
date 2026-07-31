/**
 * @file lv_example_table_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_table_styling_gen.h"
#include "../../../lvgl_open_examples.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * lv_example_table_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_table_main;
    static lv_style_t style_table_items;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_table_main);
            lv_style_set_bg_color(&style_table_main, lv_color_hex(0xffffff));
            lv_style_set_bg_opa(&style_table_main, (255 * 100 / 100));
            lv_style_set_radius(&style_table_main, 8);
            lv_style_set_border_color(&style_table_main, lv_color_hex(0xe5e7eb));
            lv_style_set_border_width(&style_table_main, 1);

            lv_style_init(&style_table_items);
            lv_style_set_bg_color(&style_table_items, lv_color_hex(0xffffff));
            lv_style_set_bg_opa(&style_table_items, (255 * 100 / 100));
            lv_style_set_border_color(&style_table_items, lv_color_hex(0xe5e7eb));
            lv_style_set_border_width(&style_table_items, 1);
            lv_style_set_pad_all(&style_table_items, 8);
            lv_style_set_text_color(&style_table_items, lv_color_hex(0x1345b0));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_table_styling_#");

        lv_obj_t * table = lv_table_create(lv_obj_0);
        lv_obj_set_align(table, LV_ALIGN_CENTER);
        lv_obj_set_name(table, "table");
        lv_table_set_row_count(table, 3);
        lv_table_set_column_count(table, 2);
        lv_table_set_cell_value(table, 0, 0, "Metric");
        lv_table_set_cell_value(table, 0, 1, "Value");
        lv_table_set_cell_value(table, 1, 0, "Latency");
        lv_table_set_cell_value(table, 1, 1, "14 ms");
        lv_table_set_cell_value(table, 2, 0, "Throughput");
        lv_table_set_cell_value(table, 2, 1, "98 req/s");
        lv_obj_add_style(table, &style_table_main, LV_PART_MAIN);
        lv_obj_add_style(table, &style_table_items, LV_PART_ITEMS);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

