/**
 * @file lv_example_checkbox_states_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_checkbox_states_gen.h"
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

lv_obj_t * lv_example_checkbox_states_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_checkbox_states_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 16, 0);

        lv_obj_t * checkbox_1 = lv_checkbox_create(lv_obj_0);
        lv_obj_set_name(checkbox_1, "checkbox_1");
        lv_checkbox_set_text(checkbox_1, "Unchecked");

        lv_obj_t * checkbox_2 = lv_checkbox_create(lv_obj_0);
        lv_obj_set_name(checkbox_2, "checkbox_2");
        lv_checkbox_set_text(checkbox_2, "Checked");
        lv_obj_set_state(checkbox_2, LV_STATE_CHECKED, true);

        lv_obj_t * checkbox_3 = lv_checkbox_create(lv_obj_0);
        lv_obj_set_name(checkbox_3, "checkbox_3");
        lv_checkbox_set_text(checkbox_3, "Disabled");
        lv_obj_set_state(checkbox_3, LV_STATE_DISABLED, true);

        lv_obj_t * checkbox_4 = lv_checkbox_create(lv_obj_0);
        lv_obj_set_name(checkbox_4, "checkbox_4");
        lv_checkbox_set_text(checkbox_4, "Disabled + Checked");
        lv_obj_set_state(checkbox_4, LV_STATE_DISABLED, true);
        lv_obj_set_state(checkbox_4, LV_STATE_CHECKED, true);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

