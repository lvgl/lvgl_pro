/**
 * @file lvgl_pro_examples_gen.h
 */

#ifndef LVGL_PRO_LVGL_PRO_EXAMPLES_GEN_H
#define LVGL_PRO_LVGL_PRO_EXAMPLES_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif



/* Prototypes for target functions, needed by responsive const definitions */

void lvgl_pro_examples_set_target(uint32_t target);
uint32_t lvgl_pro_examples_get_target(void);
bool lvgl_pro_examples_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define LVGL_PRO_EXAMPLES_TARGET_UNDEFINED  (0 << 1)
#define LVGL_PRO_EXAMPLES_TARGET_TARGET1    (1 << 1)
#define LVGL_PRO_EXAMPLES_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef LVGL_PRO_EXAMPLES_COMPILE_TARGET
#define LVGL_PRO_EXAMPLES_COMPILE_TARGET LVGL_PRO_EXAMPLES_TARGET_ALL
#endif

#define LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(target) (LVGL_PRO_EXAMPLES_COMPILE_TARGET & (target) ? 1 : 0)

/**
 * Label color over filled widgets
 */
#define COLOR_TEXT_ON_FILL (lv_color_hex(0x013992))


#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**
 * Animation path of a style transition with a `bezier(…)` easing. The control
 * points come from the transition descriptor's `user_data`, as a transition
 * descriptor cannot store animation parameters itself.
 */
static inline int32_t lvgl_pro_examples_style_transition_bezier_path_helper(const lv_anim_t * a)
{
    const lv_anim_bezier3_para_t * para = (const lv_anim_bezier3_para_t *)lv_anim_get_user_data(a);
    if(para == NULL) return lv_anim_path_linear(a);

    lv_anim_t a_tmp = *a;
    lv_anim_set_bezier3_param(&a_tmp, para->x1, para->y1, para->x2, para->y2);
    return lv_anim_path_custom_bezier3(&a_tmp);
}

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * font_large;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * img_logo;
extern const void * imgbtn_left;
extern const void * imgbtn_mid;
extern const void * imgbtn_right;
extern const void * img_bulb;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_value;
extern lv_subject_t subject_value2;
extern lv_subject_t subject_opa;
extern lv_subject_t subject_index;
extern lv_subject_t subject_checked;
extern lv_subject_t subject_text;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/*----------------
 * Easing Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void lvgl_pro_examples_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "screens/lv_example_arc_gen.h"
#include "screens/lv_example_bar_gen.h"
#include "screens/lv_example_button_gen.h"
#include "screens/lv_example_buttonmatrix_gen.h"
#include "screens/lv_example_calendar_gen.h"
#include "screens/lv_example_chart_gen.h"
#include "screens/lv_example_checkbox_gen.h"
#include "screens/lv_example_dropdown_gen.h"
#include "screens/lv_example_gif_gen.h"
#include "screens/lv_example_image_gen.h"
#include "screens/lv_example_imagebutton_gen.h"
#include "screens/lv_example_keyboard_gen.h"
#include "screens/lv_example_label_gen.h"
#include "screens/lv_example_led_gen.h"
#include "screens/lv_example_line_gen.h"
#include "screens/lv_example_obj_gen.h"
#include "screens/lv_example_qrcode_gen.h"
#include "screens/lv_example_roller_gen.h"
#include "screens/lv_example_scale_gen.h"
#include "screens/lv_example_slider_gen.h"
#include "screens/lv_example_spangroup_gen.h"
#include "screens/lv_example_spinbox_gen.h"
#include "screens/lv_example_spinner_gen.h"
#include "screens/lv_example_switch_gen.h"
#include "screens/lv_example_table_gen.h"
#include "screens/lv_example_tabview_gen.h"
#include "screens/lv_example_textarea_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_LVGL_PRO_EXAMPLES_GEN_H*/