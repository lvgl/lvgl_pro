/**
 * @file lv_example_table_width_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_table_width_gen.h"
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

lv_obj_t * lv_example_table_width_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_table_width_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * table = lv_table_create(lv_obj_0);
        lv_obj_set_name(table, "table");
        lv_table_set_row_count(table, 3);
        lv_table_set_column_count(table, 3);
        lv_table_set_column_width(table, 0, 60);
        lv_table_set_column_width(table, 1, 180);
        lv_table_set_column_width(table, 2, 80);
        lv_table_set_cell_value(table, 0, 0, "No.");
        lv_table_set_cell_value(table, 0, 1, "Description");
        lv_table_set_cell_value(table, 0, 2, "Price");
        lv_table_set_cell_value(table, 1, 0, "1");
        lv_table_set_cell_value(table, 1, 1, "Espresso, small");
        lv_table_set_cell_value(table, 1, 2, "2.50");
        lv_table_set_cell_value(table, 2, 0, "2");
        lv_table_set_cell_value(table, 2, 1, "Cappuccino, regular");
        lv_table_set_cell_value(table, 2, 2, "3.80");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

