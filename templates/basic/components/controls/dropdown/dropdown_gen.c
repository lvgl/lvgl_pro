/**
 * @file dropdown_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "dropdown_gen.h"
#include "../../../lvgl_open_template.h"

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

lv_obj_t * dropdown_create(lv_obj_t * parent, const char * options, int32_t selected, lv_subject_t * subject)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dropdown;
    static lv_style_t style_chevron_light;
    static lv_style_t style_chevron_dark;
    static lv_style_t style_list;
    static lv_style_t style_dd_selected;
    static lv_style_t style_dd_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_dropdown);
        lv_style_init(&style_chevron_light);
        lv_style_init(&style_chevron_dark);
        lv_style_init(&style_list);
        lv_style_init(&style_dd_selected);
        lv_style_init(&style_dd_pressed);

        lv_style_set_radius(&style_dropdown, RADIUS_DEFAULT);
        lv_style_set_image_recolor(&style_chevron_light, COLOR_LIGHT_TEXT);
        lv_style_set_image_recolor_opa(&style_chevron_light, (255 * 100 / 100));
        lv_style_set_image_recolor(&style_chevron_dark, COLOR_DARK_TEXT);
        lv_style_set_image_recolor_opa(&style_chevron_dark, (255 * 100 / 100));
        lv_style_set_text_line_space(&style_list, SPACE_LG);
        lv_style_set_bg_color(&style_dd_selected, COLOR_ACCENT);
        lv_style_set_bg_opa(&style_dd_selected, (255 * 100 / 100));
        lv_style_set_text_color(&style_dd_selected, COLOR_ACCENT_TEXT);
        lv_style_set_bg_color(&style_dd_pressed, COLOR_TRACK);
        lv_style_set_bg_opa(&style_dd_pressed, OPA_MUTED);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * lv_dropdown_0 = lv_dropdown_create(parent);
        lv_obj_set_name_static(lv_dropdown_0, "dropdown_#");
        lv_obj_set_width(lv_dropdown_0, 200);
        lv_dropdown_set_options(lv_dropdown_0, options);
        lv_dropdown_set_selected(lv_dropdown_0, selected);
        lv_dropdown_bind_value(lv_dropdown_0, subject);
        lv_dropdown_set_symbol(lv_dropdown_0, icon_chevron_down);

        lv_obj_add_style(lv_dropdown_0, &style_dropdown, 0);
        lv_obj_add_style(lv_dropdown_0, &style_panel_light, 0);
        lv_obj_bind_style(lv_dropdown_0, &style_panel_dark, 0, &subject_theme_dark, 1);
        lv_obj_add_style(lv_dropdown_0, &style_chevron_light, LV_PART_INDICATOR);
        lv_obj_bind_style(lv_dropdown_0, &style_chevron_dark, LV_PART_INDICATOR, &subject_theme_dark, 1);
        lv_obj_t * lv_dropdown_list_0 = lv_dropdown_get_list(lv_dropdown_0);
        lv_obj_add_style(lv_dropdown_list_0, &style_list, 0);
        lv_obj_add_style(lv_dropdown_list_0, &style_panel_light, 0);
        lv_obj_bind_style(lv_dropdown_list_0, &style_panel_dark, 0, &subject_theme_dark, 1);
        lv_obj_add_style(lv_dropdown_list_0, &style_scrollbar, LV_PART_SCROLLBAR);
        lv_obj_add_style(lv_dropdown_list_0, &style_dd_selected, LV_PART_SELECTED | LV_STATE_CHECKED);
        lv_obj_add_style(lv_dropdown_list_0, &style_dd_pressed, LV_PART_SELECTED | LV_STATE_PRESSED);

        the_root = lv_dropdown_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

