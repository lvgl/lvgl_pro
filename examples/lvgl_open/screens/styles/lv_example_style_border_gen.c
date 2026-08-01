/**
 * @file lv_example_style_border_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_border_gen.h"
#include "../../lvgl_open_examples.h"

/*********************
 *      DEFINES
 *********************/

#define ACCENT lv_color_hex(0x6366f1)


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

lv_obj_t * lv_example_style_border_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_framed;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_framed);
            lv_style_set_radius(&style_framed, 20);
            lv_style_set_bg_opa(&style_framed, (255 * 100 / 100));
            lv_style_set_bg_color(&style_framed, lv_color_hex(0xffffff));
            lv_style_set_border_color(&style_framed, ACCENT);
            lv_style_set_border_width(&style_framed, 4);
            lv_style_set_border_opa(&style_framed, (255 * 60 / 100));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_border_#");

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_width(container, 210);
        lv_obj_set_height(container, 140);
        lv_obj_set_align(container, LV_ALIGN_CENTER);
        lv_obj_add_style(container, &style_framed, 0);
        lv_obj_t * label = lv_label_create(container);
        lv_obj_set_name(label, "label");
        lv_obj_set_align(label, LV_ALIGN_CENTER);
        lv_label_set_text(label, "Bordered card");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

