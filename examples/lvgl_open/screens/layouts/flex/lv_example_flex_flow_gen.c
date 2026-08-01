/**
 * @file lv_example_flex_flow_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_flex_flow_gen.h"
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

lv_obj_t * lv_example_flex_flow_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_flex_flow_#");

        lv_obj_t * example_flex_flow = lv_obj_create(lv_obj_0);
        lv_obj_set_align(example_flex_flow, LV_ALIGN_CENTER);
        lv_obj_set_flex_flow(example_flex_flow, LV_FLEX_FLOW_ROW_WRAP);
        lv_obj_set_width(example_flex_flow, lv_pct(90));
        lv_obj_set_height(example_flex_flow, lv_pct(50));
        lv_obj_set_name(example_flex_flow, "example_flex_flow");
        lv_obj_t * button_1 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_label_set_text(label_1, "First");

        lv_obj_t * button_2 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_t * label_2 = lv_label_create(button_2);
        lv_obj_set_name(label_2, "label_2");
        lv_label_set_text(label_2, "Second");

        lv_obj_t * button_3 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_3, "button_3");
        lv_obj_t * label_3 = lv_label_create(button_3);
        lv_obj_set_name(label_3, "label_3");
        lv_label_set_text(label_3, "Third");

        lv_obj_t * button_4 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_4, "button_4");
        lv_obj_t * label_4 = lv_label_create(button_4);
        lv_obj_set_name(label_4, "label_4");
        lv_label_set_text(label_4, "Forth");

        lv_obj_t * button_5 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_5, "button_5");
        lv_obj_t * label_5 = lv_label_create(button_5);
        lv_obj_set_name(label_5, "label_5");
        lv_label_set_text(label_5, "Fifth");

        lv_obj_t * button_6 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_6, "button_6");
        lv_obj_t * label_6 = lv_label_create(button_6);
        lv_obj_set_name(label_6, "label_6");
        lv_label_set_text(label_6, "Sixth");

        lv_obj_t * button_7 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_7, "button_7");
        lv_obj_t * label_7 = lv_label_create(button_7);
        lv_obj_set_name(label_7, "label_7");
        lv_label_set_text(label_7, "Seventh");

        lv_obj_t * button_8 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_8, "button_8");
        lv_obj_t * label_8 = lv_label_create(button_8);
        lv_obj_set_name(label_8, "label_8");
        lv_label_set_text(label_8, "Eighth");

        lv_obj_t * button_9 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_9, "button_9");
        lv_obj_t * label_9 = lv_label_create(button_9);
        lv_obj_set_name(label_9, "label_9");
        lv_label_set_text(label_9, "Ninth");

        lv_obj_t * button_10 = lv_button_create(example_flex_flow);
        lv_obj_set_name(button_10, "button_10");
        lv_obj_t * label_10 = lv_label_create(button_10);
        lv_obj_set_name(label_10, "label_10");
        lv_label_set_text(label_10, "Tenth");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

