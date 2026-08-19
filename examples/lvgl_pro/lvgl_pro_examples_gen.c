/**
 * @file lvgl_pro_examples_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_pro_examples_gen.h"

#if defined(LV_USE_XML) && LV_USE_XML
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

static uint32_t lvgl_pro_examples_target = LVGL_PRO_EXAMPLES_TARGET_ALL;

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

lv_font_t * font_large;
extern lv_font_t font_large_data;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * img_logo = NULL;
extern const void * img_logo_data;
const void * imgbtn_left = NULL;
extern const void * imgbtn_left_data;
const void * imgbtn_mid = NULL;
extern const void * imgbtn_mid_data;
const void * imgbtn_right = NULL;
extern const void * imgbtn_right_data;
const void * img_bulb = NULL;
extern const void * img_bulb_data;

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
lv_subject_t subject_checked;
lv_subject_t subject_text;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_pro_examples_init_gen(const char * asset_path)
{

    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        if (!font_large) {
            /* font_large */
            /* get font 'font_large' from a C array */
            font_large = &font_large_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if LVGL_PRO_EXAMPLES_CHECK_COMPILE_TARGET(LVGL_PRO_EXAMPLES_TARGET_ALL)
    if (lvgl_pro_examples_check_target(LVGL_PRO_EXAMPLES_TARGET_ALL)) {
        /* img_logo */
        if (!img_logo) {
            img_logo = &img_logo_data;
        }
        /* imgbtn_left */
        if (!imgbtn_left) {
            imgbtn_left = &imgbtn_left_data;
        }
        /* imgbtn_mid */
        if (!imgbtn_mid) {
            imgbtn_mid = &imgbtn_mid_data;
        }
        /* imgbtn_right */
        if (!imgbtn_right) {
            imgbtn_right = &imgbtn_right_data;
        }
        /* img_bulb */
        if (!img_bulb) {
            img_bulb = &img_bulb_data;
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
    lv_subject_init_int(&subject_checked, 0);
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

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_large, "font_large");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_large", font_large);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_value", &subject_value);
    lv_xml_register_subject(NULL, "subject_value2", &subject_value2);
    lv_xml_register_subject(NULL, "subject_opa", &subject_opa);
    lv_xml_register_subject(NULL, "subject_index", &subject_index);
    lv_xml_register_subject(NULL, "subject_checked", &subject_checked);
    lv_xml_register_subject(NULL, "subject_text", &subject_text);

    /* Register callbacks */

    /* Register easing callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "img_logo", img_logo);
    lv_xml_register_image(NULL, "imgbtn_left", imgbtn_left);
    lv_xml_register_image(NULL, "imgbtn_mid", imgbtn_mid);
    lv_xml_register_image(NULL, "imgbtn_right", imgbtn_right);
    lv_xml_register_image(NULL, "img_bulb", img_bulb);
#endif

#if !defined(LV_USE_XML) || LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
#endif
}

void lvgl_pro_examples_set_target(uint32_t target)
{
    lvgl_pro_examples_target = target;
}

uint32_t lvgl_pro_examples_get_target(void)
{
    return lvgl_pro_examples_target;
}

bool lvgl_pro_examples_check_target(uint32_t target)
{
    return (lvgl_pro_examples_target & target) ? true : false;
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void check_font(lv_font_t ** font, const char * name)
{
    if (!(*font)) {
        *font = (lv_font_t *)LV_FONT_DEFAULT;
        LV_LOG_WARN("font `%s` was not set. Using `LV_FONT_DEFAULT` instead", name);
    }
}