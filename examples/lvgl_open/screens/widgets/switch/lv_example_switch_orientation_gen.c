/**
 * @file lv_example_switch_orientation_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "lv_example_switch_orientation_gen.h"
#include "../../../lvgl_open_examples.h"

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
} lv_example_switch_orientation_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static lv_anim_timeline_t * timeline_asd_create(lv_obj_t * obj);

static uint32_t lv_example_switch_orientation_get_instance_event;
static void lv_example_switch_orientation_get_instance_cb(lv_event_t * e);
static lv_example_switch_orientation_t * lv_example_switch_orientation_get_instance(lv_obj_t * obj);
static void lv_example_switch_orientation_destroy_instance(lv_example_switch_orientation_t * inst);
static void lv_example_switch_orientation_delete_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * lv_example_switch_orientation_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    if(lv_example_switch_orientation_get_instance_event == 0) lv_example_switch_orientation_get_instance_event = lv_event_register_id();
    lv_example_switch_orientation_t * inst = lv_malloc(sizeof(lv_example_switch_orientation_t));
    lv_memzero(inst, sizeof(lv_example_switch_orientation_t));

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_switch_orientation_#");
        lv_obj_add_event_cb(lv_obj_0, lv_example_switch_orientation_get_instance_cb, lv_example_switch_orientation_get_instance_event, inst);
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * sw_1 = lv_switch_create(lv_obj_0);
        lv_obj_set_name(sw_1, "sw_1");
        lv_obj_set_width(sw_1, 60);
        lv_obj_set_height(sw_1, 30);
        lv_switch_set_orientation(sw_1, LV_SWITCH_ORIENTATION_HORIZONTAL);
        lv_obj_set_checked(sw_1, true);

        lv_obj_t * sw_2 = lv_switch_create(lv_obj_0);
        lv_obj_set_name(sw_2, "sw_2");
        lv_obj_set_width(sw_2, 30);
        lv_obj_set_height(sw_2, 60);
        lv_switch_set_orientation(sw_2, LV_SWITCH_ORIENTATION_VERTICAL);
        lv_obj_set_checked(sw_2, true);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_CNT);
        at_array[LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_ASD] = timeline_asd_create(lv_obj_0);
        inst->timelines = at_array;

        the_root = lv_obj_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, lv_example_switch_orientation_delete_cb, LV_EVENT_DELETE, inst);
    else lv_example_switch_orientation_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * lv_example_switch_orientation_get_timeline(lv_obj_t * obj, lv_example_switch_orientation_timeline_t timeline_id)
{
    if ((uint32_t)timeline_id >= _LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_CNT) {
        LV_LOG_WARN("lv_example_switch_orientation has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_example_switch_orientation_t * inst = lv_example_switch_orientation_get_instance(obj);
    return inst ? inst->timelines[timeline_id] : NULL;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


static lv_anim_timeline_t * timeline_asd_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_set_repeat_count(at, 20);
    lv_anim_timeline_set_repeat_delay(at, 20);
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;



    return at;
}

static void lv_example_switch_orientation_get_instance_cb(lv_event_t * e)
{
    void ** out = lv_event_get_param(e);
    *out = lv_event_get_user_data(e);
}

static lv_example_switch_orientation_t * lv_example_switch_orientation_get_instance(lv_obj_t * obj)
{
    lv_example_switch_orientation_t * inst = NULL;
    for(lv_obj_t * o = obj; o && !inst; o = lv_obj_get_parent(o)) {
        lv_obj_send_event(o, lv_example_switch_orientation_get_instance_event, &inst);
    }
    return inst;
}

static void lv_example_switch_orientation_destroy_instance(lv_example_switch_orientation_t * inst)
{
    if(inst->timelines) {
        for(uint32_t i = 0; i < 1; i++) lv_anim_timeline_delete(inst->timelines[i]);
        lv_free(inst->timelines);
    }
    lv_free(inst);
}

static void lv_example_switch_orientation_delete_cb(lv_event_t * e)
{
    lv_example_switch_orientation_destroy_instance(lv_event_get_user_data(e));
}

