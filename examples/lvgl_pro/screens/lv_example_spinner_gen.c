/**
 * @file lv_example_spinner_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_spinner_gen.h"
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

lv_obj_t * lv_example_spinner_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_track;
    static lv_style_t style_ind;
    static lv_style_t style_ind2;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_track);
        lv_style_init(&style_ind);
        lv_style_init(&style_ind2);

        lv_style_set_arc_color(&style_track, lv_color_hex(0x334155));
        lv_style_set_arc_width(&style_track, 8);
        lv_style_set_arc_color(&style_ind, lv_color_hex(0x3b82f6));
        lv_style_set_arc_width(&style_ind, 8);
        lv_style_set_arc_color(&style_ind2, lv_color_hex(0xf59e0b));
        lv_style_set_arc_width(&style_ind2, 12);
        lv_style_set_pad_all(&style_ind2, -2);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_spinner_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * lv_spinner_0 = lv_spinner_create(lv_obj_0);
        lv_obj_set_width(lv_spinner_0, 80);
        lv_obj_set_height(lv_spinner_0, 80);
        lv_spinner_set_anim_duration(lv_spinner_0, 2000);
        lv_spinner_set_arc_sweep(lv_spinner_0, 270);
        lv_obj_add_style(lv_spinner_0, &style_track, 0);
        lv_obj_add_style(lv_spinner_0, &style_ind, LV_PART_INDICATOR);

        lv_obj_t * lv_spinner_1 = lv_spinner_create(lv_obj_0);
        lv_obj_set_width(lv_spinner_1, 80);
        lv_obj_set_height(lv_spinner_1, 80);
        lv_spinner_set_anim_duration(lv_spinner_1, 700);
        lv_spinner_set_arc_sweep(lv_spinner_1, 220);
        lv_obj_add_style(lv_spinner_1, &style_track, 0);
        lv_obj_add_style(lv_spinner_1, &style_ind2, LV_PART_INDICATOR);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

