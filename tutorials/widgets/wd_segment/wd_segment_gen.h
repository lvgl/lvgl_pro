/**
 * @file wd_segment_gen.h
 *
 */

#ifndef WD_SEGMENT_GEN_H
#define WD_SEGMENT_GEN_H

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

#include "../../tutorials_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a wd_segment object
 * @param parent pointer to an object, it will be the parent of the new wd_segment
 * @return pointer to the created wd_segment
 */
lv_obj_t * wd_segment_create(lv_obj_t * parent);
/**
 * The current selected item, -1 for none
 * @param obj   pointer to a wd_segment
 * @param selected  The current selected item, -1 for none
 */
void wd_segment_set_selected(lv_obj_t * wd_segment, int32_t selected);

/**
 * The subject to bind the selected item
 * @param obj   pointer to a wd_segment
 * @param bind_value  The subject to bind the selected item
 */
void wd_segment_bind_value(lv_obj_t * wd_segment, lv_subject_t * bind_value);

/**
 * wd_segment button
 * @param obj   pointer to a wd_segment
 * @param text  text
 */
lv_obj_t * wd_segment_add_button(lv_obj_t * wd_segment, const char * text);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_SEGMENT_GEN_H*/