/**
 * @file lv_example_grid_subgrid_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_grid_subgrid_gen.h"
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

lv_obj_t * lv_example_grid_subgrid_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_tile;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_tile);
            lv_style_set_bg_opa(&style_tile, (255 * 100 / 100));
            lv_style_set_text_color(&style_tile, lv_color_hex(0xffffff));
            lv_style_set_pad_all(&style_tile, 6);
            lv_style_set_radius(&style_tile, 4);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_grid_subgrid_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 8, 0);

        lv_obj_t * container_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_1, "container_1");
        static const int32_t container_1_style_grid_column_dsc_array_0[] = {60, 60, 60, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_column_dsc_array(container_1, container_1_style_grid_column_dsc_array_0, 0);
        static const int32_t container_1_style_grid_row_dsc_array_0[] = {40, 40, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_row_dsc_array(container_1, container_1_style_grid_row_dsc_array_0, 0);
        lv_obj_set_style_layout(container_1, LV_LAYOUT_GRID, 0);
        lv_obj_set_width(container_1, 280);
        lv_obj_set_height(container_1, LV_SIZE_CONTENT);
        lv_obj_t * label_1 = lv_label_create(container_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_style_grid_cell_column_pos(label_1, 0, 0);
        lv_obj_set_style_grid_cell_row_pos(label_1, 0, 0);
        lv_obj_set_style_bg_color(label_1, lv_color_hex(0x1f77b4), 0);
        lv_label_set_text(label_1, "P0,0");
        lv_obj_add_style(label_1, &style_tile, 0);

        lv_obj_t * container_2 = lv_obj_create(container_1);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_style_grid_cell_x_align(container_2, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(container_2, 1, 0);
        lv_obj_set_style_grid_cell_column_span(container_2, 2, 0);
        lv_obj_set_style_grid_cell_y_align(container_2, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(container_2, 0, 0);
        lv_obj_set_style_grid_cell_row_span(container_2, 2, 0);
        lv_obj_set_style_layout(container_2, LV_LAYOUT_GRID, 0);
        lv_obj_set_style_pad_all(container_2, 4, 0);
        lv_obj_t * label_2 = lv_label_create(container_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_style_grid_cell_column_pos(label_2, 0, 0);
        lv_obj_set_style_grid_cell_row_pos(label_2, 0, 0);
        lv_obj_set_style_bg_color(label_2, lv_color_hex(0x2ca02c), 0);
        lv_label_set_text(label_2, "S0,0");
        lv_obj_add_style(label_2, &style_tile, 0);

        lv_obj_t * label_3 = lv_label_create(container_2);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_style_grid_cell_column_pos(label_3, 1, 0);
        lv_obj_set_style_grid_cell_row_pos(label_3, 0, 0);
        lv_obj_set_style_bg_color(label_3, lv_color_hex(0xff7f0e), 0);
        lv_label_set_text(label_3, "S1,0");
        lv_obj_add_style(label_3, &style_tile, 0);

        lv_obj_t * label_4 = lv_label_create(container_2);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_style_grid_cell_column_pos(label_4, 0, 0);
        lv_obj_set_style_grid_cell_row_pos(label_4, 1, 0);
        lv_obj_set_style_bg_color(label_4, lv_color_hex(0xd62728), 0);
        lv_label_set_text(label_4, "S0,1");
        lv_obj_add_style(label_4, &style_tile, 0);

        lv_obj_t * label_5 = lv_label_create(container_2);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_style_grid_cell_column_pos(label_5, 1, 0);
        lv_obj_set_style_grid_cell_row_pos(label_5, 1, 0);
        lv_obj_set_style_bg_color(label_5, lv_color_hex(0x9467bd), 0);
        lv_label_set_text(label_5, "S1,1");
        lv_obj_add_style(label_5, &style_tile, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

