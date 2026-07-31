/**
 * @file lv_example_style_padding_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_padding_gen.h"
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

lv_obj_t * lv_example_style_padding_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_block;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_block);
            lv_style_set_radius(&style_block, 10);
            lv_style_set_bg_opa(&style_block, (255 * 100 / 100));
            lv_style_set_bg_color(&style_block, ACCENT);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_padding_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);

        lv_obj_t * container_2 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_width(container_2, 120);
        lv_obj_set_height(container_2, 120);
        lv_obj_set_style_pad_top(container_2, 26, 0);
        lv_obj_set_style_pad_left(container_2, 26, 0);
        lv_obj_set_style_pad_right(container_2, 8, 0);
        lv_obj_set_style_pad_bottom(container_2, 8, 0);
        lv_obj_t * container_3 = lv_obj_create(container_2);
        lv_obj_set_name(container_3, "container_3");
        lv_obj_set_width(container_3, lv_pct(100));
        lv_obj_set_height(container_3, lv_pct(100));
        lv_obj_add_style(container_3, &style_block, 0);

        lv_obj_t * container_4 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_4, "container_4");
        lv_obj_set_width(container_4, 120);
        lv_obj_set_height(container_4, 120);
        lv_obj_set_style_pad_all(container_4, 18, 0);
        lv_obj_t * container_5 = lv_obj_create(container_4);
        lv_obj_set_name(container_5, "container_5");
        lv_obj_set_width(container_5, lv_pct(100));
        lv_obj_set_height(container_5, lv_pct(100));
        lv_obj_add_style(container_5, &style_block, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

