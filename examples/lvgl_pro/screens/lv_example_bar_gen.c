/**
 * @file lv_example_bar_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_bar_gen.h"
#include "../lvgl_pro_examples.h"

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

lv_obj_t * lv_example_bar_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bar;
    static lv_style_t style_bar_ind;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_bar);
        lv_style_init(&style_bar_ind);

        lv_style_set_bg_color(&style_bar, lv_color_hex(0xdee2e7));
        lv_style_set_bg_opa(&style_bar, (255 * 100 / 100));
        lv_style_set_radius(&style_bar, 8);
        lv_style_set_outline_width(&style_bar, 1);
        lv_style_set_outline_color(&style_bar, lv_color_hex(0x3b82f6));
        lv_style_set_outline_opa(&style_bar, (255 * 90 / 100));
        lv_style_set_pad_all(&style_bar, 3);
        lv_style_set_bg_color(&style_bar_ind, lv_color_hex(0x3b82f6));
        lv_style_set_radius(&style_bar_ind, 6);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_bar_#");

        lv_obj_t * lv_bar_0 = lv_bar_create(lv_obj_0);
        lv_obj_set_width(lv_bar_0, 240);
        lv_obj_set_height(lv_bar_0, 22);
        lv_bar_bind_value(lv_bar_0, &subject_value);
        lv_obj_set_align(lv_bar_0, LV_ALIGN_LEFT_MID);
        lv_obj_set_y(lv_bar_0, -40);
        lv_obj_set_x(lv_bar_0, 20);
        lv_obj_add_style(lv_bar_0, &style_bar, 0);
        lv_obj_add_style(lv_bar_0, &style_bar_ind, LV_PART_INDICATOR);
        lv_obj_t * lv_label_0 = lv_label_create(lv_bar_0);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
        lv_label_bind_text(lv_label_0, &subject_value, "%d %%");
        lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0x192e4f), 0);

        lv_obj_t * lv_bar_1 = lv_bar_create(lv_obj_0);
        lv_obj_set_width(lv_bar_1, 240);
        lv_obj_set_height(lv_bar_1, 20);
        lv_bar_set_mode(lv_bar_1, LV_BAR_MODE_RANGE);
        lv_bar_set_value(lv_bar_1, 80, false);
        lv_bar_set_start_value(lv_bar_1, 10, false);
        lv_obj_set_align(lv_bar_1, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(lv_bar_1, 20);
        lv_obj_add_style(lv_bar_1, &style_bar, 0);
        lv_obj_add_style(lv_bar_1, &style_bar_ind, LV_PART_INDICATOR);

        lv_obj_t * lv_bar_2 = lv_bar_create(lv_obj_0);
        lv_obj_set_width(lv_bar_2, 240);
        lv_obj_set_height(lv_bar_2, 20);
        lv_bar_set_min_value(lv_bar_2, 100);
        lv_bar_set_max_value(lv_bar_2, 0);
        lv_bar_set_value(lv_bar_2, 80, false);
        lv_obj_set_align(lv_bar_2, LV_ALIGN_LEFT_MID);
        lv_obj_set_x(lv_bar_2, 20);
        lv_obj_set_y(lv_bar_2, 40);
        lv_obj_set_style_bg_color(lv_bar_2, lv_color_hex3(0x04f), LV_PART_INDICATOR);
        lv_obj_set_style_bg_grad_color(lv_bar_2, lv_color_hex3(0xa8f), LV_PART_INDICATOR);
        lv_obj_set_style_bg_grad_dir(lv_bar_2, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);
        lv_obj_add_style(lv_bar_2, &style_bar, 0);
        lv_obj_add_style(lv_bar_2, &style_bar_ind, LV_PART_INDICATOR);

        lv_obj_t * lv_bar_3 = lv_bar_create(lv_obj_0);
        lv_obj_set_width(lv_bar_3, 20);
        lv_obj_set_height(lv_bar_3, 160);
        lv_bar_set_orientation(lv_bar_3, LV_BAR_ORIENTATION_VERTICAL);
        lv_bar_set_value(lv_bar_3, 65, false);
        lv_obj_set_align(lv_bar_3, LV_ALIGN_RIGHT_MID);
        lv_obj_set_y(lv_bar_3, 0);
        lv_obj_set_x(lv_bar_3, -60);
        lv_obj_add_style(lv_bar_3, &style_bar, 0);
        lv_obj_add_style(lv_bar_3, &style_bar_ind, LV_PART_INDICATOR);

        lv_obj_t * lv_bar_4 = lv_bar_create(lv_obj_0);
        lv_obj_set_width(lv_bar_4, 20);
        lv_obj_set_height(lv_bar_4, 160);
        lv_bar_set_orientation(lv_bar_4, LV_BAR_ORIENTATION_VERTICAL);
        lv_bar_set_min_value(lv_bar_4, 100);
        lv_bar_set_max_value(lv_bar_4, 0);
        lv_bar_set_value(lv_bar_4, 65, false);
        lv_obj_set_align(lv_bar_4, LV_ALIGN_RIGHT_MID);
        lv_obj_set_y(lv_bar_4, 0);
        lv_obj_set_x(lv_bar_4, -20);
        lv_obj_add_style(lv_bar_4, &style_bar, 0);
        lv_obj_add_style(lv_bar_4, &style_bar_ind, LV_PART_INDICATOR);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

