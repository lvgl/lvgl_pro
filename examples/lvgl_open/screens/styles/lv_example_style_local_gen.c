/**
 * @file lv_example_style_local_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_local_gen.h"
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

lv_obj_t * lv_example_style_local_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_shared;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_shared);
            lv_style_set_radius(&style_shared, 14);
            lv_style_set_bg_opa(&style_shared, (255 * 100 / 100));
            lv_style_set_bg_color(&style_shared, ACCENT);
            lv_style_set_border_width(&style_shared, 3);
            lv_style_set_border_color(&style_shared, lv_color_hex(0x312e81));
            lv_style_set_pad_all(&style_shared, 14);
            lv_style_set_text_color(&style_shared, lv_color_hex(0xffffff));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_local_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * button_1 = lv_button_create(lv_obj_0);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_set_width(button_1, 95);
        lv_obj_add_style(button_1, &style_shared, 0);
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "Shared");

        lv_obj_t * button_2 = lv_button_create(lv_obj_0);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_set_width(button_2, 95);
        lv_obj_set_style_bg_color(button_2, lv_color_hex(0xec4899), 0);
        lv_obj_add_style(button_2, &style_shared, 0);
        lv_obj_t * label_2 = lv_label_create(button_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Override");

        lv_obj_t * button_3 = lv_button_create(lv_obj_0);
        lv_obj_set_name(button_3, "button_3");
        lv_obj_set_width(button_3, 95);
        lv_obj_set_style_bg_color(button_3, lv_color_hex(0x10b981), LV_STATE_PRESSED);
        lv_obj_add_style(button_3, &style_shared, 0);
        lv_obj_t * label_3 = lv_label_create(button_3);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "On press");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

