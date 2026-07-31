/**
 * @file lvgl_open_examples_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_open_examples_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void check_font(lv_font_t ** font, const char * name);

/**********************
 *  STATIC VARIABLES
 **********************/

static uint32_t lvgl_open_examples_target = LVGL_OPEN_EXAMPLES_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_example_large;
extern lv_font_t font_example_large_large_data;

/*----------------
 * Images
 *----------------*/

/* Targets: large */
const void * img_example_lvgl_logo = NULL;
extern const void * img_example_lvgl_logo_data;
const void * img_arc_bg = NULL;
extern const void * img_arc_bg_data;
const void * img_arc_indicator = NULL;
extern const void * img_arc_indicator_data;
const void * img_bar_bg = NULL;
extern const void * img_bar_bg_data;
const void * img_bar_indicator = NULL;
extern const void * img_bar_indicator_data;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_value;
lv_subject_t subject_value2;
lv_subject_t subject_opa;
lv_subject_t subject_index;
lv_subject_t subject_flag;
lv_subject_t subject_text;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_open_examples_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: large */

    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_LARGE)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_LARGE)) {
        if (!font_example_large) {
            /* font_example_large */
            /* get font 'font_example_large' from a C array */
            font_example_large = &font_example_large_large_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: large */
    #if LVGL_OPEN_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_OPEN_EXAMPLES_TARGET_LARGE)
    if (lvgl_open_examples_check_target(LVGL_OPEN_EXAMPLES_TARGET_LARGE)) {
        /* img_example_lvgl_logo */
        if (!img_example_lvgl_logo) {
            img_example_lvgl_logo = &img_example_lvgl_logo_data;
        }
        /* img_arc_bg */
        if (!img_arc_bg) {
            img_arc_bg = &img_arc_bg_data;
        }
        /* img_arc_indicator */
        if (!img_arc_indicator) {
            img_arc_indicator = &img_arc_indicator_data;
        }
        /* img_bar_bg */
        if (!img_bar_bg) {
            img_bar_bg = &img_bar_bg_data;
        }
        /* img_bar_indicator */
        if (!img_bar_indicator) {
            img_bar_indicator = &img_bar_indicator_data;
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_value, 50);
    lv_subject_set_min_value_int(&subject_value, 0);
    lv_subject_set_max_value_int(&subject_value, 100);
    lv_subject_init_int(&subject_value2, 20);
    lv_subject_set_min_value_int(&subject_value2, 0);
    lv_subject_set_max_value_int(&subject_value2, 100);
    lv_subject_init_int(&subject_opa, 128);
    lv_subject_set_min_value_int(&subject_opa, 0);
    lv_subject_set_max_value_int(&subject_opa, 255);
    lv_subject_init_int(&subject_index, 0);
    lv_subject_init_int(&subject_flag, 0);
    static char subject_text_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_text_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_text,
                           subject_text_buf,
                           subject_text_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Hello"
                          );

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_example_large, "font_example_large");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_example_large", font_example_large);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_value", &subject_value);
    lv_xml_register_subject(NULL, "subject_value2", &subject_value2);
    lv_xml_register_subject(NULL, "subject_opa", &subject_opa);
    lv_xml_register_subject(NULL, "subject_index", &subject_index);
    lv_xml_register_subject(NULL, "subject_flag", &subject_flag);
    lv_xml_register_subject(NULL, "subject_text", &subject_text);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "img_example_lvgl_logo", img_example_lvgl_logo);
    lv_xml_register_image(NULL, "img_arc_bg", img_arc_bg);
    lv_xml_register_image(NULL, "img_arc_indicator", img_arc_indicator);
    lv_xml_register_image(NULL, "img_bar_bg", img_bar_bg);
    lv_xml_register_image(NULL, "img_bar_indicator", img_bar_indicator);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void lvgl_open_examples_set_target(uint32_t target)
{
    lvgl_open_examples_target = target;
}

uint32_t lvgl_open_examples_get_target(void)
{
    return lvgl_open_examples_target;
}

bool lvgl_open_examples_check_target(uint32_t target)
{
    return (lvgl_open_examples_target & target) ? true : false;
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}