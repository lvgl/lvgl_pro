/**
 * @file checkbox_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "checkbox_gen.h"
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

lv_obj_t * checkbox_create(lv_obj_t * parent, const char * text, lv_subject_t * subject, lv_color_t color)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_checkbox;
    static lv_style_t style_box;
    static lv_style_t style_box_checked;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_checkbox);
        lv_style_init(&style_box);
        lv_style_init(&style_box_checked);

        lv_style_set_pad_column(&style_checkbox, SPACE_SM);
        lv_style_set_radius(&style_box, SPACE_SM);
        lv_style_set_border_width(&style_box, BORDER_WIDTH);
        lv_style_set_border_color(&style_box, COLOR_TRACK);
        lv_style_set_bg_opa(&style_box, (255 * 0 / 100));
        lv_style_set_pad_all(&style_box, 2);
        lv_style_set_bg_opa(&style_box_checked, (255 * 100 / 100));
        lv_style_set_bg_image_src(&style_box_checked, icon_check);
        lv_style_set_bg_image_recolor(&style_box_checked, lv_color_hex3(0xfff));
        lv_style_set_bg_image_recolor_opa(&style_box_checked, (255 * 100 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_checkbox_0 = lv_checkbox_create(parent);
        lv_obj_set_name_static(lv_checkbox_0, "checkbox_#");
        lv_checkbox_set_text(lv_checkbox_0, text);
        lv_obj_bind_checked(lv_checkbox_0, subject);
        lv_obj_set_style_bg_color(lv_checkbox_0, color, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_set_style_border_color(lv_checkbox_0, color, LV_PART_INDICATOR | LV_STATE_CHECKED);

        lv_obj_add_style(lv_checkbox_0, &style_checkbox, 0);
        lv_obj_add_style(lv_checkbox_0, &style_box, LV_PART_INDICATOR);
        lv_obj_add_style(lv_checkbox_0, &style_box_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

        the_root = lv_checkbox_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

