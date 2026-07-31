/**
 * @file lv_example_arc_pie_chart_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_arc_pie_chart_gen.h"
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

lv_obj_t * lv_example_arc_pie_chart_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_pie_main;
    static lv_style_t style_pie_indicator;
    static lv_style_t style_pie_knob;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_pie_main);
            lv_style_set_width(&style_pie_main, 200);
            lv_style_set_height(&style_pie_main, 200);
            lv_style_set_align(&style_pie_main, LV_ALIGN_CENTER);
            lv_style_set_arc_width(&style_pie_main, 100);
            lv_style_set_arc_rounded(&style_pie_main, false);

            lv_style_init(&style_pie_indicator);
            lv_style_set_arc_opa(&style_pie_indicator, 0);

            lv_style_init(&style_pie_knob);
            lv_style_set_bg_opa(&style_pie_knob, 0);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_arc_pie_chart_#");

        lv_obj_t * arc_1 = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc_1, "arc_1");
        lv_obj_set_flag(arc_1, LV_OBJ_FLAG_CLICKABLE, false);
        lv_arc_set_bg_start_angle(arc_1, 270);
        lv_arc_set_bg_end_angle(arc_1, 325);
        lv_obj_set_style_arc_color(arc_1, lv_color_hex(0xef4444), LV_PART_MAIN);
        lv_obj_add_style(arc_1, &style_pie_main, LV_PART_MAIN);
        lv_obj_add_style(arc_1, &style_pie_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(arc_1, &style_pie_knob, LV_PART_KNOB);

        lv_obj_t * arc_2 = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc_2, "arc_2");
        lv_obj_set_flag(arc_2, LV_OBJ_FLAG_CLICKABLE, false);
        lv_arc_set_bg_start_angle(arc_2, 325);
        lv_arc_set_bg_end_angle(arc_2, 38);
        lv_obj_set_style_arc_color(arc_2, lv_color_hex(0xf59e0b), LV_PART_MAIN);
        lv_obj_add_style(arc_2, &style_pie_main, LV_PART_MAIN);
        lv_obj_add_style(arc_2, &style_pie_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(arc_2, &style_pie_knob, LV_PART_KNOB);

        lv_obj_t * arc_3 = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc_3, "arc_3");
        lv_obj_set_flag(arc_3, LV_OBJ_FLAG_CLICKABLE, false);
        lv_arc_set_bg_start_angle(arc_3, 38);
        lv_arc_set_bg_end_angle(arc_3, 162);
        lv_obj_set_style_arc_color(arc_3, lv_color_hex(0x22c55e), LV_PART_MAIN);
        lv_obj_add_style(arc_3, &style_pie_main, LV_PART_MAIN);
        lv_obj_add_style(arc_3, &style_pie_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(arc_3, &style_pie_knob, LV_PART_KNOB);

        lv_obj_t * arc_4 = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc_4, "arc_4");
        lv_obj_set_flag(arc_4, LV_OBJ_FLAG_CLICKABLE, false);
        lv_arc_set_bg_start_angle(arc_4, 162);
        lv_arc_set_bg_end_angle(arc_4, 190);
        lv_obj_set_style_arc_color(arc_4, lv_color_hex(0x3b82f6), LV_PART_MAIN);
        lv_obj_add_style(arc_4, &style_pie_main, LV_PART_MAIN);
        lv_obj_add_style(arc_4, &style_pie_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(arc_4, &style_pie_knob, LV_PART_KNOB);

        lv_obj_t * arc_5 = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc_5, "arc_5");
        lv_obj_set_flag(arc_5, LV_OBJ_FLAG_CLICKABLE, false);
        lv_arc_set_bg_start_angle(arc_5, 190);
        lv_arc_set_bg_end_angle(arc_5, 270);
        lv_obj_set_style_arc_color(arc_5, lv_color_hex(0xa855f7), LV_PART_MAIN);
        lv_obj_add_style(arc_5, &style_pie_main, LV_PART_MAIN);
        lv_obj_add_style(arc_5, &style_pie_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(arc_5, &style_pie_knob, LV_PART_KNOB);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

