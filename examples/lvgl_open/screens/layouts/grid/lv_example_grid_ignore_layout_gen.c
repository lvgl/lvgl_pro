/**
 * @file lv_example_grid_ignore_layout_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_grid_ignore_layout_gen.h"
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

lv_obj_t * lv_example_grid_ignore_layout_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_cell;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_cell);
            lv_style_set_bg_opa(&style_cell, (255 * 100 / 100));
            lv_style_set_text_color(&style_cell, lv_color_hex(0xffffff));
            lv_style_set_pad_all(&style_cell, 6);
            lv_style_set_radius(&style_cell, 4);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_grid_ignore_layout_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 8, 0);

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        static const int32_t container_style_grid_column_dsc_array_0[] = {54, 54, 54, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_column_dsc_array(container, container_style_grid_column_dsc_array_0, 0);
        static const int32_t container_style_grid_row_dsc_array_0[] = {42, 42, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_row_dsc_array(container, container_style_grid_row_dsc_array_0, 0);
        lv_obj_set_style_layout(container, LV_LAYOUT_GRID, 0);
        lv_obj_set_width(container, 280);
        lv_obj_set_height(container, 120);
        lv_obj_t * label_1 = lv_label_create(container);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_style_grid_cell_column_pos(label_1, 0, 0);
        lv_obj_set_style_grid_cell_row_pos(label_1, 0, 0);
        lv_obj_set_style_bg_color(label_1, lv_color_hex(0x3498db), 0);
        lv_label_set_text(label_1, "A");
        lv_obj_add_style(label_1, &style_cell, 0);

        lv_obj_t * label_2 = lv_label_create(container);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_style_grid_cell_column_pos(label_2, 1, 0);
        lv_obj_set_style_grid_cell_row_pos(label_2, 0, 0);
        lv_obj_set_style_bg_color(label_2, lv_color_hex(0x2ecc71), 0);
        lv_label_set_text(label_2, "B");
        lv_obj_add_style(label_2, &style_cell, 0);

        lv_obj_t * label_3 = lv_label_create(container);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_style_grid_cell_column_pos(label_3, 2, 0);
        lv_obj_set_style_grid_cell_row_pos(label_3, 0, 0);
        lv_obj_set_style_bg_color(label_3, lv_color_hex(0xe67e22), 0);
        lv_label_set_text(label_3, "C");
        lv_obj_add_style(label_3, &style_cell, 0);

        lv_obj_t * label_4 = lv_label_create(container);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_style_grid_cell_column_pos(label_4, 0, 0);
        lv_obj_set_style_grid_cell_row_pos(label_4, 1, 0);
        lv_obj_set_style_bg_color(label_4, lv_color_hex(0x8e44ad), 0);
        lv_label_set_text(label_4, "D");
        lv_obj_add_style(label_4, &style_cell, 0);

        lv_obj_t * label_5 = lv_label_create(container);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_flag(label_5, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_align(label_5, LV_ALIGN_CENTER);
        lv_obj_set_style_bg_color(label_5, lv_color_hex(0xe74c3c), 0);
        lv_label_set_text(label_5, "FREE");
        lv_obj_add_style(label_5, &style_cell, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

