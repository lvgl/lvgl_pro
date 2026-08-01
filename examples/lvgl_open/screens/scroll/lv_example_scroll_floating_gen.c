/**
 * @file lv_example_scroll_floating_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_scroll_floating_gen.h"
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

lv_obj_t * lv_example_scroll_floating_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_fab;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_fab);
            lv_style_set_radius(&style_fab, 22);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_scroll_floating_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 12, 0);

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_width(container, 240);
        lv_obj_set_height(container, 180);
        lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(container, 8, 0);
        lv_obj_t * button_1 = lv_button_create(container);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_set_width(button_1, lv_pct(100));
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "Track 1");

        lv_obj_t * button_2 = lv_button_create(container);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_set_width(button_2, lv_pct(100));
        lv_obj_t * label_2 = lv_label_create(button_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Track 2");

        lv_obj_t * button_3 = lv_button_create(container);
        lv_obj_set_name(button_3, "button_3");
        lv_obj_set_width(button_3, lv_pct(100));
        lv_obj_t * label_3 = lv_label_create(button_3);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "Track 3");

        lv_obj_t * button_4 = lv_button_create(container);
        lv_obj_set_name(button_4, "button_4");
        lv_obj_set_width(button_4, lv_pct(100));
        lv_obj_t * label_4 = lv_label_create(button_4);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_align(label_4, LV_ALIGN_CENTER);
        lv_label_set_text(label_4, "Track 4");

        lv_obj_t * button_5 = lv_button_create(container);
        lv_obj_set_name(button_5, "button_5");
        lv_obj_set_width(button_5, lv_pct(100));
        lv_obj_t * label_5 = lv_label_create(button_5);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_align(label_5, LV_ALIGN_CENTER);
        lv_label_set_text(label_5, "Track 5");

        lv_obj_t * button_6 = lv_button_create(container);
        lv_obj_set_name(button_6, "button_6");
        lv_obj_set_width(button_6, lv_pct(100));
        lv_obj_t * label_6 = lv_label_create(button_6);
        lv_obj_set_name(label_6, "label_6");
        lv_obj_set_align(label_6, LV_ALIGN_CENTER);
        lv_label_set_text(label_6, "Track 6");

        lv_obj_t * button_7 = lv_button_create(container);
        lv_obj_set_name(button_7, "button_7");
        lv_obj_set_width(button_7, 44);
        lv_obj_set_height(button_7, 44);
        lv_obj_set_align(button_7, LV_ALIGN_BOTTOM_RIGHT);
        lv_obj_set_flag(button_7, LV_OBJ_FLAG_FLOATING, true);
        lv_obj_set_style_bg_color(button_7, lv_color_hex(0x9429ff), 0);
        lv_obj_add_style(button_7, &style_fab, 0);
        lv_obj_t * label_7 = lv_label_create(button_7);
        lv_obj_set_name(label_7, "label_7");
        lv_obj_set_align(label_7, LV_ALIGN_CENTER);
        lv_label_set_text(label_7, "+");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

