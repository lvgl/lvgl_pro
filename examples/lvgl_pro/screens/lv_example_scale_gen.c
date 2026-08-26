/**
 * @file lv_example_scale_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_scale_gen.h"
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

lv_obj_t * lv_example_scale_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_scale_main;
    static lv_style_t style_scale_minor_ticks;
    static lv_style_t style_scale_major_ticks;
    static lv_style_t style_danger_line;
    static lv_style_t style_danger_ind;
    static lv_style_t style_danger_items;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_scale_main);
        lv_style_init(&style_scale_minor_ticks);
        lv_style_init(&style_scale_major_ticks);
        lv_style_init(&style_danger_line);
        lv_style_init(&style_danger_ind);
        lv_style_init(&style_danger_items);

        lv_style_set_bg_color(&style_scale_main, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_scale_main, (255 * 100 / 100));
        lv_style_set_pad_all(&style_scale_main, 14);
        lv_style_set_arc_color(&style_scale_main, lv_color_hex(0x64748b));
        lv_style_set_line_color(&style_scale_main, lv_color_hex(0x64748b));
        lv_style_set_text_color(&style_scale_main, lv_color_hex(0xcbd5e1));
        lv_style_set_line_color(&style_scale_minor_ticks, lv_color_hex(0x64748b));
        lv_style_set_length(&style_scale_minor_ticks, 6);
        lv_style_set_line_color(&style_scale_major_ticks, lv_color_hex(0x3577d3));
        lv_style_set_line_width(&style_scale_major_ticks, 3);
        lv_style_set_length(&style_scale_major_ticks, 10);
        lv_style_set_line_color(&style_danger_line, lv_color_hex(0xef4444));
        lv_style_set_arc_color(&style_danger_line, lv_color_hex(0xef4444));
        lv_style_set_line_width(&style_danger_line, 4);
        lv_style_set_line_color(&style_danger_ind, lv_color_hex(0xef4444));
        lv_style_set_line_width(&style_danger_ind, 4);
        lv_style_set_text_color(&style_danger_ind, lv_color_hex(0xef4444));
        lv_style_set_line_color(&style_danger_items, lv_color_hex(0xf87171));
        lv_style_set_line_width(&style_danger_items, 3);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_scale_#");

        lv_obj_t * lv_scale_0 = lv_scale_create(lv_obj_0);
        lv_obj_set_width(lv_scale_0, 170);
        lv_obj_set_height(lv_scale_0, 170);
        lv_obj_set_y(lv_scale_0, -40);
        lv_obj_set_align(lv_scale_0, LV_ALIGN_CENTER);
        lv_scale_set_mode(lv_scale_0, LV_SCALE_MODE_ROUND_INNER);
        lv_scale_set_min_value(lv_scale_0, 0);
        lv_scale_set_max_value(lv_scale_0, 100);
        lv_scale_set_total_tick_count(lv_scale_0, 21);
        lv_scale_set_major_tick_every(lv_scale_0, 5);
        lv_scale_set_angle_range(lv_scale_0, 270);
        lv_scale_set_rotation(lv_scale_0, 135);
        lv_scale_set_label_show(lv_scale_0, true);
        lv_obj_set_style_radius(lv_scale_0, 100, 0);
        lv_obj_add_style(lv_scale_0, &style_scale_main, 0);
        lv_obj_add_style(lv_scale_0, &style_scale_minor_ticks, LV_PART_ITEMS);
        lv_obj_add_style(lv_scale_0, &style_scale_major_ticks, LV_PART_INDICATOR);
        lv_scale_section_t * lv_scale_section_0 = lv_scale_add_section(lv_scale_0);
        lv_scale_set_section_min_value(lv_scale_0, lv_scale_section_0, 80);
        lv_scale_set_section_max_value(lv_scale_0, lv_scale_section_0, 100);
        lv_scale_set_section_style_main(lv_scale_0, lv_scale_section_0, &style_danger_line);
        lv_scale_set_section_style_indicator(lv_scale_0, lv_scale_section_0, &style_danger_ind);
        lv_scale_set_section_style_items(lv_scale_0, lv_scale_section_0, &style_danger_items);

        lv_obj_t * lv_scale_1 = lv_scale_create(lv_obj_0);
        lv_obj_set_width(lv_scale_1, 220);
        lv_obj_set_height(lv_scale_1, 60);
        lv_obj_set_y(lv_scale_1, 80);
        lv_obj_set_align(lv_scale_1, LV_ALIGN_CENTER);
        lv_scale_set_mode(lv_scale_1, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
        lv_scale_set_min_value(lv_scale_1, 0);
        lv_scale_set_max_value(lv_scale_1, 100);
        lv_scale_set_total_tick_count(lv_scale_1, 21);
        lv_scale_set_major_tick_every(lv_scale_1, 5);
        lv_scale_set_label_show(lv_scale_1, true);
        lv_obj_set_style_radius(lv_scale_1, 10, 0);
        lv_obj_set_style_transform_rotation(lv_scale_1, 450, LV_PART_INDICATOR);
        lv_obj_set_style_pad_bottom(lv_scale_1, 6, LV_PART_INDICATOR);
        lv_obj_add_style(lv_scale_1, &style_scale_main, 0);
        lv_obj_add_style(lv_scale_1, &style_scale_minor_ticks, LV_PART_ITEMS);
        lv_obj_add_style(lv_scale_1, &style_scale_major_ticks, LV_PART_INDICATOR);
        lv_scale_section_t * lv_scale_section_1 = lv_scale_add_section(lv_scale_1);
        lv_scale_set_section_min_value(lv_scale_1, lv_scale_section_1, 80);
        lv_scale_set_section_max_value(lv_scale_1, lv_scale_section_1, 100);
        lv_scale_set_section_style_main(lv_scale_1, lv_scale_section_1, &style_danger_line);
        lv_scale_set_section_style_indicator(lv_scale_1, lv_scale_section_1, &style_danger_ind);
        lv_scale_set_section_style_items(lv_scale_1, lv_scale_section_1, &style_danger_items);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

