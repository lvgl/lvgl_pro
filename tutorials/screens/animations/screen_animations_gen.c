/**
 * @file screen_animations_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_animations_gen.h"
#include "../../tutorials.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static lv_anim_timeline_t * timeline_screen_open_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_animations_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_animations_#");

        lv_obj_t * button_list = list_create(lv_obj_0);
        lv_obj_set_name(button_list, "button_list");

        lv_obj_t * show = button_normal_create(lv_obj_0, "Show");
        lv_obj_set_name(show, "show");
        lv_obj_set_align(show, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_x(show, -10);
        lv_obj_set_y(show, 10);

        lv_obj_t * hide = button_normal_create(lv_obj_0, "Hide");
        lv_obj_set_name(hide, "hide");
        lv_obj_set_align(hide, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_x(hide, -10);
        lv_obj_set_y(hide, 70);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _SCREEN_ANIMATIONS_TIMELINE_CNT);
        at_array[SCREEN_ANIMATIONS_TIMELINE_SCREEN_OPEN] = timeline_screen_open_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, screen_animations_get_timeline(lv_obj_0, SCREEN_ANIMATIONS_TIMELINE_SCREEN_OPEN), 0, false);
        lv_obj_add_play_timeline_event(show, LV_EVENT_CLICKED, list_get_timeline(button_list, LIST_TIMELINE_LIST_OPEN), 0, false);
        lv_obj_add_play_timeline_event(hide, LV_EVENT_CLICKED, list_get_timeline(button_list, LIST_TIMELINE_LIST_OPEN), 0, true);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * screen_animations_get_timeline(lv_obj_t * obj, screen_animations_timeline_t timeline_id)
{
    if (timeline_id >= _SCREEN_ANIMATIONS_TIMELINE_CNT) {
        LV_LOG_WARN("screen_animations has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_screen_open_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;



    lv_obj_t * show = lv_obj_find_by_name(obj, "show");
    at_to_merge = button_normal_get_timeline(show, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 0);

    lv_obj_t * hide = lv_obj_find_by_name(obj, "hide");
    at_to_merge = button_normal_get_timeline(hide, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 0);

    lv_obj_t * button_list = lv_obj_find_by_name(obj, "button_list");
    at_to_merge = list_get_timeline(button_list, LIST_TIMELINE_LIST_OPEN);
    lv_anim_timeline_merge(at, at_to_merge, 0);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _SCREEN_ANIMATIONS_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

