/**
 * @file lv_example_calendar_basic_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_calendar_basic_gen.h"
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

lv_obj_t * lv_example_calendar_basic_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_calendar_basic_#");

        lv_obj_t * calendar = lv_calendar_create(lv_obj_0);
        lv_obj_set_name(calendar, "calendar");
        lv_obj_set_width(calendar, 300);
        lv_obj_set_height(calendar, 230);
        lv_obj_set_align(calendar, LV_ALIGN_CENTER);
        lv_calendar_set_today_year(calendar, 2026);
        lv_calendar_set_today_month(calendar, 5);
        lv_calendar_set_today_day(calendar, 15);
        lv_calendar_set_shown_year(calendar, 2026);
        lv_calendar_set_shown_month(calendar, 5);
        lv_obj_t * lv_calendar_header_arrow_0 = lv_calendar_add_header_arrow(calendar);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

