/**
 * @file lv_example_arc_img_indicator_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_arc_img_indicator_gen.h"
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

lv_obj_t * lv_example_arc_img_indicator_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_arc_bg;
    static lv_style_t style_arc_indicator;
    static lv_style_t style_arc_knob;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_arc_bg);
            lv_style_set_arc_image_src(&style_arc_bg, img_arc_bg);
            lv_style_set_arc_width(&style_arc_bg, 40);
            lv_style_set_arc_rounded(&style_arc_bg, false);

            lv_style_init(&style_arc_indicator);
            lv_style_set_arc_image_src(&style_arc_indicator, img_arc_indicator);
            lv_style_set_arc_width(&style_arc_indicator, 40);
            lv_style_set_arc_rounded(&style_arc_indicator, false);

            lv_style_init(&style_arc_knob);
            lv_style_set_opa(&style_arc_knob, 0);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_arc_img_indicator_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 0, 0);

        lv_obj_t * arc = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc, "arc");
        lv_obj_set_width(arc, 200);
        lv_obj_set_height(arc, 200);
        lv_arc_set_min_value(arc, 0);
        lv_arc_set_max_value(arc, 22);
        lv_arc_set_bg_start_angle(arc, 138);
        lv_arc_set_bg_end_angle(arc, 41);
        lv_arc_bind_value(arc, &subject_value2);
        lv_obj_add_style(arc, &style_arc_bg, LV_PART_MAIN);
        lv_obj_add_style(arc, &style_arc_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(arc, &style_arc_knob, LV_PART_KNOB);
        lv_obj_t * label = lv_label_create(arc);
        lv_obj_set_name(label, "label");
        lv_obj_set_align(label, LV_ALIGN_CENTER);
        lv_label_bind_text(label, &subject_value2, NULL);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

