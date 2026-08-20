/**
 * @file lv_example_arc_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_arc_gen.h"
#include "../lvgl_pro_examples.h"

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

lv_obj_t * lv_example_arc_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_arc_main;
    static lv_style_t style_arc_ind;
    static lv_style_t style_arc_knob;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_arc_main);
        lv_style_init(&style_arc_ind);
        lv_style_init(&style_arc_knob);

        lv_style_set_arc_color(&style_arc_main, lv_color_hex(0x334155));
        lv_style_set_arc_width(&style_arc_main, 10);
        lv_style_set_arc_color(&style_arc_ind, lv_color_hex(0x3b82f6));
        lv_style_set_arc_width(&style_arc_ind, 10);
        lv_style_set_bg_color(&style_arc_knob, lv_color_hex(0x3b82f6));
        lv_style_set_pad_all(&style_arc_knob, 6);
        lv_style_set_border_width(&style_arc_knob, 2);
        lv_style_set_border_color(&style_arc_knob, lv_color_hex3(0xfff));
        lv_style_set_shadow_offset_y(&style_arc_knob, 2);
        lv_style_set_shadow_opa(&style_arc_knob, (255 * 50 / 100));
        lv_style_set_shadow_width(&style_arc_knob, 10);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_arc_#");

        lv_obj_t * lv_arc_0 = lv_arc_create(lv_obj_0);
        lv_obj_set_width(lv_arc_0, 120);
        lv_obj_set_height(lv_arc_0, 120);
        lv_obj_set_align(lv_arc_0, LV_ALIGN_CENTER);
        lv_arc_bind_value(lv_arc_0, &subject_value);
        lv_obj_add_style(lv_arc_0, &style_arc_main, 0);
        lv_obj_add_style(lv_arc_0, &style_arc_ind, LV_PART_INDICATOR);
        lv_obj_add_style(lv_arc_0, &style_arc_knob, LV_PART_KNOB);
        lv_obj_t * lv_label_0 = lv_label_create(lv_arc_0);
        lv_label_bind_text(lv_label_0, &subject_value, "value: %d");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

