/**
 * @file button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_gen.h"
#include "../../../lvgl_open_template.h"

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

lv_obj_t * button_create(lv_obj_t * parent, const char * text, const void * icon, lv_color_t bg_color, lv_color_t text_color, int32_t radius)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_button;
    static lv_style_t style_button_pressed;
    static lv_style_t style_button_icon;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_button);
        lv_style_init(&style_button_pressed);
        lv_style_init(&style_button_icon);

        lv_style_set_pad_hor(&style_button, SPACE_LG);
        lv_style_set_pad_ver(&style_button, SPACE_MD);
        lv_style_set_flex_cross_place(&style_button, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_gap(&style_button, SPACE_SM);
        lv_style_set_recolor(&style_button_pressed, COLOR_TRACK);
        lv_style_set_recolor_opa(&style_button_pressed, (255 * 40 / 100));
        lv_style_set_image_recolor_opa(&style_button_icon, (255 * 100 / 100));
        lv_style_set_translate_y(&style_button_icon, -2);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_button_0 = lv_button_create(parent);
        lv_obj_set_name_static(lv_button_0, "button_#");
        lv_obj_set_style_bg_color(lv_button_0, bg_color, 0);
        lv_obj_set_style_text_color(lv_button_0, text_color, 0);
        lv_obj_set_style_radius(lv_button_0, radius, 0);
        lv_obj_set_flex_flow(lv_button_0, LV_FLEX_FLOW_ROW);

        lv_obj_add_style(lv_button_0, &style_button, 0);
        lv_obj_add_style(lv_button_0, &style_button_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_image_0 = lv_image_create(lv_button_0);
        lv_image_set_src(lv_image_0, icon);
        lv_obj_set_flag(lv_image_0, LV_OBJ_FLAG_HIDDEN, !icon);
        lv_obj_set_style_image_recolor(lv_image_0, text_color, 0);
        lv_obj_add_style(lv_image_0, &style_button_icon, 0);

        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_label_set_text(lv_label_0, text);
        lv_obj_set_flag(lv_label_0, LV_OBJ_FLAG_HIDDEN, !text);

        the_root = lv_button_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

