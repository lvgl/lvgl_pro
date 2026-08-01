/**
 * @file lv_example_flex_ignore_layout_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_flex_ignore_layout_gen.h"
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

lv_obj_t * lv_example_flex_ignore_layout_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_flex_ignore_layout_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
        lv_obj_set_width(container, lv_pct(90));
        lv_obj_set_height(container, 150);
        lv_obj_t * button_1 = lv_button_create(container);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_set_height(button_1, LV_SIZE_CONTENT);
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_label_set_text(label_1, "Item A");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);

        lv_obj_t * button_2 = lv_button_create(container);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_set_align(button_2, LV_ALIGN_CENTER);
        lv_obj_set_flag(button_2, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_style_bg_color(button_2, lv_color_hex(0xe74c3c), 0);
        lv_obj_t * label_2 = lv_label_create(button_2);
        lv_obj_set_name(label_2, "label_2");
        lv_label_set_text(label_2, "I'm Free!");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);

        lv_obj_t * button_3 = lv_button_create(container);
        lv_obj_set_name(button_3, "button_3");
        lv_obj_t * label_3 = lv_label_create(button_3);
        lv_obj_set_name(label_3, "label_3");
        lv_label_set_text(label_3, "Item B");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);

        lv_obj_t * button_4 = lv_button_create(container);
        lv_obj_set_name(button_4, "button_4");
        lv_obj_set_height(button_4, LV_SIZE_CONTENT);
        lv_obj_t * label_4 = lv_label_create(button_4);
        lv_obj_set_name(label_4, "label_4");
        lv_label_set_text(label_4, "Item C");
        lv_obj_set_align(label_4, LV_ALIGN_CENTER);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

