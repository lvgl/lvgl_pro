/**
 * @file lv_example_calendar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_calendar_gen.h"
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

lv_obj_t * lv_example_calendar_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_cal;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_cal);

        lv_style_set_bg_color(&style_cal, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_cal, (255 * 100 / 100));
        lv_style_set_text_color(&style_cal, lv_color_hex(0xe2e8f0));
        lv_style_set_radius(&style_cal, 8);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_calendar_#");

        lv_obj_t * lv_calendar_0 = lv_calendar_create(lv_obj_0);
        lv_obj_set_width(lv_calendar_0, 260);
        lv_obj_set_height(lv_calendar_0, 280);
        lv_calendar_set_shown_year(lv_calendar_0, 2026);
        lv_calendar_set_shown_month(lv_calendar_0, 5);
        lv_obj_set_align(lv_calendar_0, LV_ALIGN_CENTER);
        lv_calendar_set_today_year(lv_calendar_0, 2026);
        lv_calendar_set_today_month(lv_calendar_0, 5);
        lv_calendar_set_today_day(lv_calendar_0, 17);
        lv_obj_add_style(lv_calendar_0, &style_cal, 0);
        lv_obj_t * lv_calendar_header_dropdown_0 = lv_calendar_add_header_dropdown(lv_calendar_0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

