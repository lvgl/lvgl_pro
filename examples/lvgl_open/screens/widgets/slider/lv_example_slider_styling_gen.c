/**
 * @file lv_example_slider_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_slider_styling_gen.h"
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

lv_obj_t * lv_example_slider_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_slider_track;
    static lv_style_t style_slider_indicator;
    static lv_style_t style_slider_knob;
    static lv_style_t style_slider_knob_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_slider_track);
            lv_style_set_bg_opa(&style_slider_track, (255 * 100 / 100));
            lv_style_set_bg_color(&style_slider_track, lv_color_hex(0x1f2937));
            lv_style_set_radius(&style_slider_track, 12);
            lv_style_set_border_color(&style_slider_track, lv_color_hex(0x0f172a));
            lv_style_set_border_width(&style_slider_track, 1);

            lv_style_init(&style_slider_indicator);
            lv_style_set_bg_opa(&style_slider_indicator, (255 * 100 / 100));
            lv_style_set_bg_color(&style_slider_indicator, lv_color_hex(0x8b5cf6));
            lv_style_set_bg_grad_color(&style_slider_indicator, lv_color_hex(0xec4899));
            lv_style_set_bg_grad_dir(&style_slider_indicator, LV_GRAD_DIR_HOR);
            lv_style_set_radius(&style_slider_indicator, 12);
            lv_style_set_shadow_color(&style_slider_indicator, lv_color_hex(0x6d28d9));
            lv_style_set_shadow_width(&style_slider_indicator, 12);
            lv_style_set_shadow_spread(&style_slider_indicator, -1);
            lv_style_set_shadow_opa(&style_slider_indicator, 150);

            lv_style_init(&style_slider_knob);
            lv_style_set_bg_opa(&style_slider_knob, (255 * 100 / 100));
            lv_style_set_bg_color(&style_slider_knob, lv_color_hex(0xffffff));
            lv_style_set_radius(&style_slider_knob, 100);
            lv_style_set_border_color(&style_slider_knob, lv_color_hex(0x8b5cf6));
            lv_style_set_border_width(&style_slider_knob, 3);
            lv_style_set_pad_all(&style_slider_knob, 6);
            lv_style_set_shadow_color(&style_slider_knob, lv_color_hex(0x000000));
            lv_style_set_shadow_width(&style_slider_knob, 8);
            lv_style_set_shadow_offset_y(&style_slider_knob, 2);
            lv_style_set_shadow_opa(&style_slider_knob, 80);

            lv_style_init(&style_slider_knob_pressed);
            lv_style_set_bg_color(&style_slider_knob_pressed, lv_color_hex(0xfff7ed));
            lv_style_set_outline_color(&style_slider_knob_pressed, lv_color_hex(0xec4899));
            lv_style_set_outline_width(&style_slider_knob_pressed, 6);
            lv_style_set_outline_pad(&style_slider_knob_pressed, 4);
            lv_style_set_outline_opa(&style_slider_knob_pressed, 120);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_slider_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 20, 0);

        lv_obj_t * slider = lv_slider_create(lv_obj_0);
        lv_obj_set_name(slider, "slider");
        lv_obj_set_width(slider, lv_pct(90));
        lv_obj_set_height(slider, 22);
        lv_slider_set_min_value(slider, 0);
        lv_slider_set_max_value(slider, 100);
        lv_slider_set_value(slider, 55, false);
        lv_obj_add_style(slider, &style_slider_track, LV_PART_MAIN);
        lv_obj_add_style(slider, &style_slider_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(slider, &style_slider_knob, LV_PART_KNOB);
        lv_obj_add_style(slider, &style_slider_knob_pressed, LV_PART_KNOB | LV_STATE_PRESSED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

