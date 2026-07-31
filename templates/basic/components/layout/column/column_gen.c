/**
 * @file column_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "column_gen.h"
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

lv_obj_t * column_create(lv_obj_t * parent, int32_t pad, int32_t gap, int32_t grow, lv_flex_align_t horizontal_align, lv_flex_align_t vertical_align, lv_flex_align_t content_align)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * container_0 = container_create(parent, pad, gap, LV_FLEX_FLOW_COLUMN, grow);
        lv_obj_set_name_static(container_0, "column_#");
        lv_obj_set_style_flex_cross_place(container_0, horizontal_align, 0);
        lv_obj_set_style_flex_main_place(container_0, vertical_align, 0);
        lv_obj_set_style_flex_track_place(container_0, content_align, 0);

        the_root = container_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

