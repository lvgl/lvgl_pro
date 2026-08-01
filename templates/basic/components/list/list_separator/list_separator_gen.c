/**
 * @file list_separator_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_separator_gen.h"
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

lv_obj_t * list_separator_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_list_separator;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_list_separator);

        lv_style_set_bg_color(&style_list_separator, COLOR_TRACK);
        lv_style_set_bg_opa(&style_list_separator, (255 * 25 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * container_0 = container_create(parent, 8, 0, LV_FLEX_FLOW_COLUMN, 0);
        lv_obj_set_name_static(container_0, "list_separator_#");
        lv_obj_set_width(container_0, lv_pct(100));
        lv_obj_set_height(container_0, 1);

        lv_obj_add_style(container_0, &style_list_separator, 0);

        the_root = container_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

