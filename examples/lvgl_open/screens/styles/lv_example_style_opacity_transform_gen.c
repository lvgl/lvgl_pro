/**
 * @file lv_example_style_opacity_transform_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_style_opacity_transform_gen.h"
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

lv_obj_t * lv_example_style_opacity_transform_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_btn;

    static bool style_inited = false;

    if (!style_inited) {
        #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
        if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
            lv_style_init(&style_btn);
            lv_style_set_radius(&style_btn, 10);
            lv_style_set_bg_opa(&style_btn, (255 * 100 / 100));
            lv_style_set_bg_color(&style_btn, ACCENT);
            lv_style_set_pad_all(&style_btn, 12);
            lv_style_set_text_color(&style_btn, lv_color_hex(0xffffff));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_style_opacity_transform_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_row(lv_obj_0, 12, 0);

        lv_obj_t * button_1 = lv_button_create(lv_obj_0);
        lv_obj_set_name(button_1, "button_1");
        lv_obj_set_width(button_1, 130);
        lv_obj_add_style(button_1, &style_btn, 0);
        lv_obj_t * label_1 = lv_label_create(button_1);
        lv_obj_set_name(label_1, "label_1");
        lv_obj_set_align(label_1, LV_ALIGN_CENTER);
        lv_label_set_text(label_1, "Normal");

        lv_obj_t * button_2 = lv_button_create(lv_obj_0);
        lv_obj_set_name(button_2, "button_2");
        lv_obj_set_width(button_2, 130);
        lv_obj_set_style_opa(button_2, 128, 0);
        lv_obj_add_style(button_2, &style_btn, 0);
        lv_obj_t * label_2 = lv_label_create(button_2);
        lv_obj_set_name(label_2, "label_2");
        lv_obj_set_align(label_2, LV_ALIGN_CENTER);
        lv_label_set_text(label_2, "Opa 50%");

        lv_obj_t * button_3 = lv_button_create(lv_obj_0);
        lv_obj_set_name(button_3, "button_3");
        lv_obj_set_width(button_3, 130);
        lv_obj_set_style_opa(button_3, 128, 0);
        lv_obj_set_style_transform_rotation(button_3, 110, 0);
        lv_obj_set_style_transform_pivot_x(button_3, lv_pct(50), 0);
        lv_obj_set_style_transform_pivot_y(button_3, lv_pct(50), 0);
        lv_obj_set_style_transform_scale_x(button_3, 420, 0);
        lv_obj_add_style(button_3, &style_btn, 0);
        lv_obj_t * label_3 = lv_label_create(button_3);
        lv_obj_set_name(label_3, "label_3");
        lv_obj_set_align(label_3, LV_ALIGN_CENTER);
        lv_label_set_text(label_3, "Transformed");

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

