/**
 * @file lv_example_style_multiple_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_multiple_gen.h"
#include "../../lvgl_open_examples.h"

/*********************
 *      DEFINES
 *********************/

#define BASE lv_color_hex(0x6366f1)
#define WARN lv_color_hex(0xf59e0b)


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

lv_obj_t * lv_example_style_multiple_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_warning;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_base);
            lv_style_set_radius(&style_base, 14);
            lv_style_set_bg_opa(&style_base, (255 * 100 / 100));
            lv_style_set_bg_color(&style_base, BASE);
            lv_style_set_border_width(&style_base, 2);
            lv_style_set_border_color(&style_base, lv_color_hex(0x4338ca));
            lv_style_set_shadow_color(&style_base, lv_color_hex(0x312e81));
            lv_style_set_shadow_width(&style_base, 14);
            lv_style_set_shadow_offset_y(&style_base, 5);
            lv_style_set_shadow_opa(&style_base, 120);
            lv_style_set_pad_all(&style_base, 16);
            lv_style_set_text_color(&style_base, lv_color_hex(0xffffff));

            lv_style_init(&style_warning);
            lv_style_set_bg_color(&style_warning, WARN);
            lv_style_set_border_color(&style_warning, lv_color_hex(0xb45309));
            lv_style_set_text_color(&style_warning, lv_color_hex(0x1f2937));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_multiple_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * container_2 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_width(container_2, 110);
        lv_obj_set_height(container_2, LV_SIZE_CONTENT);
        lv_obj_add_style(container_2, &style_base, 0);
        lv_obj_t * label_1 = lv_label_create(container_2);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "Base");

        lv_obj_t * container_3 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_3, "container_3");
        lv_obj_set_width(container_3, 110);
        lv_obj_set_height(container_3, LV_SIZE_CONTENT);
        lv_obj_add_style(container_3, &style_base, 0);
        lv_obj_add_style(container_3, &style_warning, 0);
        lv_obj_t * label_2 = lv_label_create(container_3);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Warning");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

