/**
 * @file lv_example_buttonmatrix_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_buttonmatrix_gen.h"
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

lv_obj_t * lv_example_buttonmatrix_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_bm;
    static lv_style_t style_keys;
    static lv_style_t style_keys_pr;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_bm);
        lv_style_init(&style_keys);
        lv_style_init(&style_keys_pr);

        lv_style_set_bg_color(&style_bm, lv_color_hex(0x0f172a));
        lv_style_set_bg_opa(&style_bm, (255 * 100 / 100));
        lv_style_set_radius(&style_bm, 8);
        lv_style_set_pad_all(&style_bm, 8);
        lv_style_set_bg_color(&style_keys, lv_color_hex(0x313d51));
        lv_style_set_text_color(&style_keys, lv_color_hex(0xe2e8f0));
        lv_style_set_radius(&style_keys, 6);
        lv_style_set_shadow_width(&style_keys, 4);
        lv_style_set_bg_color(&style_keys_pr, lv_color_hex(0x3b82f6));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_buttonmatrix_#");
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(lv_obj_0, 14, 0);

        lv_obj_t * lv_buttonmatrix_0 = lv_buttonmatrix_create(lv_obj_0);
        lv_obj_set_width(lv_buttonmatrix_0, 260);
        lv_obj_set_height(lv_buttonmatrix_0, 170);
        lv_obj_set_align(lv_buttonmatrix_0, LV_ALIGN_CENTER);
        static const char *lv_buttonmatrix_0_map_0[] = {"7", "8", "9", "\n", "4", "5", "6", "\n", "1", "2", "3", "\n", "0", "Clear", NULL};
        lv_buttonmatrix_set_map(lv_buttonmatrix_0, lv_buttonmatrix_0_map_0);
        static const lv_buttonmatrix_ctrl_t lv_buttonmatrix_0_ctrl_map_0[] = {LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_NONE, LV_BUTTONMATRIX_CTRL_WIDTH_2, LV_BUTTONMATRIX_CTRL_DISABLED};
        lv_buttonmatrix_set_ctrl_map(lv_buttonmatrix_0, lv_buttonmatrix_0_ctrl_map_0);
        lv_obj_add_style(lv_buttonmatrix_0, &style_bm, 0);
        lv_obj_add_style(lv_buttonmatrix_0, &style_keys, LV_PART_ITEMS);
        lv_obj_add_style(lv_buttonmatrix_0, &style_keys_pr, LV_PART_ITEMS | LV_STATE_PRESSED);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

