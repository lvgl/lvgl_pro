/**
 * @file lv_example_line_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_line_gen.h"
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

lv_obj_t * lv_example_line_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_line;
    static lv_style_t style_line2;
    static lv_style_t style_panel;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_line);
        lv_style_init(&style_line2);
        lv_style_init(&style_panel);

        lv_style_set_line_width(&style_line, 4);
        lv_style_set_line_color(&style_line, lv_color_hex(0x3b82f6));
        lv_style_set_line_rounded(&style_line, true);
        lv_style_set_line_width(&style_line2, 4);
        lv_style_set_line_color(&style_line2, lv_color_hex(0xf59e0b));
        lv_style_set_line_rounded(&style_line2, true);
        lv_style_set_bg_color(&style_panel, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_panel, (255 * 100 / 100));
        lv_style_set_radius(&style_panel, 8);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_line_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 14, 0);
        lv_obj_set_style_pad_all(lv_obj_0, 16, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

