/**
 * @file lv_example_roller_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_roller_styling_gen.h"
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

lv_obj_t * lv_example_roller_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_roller_main;
    static lv_style_t style_roller_selected;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_roller_main);
            lv_style_set_bg_color(&style_roller_main, lv_color_hex(0xf3f4f6));
            lv_style_set_bg_opa(&style_roller_main, (255 * 100 / 100));
            lv_style_set_radius(&style_roller_main, 12);
            lv_style_set_border_color(&style_roller_main, lv_color_hex(0xd1d5db));
            lv_style_set_border_width(&style_roller_main, 1);
            lv_style_set_text_color(&style_roller_main, lv_color_hex(0x6b7280));
            lv_style_set_text_line_space(&style_roller_main, 20);

            lv_style_init(&style_roller_selected);
            lv_style_set_bg_color(&style_roller_selected, lv_color_hex(0x6366f1));
            lv_style_set_bg_opa(&style_roller_selected, (255 * 100 / 100));
            lv_style_set_text_color(&style_roller_selected, lv_color_hex(0xffffff));
            lv_style_set_text_font(&style_roller_selected, font_example_large);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_roller_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * roller = lv_roller_create(lv_obj_0);
        lv_obj_set_name(roller, "roller");
        lv_obj_set_width(roller, 160);
        lv_roller_set_visible_row_count(roller, 5);
        lv_roller_set_options(roller, "Berlin\nParis\nTokyo\nSydney\nNew York", LV_ROLLER_MODE_NORMAL);
        lv_roller_set_selected(roller, 2, false);
        lv_obj_add_style(roller, &style_roller_main, LV_PART_MAIN);
        lv_obj_add_style(roller, &style_roller_selected, LV_PART_SELECTED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

