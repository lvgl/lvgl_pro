/**
 * @file bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "bar_gen.h"
#include "../../../lvgl_open_template.h"

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

lv_obj_t * bar_create(lv_obj_t * parent, lv_subject_t * subject, int32_t min, int32_t max, lv_color_t color)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bar_track;
    static lv_style_t style_bar_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_bar_track);
        lv_style_init(&style_bar_indicator);

        lv_style_set_bg_color(&style_bar_track, COLOR_TRACK);
        lv_style_set_bg_opa(&style_bar_track, OPA_MUTED);
        lv_style_set_radius(&style_bar_track, RADIUS_DEFAULT);
        lv_style_set_bg_opa(&style_bar_indicator, (255 * 100 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_bar_0 = lv_bar_create(parent);
        lv_obj_set_name_static(lv_bar_0, "bar_#");
        lv_obj_set_width(lv_bar_0, 200);
        lv_obj_set_height(lv_bar_0, SPACE_MD);
        lv_bar_set_min_value(lv_bar_0, min);
        lv_bar_set_max_value(lv_bar_0, max);
        lv_bar_bind_value(lv_bar_0, subject);
        lv_obj_set_style_bg_color(lv_bar_0, color, LV_PART_INDICATOR);

        lv_obj_add_style(lv_bar_0, &style_bar_track, 0);
        lv_obj_add_style(lv_bar_0, &style_bar_track, LV_PART_INDICATOR);
        lv_obj_add_style(lv_bar_0, &style_bar_indicator, LV_PART_INDICATOR);

        the_root = lv_bar_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

