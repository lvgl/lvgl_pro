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

typedef struct {
    /* Index is the <COMP>_TIMELINE_* enum. Kept here rather than the root's
     * user_data, which stays free for the user. */
    lv_anim_timeline_t ** timelines;
} screen_animations_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static lv_anim_timeline_t * timeline_screen_open_create(lv_obj_t * obj);

static uint32_t screen_animations_get_instance_event;
static void screen_animations_get_instance_cb(lv_event_t * e);
static screen_animations_t * screen_animations_get_instance(lv_obj_t * obj);
static void screen_animations_destroy_instance(screen_animations_t * inst);
static void screen_animations_delete_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_animations_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    if(screen_animations_get_instance_event == 0) screen_animations_get_instance_event = lv_event_register_id();
    screen_animations_t * inst = lv_malloc(sizeof(screen_animations_t));
    lv_memzero(inst, sizeof(screen_animations_t));

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "screen_animations_#");
        lv_obj_add_event_cb(lv_obj_0, screen_animations_get_instance_cb, screen_animations_get_instance_event, inst);

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
        inst->timelines = at_array;

        lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, screen_animations_get_timeline(lv_obj_0, SCREEN_ANIMATIONS_TIMELINE_SCREEN_OPEN), 0, false);
        lv_obj_add_play_timeline_event(show, LV_EVENT_CLICKED, list_get_timeline(button_list, LIST_TIMELINE_LIST_OPEN), 0, false);
        lv_obj_add_play_timeline_event(hide, LV_EVENT_CLICKED, list_get_timeline(button_list, LIST_TIMELINE_LIST_OPEN), 0, true);

        the_root = lv_obj_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, screen_animations_delete_cb, LV_EVENT_DELETE, inst);
    else screen_animations_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * screen_animations_get_timeline(lv_obj_t * obj, screen_animations_timeline_t timeline_id)
{
    if ((uint32_t)timeline_id >= _SCREEN_ANIMATIONS_TIMELINE_CNT) {
        LV_LOG_WARN("screen_animations has no timeline with %d ID", timeline_id);
        return NULL;
    }

    screen_animations_t * inst = screen_animations_get_instance(obj);
    return inst ? inst->timelines[timeline_id] : NULL;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


static lv_anim_timeline_t * timeline_screen_open_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;



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

static void screen_animations_get_instance_cb(lv_event_t * e)
{
    void ** out = lv_event_get_param(e);
    *out = lv_event_get_user_data(e);
}

static screen_animations_t * screen_animations_get_instance(lv_obj_t * obj)
{
    screen_animations_t * inst = NULL;
    for(lv_obj_t * o = obj; o && !inst; o = lv_obj_get_parent(o)) {
        lv_obj_send_event(o, screen_animations_get_instance_event, &inst);
    }
    return inst;
}

static void screen_animations_destroy_instance(screen_animations_t * inst)
{
    if(inst->timelines) {
        for(uint32_t i = 0; i < 1; i++) lv_anim_timeline_delete(inst->timelines[i]);
        lv_free(inst->timelines);
    }
    lv_free(inst);
}

static void screen_animations_delete_cb(lv_event_t * e)
{
    screen_animations_destroy_instance(lv_event_get_user_data(e));
}

