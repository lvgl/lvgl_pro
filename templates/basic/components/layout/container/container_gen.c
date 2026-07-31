/**
 * @file container_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "container_gen.h"
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

lv_obj_t * container_create(lv_obj_t * parent, int32_t pad, int32_t gap, lv_flex_flow_t flow, int32_t grow)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * base_box_0 = base_box_create(parent);
        lv_obj_set_name_static(base_box_0, "container_#");
        lv_obj_set_flex_grow(base_box_0, grow);
        lv_obj_set_style_pad_all(base_box_0, pad, 0);
        lv_obj_set_style_pad_row(base_box_0, gap, 0);
        lv_obj_set_style_pad_column(base_box_0, gap, 0);
        lv_obj_set_flex_flow(base_box_0, flow);

        the_root = base_box_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

