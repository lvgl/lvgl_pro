/**
 * @file lv_example_checkbox_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_checkbox_gen.h"
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

lv_obj_t * lv_example_checkbox_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_tick_checked;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_tick_checked);

        lv_style_set_bg_color(&style_tick_checked, lv_color_hex(0x16a34a));
        lv_style_set_border_color(&style_tick_checked, lv_color_hex(0x16a34a));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_checkbox_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(lv_obj_0, 14, 0);
        lv_obj_set_style_pad_all(lv_obj_0, 18, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * lv_checkbox_0 = lv_checkbox_create(lv_obj_0);
        lv_checkbox_set_text(lv_checkbox_0, "Enable feature");
        lv_obj_set_state(lv_checkbox_0, LV_STATE_CHECKED, true);
        lv_obj_add_style(lv_checkbox_0, &style_tick_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

        lv_obj_t * lv_checkbox_1 = lv_checkbox_create(lv_obj_0);
        lv_checkbox_set_text(lv_checkbox_1, "Unavailable option");
        lv_obj_set_state(lv_checkbox_1, LV_STATE_DISABLED, true);

        lv_obj_t * lv_checkbox_2 = lv_checkbox_create(lv_obj_0);
        lv_checkbox_set_text(lv_checkbox_2, "Sync A");
        lv_obj_bind_checked(lv_checkbox_2, &subject_checked);
        lv_obj_add_style(lv_checkbox_2, &style_tick_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

        lv_obj_t * lv_checkbox_3 = lv_checkbox_create(lv_obj_0);
        lv_checkbox_set_text(lv_checkbox_3, "Sync B");
        lv_obj_bind_checked(lv_checkbox_3, &subject_checked);
        lv_obj_add_style(lv_checkbox_3, &style_tick_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

