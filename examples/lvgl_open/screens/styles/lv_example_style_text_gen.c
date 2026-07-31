/**
 * @file lv_example_style_text_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_text_gen.h"
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

lv_obj_t * lv_example_style_text_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_card;
    static lv_style_t style_heading;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_card);
            lv_style_set_radius(&style_card, 16);
            lv_style_set_bg_opa(&style_card, (255 * 100 / 100));
            lv_style_set_bg_color(&style_card, lv_color_hex(0xffffff));
            lv_style_set_pad_all(&style_card, 22);

            lv_style_init(&style_heading);
            lv_style_set_text_color(&style_heading, ACCENT);
            lv_style_set_text_letter_space(&style_heading, 4);
            lv_style_set_text_line_space(&style_heading, 14);
            lv_style_set_text_decor(&style_heading, LV_TEXT_DECOR_UNDERLINE);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_text_#");

        lv_obj_t * container = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container, "container");
        lv_obj_set_width(container, 240);
        lv_obj_set_height(container, LV_SIZE_CONTENT);
        lv_obj_set_align(container, LV_ALIGN_CENTER);
        lv_obj_add_style(container, &style_card, 0);
        lv_obj_t * label = lv_label_create(container);
        lv_obj_set_name(label, "label");
        lv_obj_set_align(label, LV_ALIGN_CENTER);
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
        lv_label_set_text(label, "Custom\nTypography");
        lv_obj_add_style(label, &style_heading, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

