/**
 * @file lv_example_slider_modes_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_slider_modes_gen.h"
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

lv_obj_t * lv_example_slider_modes_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_slider_modes_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * slider_1 = lv_slider_create(lv_obj_0);
        lv_obj_set_name(slider_1, "slider_1");
        lv_obj_set_width(slider_1, lv_pct(90));
        lv_obj_set_height(slider_1, 20);
        lv_slider_set_mode(slider_1, LV_SLIDER_MODE_NORMAL);
        lv_slider_set_min_value(slider_1, 0);
        lv_slider_set_max_value(slider_1, 100);
        lv_slider_set_value(slider_1, 70, false);
        lv_obj_t * label_1 = lv_label_create(slider_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "Normal");
        lv_obj_set_style_text_color(label_1, TEXT_COLOR, 0);

        lv_obj_t * slider_2 = lv_slider_create(lv_obj_0);
        lv_obj_set_name(slider_2, "slider_2");
        lv_obj_set_width(slider_2, lv_pct(90));
        lv_obj_set_height(slider_2, 20);
        lv_slider_set_mode(slider_2, LV_SLIDER_MODE_SYMMETRICAL);
        lv_slider_set_min_value(slider_2, -100);
        lv_slider_set_max_value(slider_2, 100);
        lv_slider_set_value(slider_2, 45, false);
        lv_obj_t * label_2 = lv_label_create(slider_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Symmetrical");
        lv_obj_set_style_text_color(label_2, TEXT_COLOR, 0);

        lv_obj_t * slider_3 = lv_slider_create(lv_obj_0);
        lv_obj_set_name(slider_3, "slider_3");
        lv_obj_set_width(slider_3, lv_pct(90));
        lv_obj_set_height(slider_3, 20);
        lv_slider_set_mode(slider_3, LV_SLIDER_MODE_RANGE);
        lv_slider_set_min_value(slider_3, 0);
        lv_slider_set_max_value(slider_3, 100);
        lv_slider_set_start_value(slider_3, 25, false);
        lv_slider_set_value(slider_3, 80, false);
        lv_obj_t * label_3 = lv_label_create(slider_3);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "Range");
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

