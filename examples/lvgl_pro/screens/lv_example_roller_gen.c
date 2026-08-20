/**
 * @file lv_example_roller_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_roller_gen.h"
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

lv_obj_t * lv_example_roller_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_roller;
    static lv_style_t style_roller_sel;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_roller);
        lv_style_init(&style_roller_sel);

        lv_style_set_bg_color(&style_roller, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_roller, (255 * 100 / 100));
        lv_style_set_text_color(&style_roller, lv_color_hex(0x94a3b8));
        lv_style_set_radius(&style_roller, 8);
        lv_style_set_pad_all(&style_roller, 6);
        lv_style_set_bg_color(&style_roller_sel, lv_color_hex(0x3b82f6));
        lv_style_set_text_color(&style_roller_sel, lv_color_hex(0xffffff));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_roller_#");

        lv_obj_t * lv_roller_0 = lv_roller_create(lv_obj_0);
        lv_obj_set_align(lv_roller_0, LV_ALIGN_CENTER);
        lv_roller_set_options(lv_roller_0, "January\nFebruary\nMarch\nApril\nMay\nJune\nJuly\nAugust\nSeptember\nOctober\nNovember", LV_ROLLER_MODE_INFINITE);
        lv_roller_set_visible_row_count(lv_roller_0, 3);
        lv_roller_bind_value(lv_roller_0, &subject_index);
        lv_obj_add_style(lv_roller_0, &style_roller, 0);
        lv_obj_add_style(lv_roller_0, &style_roller_sel, LV_PART_SELECTED);

        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_set_y(lv_label_0, -70);
        lv_label_bind_text(lv_label_0, &subject_index, "Month index: %d");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

