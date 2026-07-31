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

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static lv_anim_timeline_t * timeline_asd_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * lv_example_switch_orientation_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_ALL)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "lv_example_switch_orientation_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(lv_obj_0, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_t * sw_1 = lv_switch_create(lv_obj_0);
        lv_obj_set_name(sw_1, "sw_1");
        lv_obj_set_width(sw_1, 60);
        lv_obj_set_height(sw_1, 30);
        lv_switch_set_orientation(sw_1, LV_SWITCH_ORIENTATION_HORIZONTAL);
        lv_obj_set_state(sw_1, LV_STATE_CHECKED, true);

        lv_obj_t * sw_2 = lv_switch_create(lv_obj_0);
        lv_obj_set_name(sw_2, "sw_2");
        lv_obj_set_width(sw_2, 30);
        lv_obj_set_height(sw_2, 60);
        lv_switch_set_orientation(sw_2, LV_SWITCH_ORIENTATION_VERTICAL);
        lv_obj_set_state(sw_2, LV_STATE_CHECKED, true);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_CNT);
        at_array[LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_ASD] = timeline_asd_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * lv_example_switch_orientation_get_timeline(lv_obj_t * obj, lv_example_switch_orientation_timeline_t timeline_id)
{
    if (timeline_id >= _LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_CNT) {
        LV_LOG_WARN("lv_example_switch_orientation has no timeline with %d ID", timeline_id);
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

static lv_anim_timeline_t * timeline_asd_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_set_repeat_count(at, 20);
    lv_anim_timeline_set_repeat_delay(at, 20);
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;



    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _LV_EXAMPLE_SWITCH_ORIENTATION_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

