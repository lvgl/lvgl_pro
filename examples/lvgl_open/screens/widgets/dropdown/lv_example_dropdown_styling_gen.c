/**
 * @file lv_example_dropdown_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_dropdown_styling_gen.h"
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

lv_obj_t * lv_example_dropdown_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dropdown_main;
    static lv_style_t style_dropdown_focused;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_dropdown_main);
            lv_style_set_bg_opa(&style_dropdown_main, (255 * 100 / 100));
            lv_style_set_bg_color(&style_dropdown_main, lv_color_hex(0xffffff));
            lv_style_set_radius(&style_dropdown_main, 10);
            lv_style_set_border_color(&style_dropdown_main, lv_color_hex(0xd1d5db));
            lv_style_set_border_width(&style_dropdown_main, 2);
            lv_style_set_text_color(&style_dropdown_main, lv_color_hex(0x111827));
            lv_style_set_pad_left(&style_dropdown_main, 14);
            lv_style_set_pad_right(&style_dropdown_main, 14);
            lv_style_set_pad_top(&style_dropdown_main, 10);
            lv_style_set_pad_bottom(&style_dropdown_main, 10);

            lv_style_init(&style_dropdown_focused);
            lv_style_set_border_color(&style_dropdown_focused, lv_color_hex(0x6366f1));
            lv_style_set_outline_color(&style_dropdown_focused, lv_color_hex(0x6366f1));
            lv_style_set_outline_width(&style_dropdown_focused, 3);
            lv_style_set_outline_pad(&style_dropdown_focused, 2);
            lv_style_set_outline_opa(&style_dropdown_focused, 120);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_dropdown_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * dropdown = lv_dropdown_create(lv_obj_0);
        lv_obj_set_name(dropdown, "dropdown");
        lv_obj_set_width(dropdown, 200);
        lv_dropdown_set_options(dropdown, "Apple\nBanana\nCherry\nDate");
        lv_obj_add_style(dropdown, &style_dropdown_main, LV_PART_MAIN);
        lv_obj_add_style(dropdown, &style_dropdown_focused, LV_PART_MAIN | LV_STATE_FOCUSED);
        lv_obj_t * lv_dropdown_list_0 = lv_dropdown_get_list(dropdown);
        lv_obj_set_style_bg_color(lv_dropdown_list_0, lv_color_hex(0x6366f1), LV_PART_SELECTED | LV_STATE_CHECKED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

