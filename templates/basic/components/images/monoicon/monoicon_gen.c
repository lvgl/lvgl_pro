/**
 * @file monoicon_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "monoicon_gen.h"
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

lv_obj_t * monoicon_create(lv_obj_t * parent, const void * src)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_monoicon_light;
    static lv_style_t style_monoicon_dark;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_monoicon_light);
        lv_style_init(&style_monoicon_dark);

        lv_style_set_image_recolor(&style_monoicon_light, COLOR_LIGHT_TEXT);
        lv_style_set_image_recolor_opa(&style_monoicon_light, (255 * 100 / 100));
        lv_style_set_image_recolor(&style_monoicon_dark, COLOR_DARK_TEXT);
        lv_style_set_image_recolor_opa(&style_monoicon_dark, (255 * 100 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * image_0 = image_create(parent, src);
        lv_obj_set_name_static(image_0, "monoicon_#");

        lv_obj_add_style(image_0, &style_monoicon_light, 0);
        lv_obj_bind_style(image_0, &style_monoicon_dark, 0, &subject_theme_dark, 1);

        the_root = image_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

