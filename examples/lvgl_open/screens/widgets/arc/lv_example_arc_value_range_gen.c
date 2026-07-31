/**
 * @file lv_example_arc_value_range_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_arc_value_range_gen.h"
#include "../../../lvgl_open_examples.h"

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

lv_obj_t * lv_example_arc_value_range_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_arc_value_range_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * arc_2 = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc_2, "arc_2");
        lv_obj_set_width(arc_2, 120);
        lv_obj_set_height(arc_2, 120);
        lv_arc_set_min_value(arc_2, -20);
        lv_arc_set_max_value(arc_2, 220);
        lv_arc_set_value(arc_2, 140);
        lv_arc_set_bg_start_angle(arc_2, 135);
        lv_arc_set_bg_end_angle(arc_2, 45);
        lv_arc_bind_value(arc_2, &subject_value);
        lv_obj_t * label_4 = lv_label_create(arc_2);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_align(label_4, LV_ALIGN_CENTER);
        lv_obj_set_y(label_4, -10);
        lv_label_bind_text(label_4, &subject_value, NULL);

        lv_obj_t * label_3 = lv_label_create(arc_2);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_obj_set_y(label_3, 10);
        lv_label_set_text(label_3, "[-20..220]");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

