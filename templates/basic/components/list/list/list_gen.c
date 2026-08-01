/**
 * @file list_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_gen.h"
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

lv_obj_t * list_create(lv_obj_t * parent, int32_t pad, int32_t grow)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * panel_0 = panel_create(parent, pad, 0, LV_FLEX_FLOW_COLUMN, grow);
        lv_obj_set_name_static(panel_0, "list_#");
        lv_obj_set_width(panel_0, 200);

        the_root = panel_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

