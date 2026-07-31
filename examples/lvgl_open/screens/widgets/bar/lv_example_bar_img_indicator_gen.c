/**
 * @file lv_example_bar_img_indicator_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_bar_img_indicator_gen.h"
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

lv_obj_t * lv_example_bar_img_indicator_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bar_track;
    static lv_style_t style_bar_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_bar_track);
            lv_style_set_bg_image_src(&style_bar_track, img_bar_bg);
            lv_style_set_bg_opa(&style_bar_track, 0);
            lv_style_set_radius(&style_bar_track, 0);

            lv_style_init(&style_bar_indicator);
            lv_style_set_bg_image_src(&style_bar_indicator, img_bar_indicator);
            lv_style_set_bg_opa(&style_bar_indicator, 0);
            lv_style_set_radius(&style_bar_indicator, 0);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_bar_img_indicator_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * bar = lv_bar_create(lv_obj_0);
        lv_obj_set_name(bar, "bar");
        lv_obj_set_width(bar, 280);
        lv_obj_set_height(bar, 35);
        lv_bar_set_min_value(bar, 0);
        lv_bar_set_max_value(bar, 20);
        lv_bar_bind_value(bar, &subject_value2);
        lv_obj_add_style(bar, &style_bar_track, LV_PART_MAIN);
        lv_obj_add_style(bar, &style_bar_indicator, LV_PART_INDICATOR);

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(container, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(container, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_pad_column(container, 12, 0);
        lv_obj_set_style_bg_opa(container, 0, 0);
        lv_obj_set_style_border_width(container, 0, 0);
        lv_obj_set_width(container, 180);
        lv_obj_set_height(container, LV_SIZE_CONTENT);
        lv_obj_t * button_1 = lv_button_create(container);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "-");

        lv_subject_increment_dsc_t * subject_increment_event_0 = lv_obj_add_subject_increment_event(button_1, &subject_value2, LV_EVENT_CLICKED, -1);
        lv_subject_increment_dsc_t * subject_increment_event_1 = lv_obj_add_subject_increment_event(button_1, &subject_value2, LV_EVENT_LONG_PRESSED_REPEAT, -1);

        lv_obj_t * label_2 = lv_label_create(container);
        lv_obj_set_name(label_2, "label_2");
        lv_label_bind_text(label_2, &subject_value2, NULL);

        lv_obj_t * button_2 = lv_button_create(container);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_t * label_3 = lv_label_create(button_2);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "+");

        lv_subject_increment_dsc_t * subject_increment_event_2 = lv_obj_add_subject_increment_event(button_2, &subject_value2, LV_EVENT_CLICKED, 1);
        lv_subject_increment_dsc_t * subject_increment_event_3 = lv_obj_add_subject_increment_event(button_2, &subject_value2, LV_EVENT_LONG_PRESSED_REPEAT, 1);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

