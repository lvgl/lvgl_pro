/**
 * @file lv_example_table_cells_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_table_cells_gen.h"
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

lv_obj_t * lv_example_table_cells_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_table_cells_#");

        lv_obj_t * table = lv_table_create(lv_obj_0);
        lv_obj_set_name(table, "table");
        lv_table_set_row_count(table, 3);
        lv_table_set_column_count(table, 2);
        lv_obj_set_align(table, LV_ALIGN_CENTER);
        lv_table_set_cell_value(table, 0, 0, "City");
        lv_table_set_cell_value(table, 0, 1, "Population");
        lv_table_set_cell_value(table, 1, 0, "Berlin");
        lv_table_set_cell_value(table, 1, 1, "3.7M");
        lv_table_set_cell_value(table, 2, 0, "Paris");
        lv_table_set_cell_value(table, 2, 1, "2.1M");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

