/**
 * @file button_normal_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_normal_gen.h"
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

static lv_anim_timeline_t * timeline_show_up_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * button_normal_create(lv_obj_t * parent, const char * label_text)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
        if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
            lv_style_init(&style_base);
            lv_style_set_bg_opa(&style_base, (255 * 100 / 100));
            lv_style_set_bg_color(&style_base, DARK_BLUE);
            lv_style_set_width(&style_base, LV_SIZE_CONTENT);
            lv_style_set_height(&style_base, LV_SIZE_CONTENT);
            lv_style_set_radius(&style_base, UNIT_MEDIUM);
            lv_style_set_pad_hor(&style_base, UNIT_LARGE);
            lv_style_set_pad_ver(&style_base, UNIT_MEDIUM);
            lv_style_set_text_color(&style_base, lv_color_hex3(0xfff));

            lv_style_init(&style_pressed);
            lv_style_set_recolor(&style_pressed, lv_color_hex3(0xfff));
            lv_style_set_recolor_opa(&style_pressed, (255 * 20 / 100));

        }
        #endif
        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_button_0 = lv_button_create(parent);
        lv_obj_set_name_static(lv_button_0, "button_normal_#");

        lv_obj_remove_style_all(lv_button_0);
        lv_obj_add_style(lv_button_0, &style_base, 0);
        lv_obj_add_style(lv_button_0, &style_pressed, LV_STATE_PRESSED);
        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, label_text);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _BUTTON_NORMAL_TIMELINE_CNT);
        at_array[BUTTON_NORMAL_TIMELINE_SHOW_UP] = timeline_show_up_create(lv_button_0);
        lv_obj_set_user_data(lv_button_0, at_array);
        lv_obj_add_event_cb(lv_button_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        the_root = lv_button_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * button_normal_get_timeline(lv_obj_t * obj, button_normal_timeline_t timeline_id)
{
    if (timeline_id >= _BUTTON_NORMAL_TIMELINE_CNT) {
        LV_LOG_WARN("button_normal has no timeline with %d ID", timeline_id);
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

static lv_anim_timeline_t * timeline_show_up_create(lv_obj_t * obj)
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
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSLATE_Y & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, obj);
    lv_anim_set_values(&a, 20, 0);
    lv_anim_set_duration(&a, 200);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _BUTTON_NORMAL_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

