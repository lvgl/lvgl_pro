/**
 * @file lv_example_buttonmatrix_styling_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_buttonmatrix_styling_gen.h"
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

lv_obj_t * lv_example_buttonmatrix_styling_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bm_item;
    static lv_style_t style_bm_item_checked;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_bm_item);
            lv_style_set_bg_opa(&style_bm_item, (255 * 100 / 100));
            lv_style_set_bg_color(&style_bm_item, lv_color_hex(0xf3f4f6));
            lv_style_set_radius(&style_bm_item, 8);
            lv_style_set_border_color(&style_bm_item, lv_color_hex(0xd1d5db));
            lv_style_set_border_width(&style_bm_item, 1);
            lv_style_set_text_color(&style_bm_item, lv_color_hex(0x111827));

            lv_style_init(&style_bm_item_checked);
            lv_style_set_bg_color(&style_bm_item_checked, lv_color_hex(0x6366f1));
            lv_style_set_text_color(&style_bm_item_checked, lv_color_hex(0xffffff));
            lv_style_set_outline_color(&style_bm_item_checked, lv_color_hex(0x6366f1));
            lv_style_set_outline_width(&style_bm_item_checked, 3);
            lv_style_set_outline_pad(&style_bm_item_checked, 2);
            lv_style_set_outline_opa(&style_bm_item_checked, 80);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_buttonmatrix_styling_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * buttonmatrix = lv_buttonmatrix_create(lv_obj_0);
        lv_obj_set_name(buttonmatrix, "buttonmatrix");
        lv_obj_set_width(buttonmatrix, lv_pct(90));
        lv_obj_set_height(buttonmatrix, 80);
        static const char *buttonmatrix_map_0[] = {"M", "T", "W", "T", "F", "S", "S", NULL};
        lv_buttonmatrix_set_map(buttonmatrix, buttonmatrix_map_0);
        lv_buttonmatrix_set_one_checked(buttonmatrix, true);
        static const lv_buttonmatrix_ctrl_t buttonmatrix_ctrl_map_0[] = {LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE | LV_BUTTONMATRIX_CTRL_CHECKED, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE, LV_BUTTONMATRIX_CTRL_CHECKABLE};
        lv_buttonmatrix_set_ctrl_map(buttonmatrix, buttonmatrix_ctrl_map_0);
        lv_obj_set_style_bg_opa(buttonmatrix, (255 * 100 / 100), 0);
        lv_obj_set_style_bg_color(buttonmatrix, lv_color_hex(0xffffff), 0);
        lv_obj_set_style_border_color(buttonmatrix, lv_color_hex(0xe5e7eb), 0);
        lv_obj_set_style_border_width(buttonmatrix, 1, 0);
        lv_obj_set_style_radius(buttonmatrix, 10, 0);
        lv_obj_set_style_pad_all(buttonmatrix, 6, 0);
        lv_obj_set_style_pad_row(buttonmatrix, 6, 0);
        lv_obj_set_style_pad_column(buttonmatrix, 6, 0);
        lv_obj_add_style(buttonmatrix, &style_bm_item, LV_PART_ITEMS);
        lv_obj_add_style(buttonmatrix, &style_bm_item_checked, LV_PART_ITEMS | LV_STATE_CHECKED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

