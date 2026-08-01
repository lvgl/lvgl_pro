/**
 * @file segment_item_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "segment_item_gen.h"
#include "../../../tutorials.h"

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

lv_obj_t * segment_item_create(lv_obj_t * parent, const char * text)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_checked;

    static bool style_inited = false;

    if (!style_inited) {
        #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
        if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
            lv_style_init(&style_base);
            lv_style_set_width(&style_base, 100);
            lv_style_set_height(&style_base, lv_pct(100));
            lv_style_set_bg_color(&style_base, lv_color_hex(0x545454));
            lv_style_set_border_width(&style_base, 0);
            lv_style_set_text_color(&style_base, lv_color_hex(0xffffff));
            lv_style_set_radius(&style_base, 0);

            lv_style_init(&style_checked);
            lv_style_set_bg_color(&style_checked, lv_color_hex(0xd3d3d3));
            lv_style_set_text_color(&style_checked, lv_color_hex(0x000000));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "segment_item_#");
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_add_style(lv_obj_0, &style_base, 0);
        lv_obj_add_style(lv_obj_0, &style_checked, LV_STATE_CHECKED);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_0, text);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

