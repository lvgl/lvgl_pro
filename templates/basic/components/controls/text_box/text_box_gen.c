/**
 * @file text_box_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "text_box_gen.h"
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

lv_obj_t * text_box_create(lv_obj_t * parent, const char * text, const char * placeholder)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_textarea_0 = lv_textarea_create(parent);
        lv_obj_set_name_static(lv_textarea_0, "text_box_#");
        lv_obj_set_width(lv_textarea_0, 260);
        lv_obj_set_height(lv_textarea_0, 120);
        lv_textarea_set_text(lv_textarea_0, text);
        lv_textarea_set_placeholder_text(lv_textarea_0, placeholder);

        lv_obj_add_style(lv_textarea_0, &style_panel_light, 0);
        lv_obj_bind_style(lv_textarea_0, &style_panel_dark, 0, &subject_theme_dark, 1);
        lv_obj_add_style(lv_textarea_0, &style_text_muted, LV_PART_TEXTAREA_PLACEHOLDER);

        the_root = lv_textarea_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

