/**
 * @file slider_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "slider_gen.h"
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

lv_obj_t * slider_create(lv_obj_t * parent, lv_subject_t * subject, int32_t min, int32_t max, lv_color_t color)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_slider_track;
    static lv_style_t style_slider_indicator;
    static lv_style_t style_slider_knob;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_slider_track);
        lv_style_init(&style_slider_indicator);
        lv_style_init(&style_slider_knob);

        lv_style_set_bg_color(&style_slider_track, COLOR_TRACK);
        lv_style_set_bg_opa(&style_slider_track, OPA_MUTED);
        lv_style_set_radius(&style_slider_track, 100);
        lv_style_set_bg_opa(&style_slider_indicator, (255 * 100 / 100));
        lv_style_set_radius(&style_slider_knob, 100);
        lv_style_set_pad_all(&style_slider_knob, SPACE_SM);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_slider_0 = lv_slider_create(parent);
        lv_obj_set_name_static(lv_slider_0, "slider_#");
        lv_obj_set_width(lv_slider_0, 200);
        lv_obj_set_height(lv_slider_0, SPACE_MD);
        lv_slider_set_min_value(lv_slider_0, min);
        lv_slider_set_max_value(lv_slider_0, max);
        lv_slider_bind_value(lv_slider_0, subject);
        lv_obj_set_style_bg_color(lv_slider_0, color, LV_PART_INDICATOR);
        lv_obj_set_style_bg_color(lv_slider_0, color, LV_PART_KNOB);

        lv_obj_add_style(lv_slider_0, &style_slider_track, 0);
        lv_obj_add_style(lv_slider_0, &style_slider_track, LV_PART_INDICATOR);
        lv_obj_add_style(lv_slider_0, &style_slider_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(lv_slider_0, &style_slider_knob, LV_PART_KNOB);

        the_root = lv_slider_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

