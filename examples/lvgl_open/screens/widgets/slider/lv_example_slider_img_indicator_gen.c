/**
 * @file lv_example_slider_img_indicator_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_slider_img_indicator_gen.h"
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

lv_obj_t * lv_example_slider_img_indicator_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_slider_track;
    static lv_style_t style_slider_indicator;
    static lv_style_t style_slider_knob;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_slider_track);
            lv_style_set_bg_image_src(&style_slider_track, img_bar_bg);
            lv_style_set_bg_opa(&style_slider_track, 0);
            lv_style_set_radius(&style_slider_track, 0);

            lv_style_init(&style_slider_indicator);
            lv_style_set_bg_image_src(&style_slider_indicator, img_bar_indicator);
            lv_style_set_bg_opa(&style_slider_indicator, 0);
            lv_style_set_radius(&style_slider_indicator, 0);

            lv_style_init(&style_slider_knob);
            lv_style_set_bg_opa(&style_slider_knob, (255 * 100 / 100));
            lv_style_set_bg_color(&style_slider_knob, lv_color_hex(0x101820));
            lv_style_set_radius(&style_slider_knob, 4);
            lv_style_set_border_color(&style_slider_knob, lv_color_hex(0x00d4ff));
            lv_style_set_border_width(&style_slider_knob, 2);
            lv_style_set_pad_hor(&style_slider_knob, 0);
            lv_style_set_pad_ver(&style_slider_knob, 6);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_slider_img_indicator_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * slider = lv_slider_create(lv_obj_0);
        lv_obj_set_name(slider, "slider");
        lv_obj_set_width(slider, 280);
        lv_obj_set_height(slider, 30);
        lv_slider_set_min_value(slider, 0);
        lv_slider_set_max_value(slider, 20);
        lv_slider_bind_value(slider, &subject_value2);
        lv_obj_add_style(slider, &style_slider_track, LV_PART_MAIN);
        lv_obj_add_style(slider, &style_slider_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(slider, &style_slider_knob, LV_PART_KNOB);

        lv_obj_t * label = lv_label_create(lv_obj_0);
        lv_obj_set_name(label, "label");
        lv_label_bind_text(label, &subject_value2, "%d");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

