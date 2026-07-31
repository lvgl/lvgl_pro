/**
 * @file lv_example_scroll_one_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_scroll_one_gen.h"
#include "../../lvgl_open_examples.h"

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

lv_obj_t * lv_example_scroll_one_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_scroll_one_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 12, 0);

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_width(container, 300);
        lv_obj_set_height(container, 150);
        lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_pad_column(container, 10, 0);
        lv_obj_set_scroll_snap_x(container, LV_SCROLL_SNAP_CENTER);
        lv_obj_set_flag(container, LV_OBJ_FLAG_SCROLL_ONE, true);
        lv_obj_t * button_1 = lv_button_create(container);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_set_width(button_1, 80);
        lv_obj_set_height(button_1, lv_pct(100));
        lv_obj_set_flag(button_1, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "Panel 1");

        lv_obj_t * button_2 = lv_button_create(container);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_set_width(button_2, 80);
        lv_obj_set_height(button_2, lv_pct(100));
        lv_obj_set_flag(button_2, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_2 = lv_label_create(button_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Panel 2");

        lv_obj_t * button_3 = lv_button_create(container);
        lv_obj_set_name(button_3, "button_3");
        lv_obj_set_width(button_3, 80);
        lv_obj_set_height(button_3, lv_pct(100));
        lv_obj_set_flag(button_3, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_3 = lv_label_create(button_3);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "Panel 3");

        lv_obj_t * button_4 = lv_button_create(container);
        lv_obj_set_name(button_4, "button_4");
        lv_obj_set_width(button_4, 80);
        lv_obj_set_height(button_4, lv_pct(100));
        lv_obj_set_flag(button_4, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_4 = lv_label_create(button_4);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_align(label_4, LV_ALIGN_CENTER);
        lv_label_set_text(label_4, "Panel 4");

        lv_obj_t * button_5 = lv_button_create(container);
        lv_obj_set_name(button_5, "button_5");
        lv_obj_set_width(button_5, 80);
        lv_obj_set_height(button_5, lv_pct(100));
        lv_obj_set_flag(button_5, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_5 = lv_label_create(button_5);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_align(label_5, LV_ALIGN_CENTER);
        lv_label_set_text(label_5, "Panel 5");

        lv_obj_t * button_6 = lv_button_create(container);
        lv_obj_set_name(button_6, "button_6");
        lv_obj_set_width(button_6, 80);
        lv_obj_set_height(button_6, lv_pct(100));
        lv_obj_set_flag(button_6, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_6 = lv_label_create(button_6);
        lv_obj_set_name(label_6, "label_6");
        lv_obj_set_align(label_6, LV_ALIGN_CENTER);
        lv_label_set_text(label_6, "Panel 6");

        lv_obj_t * button_7 = lv_button_create(container);
        lv_obj_set_name(button_7, "button_7");
        lv_obj_set_width(button_7, 80);
        lv_obj_set_height(button_7, lv_pct(100));
        lv_obj_set_flag(button_7, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_7 = lv_label_create(button_7);
        lv_obj_set_name(label_7, "label_7");
        lv_obj_set_align(label_7, LV_ALIGN_CENTER);
        lv_label_set_text(label_7, "Panel 7");

        lv_obj_t * button_8 = lv_button_create(container);
        lv_obj_set_name(button_8, "button_8");
        lv_obj_set_width(button_8, 80);
        lv_obj_set_height(button_8, lv_pct(100));
        lv_obj_set_flag(button_8, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_8 = lv_label_create(button_8);
        lv_obj_set_name(label_8, "label_8");
        lv_obj_set_align(label_8, LV_ALIGN_CENTER);
        lv_label_set_text(label_8, "Panel 8");

        lv_obj_t * button_9 = lv_button_create(container);
        lv_obj_set_name(button_9, "button_9");
        lv_obj_set_width(button_9, 80);
        lv_obj_set_height(button_9, lv_pct(100));
        lv_obj_set_flag(button_9, LV_OBJ_FLAG_SCROLL_ON_FOCUS, false);
        lv_obj_t * label_9 = lv_label_create(button_9);
        lv_obj_set_name(label_9, "label_9");
        lv_obj_set_align(label_9, LV_ALIGN_CENTER);
        lv_label_set_text(label_9, "Panel 9");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

