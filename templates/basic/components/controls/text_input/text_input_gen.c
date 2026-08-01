/**
 * @file text_input_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "text_input_gen.h"
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

lv_obj_t * text_input_create(lv_obj_t * parent, const char * text, const char * placeholder, bool password)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_text_input;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_text_input);

        lv_style_set_radius(&style_text_input, RADIUS_DEFAULT);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * text_box_0 = text_box_create(parent, text, "Write here...");
        lv_obj_set_name_static(text_box_0, "text_input_#");
        lv_textarea_set_one_line(text_box_0, true);
        lv_obj_set_width(text_box_0, 200);
        lv_textarea_set_placeholder_text(text_box_0, placeholder);
        lv_textarea_set_password_mode(text_box_0, password);

        lv_obj_add_style(text_box_0, &style_text_input, 0);

        the_root = text_box_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

