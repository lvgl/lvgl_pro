/**
 * @file lv_example_tabview_tab_button_content_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_tabview_tab_button_content_gen.h"
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

lv_obj_t * lv_example_tabview_tab_button_content_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_tabview_tab_button_content_#");

        lv_obj_t * tabview = lv_tabview_create(lv_obj_0);
        lv_obj_set_name(tabview, "tabview");
        lv_obj_set_width(tabview, lv_pct(100));
        lv_obj_set_height(tabview, lv_pct(100));
        lv_obj_t * lv_tabview_tab_0 = lv_tabview_add_tab(tabview, "WiFi");
        lv_obj_t * label_1 = lv_label_create(lv_tabview_tab_0);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "WiFi tab content");

        lv_obj_t * lv_tabview_tab_1 = lv_tabview_add_tab(tabview, "Bluetooth");
        lv_obj_t * label_2 = lv_label_create(lv_tabview_tab_1);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Bluetooth tab content");

        lv_obj_t * lv_tabview_tab_button_0 = lv_tabview_get_tab_button(tabview, 0);
        lv_obj_t * sw_1 = lv_switch_create(lv_tabview_tab_button_0);
        lv_obj_set_name(sw_1, "sw_1");
        lv_obj_set_width(sw_1, 40);
        lv_obj_set_height(sw_1, 20);
        lv_obj_set_flag(sw_1, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_align(sw_1, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(sw_1, -10);

        lv_obj_t * lv_tabview_tab_button_1 = lv_tabview_get_tab_button(tabview, 1);
        lv_obj_t * sw_2 = lv_switch_create(lv_tabview_tab_button_1);
        lv_obj_set_name(sw_2, "sw_2");
        lv_obj_set_width(sw_2, 40);
        lv_obj_set_height(sw_2, 20);
        lv_obj_set_flag(sw_2, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_align(sw_2, LV_ALIGN_RIGHT_MID);
        lv_obj_set_x(sw_2, -10);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

