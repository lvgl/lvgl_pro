/**
 * @file lv_example_button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_button_gen.h"
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

lv_obj_t * lv_example_button_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_btn;
    static lv_style_t style_btn_pressed;
    static lv_style_t style_btn_checked;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_btn);
        lv_style_init(&style_btn_pressed);
        lv_style_init(&style_btn_checked);

        lv_style_set_bg_color(&style_btn, lv_color_hex(0x3b82f6));
        lv_style_set_bg_opa(&style_btn, (255 * 100 / 100));
        lv_style_set_radius(&style_btn, 8);
        lv_style_set_pad_hor(&style_btn, 18);
        lv_style_set_pad_ver(&style_btn, 10);
        lv_style_set_text_color(&style_btn, lv_color_hex(0xffffff));
        lv_style_set_bg_color(&style_btn_pressed, lv_color_hex(0x1d4ed8));
        lv_style_set_bg_color(&style_btn_checked, lv_color_hex(0x16a34a));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_button_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 14, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * lv_button_0 = lv_button_create(lv_obj_0);
        lv_obj_add_style(lv_button_0, &style_btn, 0);
        lv_obj_add_style(lv_button_0, &style_btn_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, "Action");

        lv_obj_t * lv_button_1 = lv_button_create(lv_obj_0);
        lv_obj_set_state(lv_button_1, LV_STATE_CHECKED, true);
        lv_obj_add_style(lv_button_1, &style_btn, 0);
        lv_obj_add_style(lv_button_1, &style_btn_pressed, LV_STATE_PRESSED);
        lv_obj_add_style(lv_button_1, &style_btn_checked, LV_STATE_CHECKED);
        lv_obj_t * lv_label_1 = lv_label_create(lv_button_1);
        lv_label_set_text(lv_label_1, "Toggle");

        lv_obj_t * lv_button_2 = lv_button_create(lv_obj_0);
        lv_obj_set_state(lv_button_2, LV_STATE_DISABLED, true);
        lv_obj_set_style_bg_opa(lv_button_2, (255 * 40 / 100), 0);
        lv_obj_add_style(lv_button_2, &style_btn, 0);
        lv_obj_t * lv_label_2 = lv_label_create(lv_button_2);
        lv_label_set_text(lv_label_2, "Disabled");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

