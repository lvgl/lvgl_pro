/**
 * @file list_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "list_gen.h"
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

static lv_anim_timeline_t * timeline_list_open_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * list_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "list_#");
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_all(lv_obj_0, UNIT_SMALL, 0);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0x8db4ef), 0);
        lv_obj_set_height(lv_obj_0, lv_pct(100));
        lv_obj_set_width(lv_obj_0, lv_pct(50));

        lv_obj_t * button_0 = button_normal_create(lv_obj_0, "Button 0");
        lv_obj_set_name(button_0, "button_0");

        lv_obj_t * button_1 = button_normal_create(lv_obj_0, "Button 1");
        lv_obj_set_name(button_1, "button_1");

        lv_obj_t * button_2 = button_normal_create(lv_obj_0, "Button 2");
        lv_obj_set_name(button_2, "button_2");

        lv_obj_t * button_3 = button_normal_create(lv_obj_0, "Button 3");
        lv_obj_set_name(button_3, "button_3");

        lv_obj_t * button_4 = button_normal_create(lv_obj_0, "Button 4");
        lv_obj_set_name(button_4, "button_4");

        lv_obj_t * button_5 = button_normal_create(lv_obj_0, "Button 5");
        lv_obj_set_name(button_5, "button_5");

        lv_obj_t * button_6 = button_normal_create(lv_obj_0, "Button 6");
        lv_obj_set_name(button_6, "button_6");

        lv_obj_t * button_7 = button_normal_create(lv_obj_0, "Button 7");
        lv_obj_set_name(button_7, "button_7");


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _LIST_TIMELINE_CNT);
        at_array[LIST_TIMELINE_LIST_OPEN] = timeline_list_open_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * list_get_timeline(lv_obj_t * obj, list_timeline_t timeline_id)
{
    if (timeline_id >= _LIST_TIMELINE_CNT) {
        LV_LOG_WARN("list has no timeline with %d ID", timeline_id);
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

static lv_anim_timeline_t * timeline_list_open_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, 0, 255);
    lv_anim_set_duration(&a, 300);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, -60, 0);
    lv_anim_set_duration(&a, 300);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    lv_obj_t * button_0 = lv_obj_find_by_name(obj, "button_0");
    at_to_merge = button_normal_get_timeline(button_0, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 0);

    lv_obj_t * button_1 = lv_obj_find_by_name(obj, "button_1");
    at_to_merge = button_normal_get_timeline(button_1, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 100);

    lv_obj_t * button_2 = lv_obj_find_by_name(obj, "button_2");
    at_to_merge = button_normal_get_timeline(button_2, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 200);

    lv_obj_t * button_3 = lv_obj_find_by_name(obj, "button_3");
    at_to_merge = button_normal_get_timeline(button_3, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 300);

    lv_obj_t * button_4 = lv_obj_find_by_name(obj, "button_4");
    at_to_merge = button_normal_get_timeline(button_4, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 400);

    lv_obj_t * button_5 = lv_obj_find_by_name(obj, "button_5");
    at_to_merge = button_normal_get_timeline(button_5, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 400);

    lv_obj_t * button_6 = lv_obj_find_by_name(obj, "button_6");
    at_to_merge = button_normal_get_timeline(button_6, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 400);

    lv_obj_t * button_7 = lv_obj_find_by_name(obj, "button_7");
    at_to_merge = button_normal_get_timeline(button_7, BUTTON_NORMAL_TIMELINE_SHOW_UP);
    lv_anim_timeline_merge(at, at_to_merge, 400);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _LIST_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

