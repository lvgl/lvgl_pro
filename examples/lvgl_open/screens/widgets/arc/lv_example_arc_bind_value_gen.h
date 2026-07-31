/**
 * @file lv_example_arc_bind_value_gen.h
 */

#ifndef LV_EXAMPLE_ARC_BIND_VALUE_H
#define LV_EXAMPLE_ARC_BIND_VALUE_H

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
    LV_EXAMPLE_ARC_BIND_VALUE_TIMELINE_T1 = 0,
    _LV_EXAMPLE_ARC_BIND_VALUE_TIMELINE_CNT = 1
}lv_example_arc_bind_value_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * lv_example_arc_bind_value_create(void);

/**
 * Get a timeline of a lv_example_arc_bind_value
 * @param obj          pointer to a lv_example_arc_bind_value component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * lv_example_arc_bind_value_get_timeline(lv_obj_t * obj, lv_example_arc_bind_value_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LV_EXAMPLE_ARC_BIND_VALUE_H*/