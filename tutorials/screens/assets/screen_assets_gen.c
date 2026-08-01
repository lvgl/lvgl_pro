/**
 * @file screen_assets_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_assets_gen.h"
#include "../../tutorials.h"

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

lv_obj_t * screen_assets_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_assets_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_all(lv_obj_0, 8, 0);

        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_0, "I'm from a C array: °");
        lv_obj_set_style_text_font(lv_label_0, montserrat_14_c_array, 0);

        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_1, "I'm from a bin file: °");
        lv_obj_set_style_text_font(lv_label_1, montserrat_16_bin_file, 0);

        lv_obj_t * lv_label_2 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_2, "I'm TinyTTF from data: Schöne");
        lv_obj_set_style_text_font(lv_label_2, montserrat_18_tiny_ttf_data, 0);

        lv_obj_t * lv_label_3 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_3, "I'm TinyTTF from file: Schöne");
        lv_obj_set_style_text_font(lv_label_3, montserrat_20_tiny_ttf_file, 0);

        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_height(lv_obj_1, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(lv_obj_1, LV_FLEX_FLOW_ROW);
        lv_obj_t * lv_image_0 = lv_image_create(lv_obj_1);
        lv_image_set_src(lv_image_0, flower_data);

        lv_obj_t * lv_image_1 = lv_image_create(lv_obj_1);
        lv_image_set_src(lv_image_1, flower_file);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

