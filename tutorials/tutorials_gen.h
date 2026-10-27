/**
 * @file tutorials_gen.h
 */

#ifndef LVGL_PRO_TUTORIALS_GEN_H
#define LVGL_PRO_TUTORIALS_GEN_H

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
    #include "lvgl_private/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif



/* Prototypes for target functions, needed by responsive const definitions */

void tutorials_set_target(uint32_t target);
uint32_t tutorials_get_target(void);
bool tutorials_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define TUTORIALS_TARGET_UNDEFINED  (0 << 1)
#define TUTORIALS_TARGET_TARGET1    (1 << 1)
#define TUTORIALS_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef TUTORIALS_COMPILE_TARGET
#define TUTORIALS_COMPILE_TARGET TUTORIALS_TARGET_ALL
#endif

#define TUTORIALS_CHECK_COMPILE_TARGET(target) (TUTORIALS_COMPILE_TARGET & (target) ? 1 : 0)

#define UNIT_SMALL (6)
#define UNIT_MEDIUM (12)
#define UNIT_LARGE (24)
#define DARK_BLUE (lv_color_hex(0x035391))
#define YELLOW (lv_color_hex(0xda9d19))


#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**
 * Animation path of a style transition with a `bezier(…)` easing. The control
 * points come from the transition descriptor's `user_data`, as a transition
 * descriptor cannot store animation parameters itself.
 */
static inline int32_t tutorials_style_transition_bezier_path_helper(const lv_anim_t * a)
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

extern lv_obj_t * screen_main;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * montserrat_14_c_array;
extern lv_font_t * montserrat_16_bin_file;
extern lv_font_t * montserrat_18_tiny_ttf_data;
extern lv_font_t * montserrat_20_tiny_ttf_file;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * flower_data;
extern const void * flower_file;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t * subject_dark_mode;
extern lv_subject_t * subject_max_current;
extern lv_subject_t * subject_timeout;
extern lv_subject_t * subject_volume;
extern lv_subject_t * subject_segment;

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

void tutorials_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/buttons/button_normal_gen.h"
#include "components/buttons/button_warning_gen.h"
#include "components/column/column_gen.h"
#include "components/list/list_gen.h"
#include "components/round_button_gen.h"
#include "components/row/row_gen.h"
#include "components/section_gen.h"
#include "components/sliderbox_gen.h"
#include "components/widget_items/segment_item/segment_item_gen.h"
#include "screens/animations/screen_animations_gen.h"
#include "screens/assets/screen_assets_gen.h"
#include "screens/data_bindings/screen_data_bindings_gen.h"
#include "screens/hello_world/screen_hello_world_gen.h"
#include "screens/layout/screen_layouts_gen.h"
#include "screens/new_component/screen_components_gen.h"
#include "screens/new_widget/screen_widgets/screen_widgets_gen.h"
#include "screens/screens/screen_about_gen.h"
#include "screens/screens/screen_main_gen.h"
#include "screens/styles/screen_styles_gen.h"
#include "screens/translations/screen_translations_gen.h"
#include "widgets/wd_segment/wd_segment_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_TUTORIALS_GEN_H*/