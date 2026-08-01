/**
 * @file lv_example_grid_align_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_grid_align_gen.h"
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

lv_obj_t * lv_example_grid_align_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_grid_align_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 8, 0);

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        static const int32_t container_style_grid_column_dsc_array_0[] = {56, 56, 56, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_column_dsc_array(container, container_style_grid_column_dsc_array_0, 0);
        static const int32_t container_style_grid_row_dsc_array_0[] = {36, 36, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_row_dsc_array(container, container_style_grid_row_dsc_array_0, 0);
        lv_obj_set_style_grid_column_align(container, LV_GRID_ALIGN_START, 0);
        lv_obj_set_style_grid_row_align(container, LV_GRID_ALIGN_END, 0);
        lv_obj_set_style_layout(container, LV_LAYOUT_GRID, 0);
        lv_obj_set_width(container, 300);
        lv_obj_set_height(container, 180);
        lv_obj_t * label_1 = lv_label_create(container);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_style_grid_cell_x_align(label_1, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(label_1, 0, 0);
        lv_obj_set_style_grid_cell_y_align(label_1, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(label_1, 0, 0);
        lv_obj_set_style_bg_color(label_1, lv_color_hex(0xd6eaf8), 0);
        lv_obj_set_style_bg_opa(label_1, (255 * 100 / 100), 0);
        lv_label_set_text(label_1, "0,0");

        lv_obj_t * label_2 = lv_label_create(container);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_style_grid_cell_x_align(label_2, LV_GRID_ALIGN_START, 0);
        lv_obj_set_style_grid_cell_column_pos(label_2, 1, 0);
        lv_obj_set_style_grid_cell_y_align(label_2, LV_GRID_ALIGN_START, 0);
        lv_obj_set_style_grid_cell_row_pos(label_2, 0, 0);
        lv_obj_set_style_bg_color(label_2, lv_color_hex(0xd6eaf8), 0);
        lv_obj_set_style_bg_opa(label_2, (255 * 100 / 100), 0);
        lv_label_set_text(label_2, "1,0");

        lv_obj_t * label_3 = lv_label_create(container);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_style_grid_cell_x_align(label_3, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(label_3, 2, 0);
        lv_obj_set_style_grid_cell_y_align(label_3, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(label_3, 0, 0);
        lv_obj_set_style_bg_color(label_3, lv_color_hex(0xd6eaf8), 0);
        lv_obj_set_style_bg_opa(label_3, (255 * 100 / 100), 0);
        lv_label_set_text(label_3, "2,0");

        lv_obj_t * label_4 = lv_label_create(container);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_style_grid_cell_x_align(label_4, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(label_4, 0, 0);
        lv_obj_set_style_grid_cell_y_align(label_4, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(label_4, 1, 0);
        lv_obj_set_style_bg_color(label_4, lv_color_hex(0xd5f5e3), 0);
        lv_obj_set_style_bg_opa(label_4, (255 * 100 / 100), 0);
        lv_label_set_text(label_4, "0,1");

        lv_obj_t * label_5 = lv_label_create(container);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_style_grid_cell_x_align(label_5, LV_GRID_ALIGN_START, 0);
        lv_obj_set_style_grid_cell_column_pos(label_5, 1, 0);
        lv_obj_set_style_grid_cell_y_align(label_5, LV_GRID_ALIGN_START, 0);
        lv_obj_set_style_grid_cell_row_pos(label_5, 1, 0);
        lv_obj_set_style_bg_color(label_5, lv_color_hex(0xd5f5e3), 0);
        lv_obj_set_style_bg_opa(label_5, (255 * 100 / 100), 0);
        lv_label_set_text(label_5, "1,1");

        lv_obj_t * label_6 = lv_label_create(container);
        lv_obj_set_name(label_6, "label_6");
        lv_obj_set_style_grid_cell_x_align(label_6, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(label_6, 2, 0);
        lv_obj_set_style_grid_cell_y_align(label_6, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(label_6, 1, 0);
        lv_obj_set_style_bg_color(label_6, lv_color_hex(0xd5f5e3), 0);
        lv_obj_set_style_bg_opa(label_6, (255 * 100 / 100), 0);
        lv_label_set_text(label_6, "2,1");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

