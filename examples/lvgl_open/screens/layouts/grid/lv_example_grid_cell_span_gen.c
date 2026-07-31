/**
 * @file lv_example_grid_cell_span_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_grid_cell_span_gen.h"
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

lv_obj_t * lv_example_grid_cell_span_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_card;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_card);
            lv_style_set_bg_color(&style_card, lv_color_hex(0xf6f6f6));
            lv_style_set_bg_opa(&style_card, (255 * 100 / 100));
            lv_style_set_pad_all(&style_card, 6);
            lv_style_set_radius(&style_card, 6);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_grid_cell_span_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * container_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_1, "container_1");
        static const int32_t container_1_style_grid_column_dsc_array_0[] = {90, 90, 90, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_column_dsc_array(container_1, container_1_style_grid_column_dsc_array_0, 0);
        static const int32_t container_1_style_grid_row_dsc_array_0[] = {60, 60, 60, LV_GRID_TEMPLATE_LAST};
        lv_obj_set_style_grid_row_dsc_array(container_1, container_1_style_grid_row_dsc_array_0, 0);
        lv_obj_set_style_layout(container_1, LV_LAYOUT_GRID, 0);
        lv_obj_set_width(container_1, lv_pct(90));
        lv_obj_set_height(container_1, LV_SIZE_CONTENT);
        lv_obj_t * container_2 = lv_obj_create(container_1);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_style_grid_cell_x_align(container_2, LV_GRID_ALIGN_START, 0);
        lv_obj_set_style_grid_cell_column_pos(container_2, 0, 0);
        lv_obj_set_style_grid_cell_y_align(container_2, LV_GRID_ALIGN_START, 0);
        lv_obj_set_style_grid_cell_row_pos(container_2, 0, 0);
        lv_obj_set_width(container_2, LV_SIZE_CONTENT);
        lv_obj_set_height(container_2, LV_SIZE_CONTENT);
        lv_obj_add_style(container_2, &style_card, 0);
        lv_obj_t * label_1 = lv_label_create(container_2);
        lv_obj_set_name(label_1, "label_1");
        lv_label_set_text(label_1, "start/start");

        lv_obj_t * container_3 = lv_obj_create(container_1);
        lv_obj_set_name(container_3, "container_3");
        lv_obj_set_style_grid_cell_x_align(container_3, LV_GRID_ALIGN_CENTER, 0);
        lv_obj_set_style_grid_cell_column_pos(container_3, 1, 0);
        lv_obj_set_style_grid_cell_y_align(container_3, LV_GRID_ALIGN_CENTER, 0);
        lv_obj_set_style_grid_cell_row_pos(container_3, 0, 0);
        lv_obj_set_width(container_3, LV_SIZE_CONTENT);
        lv_obj_set_height(container_3, LV_SIZE_CONTENT);
        lv_obj_add_style(container_3, &style_card, 0);
        lv_obj_t * label_2 = lv_label_create(container_3);
        lv_obj_set_name(label_2, "label_2");
        lv_label_set_text(label_2, "center");

        lv_obj_t * container_4 = lv_obj_create(container_1);
        lv_obj_set_name(container_4, "container_4");
        lv_obj_set_style_grid_cell_x_align(container_4, LV_GRID_ALIGN_END, 0);
        lv_obj_set_style_grid_cell_column_pos(container_4, 2, 0);
        lv_obj_set_style_grid_cell_y_align(container_4, LV_GRID_ALIGN_END, 0);
        lv_obj_set_style_grid_cell_row_pos(container_4, 0, 0);
        lv_obj_set_width(container_4, LV_SIZE_CONTENT);
        lv_obj_set_height(container_4, LV_SIZE_CONTENT);
        lv_obj_add_style(container_4, &style_card, 0);
        lv_obj_t * label_3 = lv_label_create(container_4);
        lv_obj_set_name(label_3, "label_3");
        lv_label_set_text(label_3, "end/end");

        lv_obj_t * container_5 = lv_obj_create(container_1);
        lv_obj_set_name(container_5, "container_5");
        lv_obj_set_style_grid_cell_x_align(container_5, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(container_5, 1, 0);
        lv_obj_set_style_grid_cell_column_span(container_5, 2, 0);
        lv_obj_set_style_grid_cell_y_align(container_5, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(container_5, 1, 0);
        lv_obj_set_style_bg_color(container_5, lv_color_hex(0xd8ecff), 0);
        lv_obj_set_style_bg_opa(container_5, (255 * 100 / 100), 0);
        lv_obj_t * label_4 = lv_label_create(container_5);
        lv_obj_set_name(label_4, "label_4");
        lv_label_set_text(label_4, "span 2 columns");
        lv_obj_set_align(label_4, LV_ALIGN_CENTER);

        lv_obj_t * container_6 = lv_obj_create(container_1);
        lv_obj_set_name(container_6, "container_6");
        lv_obj_set_style_grid_cell_x_align(container_6, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_column_pos(container_6, 0, 0);
        lv_obj_set_style_grid_cell_y_align(container_6, LV_GRID_ALIGN_STRETCH, 0);
        lv_obj_set_style_grid_cell_row_pos(container_6, 1, 0);
        lv_obj_set_style_grid_cell_row_span(container_6, 2, 0);
        lv_obj_set_style_bg_color(container_6, lv_color_hex(0xffe8cc), 0);
        lv_obj_set_style_bg_opa(container_6, (255 * 100 / 100), 0);
        lv_obj_t * label_5 = lv_label_create(container_6);
        lv_obj_set_name(label_5, "label_5");
        lv_label_set_text(label_5, "span\n2 rows");
        lv_obj_set_align(label_5, LV_ALIGN_CENTER);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

