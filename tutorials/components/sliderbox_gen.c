/**
 * @file sliderbox_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "sliderbox_gen.h"
#include "../tutorials.h"

/*********************
 *      DEFINES
 *********************/

/**
 * Width of the whole slider box
 */
#define WIDTH (200)


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
    char * unit_snapshot;
} sliderbox_t;

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

static void sliderbox_destroy_instance(sliderbox_t * inst);
static void sliderbox_delete_cb(lv_event_t * e);
static void sliderbox_lv_label_1_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * sliderbox_create(lv_obj_t * parent, const char * title, lv_subject_t * subject, const char * unit)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_dark;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_dark);

        lv_style_set_bg_color(&style_dark, lv_color_hex3(0x333));
        lv_style_set_text_color(&style_dark, lv_color_hex3(0xfff));
        lv_style_set_border_color(&style_dark, lv_color_hex3(0x111));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    sliderbox_t * inst = lv_malloc(sizeof(sliderbox_t));
    lv_memzero(inst, sizeof(sliderbox_t));
    inst->subject = subject;
    inst->unit_snapshot = lv_strdup(unit);

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(parent);
        lv_obj_set_name_static(lv_obj_0, "sliderbox_#");
        lv_obj_set_width(lv_obj_0, WIDTH);
        lv_obj_set_height(lv_obj_0, LV_SIZE_CONTENT);
        lv_obj_set_flex_flow(lv_obj_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(lv_obj_0, LV_FLEX_ALIGN_CENTER, 0);

        lv_obj_bind_style(lv_obj_0, &style_dark, 0, subject_dark_mode, 1);
        lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
        lv_label_set_text(lv_label_0, title);
        lv_obj_set_width(lv_label_0, lv_pct(100));
        lv_obj_set_style_text_align(lv_label_0, LV_TEXT_ALIGN_CENTER, 0);

        lv_obj_t * round_button_0 = round_button_create(lv_obj_0, "-", subject, -1);
        lv_obj_set_flex_in_new_track(round_button_0, true);

        lv_obj_t * lv_label_1 = lv_label_create(lv_obj_0);
        lv_obj_set_flex_grow(lv_label_1, 1);
        lv_subject_add_observer_obj(inst->subject, sliderbox_lv_label_1_text_binding_cb, lv_label_1, inst);
        lv_obj_set_style_text_align(lv_label_1, LV_TEXT_ALIGN_CENTER, 0);

        round_button_create(lv_obj_0, "+", subject, 1);

        lv_obj_t * lv_slider_0 = lv_slider_create(lv_obj_0);
        lv_slider_bind_value(lv_slider_0, subject);
        lv_obj_set_flex_in_new_track(lv_slider_0, true);
        lv_obj_set_width(lv_slider_0, lv_pct(100));

        the_root = lv_obj_0;
    }
    #endif

    if(the_root) lv_obj_add_event_cb(the_root, sliderbox_delete_cb, LV_EVENT_DELETE, inst);
    else sliderbox_destroy_instance(inst); /* no target matched, so nothing owns it */

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void sliderbox_destroy_instance(sliderbox_t * inst)
{
    lv_free(inst->unit_snapshot);
    lv_free(inst);
}

static void sliderbox_delete_cb(lv_event_t * e)
{
    sliderbox_destroy_instance(lv_event_get_user_data(e));
}

static void sliderbox_lv_label_1_text_binding_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(subject);
    sliderbox_t * inst = lv_observer_get_user_data(observer);
    lv_obj_t * obj = lv_observer_get_target_obj(observer);
    char eval_buf_1[LV_XML_EVAL_STRING_BUF_SIZE];
    lv_snprintf(eval_buf_1, sizeof(eval_buf_1), "%d%s", (int)(lv_subject_get_int(inst->subject)), inst->unit_snapshot);
    lv_label_set_text(obj, eval_buf_1);
}

