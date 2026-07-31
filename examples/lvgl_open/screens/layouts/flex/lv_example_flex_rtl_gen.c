/**
 * @file lv_example_flex_rtl_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_flex_rtl_gen.h"
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

lv_obj_t * lv_example_flex_rtl_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_label;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_label);
            lv_style_set_bg_opa(&style_label, (255 * 100 / 100));
            lv_style_set_text_color(&style_label, lv_color_hex(0xffffff));
            lv_style_set_pad_all(&style_label, 8);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_flex_rtl_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 10, 0);

        lv_obj_t * label_1 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_1, "label_1");
        lv_label_set_text(label_1, "LTR (default):");

        lv_obj_t * container_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_1, "container_1");
        lv_obj_set_flex_flow(container_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_width(container_1, lv_pct(90));
        lv_obj_set_height(container_1, LV_SIZE_CONTENT);
        lv_obj_t * label_2 = lv_label_create(container_1);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_style_bg_color(label_2, lv_color_hex(0x3498db), 0);
        lv_label_set_text(label_2, "First");
        lv_obj_add_style(label_2, &style_label, 0);

        lv_obj_t * label_3 = lv_label_create(container_1);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_style_bg_color(label_3, lv_color_hex(0x2ecc71), 0);
        lv_label_set_text(label_3, "Second");
        lv_obj_add_style(label_3, &style_label, 0);

        lv_obj_t * label_4 = lv_label_create(container_1);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_style_bg_color(label_4, lv_color_hex(0xe74c3c), 0);
        lv_label_set_text(label_4, "Third");
        lv_obj_add_style(label_4, &style_label, 0);

        lv_obj_t * label_5 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_5, "label_5");
        lv_label_set_text(label_5, "RTL:");

        lv_obj_t * container_2 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_flex_flow(container_2, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_base_dir(container_2, LV_BASE_DIR_RTL, 0);
        lv_obj_set_width(container_2, lv_pct(90));
        lv_obj_set_height(container_2, LV_SIZE_CONTENT);
        lv_obj_t * label_6 = lv_label_create(container_2);
        lv_obj_set_name(label_6, "label_6");
        lv_obj_set_style_bg_color(label_6, lv_color_hex(0x3498db), 0);
        lv_label_set_text(label_6, "First");
        lv_obj_add_style(label_6, &style_label, 0);

        lv_obj_t * label_7 = lv_label_create(container_2);
        lv_obj_set_name(label_7, "label_7");
        lv_obj_set_style_bg_color(label_7, lv_color_hex(0x2ecc71), 0);
        lv_label_set_text(label_7, "Second");
        lv_obj_add_style(label_7, &style_label, 0);

        lv_obj_t * label_8 = lv_label_create(container_2);
        lv_obj_set_name(label_8, "label_8");
        lv_obj_set_style_bg_color(label_8, lv_color_hex(0xe74c3c), 0);
        lv_label_set_text(label_8, "Third");
        lv_obj_add_style(label_8, &style_label, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

