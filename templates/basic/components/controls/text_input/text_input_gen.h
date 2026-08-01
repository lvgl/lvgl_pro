/**
 * @file text_input_gen.h
 */

#ifndef TEXT_INPUT_H
#define TEXT_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * text_input_create(lv_obj_t * parent, const char * text, const char * placeholder, bool password);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*TEXT_INPUT_H*/