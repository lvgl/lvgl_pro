/**
 * @file lv_example_spinbox_bind_value_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_spinbox_bind_value_gen.h"
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

lv_obj_t * lv_example_spinbox_bind_value_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_spinbox_bind_value_#");

        lv_obj_t * arc = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc, "arc");
        lv_obj_set_width(arc, 160);
        lv_obj_set_height(arc, 160);
        lv_arc_bind_value(arc, &subject_value);
        lv_obj_set_align(arc, LV_ALIGN_CENTER);
        lv_obj_t * spinbox = lv_spinbox_create(arc);
        lv_obj_set_name(spinbox, "spinbox");
        lv_obj_set_width(spinbox, 80);
        lv_spinbox_set_digit_count(spinbox, 3);
        lv_spinbox_set_min_value(spinbox, 0);
        lv_spinbox_set_max_value(spinbox, 100);
        lv_spinbox_set_step(spinbox, 1);
        lv_spinbox_bind_value(spinbox, &subject_value);
        lv_obj_set_align(spinbox, LV_ALIGN_CENTER);
        lv_obj_set_y(spinbox, -20);

        lv_obj_t * button_1 = lv_button_create(arc);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_set_align(button_1, LV_ALIGN_CENTER);
        lv_obj_set_y(button_1, 20);
        lv_obj_set_x(button_1, -20);
        lv_obj_set_width(button_1, 30);
        lv_obj_set_height(button_1, 30);
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_label_set_text(label_1, "-");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);

        lv_subject_increment_dsc_t * subject_increment_event_0 = lv_obj_add_subject_increment_event(button_1, &subject_value, LV_EVENT_CLICKED, -1);
        lv_subject_increment_dsc_t * subject_increment_event_1 = lv_obj_add_subject_increment_event(button_1, &subject_value, LV_EVENT_LONG_PRESSED_REPEAT, -1);

        lv_obj_t * button_2 = lv_button_create(arc);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_set_align(button_2, LV_ALIGN_CENTER);
        lv_obj_set_y(button_2, 20);
        lv_obj_set_x(button_2, 20);
        lv_obj_set_width(button_2, 30);
        lv_obj_set_height(button_2, 30);
        lv_obj_t * label_2 = lv_label_create(button_2);
        lv_obj_set_name(label_2, "label_2");
        lv_label_set_text(label_2, "+");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);

        lv_subject_increment_dsc_t * subject_increment_event_2 = lv_obj_add_subject_increment_event(button_2, &subject_value, LV_EVENT_CLICKED, 1);
        lv_subject_increment_dsc_t * subject_increment_event_3 = lv_obj_add_subject_increment_event(button_2, &subject_value, LV_EVENT_LONG_PRESSED_REPEAT, 1);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

