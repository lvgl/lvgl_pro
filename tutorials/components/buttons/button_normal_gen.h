/**
 * @file button_normal_gen.h
 */

#ifndef LVGL_PRO_BUTTON_NORMAL_GEN_H
#define LVGL_PRO_BUTTON_NORMAL_GEN_H

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

typedef enum {
    BUTTON_NORMAL_TIMELINE_SHOW_UP = 0,
    _BUTTON_NORMAL_TIMELINE_CNT = 1
}button_normal_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * button_normal_create(lv_obj_t * parent, const char * label_text);

/**
 * Get a timeline of a button_normal
 * @param obj          pointer to a button_normal component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * button_normal_get_timeline(lv_obj_t * obj, button_normal_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_BUTTON_NORMAL_GEN_H*/