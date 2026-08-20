/**
 * @file lv_example_spinbox_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_spinbox_gen.h"
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

lv_obj_t * lv_example_spinbox_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_sb;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_sb);

        lv_style_set_bg_color(&style_sb, lv_color_hex(0x111827));
        lv_style_set_bg_opa(&style_sb, (255 * 100 / 100));
        lv_style_set_text_color(&style_sb, lv_color_hex(0xf9fafb));
        lv_style_set_radius(&style_sb, 8);
        lv_style_set_pad_all(&style_sb, 10);
        lv_style_set_text_font(&style_sb, font_large);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_spinbox_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);
        lv_obj_set_style_pad_all(lv_obj_0, 16, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * lv_spinbox_0 = lv_spinbox_create(lv_obj_0);
        lv_obj_set_width(lv_spinbox_0, 150);
        lv_spinbox_set_digit_count(lv_spinbox_0, 4);
        lv_spinbox_set_dec_point_pos(lv_spinbox_0, 2);
        lv_spinbox_set_min_value(lv_spinbox_0, 0);
        lv_spinbox_set_max_value(lv_spinbox_0, 9999);
        lv_spinbox_set_step(lv_spinbox_0, 25);
        lv_spinbox_set_rollover(lv_spinbox_0, true);
        lv_spinbox_set_value(lv_spinbox_0, 1250);
        lv_obj_add_style(lv_spinbox_0, &style_sb, 0);

        lv_obj_t * lv_spinbox_1 = lv_spinbox_create(lv_obj_0);
        lv_obj_set_width(lv_spinbox_1, 150);
        lv_spinbox_set_min_value(lv_spinbox_1, 0);
        lv_spinbox_set_max_value(lv_spinbox_1, 100);
        lv_spinbox_bind_value(lv_spinbox_1, &subject_value);
        lv_obj_add_style(lv_spinbox_1, &style_sb, 0);

        lv_obj_t * lv_slider_0 = lv_slider_create(lv_obj_0);
        lv_obj_set_width(lv_slider_0, 220);
        lv_slider_bind_value(lv_slider_0, &subject_value);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

