/**
 * @file list_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_item_gen.h"
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

lv_obj_t * list_item_create(lv_obj_t * parent, const char * title, const char * subtitle, const void * icon)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_list_row;
    static lv_style_t style_icon_light;
    static lv_style_t style_icon_dark;
    static lv_style_t style_list_row_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_list_row);
        lv_style_init(&style_icon_light);
        lv_style_init(&style_icon_dark);
        lv_style_init(&style_list_row_pressed);

        lv_style_set_width(&style_list_row, lv_pct(100));
        lv_style_set_flex_cross_place(&style_list_row, LV_FLEX_ALIGN_CENTER);
        lv_style_set_border_side(&style_list_row, LV_BORDER_SIDE_BOTTOM);
        lv_style_set_border_width(&style_list_row, 1);
        lv_style_set_border_color(&style_list_row, COLOR_TRACK);
        lv_style_set_border_opa(&style_list_row, (255 * 25 / 100));
        lv_style_set_image_recolor(&style_icon_light, COLOR_LIGHT_TEXT);
        lv_style_set_image_recolor_opa(&style_icon_light, (255 * 100 / 100));
        lv_style_set_image_recolor(&style_icon_dark, COLOR_DARK_TEXT);
        lv_style_set_image_recolor_opa(&style_icon_dark, (255 * 100 / 100));
        lv_style_set_bg_color(&style_list_row_pressed, COLOR_TRACK);
        lv_style_set_bg_opa(&style_list_row_pressed, (255 * 40 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        lv_obj_t * container_0 = container_create(parent, SPACE_MD, SPACE_MD, LV_FLEX_FLOW_ROW, 0);
        lv_obj_set_name_static(container_0, "list_item_#");
        lv_obj_set_flag(container_0, LV_OBJ_FLAG_CLICKABLE, true);

        lv_obj_add_style(container_0, &style_list_row, 0);
        lv_obj_add_style(container_0, &style_list_row_pressed, LV_STATE_PRESSED);
        lv_obj_t * monoicon_0 = monoicon_create(container_0, icon);
        lv_obj_set_flag(monoicon_0, LV_OBJ_FLAG_HIDDEN, !icon);

        lv_obj_t * container_1 = container_create(container_0, 0, SPACE_XS, LV_FLEX_FLOW_COLUMN, 1);
        lv_obj_set_flag(container_1, LV_OBJ_FLAG_CLICKABLE, false);
        h5_create(container_1, title, "");

        lv_obj_t * text_0 = text_create(container_1, subtitle);
        lv_obj_set_flag(text_0, LV_OBJ_FLAG_HIDDEN, !subtitle);
        lv_obj_add_style(text_0, &style_text_muted, 0);

        lv_obj_t * trailing = container_create(container_0, 0, SPACE_SM, LV_FLEX_FLOW_ROW, 0);
        lv_obj_set_name(trailing, "trailing");

        the_root = container_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_obj_t * list_item_get_trailing(lv_obj_t *parent)
{
    return lv_obj_find_by_name(parent, "trailing");
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

