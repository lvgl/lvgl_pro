/**
 * @file lv_example_switch_orientation_gen.h
 */

#ifndef LV_EXAMPLE_SWITCH_ORIENTATION_H
#define LV_EXAMPLE_SWITCH_ORIENTATION_H

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

typedef enum {
    LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_ASD = 0,
    _LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_CNT = 1
}lv_example_switch_orientation_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * lv_example_switch_orientation_create(void);

/**
 * Get a timeline of a lv_example_switch_orientation
 * @param obj          pointer to a lv_example_switch_orientation component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * lv_example_switch_orientation_get_timeline(lv_obj_t * obj, lv_example_switch_orientation_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_EXAMPLE_SWITCH_ORIENTATION_H*/