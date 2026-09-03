/**
 * @file tutorials_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "tutorials_gen.h"

#if defined(LV_USE_XML) && LV_USE_XML
#include "widgets/wd_segment/wd_segment_private_gen.h"
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

static uint32_t tutorials_target = TUTORIALS_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

#ifndef LV_EDITOR_PREVIEW
    static const char * translation_languages[] = {"en", "de", NULL};
    static const char * translation_tags[] = {"dog", "cat", "house", "person", NULL};
    static const char * translation_texts[] = {
        "This is a dog", "Das ist ein Hund", /* dog */
        "A curious little cat", "Eine neugierige kleine Katze", /* cat */
        "The house is cozy and warm", "Das Haus ist gemütlich und warm", /* house */
        "A kind person with a bright smile", "Eine freundliche Person mit einem strahlenden Lächeln", /* person */
    };
#endif

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

lv_obj_t * screen_main = NULL;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * montserrat_14_c_array;
extern lv_font_t montserrat_14_c_array_data;
lv_font_t * montserrat_16_bin_file;
extern lv_font_t montserrat_16_bin_file_data;
lv_font_t * montserrat_18_tiny_ttf_data;
extern uint8_t Montserrat_Medium_ttf_data[];
extern size_t Montserrat_Medium_ttf_data_size;
lv_font_t * montserrat_20_tiny_ttf_file;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * flower_data = NULL;
extern const void * flower_data_data;
const void * flower_file = NULL;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_dark_mode;
lv_subject_t subject_max_current;
lv_subject_t subject_timeout;
lv_subject_t subject_volume;
lv_subject_t subject_segment;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void tutorials_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        if (!montserrat_14_c_array) {
            /* montserrat_14_c_array */
            /* get font 'montserrat_14_c_array' from a C array */
            montserrat_14_c_array = &montserrat_14_c_array_data;

        }
        if (!montserrat_16_bin_file) {
            /* montserrat_16_bin_file */
            /* get font 'montserrat_16_bin_file' from a C array */
            montserrat_16_bin_file = &montserrat_16_bin_file_data;

        }
        if (!montserrat_18_tiny_ttf_data) {
            /* montserrat_18_tiny_ttf_data */
            /* create tiny ttf font 'montserrat_18_tiny_ttf_data' from C array */
            montserrat_18_tiny_ttf_data = lv_tiny_ttf_create_data(Montserrat_Medium_ttf_data, Montserrat_Medium_ttf_data_size, 18);

        }
        if (!montserrat_20_tiny_ttf_file) {
            /* montserrat_20_tiny_ttf_file */
            /* create tiny ttf font "montserrat_20_tiny_ttf_file" from file */
            lv_snprintf(buf, 256, "%s%s", asset_path, "fonts/Montserrat_Medium.ttf");
            montserrat_20_tiny_ttf_file = lv_tiny_ttf_create_file(buf, 20);
        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if TUTORIALS_CHECK_COMPILE_TARGET(TUTORIALS_TARGET_ALL)
    if (tutorials_check_target(TUTORIALS_TARGET_ALL)) {
        /* flower_data */
        if (!flower_data) {
            flower_data = &flower_data_data;
        }
        /* flower_file */
        if (!flower_file) {
            lv_snprintf(buf, 256, "%s%s", asset_path, "images/orange-flower.png");
            flower_file = lv_strdup(buf);
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_dark_mode, 0);
    lv_subject_init_int(&subject_max_current, 0);
    lv_subject_init_int(&subject_timeout, 0);
    lv_subject_init_int(&subject_volume, 0);
    lv_subject_init_int(&subject_segment, 0);

    /*----------------
     * Translations
     *----------------*/

    #ifndef LV_EDITOR_PREVIEW
        lv_translation_add_static(translation_languages, translation_tags, translation_texts);
        lv_translation_set_language(translation_languages[0]);
    #endif

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */
    wd_segment_register();

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&montserrat_14_c_array, "montserrat_14_c_array");
    check_font(&montserrat_16_bin_file, "montserrat_16_bin_file");
    check_font(&montserrat_18_tiny_ttf_data, "montserrat_18_tiny_ttf_data");
    check_font(&montserrat_20_tiny_ttf_file, "montserrat_20_tiny_ttf_file");

    /* Register fonts */
    lv_xml_register_font(NULL, "montserrat_14_c_array", montserrat_14_c_array);
    lv_xml_register_font(NULL, "montserrat_16_bin_file", montserrat_16_bin_file);
    lv_xml_register_font(NULL, "montserrat_18_tiny_ttf_data", montserrat_18_tiny_ttf_data);
    lv_xml_register_font(NULL, "montserrat_20_tiny_ttf_file", montserrat_20_tiny_ttf_file);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_dark_mode", &subject_dark_mode);
    lv_xml_register_subject(NULL, "subject_max_current", &subject_max_current);
    lv_xml_register_subject(NULL, "subject_timeout", &subject_timeout);
    lv_xml_register_subject(NULL, "subject_volume", &subject_volume);
    lv_xml_register_subject(NULL, "subject_segment", &subject_segment);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "flower_data", flower_data);
    lv_xml_register_image(NULL, "flower_file", flower_file);
#endif

#if !defined(LV_USE_XML) || LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
    /* To allow screens to reference each other, create them all before calling the sceen create functions */
    screen_main = lv_obj_create(NULL);

    screen_main_create();
#endif
}

void tutorials_set_target(uint32_t target)
{
    tutorials_target = target;
}

uint32_t tutorials_get_target(void)
{
    return tutorials_target;
}

bool tutorials_check_target(uint32_t target)
{
    return (tutorials_target & target) ? true : false;
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