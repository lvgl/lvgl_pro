/**
 * @file lv_example_tabview_tab_bar_position_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_tabview_tab_bar_position_gen.h"
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

lv_obj_t * lv_example_tabview_tab_bar_position_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_tabview_tab_bar_position_#");

        lv_obj_t * tabview_1 = lv_tabview_create(lv_obj_0);
        lv_obj_set_name(tabview_1, "tabview_1");
        lv_tabview_set_tab_bar_position(tabview_1, LV_DIR_RIGHT);
        lv_obj_set_style_bg_color(tabview_1, lv_color_hex(0xce93d8), 0);
        lv_obj_set_style_bg_opa(tabview_1, (255 * 100 / 100), 0);
        lv_obj_t * lv_tabview_tab_0 = lv_tabview_add_tab(tabview_1, "A");
        lv_obj_t * label_1 = lv_label_create(lv_tabview_tab_0);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "Right tab bar");

        lv_obj_t * lv_tabview_tab_1 = lv_tabview_add_tab(tabview_1, "B");
        lv_obj_t * label_2 = lv_label_create(lv_tabview_tab_1);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Same here");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

