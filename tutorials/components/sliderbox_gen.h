/**
 * @file sliderbox_gen.h
 */

#ifndef SLIDERBOX_H
#define SLIDERBOX_H

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

#ifdef LV_USE_XML
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

lv_obj_t * sliderbox_create(lv_obj_t * parent, const char * title, lv_subject_t * subject, const char * unit);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*SLIDERBOX_H*/