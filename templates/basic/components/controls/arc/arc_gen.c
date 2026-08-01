/**
 * @file arc_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "arc_gen.h"
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

lv_obj_t * arc_create(lv_obj_t * parent, lv_subject_t * subject, int32_t min, int32_t max, lv_color_t color)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_arc_track;
    static lv_style_t style_arc_ind;
    static lv_style_t style_arc_knob;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_arc_track);
        lv_style_init(&style_arc_ind);
        lv_style_init(&style_arc_knob);

        lv_style_set_arc_width(&style_arc_track, SPACE_MD);
        lv_style_set_arc_color(&style_arc_track, COLOR_TRACK);
        lv_style_set_arc_opa(&style_arc_track, (255 * 35 / 100));
        lv_style_set_arc_rounded(&style_arc_track, true);
        lv_style_set_arc_width(&style_arc_ind, SPACE_MD);
        lv_style_set_arc_rounded(&style_arc_ind, true);
        lv_style_set_pad_all(&style_arc_knob, SPACE_SM);
        lv_style_set_radius(&style_arc_knob, 100);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_arc_0 = lv_arc_create(parent);
        lv_obj_set_name_static(lv_arc_0, "arc_#");
        lv_obj_set_width(lv_arc_0, 100);
        lv_obj_set_height(lv_arc_0, 100);
        lv_arc_set_min_value(lv_arc_0, min);
        lv_arc_set_max_value(lv_arc_0, max);
        lv_arc_bind_value(lv_arc_0, subject);
        lv_obj_set_style_arc_color(lv_arc_0, color, LV_PART_INDICATOR);
        lv_obj_set_style_bg_color(lv_arc_0, color, LV_PART_KNOB);

        lv_obj_add_style(lv_arc_0, &style_arc_track, 0);
        lv_obj_add_style(lv_arc_0, &style_arc_ind, LV_PART_INDICATOR);
        lv_obj_add_style(lv_arc_0, &style_arc_knob, LV_PART_KNOB);

        the_root = lv_arc_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

