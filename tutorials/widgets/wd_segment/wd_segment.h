/**
 * @file wd_segment.h
 *
 */

#ifndef WD_SEGMENT_H
#define WD_SEGMENT_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "wd_segment_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

int32_t wd_segment_get_selected(lv_obj_t * wd_segment);

/**********************
 *      MACROS
 **********************/

#define WD_SEGMENT_USER_DATA

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_SEGMENT_H*/