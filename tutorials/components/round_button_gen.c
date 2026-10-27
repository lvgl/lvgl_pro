/**
 * @file round_button_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "round_button_gen.h"
#include "../tutorials.h"

/*********************
 *      DEFINES
 *********************/

#define SIZE (36)


/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    /* <prop type="subject">: owned by the caller, stored, never deleted */
    lv_subject_t * subject;

    /* A plain <prop> a binding froze. The runtime inlines it, because it
     * re-parses the view per instance; the generator compiles once, so the value
     * is kept here and read back in the callback. A plain field, not a subject:
     * nothing ever notifies on it. */
    int32_t step_snapshot;
} round_button_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static void round_button_destroy_instance(round_button_t * inst);
static void round_button_delete_cb(lv_event_t * e);
static void round_button_set_subject_cb(lv_event_t * e);
static void round_button_set_subject_cb_2(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * round_button_create(lv_obj_t * parent, const char * text, lv_subject_t * subject, int32_t step)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    round_button_t * inst = lv_malloc(sizeof(round_button_t));
    lv_memzero(inst, sizeof(round_button_t));
    inst->subject = subject;
    inst->step_snapshot = step;

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_button_0 = lv_button_create(parent);
        lv_obj_set_name_static(lv_button_0, "round_button_#");
        lv_obj_set_width(lv_button_0, SIZE);
        lv_obj_set_height(lv_button_0, SIZE);
        lv_obj_set_style_radius(lv_button_0, SIZE / 2, 0);
        lv_obj_set_ext_click_area(lv_button_0, 8);

        lv_obj_t * lv_label_0 = lv_label_create(lv_button_0);
        lv_label_set_text(lv_label_0, text);
        lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);

        lv_obj_add_event_cb(lv_button_0, round_button_set_subject_cb, LV_EVENT_PRESSED, inst);
        lv_obj_add_event_cb(lv_button_0, round_button_set_subject_cb_2, LV_EVENT_LONG_PRESSED_REPEAT, inst);

        the_root = lv_button_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, round_button_delete_cb, LV_EVENT_DELETE, inst);
    else round_button_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void round_button_destroy_instance(round_button_t * inst)
{
    lv_free(inst);
}

static void round_button_delete_cb(lv_event_t * e)
{
    round_button_destroy_instance(lv_event_get_user_data(e));
}

static void round_button_set_subject_cb(lv_event_t * e)
{
    round_button_t * inst = lv_event_get_user_data(e);
    lv_subject_set_int(inst->subject, lv_subject_get_int(inst->subject) + inst->step_snapshot);
}

static void round_button_set_subject_cb_2(lv_event_t * e)
{
    round_button_t * inst = lv_event_get_user_data(e);
    lv_subject_set_int(inst->subject, lv_subject_get_int(inst->subject) + inst->step_snapshot);
}

