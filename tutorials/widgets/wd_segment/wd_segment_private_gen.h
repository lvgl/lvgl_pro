/**
 * @file wd_segment_private_gen.h
 *
 */

#ifndef WD_SEGMENT_PRIVATE_H
#define WD_SEGMENT_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl_private.h"
#endif
#include "wd_segment.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_SEGMENT_USER_DATA
#define WD_SEGMENT_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    int32_t selected;
    lv_subject_t * bind_value;
    WD_SEGMENT_USER_DATA
} wd_segment_t;

extern const lv_obj_class_t wd_segment_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_segment_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_SEGMENT_PRIVATE_H*/