/**
 * @file sliderbox_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "sliderbox_gen.h"
#include "../tutorials.h"

/*********************
 *      DEFINES
 *********************/

/**
 * Width of the whole slider box
 */
#define WIDTH 200


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

lv_obj_t * sliderbox_create(lv_obj_t * parent, const char * title, lv_subject_t * subject, const char * unit)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dark;

    static bool style_inited = false;

    if (!style_inited) {
        #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
        if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
            lv_style_init(&style_dark);
            lv_style_set_bg_color(&style_dark, lv_color_hex3(0x333));
            lv_style_set_text_color(&style_dark, lv_color_hex3(0xfff));
            lv_style_set_border_color(&style_dark, lv_color_hex3(0x111));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "sliderbox_#");
        lv_obj_set_width(lv_obj_0, WIDTH);
        lv_obj_set_height(lv_obj_0, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_bind_style(lv_obj_0, &style_dark, 0, &subject_dark_mode, 1);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_0, title);
        lv_obj_set_width(lv_label_0, lv_pct(100));
        lv_obj_set_style_text_align(lv_label_0, LV_TEXT_ALIGN_CENTER, 0);

        lv_obj_t * round_button_0 = round_button_create(lv_obj_0, "-", subject, -1);
        lv_obj_set_flag(round_button_0, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK, true);

        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
        lv_obj_set_flex_grow(lv_label_1, 1);
        lv_label_bind_text(lv_label_1, subject, unit);
        lv_obj_set_style_text_align(lv_label_1, LV_TEXT_ALIGN_CENTER, 0);

        round_button_create(lv_obj_0, "+", subject, 1);

        lv_obj_t * lv_slider_0 = lv_slider_create(lv_obj_0);
        lv_slider_bind_value(lv_slider_0, subject);
        lv_obj_set_flag(lv_slider_0, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK, true);
        lv_obj_set_width(lv_slider_0, lv_pct(100));

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

