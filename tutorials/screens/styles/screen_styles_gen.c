/**
 * @file screen_styles_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_styles_gen.h"
#include "../../tutorials.h"

/*********************
 *      DEFINES
 *********************/

#define MAIN_COLOR lv_color_hex(0x7a00ff)
#define SECONDARY_COLOR lv_color_hex(0xfaab44)


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

lv_obj_t * screen_styles_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_main_dark;
    static lv_style_t style_indicator;
    static lv_style_t style_knob;

    static bool style_inited = false;

    if (!style_inited) {
        #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
        if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
            lv_style_init(&style_main);
            lv_style_set_bg_color(&style_main, lv_color_hex3(0x333));
            lv_style_set_bg_opa(&style_main, (255 * 30 / 100));
            lv_style_set_radius(&style_main, 2);

            lv_style_init(&style_main_dark);
            lv_style_set_bg_color(&style_main_dark, MAIN_COLOR);

            lv_style_init(&style_indicator);
            lv_style_set_bg_color(&style_indicator, MAIN_COLOR);
            lv_style_set_radius(&style_indicator, 2);

            lv_style_init(&style_knob);
            lv_style_set_bg_color(&style_knob, MAIN_COLOR);
            lv_style_set_radius(&style_knob, 4);
            lv_style_set_pad_all(&style_knob, 6);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_styles_#");

        lv_obj_t * lv_slider_0 = lv_slider_create(lv_obj_0);
        lv_obj_set_align(lv_slider_0, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_slider_0, -20);
        lv_slider_set_value(lv_slider_0, 20, false);
        lv_obj_add_style(lv_slider_0, &style_main, 0);
        lv_obj_add_style(lv_slider_0, &style_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(lv_slider_0, &style_knob, LV_PART_KNOB);
        lv_obj_bind_style(lv_slider_0, &style_main_dark, 0, &subject_dark_mode, 1);

        lv_obj_t * lv_slider_1 = lv_slider_create(lv_obj_0);
        lv_obj_set_align(lv_slider_1, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_slider_1, 20);
        lv_slider_set_value(lv_slider_1, 30, false);
        lv_obj_set_style_bg_color(lv_slider_1, SECONDARY_COLOR, LV_PART_INDICATOR);
        lv_obj_add_style(lv_slider_1, &style_main, 0);
        lv_obj_add_style(lv_slider_1, &style_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(lv_slider_1, &style_knob, LV_PART_KNOB);
        lv_obj_bind_style(lv_slider_1, &style_main_dark, 0, &subject_dark_mode, 1);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

