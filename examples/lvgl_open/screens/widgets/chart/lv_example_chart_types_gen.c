/**
 * @file lv_example_chart_types_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_chart_types_gen.h"
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

lv_obj_t * lv_example_chart_types_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_chart_types_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * chart_1 = lv_chart_create(lv_obj_0);
        lv_obj_set_name(chart_1, "chart_1");
        lv_obj_set_width(chart_1, lv_pct(90));
        lv_obj_set_height(chart_1, lv_pct(40));
        lv_chart_set_type(chart_1, LV_CHART_TYPE_LINE);
        lv_chart_set_point_count(chart_1, 8);
        lv_chart_series_t * lv_chart_series_0 = lv_chart_add_series(chart_1, lv_color_hex(0x6366f1), LV_CHART_AXIS_PRIMARY_Y);
        static const int32_t chart_1_values_0[] = {10, 35, 25, 55, 40, 70, 60, 85};
        lv_chart_set_series_values(chart_1, lv_chart_series_0, chart_1_values_0, 8);
        lv_chart_set_axis_min_value(chart_1, LV_CHART_AXIS_PRIMARY_Y, 0);
        lv_chart_set_axis_max_value(chart_1, LV_CHART_AXIS_PRIMARY_Y, 100);

        lv_obj_t * chart_2 = lv_chart_create(lv_obj_0);
        lv_obj_set_name(chart_2, "chart_2");
        lv_obj_set_width(chart_2, lv_pct(90));
        lv_obj_set_height(chart_2, lv_pct(40));
        lv_chart_set_type(chart_2, LV_CHART_TYPE_STACKED);
        lv_chart_set_point_count(chart_2, 12);
        lv_chart_series_t * lv_chart_series_1 = lv_chart_add_series(chart_2, lv_color_hex(0xef4444), LV_CHART_AXIS_PRIMARY_Y | LV_CHART_AXIS_PRIMARY_X);
        static const int32_t chart_2_values_0[] = {8, 10, 40, 20, 80, 50, 20, 30, 60, 30, 40, 20};
        lv_chart_set_series_values(chart_2, lv_chart_series_1, chart_2_values_0, 12);
        lv_chart_series_t * lv_chart_series_2 = lv_chart_add_series(chart_2, lv_color_hex(0x22c55e), LV_CHART_AXIS_PRIMARY_Y | LV_CHART_AXIS_PRIMARY_X);
        static const int32_t chart_2_values_1[] = {10, 40, 20, 80, 50, 30, 40, 80, 40, 70, 80, 70};
        lv_chart_set_series_values(chart_2, lv_chart_series_2, chart_2_values_1, 12);
        lv_chart_set_axis_min_value(chart_2, LV_CHART_AXIS_PRIMARY_Y, 0);
        lv_chart_set_axis_max_value(chart_2, LV_CHART_AXIS_PRIMARY_Y, 150);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

