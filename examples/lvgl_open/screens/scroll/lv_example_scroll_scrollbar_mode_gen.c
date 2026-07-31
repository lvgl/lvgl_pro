/**
 * @file lv_example_scroll_scrollbar_mode_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_scroll_scrollbar_mode_gen.h"
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

lv_obj_t * lv_example_scroll_scrollbar_mode_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_scroll_scrollbar_mode_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 12, 0);

        lv_obj_t * container_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_1, "container_1");
        lv_obj_set_width(container_1, lv_pct(100));
        lv_obj_set_height(container_1, 160);
        lv_obj_set_flex_flow(container_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(container_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_column(container_1, 16, 0);
        lv_obj_t * container_2 = lv_obj_create(container_1);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_width(container_2, 130);
        lv_obj_set_height(container_2, lv_pct(100));
        lv_obj_set_flex_flow(container_2, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(container_2, 8, 0);
        lv_obj_set_scrollbar_mode(container_2, LV_SCROLLBAR_MODE_OFF);
        lv_obj_t * label_1 = lv_label_create(container_2);
        lv_obj_set_name(label_1, "label_1");
        lv_label_set_text(label_1, "mode: off");

        lv_obj_t * button_1 = lv_button_create(container_2);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_set_width(button_1, lv_pct(100));
        lv_obj_t * label_2 = lv_label_create(button_1);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "A");

        lv_obj_t * button_2 = lv_button_create(container_2);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_set_width(button_2, lv_pct(100));
        lv_obj_t * label_3 = lv_label_create(button_2);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "B");

        lv_obj_t * button_3 = lv_button_create(container_2);
        lv_obj_set_name(button_3, "button_3");
        lv_obj_set_width(button_3, lv_pct(100));
        lv_obj_t * label_4 = lv_label_create(button_3);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_align(label_4, LV_ALIGN_CENTER);
        lv_label_set_text(label_4, "C");

        lv_obj_t * button_4 = lv_button_create(container_2);
        lv_obj_set_name(button_4, "button_4");
        lv_obj_set_width(button_4, lv_pct(100));
        lv_obj_t * label_5 = lv_label_create(button_4);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_align(label_5, LV_ALIGN_CENTER);
        lv_label_set_text(label_5, "D");

        lv_obj_t * container_3 = lv_obj_create(container_1);
        lv_obj_set_name(container_3, "container_3");
        lv_obj_set_width(container_3, 130);
        lv_obj_set_height(container_3, lv_pct(100));
        lv_obj_set_flex_flow(container_3, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(container_3, 8, 0);
        lv_obj_set_scrollbar_mode(container_3, LV_SCROLLBAR_MODE_ON);
        lv_obj_set_style_bg_color(container_3, lv_color_hex(0x9429ff), LV_PART_SCROLLBAR);
        lv_obj_set_style_bg_opa(container_3, (255 * 100 / 100), LV_PART_SCROLLBAR);
        lv_obj_t * label_6 = lv_label_create(container_3);
        lv_obj_set_name(label_6, "label_6");
        lv_label_set_text(label_6, "mode: on");

        lv_obj_t * button_5 = lv_button_create(container_3);
        lv_obj_set_name(button_5, "button_5");
        lv_obj_set_width(button_5, lv_pct(100));
        lv_obj_t * label_7 = lv_label_create(button_5);
        lv_obj_set_name(label_7, "label_7");
        lv_obj_set_align(label_7, LV_ALIGN_CENTER);
        lv_label_set_text(label_7, "A");

        lv_obj_t * button_6 = lv_button_create(container_3);
        lv_obj_set_name(button_6, "button_6");
        lv_obj_set_width(button_6, lv_pct(100));
        lv_obj_t * label_8 = lv_label_create(button_6);
        lv_obj_set_name(label_8, "label_8");
        lv_obj_set_align(label_8, LV_ALIGN_CENTER);
        lv_label_set_text(label_8, "B");

        lv_obj_t * button_7 = lv_button_create(container_3);
        lv_obj_set_name(button_7, "button_7");
        lv_obj_set_width(button_7, lv_pct(100));
        lv_obj_t * label_9 = lv_label_create(button_7);
        lv_obj_set_name(label_9, "label_9");
        lv_obj_set_align(label_9, LV_ALIGN_CENTER);
        lv_label_set_text(label_9, "C");

        lv_obj_t * button_8 = lv_button_create(container_3);
        lv_obj_set_name(button_8, "button_8");
        lv_obj_set_width(button_8, lv_pct(100));
        lv_obj_t * label_10 = lv_label_create(button_8);
        lv_obj_set_name(label_10, "label_10");
        lv_obj_set_align(label_10, LV_ALIGN_CENTER);
        lv_label_set_text(label_10, "D");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

