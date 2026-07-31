/**
 * @file wd_segment_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_segment_private_gen.h"
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
#include "../../tutorials.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void wd_segment_constructor_hook(lv_obj_t * obj);
void wd_segment_destructor_hook(lv_obj_t * obj);
void wd_segment_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_segment_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_segment_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_segment_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_segment_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_segment_constructor,
    .destructor_cb = wd_segment_destructor,
    .event_cb = wd_segment_event,
    .instance_size = sizeof(wd_segment_t),
    .editable = 1,
    .name = "wd_segment"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_segment_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_segment_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_segment_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_segment_t * widget = (wd_segment_t *)obj;
    static lv_style_t style_base;
    static bool style_inited = false;

    if (!style_inited) {
        #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
        if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
            lv_style_init(&style_base);
            lv_style_set_width(&style_base, 200);
            lv_style_set_height(&style_base, 40);
            lv_style_set_bg_opa(&style_base, (255 * 100 / 100));
            lv_style_set_bg_color(&style_base, lv_color_hex(0xa2a2a2));
            lv_style_set_radius(&style_base, 10);
            lv_style_set_layout(&style_base, LV_LAYOUT_FLEX);
            lv_style_set_flex_flow(&style_base, LV_FLEX_FLOW_ROW);
            lv_style_set_clip_corner(&style_base, true);

        }
        #endif
        style_inited = true;
    }

    lv_obj_t * the_root = NULL;
    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_add_style(obj, &style_base, 0);

        the_root = obj;
    }
    #endif
    wd_segment_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_segment_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_segment_destructor_hook(obj);
}

static void wd_segment_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_segment_class, e);
    if(res != LV_RESULT_OK) return;

    wd_segment_event_hook(e);
}

