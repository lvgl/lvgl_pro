/**
 * @file column_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "column_gen.h"
#include "../../tutorials.h"

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

lv_obj_t * column_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;

    static bool style_inited = false;

    if (!style_inited) {
        #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
        if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
            lv_style_init(&style_base);
            lv_style_set_width(&style_base, LV_SIZE_CONTENT);
            lv_style_set_height(&style_base, LV_SIZE_CONTENT);
            lv_style_set_layout(&style_base, LV_LAYOUT_FLEX);
            lv_style_set_flex_flow(&style_base, LV_FLEX_FLOW_COLUMN);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "column_#");

        lv_obj_remove_style_all(lv_obj_0);
        lv_obj_add_style(lv_obj_0, &style_base, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

