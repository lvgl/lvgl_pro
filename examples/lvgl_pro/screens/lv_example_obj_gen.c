/**
 * @file lv_example_obj_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_obj_gen.h"
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

lv_obj_t * lv_example_obj_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_box;
    static lv_style_t style_box_alt;
    static lv_style_t style_row;
    static lv_style_t style_scrollbar;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_box);
        lv_style_init(&style_box_alt);
        lv_style_init(&style_row);
        lv_style_init(&style_scrollbar);

        lv_style_set_bg_color(&style_box, lv_color_hex(0x1e293b));
        lv_style_set_bg_opa(&style_box, (255 * 100 / 100));
        lv_style_set_radius(&style_box, 10);
        lv_style_set_pad_all(&style_box, 14);
        lv_style_set_text_color(&style_box, lv_color_hex(0xe2e8f0));
        lv_style_set_bg_color(&style_box_alt, lv_color_hex(0x5b1db7));
        lv_style_set_bg_color(&style_row, lv_color_hex(0x334155));
        lv_style_set_border_color(&style_row, lv_color_hex(0x5a697e));
        lv_style_set_bg_opa(&style_row, (255 * 100 / 100));
        lv_style_set_radius(&style_row, 6);
        lv_style_set_pad_all(&style_row, 10);
        lv_style_set_height(&style_row, LV_SIZE_CONTENT);
        lv_style_set_width(&style_row, lv_pct(100));
        lv_style_set_text_color(&style_row, lv_color_hex(0xe2e8f0));
        lv_style_set_bg_color(&style_scrollbar, lv_color_hex(0x9a80c1));
        lv_style_set_bg_opa(&style_scrollbar, (255 * 100 / 100));
        lv_style_set_width(&style_scrollbar, 6);
        lv_style_set_pad_ver(&style_scrollbar, 14);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_obj_#");

        lv_obj_t * lv_switch_0 = lv_switch_create(lv_obj_0);
        lv_obj_bind_checked(lv_switch_0, &subject_checked);
        lv_obj_set_x(lv_switch_0, 92);
        lv_obj_set_y(lv_switch_0, 11);

        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_0, "Switch theme");
        lv_obj_set_x(lv_label_0, 163);
        lv_obj_set_y(lv_label_0, 19);

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, 300);
        lv_obj_set_height(lv_obj_1, 200);
        lv_obj_set_align(lv_obj_1, LV_ALIGN_CENTER);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_1, 8, 0);
        lv_obj_set_scrollbar_mode(lv_obj_1, LV_SCROLLBAR_MODE_ACTIVE);
        lv_obj_add_style(lv_obj_1, &style_box, 0);
        lv_obj_bind_style(lv_obj_1, &style_box_alt, 0, &subject_checked, 1);
        lv_obj_add_style(lv_obj_1, &style_scrollbar, LV_PART_SCROLLBAR);
        lv_obj_t * lv_obj_2 = lv_obj_create(lv_obj_1);
        lv_obj_add_style(lv_obj_2, &style_row, 0);
        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_2);
        lv_label_set_text(lv_label_1, "Row 1 . Scroll down");

        lv_obj_t * lv_obj_3 = lv_obj_create(lv_obj_1);
        lv_obj_add_style(lv_obj_3, &style_row, 0);
        lv_obj_t * lv_label_2 = lv_label_create(lv_obj_3);
        lv_label_set_text(lv_label_2, "Row 2");

        lv_obj_t * lv_obj_4 = lv_obj_create(lv_obj_1);
        lv_obj_add_style(lv_obj_4, &style_row, 0);
        lv_obj_t * lv_label_3 = lv_label_create(lv_obj_4);
        lv_label_set_text(lv_label_3, "Row 3");

        lv_obj_t * lv_obj_5 = lv_obj_create(lv_obj_1);
        lv_obj_add_style(lv_obj_5, &style_row, 0);
        lv_obj_t * lv_label_4 = lv_label_create(lv_obj_5);
        lv_label_set_text(lv_label_4, "Row 4");

        lv_obj_t * lv_obj_6 = lv_obj_create(lv_obj_1);
        lv_obj_add_style(lv_obj_6, &style_row, 0);
        lv_obj_t * lv_label_5 = lv_label_create(lv_obj_6);
        lv_label_set_text(lv_label_5, "Row 5 - I'm the last");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

