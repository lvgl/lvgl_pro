/**
 * @file lv_example_tabview_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_tabview_gen.h"
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

lv_obj_t * lv_example_tabview_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_tv;
    static lv_style_t style_tabbar_bg;
    static lv_style_t style_tabbar_btn;
    static lv_style_t style_tabbar_btn_checked;
    static lv_style_t style_card;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_tv);
        lv_style_init(&style_tabbar_bg);
        lv_style_init(&style_tabbar_btn);
        lv_style_init(&style_tabbar_btn_checked);
        lv_style_init(&style_card);

        lv_style_set_bg_color(&style_tv, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_tv, (255 * 100 / 100));
        lv_style_set_bg_color(&style_tabbar_bg, lv_color_hex(0x0f172a));
        lv_style_set_border_side(&style_tabbar_bg, LV_BORDER_SIDE_TOP);
        lv_style_set_border_width(&style_tabbar_bg, 2);
        lv_style_set_border_color(&style_tabbar_bg, lv_color_hex(0x343f5a));
        lv_style_set_bg_color(&style_tabbar_btn, lv_color_hex(0x0f172a));
        lv_style_set_text_color(&style_tabbar_btn, lv_color_hex(0x3b6ce9));
        lv_style_set_border_width(&style_tabbar_btn, 0);
        lv_style_set_pad_all(&style_tabbar_btn, 0);
        lv_style_set_bg_color(&style_tabbar_btn_checked, lv_color_hex(0x192748));
        lv_style_set_bg_opa(&style_tabbar_btn_checked, (255 * 100 / 100));
        lv_style_set_border_width(&style_tabbar_btn_checked, 0);
        lv_style_set_pad_all(&style_tabbar_btn_checked, 0);
        lv_style_set_text_color(&style_tabbar_btn_checked, lv_color_hex(0xb3c8fc));
        lv_style_set_bg_color(&style_card, lv_color_hex(0x1e293b));
        lv_style_set_bg_opa(&style_card, (255 * 100 / 100));
        lv_style_set_radius(&style_card, 8);
        lv_style_set_pad_all(&style_card, 12);
        lv_style_set_text_color(&style_card, lv_color_hex(0xe2e8f0));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_tabview_#");

        lv_obj_t * lv_tabview_0 = lv_tabview_create(lv_obj_0);
        lv_obj_set_width(lv_tabview_0, 300);
        lv_obj_set_height(lv_tabview_0, 210);
        lv_tabview_set_tab_bar_position(lv_tabview_0, LV_DIR_BOTTOM);
        lv_tabview_set_active(lv_tabview_0, 0, false);
        lv_obj_set_align(lv_tabview_0, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_tabview_0, &style_tv, 0);
        lv_obj_t * lv_tabview_tab_bar_0 = lv_tabview_get_tab_bar(lv_tabview_0);
        lv_obj_set_height(lv_tabview_tab_bar_0, 48);
        lv_obj_add_style(lv_tabview_tab_bar_0, &style_tabbar_bg, 0);
        lv_obj_t * lv_tabview_tab_0 = lv_tabview_add_tab(lv_tabview_0, "Home");
        lv_obj_t * lv_label_0 = lv_label_create(lv_tabview_tab_0);
        lv_label_set_text(lv_label_0, "Welcome to the Home tab.");
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_label_0, &style_card, 0);

        lv_obj_t * lv_tabview_tab_1 = lv_tabview_add_tab(lv_tabview_0, "Stats");
        lv_obj_t * lv_bar_0 = lv_bar_create(lv_tabview_tab_1);
        lv_obj_set_width(lv_bar_0, 200);
        lv_obj_set_height(lv_bar_0, 22);
        lv_bar_set_value(lv_bar_0, 65, false);
        lv_obj_set_align(lv_bar_0, LV_ALIGN_CENTER);
        lv_obj_add_style(lv_bar_0, &style_card, 0);

        lv_obj_t * lv_tabview_tab_2 = lv_tabview_add_tab(lv_tabview_0, "About");
        lv_obj_t * lv_label_1 = lv_label_create(lv_tabview_tab_2);
        lv_label_set_text(lv_label_1, "Tab view organizes content into pages.");
        lv_obj_set_width(lv_label_1, lv_pct(100));
        lv_obj_add_style(lv_label_1, &style_card, 0);

        lv_obj_t * lv_tabview_tab_bar_1 = lv_tabview_get_tab_bar(lv_tabview_0);
        lv_obj_set_height(lv_tabview_tab_bar_1, 48);
        lv_obj_add_style(lv_tabview_tab_bar_1, &style_tabbar_bg, 0);
        lv_obj_t * lv_tabview_tab_button_0 = lv_tabview_get_tab_button(lv_tabview_0, 0);
        lv_obj_add_style(lv_tabview_tab_button_0, &style_tabbar_btn, 0);
        lv_obj_add_style(lv_tabview_tab_button_0, &style_tabbar_btn_checked, LV_STATE_CHECKED);
        lv_obj_t * lv_tabview_tab_button_1 = lv_tabview_get_tab_button(lv_tabview_0, 1);
        lv_obj_add_style(lv_tabview_tab_button_1, &style_tabbar_btn, 0);
        lv_obj_add_style(lv_tabview_tab_button_1, &style_tabbar_btn_checked, LV_STATE_CHECKED);
        lv_obj_t * lv_tabview_tab_button_2 = lv_tabview_get_tab_button(lv_tabview_0, 2);
        lv_obj_add_style(lv_tabview_tab_button_2, &style_tabbar_btn, 0);
        lv_obj_add_style(lv_tabview_tab_button_2, &style_tabbar_btn_checked, LV_STATE_CHECKED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

