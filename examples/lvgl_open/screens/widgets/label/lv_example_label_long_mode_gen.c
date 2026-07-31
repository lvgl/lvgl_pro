/**
 * @file lv_example_label_long_mode_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_label_long_mode_gen.h"
#include "../../../lvgl_open_examples.h"

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

lv_obj_t * lv_example_label_long_mode_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_label_bg;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_label_bg);
            lv_style_set_bg_opa(&style_label_bg, (255 * 100 / 100));
            lv_style_set_radius(&style_label_bg, 6);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_label_long_mode_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 12, 0);

        lv_obj_t * label_1 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_width(label_1, 170);
        lv_label_set_long_mode(label_1, LV_LABEL_LONG_MODE_WRAP);
        lv_obj_set_style_bg_color(label_1, lv_color_hex(0xd6eaf8), 0);
        lv_label_set_text(label_1, "Wrap keeps all text visible by splitting long lines into multiple rows.");
        lv_obj_add_style(label_1, &style_label_bg, 0);

        lv_obj_t * label_2 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_width(label_2, 170);
        lv_obj_set_height(label_2, 32);
        lv_label_set_long_mode(label_2, LV_LABEL_LONG_MODE_DOTS);
        lv_obj_set_style_bg_color(label_2, lv_color_hex(0xd5f5e3), 0);
        lv_label_set_text(label_2, "Dots shortens overflowing text and replaces the tail with '...'");
        lv_obj_add_style(label_2, &style_label_bg, 0);

        lv_obj_t * label_3 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_width(label_3, 170);
        lv_label_set_long_mode(label_3, LV_LABEL_LONG_MODE_SCROLL);
        lv_obj_set_style_bg_color(label_3, lv_color_hex(0xfdebd0), 0);
        lv_label_set_text(label_3, "Scroll moves overflowing text back and forth inside the label area.");
        lv_obj_add_style(label_3, &style_label_bg, 0);

        lv_obj_t * label_4 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_width(label_4, 170);
        lv_label_set_long_mode(label_4, LV_LABEL_LONG_MODE_SCROLL_CIRCULAR);
        lv_obj_set_style_bg_color(label_4, lv_color_hex(0xfadbd8), 0);
        lv_label_set_text(label_4, "Scroll circular continuously loops overflowing text forever.");
        lv_obj_add_style(label_4, &style_label_bg, 0);

        lv_obj_t * label_5 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_width(label_5, 170);
        lv_label_set_long_mode(label_5, LV_LABEL_LONG_MODE_CLIP);
        lv_obj_set_style_bg_color(label_5, lv_color_hex(0xebdef0), 0);
        lv_label_set_text(label_5, "Clip simply cuts any part that falls outside the label width.");
        lv_obj_add_style(label_5, &style_label_bg, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

