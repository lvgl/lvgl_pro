/**
 * @file lv_example_textarea_cursor_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_textarea_cursor_gen.h"
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

lv_obj_t * lv_example_textarea_cursor_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_block_cursor;
    static lv_style_t style_bar_cursor;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_block_cursor);
            lv_style_set_bg_opa(&style_block_cursor, (255 * 100 / 100));
            lv_style_set_bg_color(&style_block_cursor, lv_color_hex(0x2563eb));
            lv_style_set_text_color(&style_block_cursor, lv_color_hex(0xffffff));
            lv_style_set_border_side(&style_block_cursor, LV_BORDER_SIDE_NONE);

            lv_style_init(&style_bar_cursor);
            lv_style_set_bg_opa(&style_bar_cursor, (255 * 0 / 100));
            lv_style_set_border_side(&style_bar_cursor, LV_BORDER_SIDE_LEFT);
            lv_style_set_border_width(&style_bar_cursor, 2);
            lv_style_set_border_color(&style_bar_cursor, lv_color_hex(0xdc2626));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_textarea_cursor_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * textarea_1 = lv_textarea_create(lv_obj_0);
        lv_obj_set_name(textarea_1, "textarea_1");
        lv_obj_set_width(textarea_1, lv_pct(60));
        lv_textarea_set_one_line(textarea_1, true);
        lv_textarea_set_text(textarea_1, "Block");
        lv_textarea_set_cursor_pos(textarea_1, 2);
        lv_obj_set_state(textarea_1, LV_STATE_FOCUSED, true);
        lv_obj_add_style(textarea_1, &style_block_cursor, LV_PART_CURSOR | LV_STATE_FOCUSED);

        lv_obj_t * textarea_2 = lv_textarea_create(lv_obj_0);
        lv_obj_set_name(textarea_2, "textarea_2");
        lv_obj_set_width(textarea_2, lv_pct(60));
        lv_textarea_set_one_line(textarea_2, true);
        lv_textarea_set_text(textarea_2, "Bar");
        lv_textarea_set_cursor_pos(textarea_2, 2);
        lv_obj_set_state(textarea_2, LV_STATE_FOCUSED, true);
        lv_obj_add_style(textarea_2, &style_bar_cursor, LV_PART_CURSOR | LV_STATE_FOCUSED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

