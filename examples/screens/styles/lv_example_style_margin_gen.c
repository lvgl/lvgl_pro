/**
 * @file lv_example_style_margin_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_margin_gen.h"
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

lv_obj_t * lv_example_style_margin_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_chip;
    static lv_style_t style_chip_accent;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_chip);
            lv_style_set_radius(&style_chip, 10);
            lv_style_set_bg_opa(&style_chip, (255 * 100 / 100));
            lv_style_set_bg_color(&style_chip, lv_color_hex(0xe2e8f0));
            lv_style_set_pad_all(&style_chip, 14);

            lv_style_init(&style_chip_accent);
            lv_style_set_radius(&style_chip_accent, 10);
            lv_style_set_bg_opa(&style_chip_accent, (255 * 100 / 100));
            lv_style_set_bg_color(&style_chip_accent, ACCENT);
            lv_style_set_pad_all(&style_chip_accent, 14);
            lv_style_set_text_color(&style_chip_accent, lv_color_hex(0xffffff));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_margin_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * label_1 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_1, "label_1");
        lv_label_set_text(label_1, "A");
        lv_obj_add_style(label_1, &style_chip, 0);

        lv_obj_t * label_2 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_2, "label_2");
        lv_label_set_text(label_2, "B");
        lv_obj_set_style_margin_left(label_2, 48, 0);
        lv_obj_set_style_margin_right(label_2, 24, 0);
        lv_obj_add_style(label_2, &style_chip_accent, 0);

        lv_obj_t * label_3 = lv_label_create(lv_obj_0);
        lv_obj_set_name(label_3, "label_3");
        lv_label_set_text(label_3, "C");
        lv_obj_add_style(label_3, &style_chip, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

