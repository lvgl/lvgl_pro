/**
 * @file wd_segment.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_segment_private_gen.h"
#include "../../tutorials.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void set_selected_item(wd_segment_t * widget, int32_t index);
static void segment_selected_cb(lv_event_t *e);
static void value_observer_cb(lv_observer_t * observer, lv_subject_t * subject);
/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_segment_constructor_hook(lv_obj_t * obj)
{
    wd_segment_t * widget = (wd_segment_t *)obj;
    widget->selected = -1; // default selected item
}

void wd_segment_destructor_hook(lv_obj_t * obj)
{

}

void wd_segment_event_hook(lv_event_t * e)
{

}

void wd_segment_set_selected(lv_obj_t * wd_segment, int32_t selected)
{
    wd_segment_t * widget = (wd_segment_t *)wd_segment;
    widget->selected = selected;
    set_selected_item(widget, widget->selected);

}


void wd_segment_bind_value(lv_obj_t * wd_segment, lv_subject_t * bind_value)
{
    wd_segment_t * widget = (wd_segment_t *)wd_segment;
    widget->bind_value = bind_value;
    lv_subject_add_observer_obj(widget->bind_value, value_observer_cb, wd_segment, widget);

}

lv_obj_t * wd_segment_add_button(lv_obj_t * wd_segment, const char * text)
{
    wd_segment_t * widget = (wd_segment_t *)wd_segment;
    lv_obj_t * segment_item = segment_item_create(wd_segment, text);
    lv_obj_set_flex_grow(segment_item, 1);
    lv_obj_add_event_cb(segment_item, segment_selected_cb, LV_EVENT_CLICKED, widget);
    if (widget->bind_value) {
        widget->selected = lv_subject_get_int(widget->bind_value);
    }
    set_selected_item(widget, widget->selected);
    return segment_item;
}

int32_t wd_segment_get_selected(lv_obj_t * wd_segment)
{
    wd_segment_t * widget = (wd_segment_t *)wd_segment;
    return widget->selected;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void segment_selected_cb(lv_event_t *e)
{
    lv_obj_t *clicked = lv_event_get_target(e);
    wd_segment_t * widget = (wd_segment_t *)lv_event_get_user_data(e);
    lv_obj_t * obj = (lv_obj_t *)widget;
    for (int32_t i = 0; i < lv_obj_get_child_count(obj); i++)
    {
        lv_obj_t *child = lv_obj_get_child(obj, i);
        lv_obj_set_state(child, LV_STATE_CHECKED, child == clicked);
        if (child == clicked) {
            widget->selected = i;
            if (widget->bind_value) {
                lv_subject_set_int(widget->bind_value, widget->selected);
            }
        }
    }
    lv_obj_send_event(obj, LV_EVENT_VALUE_CHANGED, NULL);
}

static void set_selected_item(wd_segment_t * widget, int32_t index)
{
    
    lv_obj_t * obj = (lv_obj_t *)widget;
    int32_t count = lv_obj_get_child_count(obj);
    for (int32_t i = 0; i < count; i++)
    {
        lv_obj_t *child = lv_obj_get_child(obj, i);
        lv_obj_set_state(child, LV_STATE_CHECKED, i == index);
    }
}


static void value_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    wd_segment_t * widget = (wd_segment_t *)lv_observer_get_user_data(observer);
    int32_t index = lv_subject_get_int(subject);
    widget->selected = index;
    set_selected_item(widget, index);
}