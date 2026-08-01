/**
 * @file lv_example_tabview_tab_bar_style_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_tabview_tab_bar_style_gen.h"
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

lv_obj_t * lv_example_tabview_tab_bar_style_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_tabview_tab_bar_style_#");

        lv_obj_t * tabview = lv_tabview_create(lv_obj_0);
        lv_obj_set_name(tabview, "tabview");
        lv_obj_set_width(tabview, lv_pct(100));
        lv_obj_set_height(tabview, lv_pct(100));
        lv_tabview_set_tab_bar_position(tabview, LV_DIR_LEFT);
        lv_tabview_set_active(tabview, 1, false);
        lv_obj_set_style_bg_color(tabview, lv_color_hex(0x37474f), 0);
        lv_obj_set_style_bg_opa(tabview, (255 * 100 / 100), 0);
        lv_obj_t * lv_tabview_tab_bar_0 = lv_tabview_get_tab_bar(tabview);
        lv_obj_set_width(lv_tabview_tab_bar_0, 100);
        lv_obj_set_style_bg_color(lv_tabview_tab_bar_0, lv_color_hex(0x222831), 0);
        lv_obj_set_style_bg_opa(lv_tabview_tab_bar_0, (255 * 100 / 100), 0);
        lv_obj_set_style_text_color(lv_tabview_tab_bar_0, lv_color_hex(0xeeeeee), 0);
        lv_obj_t * lv_tabview_tab_0 = lv_tabview_add_tab(tabview, "A");
        lv_obj_t * label_1 = lv_label_create(lv_tabview_tab_0);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(label_1, lv_color_hex(0xeeeeee), 0);
        lv_label_set_text(label_1, "tab view bg = 0x37474f");

        lv_obj_t * lv_tabview_tab_1 = lv_tabview_add_tab(tabview, "B");
        lv_obj_set_style_bg_color(lv_tabview_tab_1, lv_color_hex(0xff7043), 0);
        lv_obj_set_style_bg_opa(lv_tabview_tab_1, (255 * 100 / 100), 0);
        lv_obj_t * label_2 = lv_label_create(lv_tabview_tab_1);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "this tab overrides bg = 0xff7043");

        lv_obj_t * lv_tabview_tab_2 = lv_tabview_add_tab(tabview, "C");
        lv_obj_t * label_3 = lv_label_create(lv_tabview_tab_2);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(label_3, lv_color_hex(0xeeeeee), 0);
        lv_label_set_text(label_3, "tab bar bg = 0x222831");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

