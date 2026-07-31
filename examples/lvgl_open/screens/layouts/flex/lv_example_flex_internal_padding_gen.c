/**
 * @file lv_example_flex_internal_padding_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_flex_internal_padding_gen.h"
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

lv_obj_t * lv_example_flex_internal_padding_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_tag;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_tag);
            lv_style_set_bg_opa(&style_tag, (255 * 100 / 100));
            lv_style_set_pad_ver(&style_tag, 12);
            lv_style_set_pad_hor(&style_tag, 18);
            lv_style_set_radius(&style_tag, 4);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_flex_internal_padding_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 10, 0);

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW_WRAP);
        lv_obj_set_style_pad_column(container, 10, 0);
        lv_obj_set_style_pad_row(container, 30, 0);
        lv_obj_set_width(container, lv_pct(90));
        lv_obj_set_height(container, LV_SIZE_CONTENT);
        lv_obj_t * label_1 = lv_label_create(container);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_style_bg_color(label_1, lv_color_hex(0x5e9ee3), 0);
        lv_label_set_text(label_1, "HTML");
        lv_obj_add_style(label_1, &style_tag, 0);

        lv_obj_t * label_2 = lv_label_create(container);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_style_bg_color(label_2, lv_color_hex(0xe67e22), 0);
        lv_label_set_text(label_2, "CSS");
        lv_obj_add_style(label_2, &style_tag, 0);

        lv_obj_t * label_3 = lv_label_create(container);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_style_bg_color(label_3, lv_color_hex(0x27ae60), 0);
        lv_label_set_text(label_3, "JavaScript");
        lv_obj_add_style(label_3, &style_tag, 0);

        lv_obj_t * label_4 = lv_label_create(container);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_style_bg_color(label_4, lv_color_hex(0x8e44ad), 0);
        lv_label_set_text(label_4, "Python");
        lv_obj_add_style(label_4, &style_tag, 0);

        lv_obj_t * label_5 = lv_label_create(container);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_style_bg_color(label_5, lv_color_hex(0xc0392b), 0);
        lv_label_set_text(label_5, "C++");
        lv_obj_add_style(label_5, &style_tag, 0);

        lv_obj_t * label_6 = lv_label_create(container);
        lv_obj_set_name(label_6, "label_6");
        lv_obj_set_style_bg_color(label_6, lv_color_hex(0x16a085), 0);
        lv_label_set_text(label_6, "Rust");
        lv_obj_add_style(label_6, &style_tag, 0);

        lv_obj_t * label_7 = lv_label_create(container);
        lv_obj_set_name(label_7, "label_7");
        lv_obj_set_style_bg_color(label_7, lv_color_hex(0xd8da19), 0);
        lv_label_set_text(label_7, "Java");
        lv_obj_add_style(label_7, &style_tag, 0);

        lv_obj_t * label_8 = lv_label_create(container);
        lv_obj_set_name(label_8, "label_8");
        lv_obj_set_style_bg_color(label_8, lv_color_hex(0x18d99e), 0);
        lv_label_set_text(label_8, "PHP");
        lv_obj_add_style(label_8, &style_tag, 0);

        lv_obj_t * label_9 = lv_label_create(container);
        lv_obj_set_name(label_9, "label_9");
        lv_obj_set_style_bg_color(label_9, lv_color_hex(0xeb4c9e), 0);
        lv_label_set_text(label_9, "Zig");
        lv_obj_add_style(label_9, &style_tag, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

