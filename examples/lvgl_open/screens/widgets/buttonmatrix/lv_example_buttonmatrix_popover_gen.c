/**
 * @file lv_example_buttonmatrix_popover_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_buttonmatrix_popover_gen.h"
#include "../../../lvgl_open_examples.h"

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

lv_obj_t * lv_example_buttonmatrix_popover_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_buttonmatrix_popover_#");

        lv_obj_t * buttonmatrix = lv_buttonmatrix_create(lv_obj_0);
        lv_obj_set_name(buttonmatrix, "buttonmatrix");
        lv_obj_set_align(buttonmatrix, LV_ALIGN_CENTER);
        lv_obj_set_width(buttonmatrix, lv_pct(90));
        lv_obj_set_height(buttonmatrix, 80);
        static const char *buttonmatrix_map_0[] = {"Q", "W", "E", "R", "T", "Y", NULL};
        lv_buttonmatrix_set_map(buttonmatrix, buttonmatrix_map_0);
        static const lv_buttonmatrix_ctrl_t buttonmatrix_ctrl_map_0[] = {LV_BUTTONMATRIX_CTRL_POPOVER, LV_BUTTONMATRIX_CTRL_POPOVER, LV_BUTTONMATRIX_CTRL_POPOVER, LV_BUTTONMATRIX_CTRL_POPOVER, LV_BUTTONMATRIX_CTRL_POPOVER, LV_BUTTONMATRIX_CTRL_POPOVER};
        lv_buttonmatrix_set_ctrl_map(buttonmatrix, buttonmatrix_ctrl_map_0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

