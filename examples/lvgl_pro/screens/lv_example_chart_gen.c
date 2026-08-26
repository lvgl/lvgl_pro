/**
 * @file lv_example_chart_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_chart_gen.h"
#include "../lvgl_pro_examples.h"

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

lv_obj_t * lv_example_chart_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_chart;
    static lv_style_t style_chart_cursor;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_chart);
        lv_style_init(&style_chart_cursor);

        lv_style_set_bg_color(&style_chart, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_chart, (255 * 100 / 100));
        lv_style_set_radius(&style_chart, 8);
        lv_style_set_pad_all(&style_chart, 10);
        lv_style_set_line_color(&style_chart, lv_color_hex(0x334155));
        lv_style_set_border_width(&style_chart, 0);
        lv_style_set_line_dash_gap(&style_chart_cursor, 10);
        lv_style_set_line_dash_width(&style_chart_cursor, 5);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_chart_#");

        lv_obj_t * lv_chart_0 = lv_chart_create(lv_obj_0);
        lv_obj_set_width(lv_chart_0, 300);
        lv_obj_set_height(lv_chart_0, 220);
        lv_obj_set_align(lv_chart_0, LV_ALIGN_CENTER);
        lv_chart_set_type(lv_chart_0, LV_CHART_TYPE_LINE);
        lv_chart_set_point_count(lv_chart_0, 6);
        lv_chart_set_hor_div_line_count(lv_chart_0, 5);
        lv_chart_set_ver_div_line_count(lv_chart_0, 6);
        lv_obj_add_style(lv_chart_0, &style_chart, 0);
        lv_obj_add_style(lv_chart_0, &style_chart_cursor, LV_PART_CURSOR);
        lv_chart_set_axis_min_value(lv_chart_0, LV_CHART_AXIS_PRIMARY_Y, 0);
        lv_chart_set_axis_max_value(lv_chart_0, LV_CHART_AXIS_PRIMARY_Y, 100);
        lv_chart_series_t * lv_chart_series_0 = lv_chart_add_series(lv_chart_0, lv_color_hex(0x3b82f6), LV_CHART_AXIS_PRIMARY_Y);
        static const int32_t lv_chart_0_values_0[] = {20, 45, 30, 70, 55, 90};
        lv_chart_set_series_values(lv_chart_0, lv_chart_series_0, lv_chart_0_values_0, 6);
        lv_chart_series_t * lv_chart_series_1 = lv_chart_add_series(lv_chart_0, lv_color_hex(0xf59e0b), LV_CHART_AXIS_PRIMARY_Y);
        static const int32_t lv_chart_0_values_1[] = {80, 60, 65, 40, 50, 25};
        lv_chart_set_series_values(lv_chart_0, lv_chart_series_1, lv_chart_0_values_1, 6);
        lv_chart_cursor_t * lv_chart_cursor_0 = lv_chart_add_cursor(lv_chart_0, lv_color_hex(0xef4444), LV_DIR_HOR);
        lv_chart_set_cursor_pos_y(lv_chart_0, lv_chart_cursor_0, 70);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

