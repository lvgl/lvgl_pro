/**
 * @file lv_example_switch_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_switch_gen.h"
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

lv_obj_t * lv_example_switch_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_sw;
    static lv_style_t style_sw_on;
    static lv_style_t style_knob;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_sw);
        lv_style_init(&style_sw_on);
        lv_style_init(&style_knob);

        lv_style_set_bg_color(&style_sw, lv_color_hex(0xcbd5e1));
        lv_style_set_bg_opa(&style_sw, (255 * 100 / 100));
        lv_style_set_bg_color(&style_sw_on, lv_color_hex(0x16a34a));
        lv_style_set_bg_color(&style_knob, lv_color_hex(0xffffff));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_switch_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);
        lv_obj_set_style_pad_all(lv_obj_0, 18, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * lv_switch_0 = lv_switch_create(lv_obj_0);
        lv_obj_set_state(lv_switch_0, LV_STATE_CHECKED, true);
        lv_obj_add_style(lv_switch_0, &style_sw, 0);
        lv_obj_add_style(lv_switch_0, &style_sw_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_add_style(lv_switch_0, &style_knob, LV_PART_KNOB);

        lv_obj_t * lv_switch_1 = lv_switch_create(lv_obj_0);
        lv_obj_set_state(lv_switch_1, LV_STATE_DISABLED, true);
        lv_obj_set_style_bg_opa(lv_switch_1, (255 * 40 / 100), 0);
        lv_obj_add_style(lv_switch_1, &style_sw, 0);
        lv_obj_add_style(lv_switch_1, &style_knob, LV_PART_KNOB);

        lv_obj_t * lv_switch_2 = lv_switch_create(lv_obj_0);
        lv_obj_bind_checked(lv_switch_2, &subject_checked);
        lv_obj_add_style(lv_switch_2, &style_sw, 0);
        lv_obj_add_style(lv_switch_2, &style_sw_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_add_style(lv_switch_2, &style_knob, LV_PART_KNOB);

        lv_obj_t * lv_switch_3 = lv_switch_create(lv_obj_0);
        lv_obj_bind_checked(lv_switch_3, &subject_checked);
        lv_obj_add_style(lv_switch_3, &style_sw, 0);
        lv_obj_add_style(lv_switch_3, &style_sw_on, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_add_style(lv_switch_3, &style_knob, LV_PART_KNOB);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

