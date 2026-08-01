/**
 * @file lvgl_open_template.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_open_template.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_open_template_init(const char * asset_path)
{
    LV_LOG("Initializing custom C code using LVGL v%d.%d.%d", LVGL_VERSION_MAJOR, LVGL_VERSION_MINOR, LVGL_VERSION_PATCH);

    lvgl_open_template_init_gen(asset_path);

    /* Add your own custom code here if needed */
}

/**********************
 *   STATIC FUNCTIONS
 **********************/