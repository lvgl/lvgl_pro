/**
 * @file lv_example_style_size_position_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_size_position_gen.h"
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

lv_obj_t * lv_example_style_size_position_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_card;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_card);
            lv_style_set_radius(&style_card, 16);
            lv_style_set_bg_opa(&style_card, (255 * 100 / 100));
            lv_style_set_bg_color(&style_card, lv_color_hex(0xffffff));
            lv_style_set_border_width(&style_card, 0);
            lv_style_set_shadow_color(&style_card, ACCENT);
            lv_style_set_shadow_width(&style_card, 22);
            lv_style_set_shadow_offset_y(&style_card, 6);
            lv_style_set_shadow_opa(&style_card, 55);

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_size_position_#");

        lv_obj_t * container_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_1, "container_1");
        lv_obj_set_width(container_1, 140);
        lv_obj_set_height(container_1, LV_SIZE_CONTENT);
        lv_obj_set_align(container_1, LV_ALIGN_CENTER);
        lv_obj_set_y(container_1, -40);
        lv_obj_set_style_pad_all(container_1, 12, 0);
        lv_obj_add_style(container_1, &style_card, 0);
        lv_obj_t * label_1 = lv_label_create(container_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "140 wide");

        lv_obj_t * container_2 = lv_obj_create(lv_obj_0);
        lv_obj_set_name(container_2, "container_2");
        lv_obj_set_width(container_2, 260);
        lv_obj_set_height(container_2, LV_SIZE_CONTENT);
        lv_obj_set_align(container_2, LV_ALIGN_CENTER);
        lv_obj_set_y(container_2, 40);
        lv_obj_set_style_pad_all(container_2, 28, 0);
        lv_obj_add_style(container_2, &style_card, 0);
        lv_obj_t * label_2 = lv_label_create(container_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "260 wide, roomy padding");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

