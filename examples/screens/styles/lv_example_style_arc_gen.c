/**
 * @file lv_example_style_arc_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_arc_gen.h"
#include "../../lvgl_open_examples.h"

/*********************
 *      DEFINES
 *********************/

#define ACCENT lv_color_hex(0x6366f1)


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

lv_obj_t * lv_example_style_arc_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bg;
    static lv_style_t style_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_bg);
            lv_style_set_arc_color(&style_bg, ACCENT);
            lv_style_set_arc_width(&style_bg, 14);
            lv_style_set_arc_opa(&style_bg, (255 * 20 / 100));
            lv_style_set_arc_rounded(&style_bg, true);

            lv_style_init(&style_indicator);
            lv_style_set_arc_color(&style_indicator, ACCENT);
            lv_style_set_arc_width(&style_indicator, 14);
            lv_style_set_arc_rounded(&style_indicator, true);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_arc_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 12, 0);

        lv_obj_t * arc = lv_arc_create(lv_obj_0);
        lv_obj_set_name(arc, "arc");
        lv_obj_set_width(arc, 160);
        lv_obj_set_height(arc, 160);
        lv_arc_set_min_value(arc, 0);
        lv_arc_set_max_value(arc, 100);
        lv_arc_set_value(arc, 68);
        lv_obj_add_style(arc, &style_bg, LV_PART_MAIN);
        lv_obj_add_style(arc, &style_indicator, LV_PART_INDICATOR);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

