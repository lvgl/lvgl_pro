/**
 * @file lv_example_style_parts_states_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_parts_states_gen.h"
#include "../../lvgl_open_examples.h"

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

lv_obj_t * lv_example_style_parts_states_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_indicator;
    static lv_style_t style_indicator_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_indicator);
            lv_style_set_bg_opa(&style_indicator, (255 * 100 / 100));
            lv_style_set_bg_color(&style_indicator, lv_color_hex(0x8b5cf6));
            lv_style_set_bg_grad_color(&style_indicator, lv_color_hex(0xec4899));
            lv_style_set_bg_grad_dir(&style_indicator, LV_GRAD_DIR_HOR);
            lv_style_set_radius(&style_indicator, 10);

            lv_style_init(&style_indicator_pressed);
            lv_style_set_shadow_color(&style_indicator_pressed, lv_color_hex(0xec4899));
            lv_style_set_shadow_width(&style_indicator_pressed, 18);
            lv_style_set_shadow_spread(&style_indicator_pressed, 2);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_parts_states_#");

        lv_obj_t * slider = lv_slider_create(lv_obj_0);
        lv_obj_set_name(slider, "slider");
        lv_obj_set_align(slider, LV_ALIGN_CENTER);
        lv_obj_set_width(slider, 220);
        lv_obj_set_height(slider, 16);
        lv_slider_set_min_value(slider, 0);
        lv_slider_set_max_value(slider, 100);
        lv_slider_set_value(slider, 65, false);
        lv_obj_add_style(slider, &style_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(slider, &style_indicator_pressed, LV_PART_INDICATOR | LV_STATE_PRESSED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

