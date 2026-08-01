/**
 * @file switch_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "switch_gen.h"
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

lv_obj_t * switch_create(lv_obj_t * parent, lv_subject_t * subject, lv_color_t color)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_checked;
    static lv_style_t style_knob;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);
        lv_style_init(&style_checked);
        lv_style_init(&style_knob);

        lv_style_set_radius(&style_main, 100);
        lv_style_set_bg_color(&style_main, COLOR_TRACK);
        lv_style_set_bg_opa(&style_main, OPA_MUTED);
        lv_style_set_radius(&style_checked, 100);
        lv_style_set_bg_opa(&style_checked, (255 * 100 / 100));
        lv_style_set_radius(&style_knob, 100);
        lv_style_set_bg_color(&style_knob, COLOR_ACCENT_TEXT);
        lv_style_set_pad_all(&style_knob, -2);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_switch_0 = lv_switch_create(parent);
        lv_obj_set_name_static(lv_switch_0, "switch_#");
        lv_obj_bind_checked(lv_switch_0, subject);
        lv_obj_set_style_bg_color(lv_switch_0, color, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_set_width(lv_switch_0, 55);
        lv_obj_set_height(lv_switch_0, 30);

        lv_obj_add_style(lv_switch_0, &style_main, 0);
        lv_obj_add_style(lv_switch_0, &style_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_add_style(lv_switch_0, &style_knob, LV_PART_KNOB);

        the_root = lv_switch_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

