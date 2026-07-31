/**
 * @file lv_example_bar_modes_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_bar_modes_gen.h"
#include "../../../lvgl_open_examples.h"

/*********************
 *      DEFINES
 *********************/

#define TEXT_COLOR lv_color_hex(0x013992)


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

lv_obj_t * lv_example_bar_modes_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_bar_modes_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * bar_1 = lv_bar_create(lv_obj_0);
        lv_obj_set_name(bar_1, "bar_1");
        lv_obj_set_width(bar_1, lv_pct(90));
        lv_obj_set_height(bar_1, 20);
        lv_bar_set_mode(bar_1, LV_BAR_MODE_NORMAL);
        lv_bar_set_min_value(bar_1, 0);
        lv_bar_set_max_value(bar_1, 100);
        lv_bar_set_value(bar_1, 70, false);
        lv_obj_t * label_1 = lv_label_create(bar_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "normal");
        lv_obj_set_style_text_color(label_1, TEXT_COLOR, 0);

        lv_obj_t * bar_2 = lv_bar_create(lv_obj_0);
        lv_obj_set_name(bar_2, "bar_2");
        lv_obj_set_width(bar_2, lv_pct(90));
        lv_obj_set_height(bar_2, 20);
        lv_bar_set_mode(bar_2, LV_BAR_MODE_SYMMETRICAL);
        lv_bar_set_min_value(bar_2, -100);
        lv_bar_set_max_value(bar_2, 100);
        lv_bar_set_value(bar_2, 45, false);
        lv_obj_t * label_2 = lv_label_create(bar_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "symmetrical");
        lv_obj_set_style_text_color(label_2, TEXT_COLOR, 0);

        lv_obj_t * bar_3 = lv_bar_create(lv_obj_0);
        lv_obj_set_name(bar_3, "bar_3");
        lv_obj_set_width(bar_3, lv_pct(90));
        lv_obj_set_height(bar_3, 20);
        lv_bar_set_mode(bar_3, LV_BAR_MODE_RANGE);
        lv_bar_set_min_value(bar_3, 0);
        lv_bar_set_max_value(bar_3, 100);
        lv_bar_set_start_value(bar_3, 25, false);
        lv_bar_set_value(bar_3, 80, false);
        lv_obj_t * label_3 = lv_label_create(bar_3);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "range");
        lv_obj_set_style_text_color(label_3, TEXT_COLOR, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

