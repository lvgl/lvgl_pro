/**
 * @file lv_example_table_scroll_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_table_scroll_gen.h"
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

lv_obj_t * lv_example_table_scroll_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_table_scroll_#");

        lv_obj_t * table = lv_table_create(lv_obj_0);
        lv_obj_set_name(table, "table");
        lv_obj_set_align(table, LV_ALIGN_CENTER);
        lv_obj_set_width(table, 240);
        lv_obj_set_height(table, 160);
        lv_table_set_row_count(table, 12);
        lv_table_set_column_count(table, 2);
        lv_table_set_column_width(table, 0, 70);
        lv_table_set_column_width(table, 1, 160);
        lv_table_set_cell_value(table, 0, 0, "No.");
        lv_table_set_cell_value(table, 0, 1, "Item");
        lv_table_set_cell_value(table, 1, 0, "1");
        lv_table_set_cell_value(table, 1, 1, "Wrench");
        lv_table_set_cell_value(table, 2, 0, "2");
        lv_table_set_cell_value(table, 2, 1, "Screwdriver");
        lv_table_set_cell_value(table, 3, 0, "3");
        lv_table_set_cell_value(table, 3, 1, "Hammer");
        lv_table_set_cell_value(table, 4, 0, "4");
        lv_table_set_cell_value(table, 4, 1, "Drill");
        lv_table_set_cell_value(table, 5, 0, "5");
        lv_table_set_cell_value(table, 5, 1, "Saw");
        lv_table_set_cell_value(table, 6, 0, "6");
        lv_table_set_cell_value(table, 6, 1, "Pliers");
        lv_table_set_cell_value(table, 7, 0, "7");
        lv_table_set_cell_value(table, 7, 1, "Tape measure");
        lv_table_set_cell_value(table, 8, 0, "8");
        lv_table_set_cell_value(table, 8, 1, "Level");
        lv_table_set_cell_value(table, 9, 0, "9");
        lv_table_set_cell_value(table, 9, 1, "Crowbar");
        lv_table_set_cell_value(table, 10, 0, "10");
        lv_table_set_cell_value(table, 10, 1, "Mallet");
        lv_table_set_cell_value(table, 11, 0, "11");
        lv_table_set_cell_value(table, 11, 1, "Chisel");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

