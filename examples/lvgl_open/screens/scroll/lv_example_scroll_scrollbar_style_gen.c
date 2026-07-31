/**
 * @file lv_example_scroll_scrollbar_style_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_scroll_scrollbar_style_gen.h"
#include "../../lvgl_open_examples.h"

/*********************
 *      DEFINES
 *********************/

#define ACCENT lv_color_hex(0x9429ff)


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

lv_obj_t * lv_example_scroll_scrollbar_style_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_scrollbar;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_scrollbar);
            lv_style_set_width(&style_scrollbar, 10);
            lv_style_set_radius(&style_scrollbar, 5);
            lv_style_set_bg_color(&style_scrollbar, ACCENT);
            lv_style_set_bg_opa(&style_scrollbar, (255 * 100 / 100));
            lv_style_set_pad_right(&style_scrollbar, 4);
            lv_style_set_pad_top(&style_scrollbar, 4);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_scroll_scrollbar_style_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 12, 0);

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_width(container, 240);
        lv_obj_set_height(container, 160);
        lv_obj_set_flex_flow(container, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_row(container, 8, 0);
        lv_obj_set_scrollbar_mode(container, LV_SCROLLBAR_MODE_ON);
        lv_obj_add_style(container, &style_scrollbar, LV_PART_SCROLLBAR);
        lv_obj_t * button_1 = lv_button_create(container);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_set_width(button_1, lv_pct(100));
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "Row 1");

        lv_obj_t * button_2 = lv_button_create(container);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_set_width(button_2, lv_pct(100));
        lv_obj_t * label_2 = lv_label_create(button_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Row 2");

        lv_obj_t * button_3 = lv_button_create(container);
        lv_obj_set_name(button_3, "button_3");
        lv_obj_set_width(button_3, lv_pct(100));
        lv_obj_t * label_3 = lv_label_create(button_3);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "Row 3");

        lv_obj_t * button_4 = lv_button_create(container);
        lv_obj_set_name(button_4, "button_4");
        lv_obj_set_width(button_4, lv_pct(100));
        lv_obj_t * label_4 = lv_label_create(button_4);
        lv_obj_set_name(label_4, "label_4");
        lv_obj_set_align(label_4, LV_ALIGN_CENTER);
        lv_label_set_text(label_4, "Row 4");

        lv_obj_t * button_5 = lv_button_create(container);
        lv_obj_set_name(button_5, "button_5");
        lv_obj_set_width(button_5, lv_pct(100));
        lv_obj_t * label_5 = lv_label_create(button_5);
        lv_obj_set_name(label_5, "label_5");
        lv_obj_set_align(label_5, LV_ALIGN_CENTER);
        lv_label_set_text(label_5, "Row 5");

        lv_obj_t * button_6 = lv_button_create(container);
        lv_obj_set_name(button_6, "button_6");
        lv_obj_set_width(button_6, lv_pct(100));
        lv_obj_t * label_6 = lv_label_create(button_6);
        lv_obj_set_name(label_6, "label_6");
        lv_obj_set_align(label_6, LV_ALIGN_CENTER);
        lv_label_set_text(label_6, "Row 6");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

