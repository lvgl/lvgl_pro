/**
 * @file lv_example_grid_fr_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_grid_fr_gen.h"
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

lv_obj_t * lv_example_grid_fr_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_grid_fr_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * container_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_1, "container_1");
        static const int32_t container_1_style_grid_column_dsc_array_0[] = {80, LV_GRID_FR(1), LV_GRID_FR(2), LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_column_dsc_array(container_1, container_1_style_grid_column_dsc_array_0, 0);
        static const int32_t container_1_style_grid_row_dsc_array_0[] = {44, LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_row_dsc_array(container_1, container_1_style_grid_row_dsc_array_0, 0);
        lv_obj_set_style_layout(container_1, LV_LAYOUT_GRID, 0);
        lv_obj_set_width(container_1, lv_pct(100));
        lv_obj_set_height(container_1, 190);
        lv_obj_t * label_1 = lv_label_create(container_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_style_grid_cell_x_align(label_1, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(label_1, 0, 0);
        lv_obj_set_style_grid_cell_y_align(label_1, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(label_1, 0, 0);
        lv_obj_set_style_bg_color(label_1, lv_color_hex(0xb8d8f8), 0);
        lv_obj_set_style_bg_opa(label_1, (255 * 100 / 100), 0);
        lv_label_set_text(label_1, "80px");

        lv_obj_t * label_2 = lv_label_create(container_1);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_style_grid_cell_x_align(label_2, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(label_2, 1, 0);
        lv_obj_set_style_grid_cell_y_align(label_2, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(label_2, 0, 0);
        lv_obj_set_style_bg_color(label_2, lv_color_hex(0x7ec8ff), 0);
        lv_obj_set_style_bg_opa(label_2, (255 * 100 / 100), 0);
        lv_label_set_text(label_2, "1fr");

        lv_obj_t * label_3 = lv_label_create(container_1);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_style_grid_cell_x_align(label_3, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(label_3, 2, 0);
        lv_obj_set_style_grid_cell_y_align(label_3, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(label_3, 0, 0);
        lv_obj_set_style_bg_color(label_3, lv_color_hex(0x4daff7), 0);
        lv_obj_set_style_bg_opa(label_3, (255 * 100 / 100), 0);
        lv_label_set_text(label_3, "2fr");

        lv_obj_t * container_2 = lv_obj_create(container_1);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_style_grid_cell_x_align(container_2, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(container_2, 0, 0);
        lv_obj_set_style_grid_cell_y_align(container_2, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(container_2, 1, 0);
        lv_obj_set_style_bg_color(container_2, lv_color_hex(0xb8d8f8), 0);
        lv_obj_set_style_bg_opa(container_2, (255 * 100 / 100), 0);
        lv_obj_t * label_4 = lv_label_create(container_2);
        lv_obj_set_name(label_4, "label_4");
        lv_label_set_text(label_4, "80px");
        lv_obj_set_align(label_4, LV_ALIGN_CENTER);

        lv_obj_t * container_3 = lv_obj_create(container_1);
        lv_obj_set_name(container_3, "container_3");
        lv_obj_set_style_grid_cell_x_align(container_3, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(container_3, 1, 0);
        lv_obj_set_style_grid_cell_y_align(container_3, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(container_3, 1, 0);
        lv_obj_set_style_bg_color(container_3, lv_color_hex(0x7ec8ff), 0);
        lv_obj_set_style_bg_opa(container_3, (255 * 100 / 100), 0);
        lv_obj_t * label_5 = lv_label_create(container_3);
        lv_obj_set_name(label_5, "label_5");
        lv_label_set_text(label_5, "1fr");
        lv_obj_set_align(label_5, LV_ALIGN_CENTER);

        lv_obj_t * container_4 = lv_obj_create(container_1);
        lv_obj_set_name(container_4, "container_4");
        lv_obj_set_style_grid_cell_x_align(container_4, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(container_4, 2, 0);
        lv_obj_set_style_grid_cell_y_align(container_4, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(container_4, 1, 0);
        lv_obj_set_style_bg_color(container_4, lv_color_hex(0x4daff7), 0);
        lv_obj_set_style_bg_opa(container_4, (255 * 100 / 100), 0);
        lv_obj_t * label_6 = lv_label_create(container_4);
        lv_obj_set_name(label_6, "label_6");
        lv_label_set_text(label_6, "2fr");
        lv_obj_set_align(label_6, LV_ALIGN_CENTER);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

