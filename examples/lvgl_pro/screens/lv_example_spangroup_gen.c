/**
 * @file lv_example_spangroup_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_spangroup_gen.h"
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

lv_obj_t * lv_example_spangroup_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_normal;
    static lv_style_t style_accent;
    static lv_style_t style_big;
    static lv_style_t style_panel;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_normal);
        lv_style_init(&style_accent);
        lv_style_init(&style_big);
        lv_style_init(&style_panel);

        lv_style_set_text_color(&style_normal, lv_color_hex(0xe5e7eb));
        lv_style_set_text_color(&style_accent, lv_color_hex(0x3b82f6));
        lv_style_set_text_color(&style_big, lv_color_hex(0xf59e0b));
        lv_style_set_text_font(&style_big, font_large);
        lv_style_set_bg_color(&style_panel, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_panel, (255 * 100 / 100));
        lv_style_set_radius(&style_panel, 8);
        lv_style_set_pad_all(&style_panel, 12);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_spangroup_#");

        lv_obj_t * lv_spangroup_0 = lv_spangroup_create(lv_obj_0);
        lv_obj_set_width(lv_spangroup_0, 260);
        lv_obj_set_height(lv_spangroup_0, LV_SIZE_CONTENT);
        lv_spangroup_set_overflow(lv_spangroup_0, LV_SPAN_OVERFLOW_ELLIPSIS);
        lv_spangroup_set_max_lines(lv_spangroup_0, 3);
        lv_spangroup_set_indent(lv_spangroup_0, 16);
        lv_obj_set_align(lv_spangroup_0, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_spangroup_0, &style_panel, 0);
        lv_span_t * lv_spangroup_span_0 = lv_spangroup_add_span(lv_spangroup_0);
        lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_0, "LVGL ");
        lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_0, &style_normal);
        lv_span_t * lv_spangroup_span_1 = lv_spangroup_add_span(lv_spangroup_0);
        lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_1, "Pro");
        lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_1, &style_big);
        lv_span_t * lv_spangroup_span_2 = lv_spangroup_add_span(lv_spangroup_0);
        lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_2, " lets you mix ");
        lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_2, &style_normal);
        lv_span_t * lv_spangroup_span_3 = lv_spangroup_add_span(lv_spangroup_0);
        lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_3, "colours");
        lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_3, &style_accent);
        lv_span_t * lv_spangroup_span_4 = lv_spangroup_add_span(lv_spangroup_0);
        lv_spangroup_set_span_text(lv_spangroup_0, lv_spangroup_span_4, " and sizes in a single block of text.");
        lv_spangroup_set_span_style(lv_spangroup_0, lv_spangroup_span_4, &style_normal);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

