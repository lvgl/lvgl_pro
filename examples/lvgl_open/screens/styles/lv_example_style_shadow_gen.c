/**
 * @file lv_example_style_shadow_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_shadow_gen.h"
#include "../../lvgl_open_examples.h"

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

lv_obj_t * lv_example_style_shadow_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_elevated;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_elevated);
            lv_style_set_radius(&style_elevated, 20);
            lv_style_set_bg_opa(&style_elevated, (255 * 100 / 100));
            lv_style_set_bg_color(&style_elevated, lv_color_hex(0xffffff));
            lv_style_set_border_width(&style_elevated, 0);
            lv_style_set_shadow_color(&style_elevated, lv_color_hex(0x312e81));
            lv_style_set_shadow_width(&style_elevated, 30);
            lv_style_set_shadow_offset_y(&style_elevated, 12);
            lv_style_set_shadow_opa(&style_elevated, 80);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_shadow_#");

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_align(container, LV_ALIGN_CENTER);
        lv_obj_set_width(container, 210);
        lv_obj_set_height(container, 130);
        lv_obj_add_style(container, &style_elevated, 0);
        lv_obj_t * label = lv_label_create(container);
        lv_obj_set_name(label, "label");
        lv_obj_set_align(label, LV_ALIGN_CENTER);
        lv_label_set_text(label, "Elevated");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

