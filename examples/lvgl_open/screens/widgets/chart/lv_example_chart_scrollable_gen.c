/**
 * @file lv_example_chart_scrollable_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_chart_scrollable_gen.h"
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

lv_obj_t * lv_example_chart_scrollable_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_chart_scrollable_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * container_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_1, "container_1");
        lv_obj_set_width(container_1, 300);
        lv_obj_set_height(container_1, 180);
        lv_obj_set_style_pad_all(container_1, 0, 0);
        lv_obj_t * container_2 = lv_obj_create(container_1);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_width(container_2, lv_pct(200));
        lv_obj_set_height(container_2, lv_pct(100));
        lv_obj_set_flex_flow(container_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_bg_opa(container_2, 0, 0);
        lv_obj_set_style_border_width(container_2, 0, 0);
        lv_obj_set_style_pad_all(container_2, 4, 0);
        lv_obj_t * chart = lv_chart_create(container_2);
        lv_obj_set_name(chart, "chart");
        lv_obj_set_width(chart, lv_pct(100));
        lv_obj_set_flex_grow(chart, 1);
        lv_chart_set_type(chart, LV_CHART_TYPE_BAR);
        lv_chart_set_point_count(chart, 12);
        lv_chart_set_hor_div_line_count(chart, 3);
        lv_chart_set_ver_div_line_count(chart, 0);
        lv_chart_series_t * lv_chart_series_0 = lv_chart_add_series(chart, lv_color_hex(0x6366f1), LV_CHART_AXIS_PRIMARY_Y);
        static const int32_t chart_values_0[] = {32, 41, 38, 55, 62, 70, 65, 58, 47, 60, 75, 80};
        lv_chart_set_series_values(chart, lv_chart_series_0, chart_values_0, 12);
        lv_chart_set_axis_min_value(chart, LV_CHART_AXIS_PRIMARY_Y, 0);
        lv_chart_set_axis_max_value(chart, LV_CHART_AXIS_PRIMARY_Y, 100);

        lv_obj_t * scale = lv_scale_create(container_2);
        lv_obj_set_name(scale, "scale");
        lv_obj_set_width(scale, lv_pct(100));
        lv_obj_set_style_pad_hor(scale, 30, 0);
        lv_obj_set_height(scale, 22);
        lv_scale_set_mode(scale, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
        lv_scale_set_total_tick_count(scale, 12);
        lv_scale_set_major_tick_every(scale, 1);
        lv_scale_set_label_show(scale, true);
        static const char *scale_text_src_0[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec", NULL};
        lv_scale_set_text_src(scale, scale_text_src_0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

