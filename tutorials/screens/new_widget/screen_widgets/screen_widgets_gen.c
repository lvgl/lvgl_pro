/**
 * @file screen_widgets_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_widgets_gen.h"
#include "../../../tutorials.h"

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

lv_obj_t * screen_widgets_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_widgets_#");

        lv_obj_t * wd_segment_0 = wd_segment_create(lv_obj_0);
        lv_obj_set_width(wd_segment_0, 300);
        wd_segment_bind_value(wd_segment_0, &subject_segment);
        lv_obj_set_style_pad_column(wd_segment_0, 1, 0);
        lv_obj_t * wd_segment_button_0 = wd_segment_add_button(wd_segment_0, "Option 1");
        lv_obj_t * wd_segment_button_1 = wd_segment_add_button(wd_segment_0, "Option 2");
        lv_obj_t * wd_segment_button_2 = wd_segment_add_button(wd_segment_0, "Option 3");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

