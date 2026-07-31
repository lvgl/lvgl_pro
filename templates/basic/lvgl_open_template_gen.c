/**
 * @file lvgl_open_template_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvgl_open_template_gen.h"

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

static uint32_t lvgl_open_template_target = LVGL_OPEN_TEMPLATE_TARGET_ALL;

/*----------------
 * Translations
 *----------------*/

#ifndef LV_EDITOR_PREVIEW
    static const char * translation_languages[] = {"en", "de", "es", NULL};
    static const char * translation_tags[] = {"dark_theme", "buttons", "controls", "text_inputs", "selection", NULL};
    static const char * translation_texts[] = {
        "Dark theme", "Dunkles Design", "Tema oscuro", /* dark_theme */
        "Buttons", "Tasten", "Botones", /* buttons */
        "Controls", "Steuerelemente", "Controles", /* controls */
        "Text inputs", "Texteingaben", "Campos de texto", /* text_inputs */
        "Selection", "Auswahl", "Seleccion", /* selection */
    };
#endif

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

lv_obj_t * screen_components = NULL;

/*----------------
 * Fonts
 *----------------*/

lv_font_t * font_body_symbols;
extern lv_font_t font_body_symbols_data;
lv_font_t * font_body;
extern lv_font_t font_body_data;
lv_font_t * font_h5;
extern lv_font_t font_h5_data;
lv_font_t * font_h4;
extern lv_font_t font_h4_data;
lv_font_t * font_h3;
extern lv_font_t font_h3_data;
lv_font_t * font_h2;
extern lv_font_t font_h2_data;
lv_font_t * font_h1;
extern lv_font_t font_h1_data;

/*----------------
 * Images
 *----------------*/

/* Targets: any */
const void * icon_arrow_down = NULL;
extern const void * icon_arrow_down_data;
const void * icon_arrow_left = NULL;
extern const void * icon_arrow_left_data;
const void * icon_arrow_right = NULL;
extern const void * icon_arrow_right_data;
const void * icon_arrow_up = NULL;
extern const void * icon_arrow_up_data;
const void * icon_battery = NULL;
extern const void * icon_battery_data;
const void * icon_battery_full = NULL;
extern const void * icon_battery_full_data;
const void * icon_bell = NULL;
extern const void * icon_bell_data;
const void * icon_bluetooth = NULL;
extern const void * icon_bluetooth_data;
const void * icon_calendar = NULL;
extern const void * icon_calendar_data;
const void * icon_camera = NULL;
extern const void * icon_camera_data;
const void * icon_check = NULL;
extern const void * icon_check_data;
const void * icon_chevron_down = NULL;
extern const void * icon_chevron_down_data;
const void * icon_chevron_left = NULL;
extern const void * icon_chevron_left_data;
const void * icon_chevron_right = NULL;
extern const void * icon_chevron_right_data;
const void * icon_chevron_up = NULL;
extern const void * icon_chevron_up_data;
const void * icon_clock = NULL;
extern const void * icon_clock_data;
const void * icon_close = NULL;
extern const void * icon_close_data;
const void * icon_download = NULL;
extern const void * icon_download_data;
const void * icon_edit = NULL;
extern const void * icon_edit_data;
const void * icon_heart = NULL;
extern const void * icon_heart_data;
const void * icon_home = NULL;
extern const void * icon_home_data;
const void * icon_info = NULL;
extern const void * icon_info_data;
const void * icon_lock = NULL;
extern const void * icon_lock_data;
const void * icon_mail = NULL;
extern const void * icon_mail_data;
const void * icon_menu = NULL;
extern const void * icon_menu_data;
const void * icon_minus = NULL;
extern const void * icon_minus_data;
const void * icon_moon = NULL;
extern const void * icon_moon_data;
const void * icon_pause = NULL;
extern const void * icon_pause_data;
const void * icon_play = NULL;
extern const void * icon_play_data;
const void * icon_plus = NULL;
extern const void * icon_plus_data;
const void * icon_power = NULL;
extern const void * icon_power_data;
const void * icon_refresh = NULL;
extern const void * icon_refresh_data;
const void * icon_search = NULL;
extern const void * icon_search_data;
const void * icon_settings = NULL;
extern const void * icon_settings_data;
const void * icon_signal = NULL;
extern const void * icon_signal_data;
const void * icon_star = NULL;
extern const void * icon_star_data;
const void * icon_sun = NULL;
extern const void * icon_sun_data;
const void * icon_trash = NULL;
extern const void * icon_trash_data;
const void * icon_unlock = NULL;
extern const void * icon_unlock_data;
const void * icon_upload = NULL;
extern const void * icon_upload_data;
const void * icon_user = NULL;
extern const void * icon_user_data;
const void * icon_volume = NULL;
extern const void * icon_volume_data;
const void * icon_wifi = NULL;
extern const void * icon_wifi_data;
const void * icon_wifi_high = NULL;
extern const void * icon_wifi_high_data;
const void * icon_wifi_low = NULL;
extern const void * icon_wifi_low_data;
const void * icon_wifi_zero = NULL;
extern const void * icon_wifi_zero_data;

/*----------------
 * Global styles
 *----------------*/

lv_style_t style_screen_light;
lv_style_t style_screen_dark;
lv_style_t style_panel_light;
lv_style_t style_panel_dark;
lv_style_t style_text_accent;
lv_style_t style_text_muted;
lv_style_t style_scrollbar;

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_theme_dark;
lv_subject_t subject_brightness;
lv_subject_t subject_show_keyboard;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvgl_open_template_init_gen(const char * asset_path)
{
    /* When running from the editor the theme set from the XML should overwrite this */
#if !defined(LV_EDITOR_PREVIEW)
#if LV_USE_THEME_SIMPLE
    lv_display_t * disp = lv_display_get_default();
    lv_theme_t * th = lv_theme_simple_init(disp);
    lv_display_set_theme(disp, th);
#else
    LV_LOG_WARN("Simple theme is selected in project.xml but LV_USE_THEME_SIMPLE is disabled");
#endif
#endif /*LV_EDITOR_PREVIEW*/


    /*----------------
     * Fonts
     *----------------*/

    /* Targets: any */

    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        if (!font_body_symbols) {
            /* font_body_symbols */
            /* get font 'font_body_symbols' from a C array */
            font_body_symbols = &font_body_symbols_data;

        }
        if (!font_body) {
            /* font_body */
            /* get font 'font_body' from a C array */
            font_body = &font_body_data;

        }
        if (!font_h5) {
            /* font_h5 */
            /* get font 'font_h5' from a C array */
            font_h5 = &font_h5_data;

        }
        if (!font_h4) {
            /* font_h4 */
            /* get font 'font_h4' from a C array */
            font_h4 = &font_h4_data;

        }
        if (!font_h3) {
            /* font_h3 */
            /* get font 'font_h3' from a C array */
            font_h3 = &font_h3_data;

        }
        if (!font_h2) {
            /* font_h2 */
            /* get font 'font_h2' from a C array */
            font_h2 = &font_h2_data;

        }
        if (!font_h1) {
            /* font_h1 */
            /* get font 'font_h1' from a C array */
            font_h1 = &font_h1_data;

        }
    }
    #endif

    /*----------------
     * Images
     *----------------*/

    /* Targets: any */
    #if LVGL_OPEN_TEMPLATE_CHECK_COMPILE_TARGET(LVGL_OPEN_TEMPLATE_TARGET_ALL)
    if (lvgl_open_template_check_target(LVGL_OPEN_TEMPLATE_TARGET_ALL)) {
        /* icon_arrow_down */
        if (!icon_arrow_down) {
            icon_arrow_down = &icon_arrow_down_data;
        }
        /* icon_arrow_left */
        if (!icon_arrow_left) {
            icon_arrow_left = &icon_arrow_left_data;
        }
        /* icon_arrow_right */
        if (!icon_arrow_right) {
            icon_arrow_right = &icon_arrow_right_data;
        }
        /* icon_arrow_up */
        if (!icon_arrow_up) {
            icon_arrow_up = &icon_arrow_up_data;
        }
        /* icon_battery */
        if (!icon_battery) {
            icon_battery = &icon_battery_data;
        }
        /* icon_battery_full */
        if (!icon_battery_full) {
            icon_battery_full = &icon_battery_full_data;
        }
        /* icon_bell */
        if (!icon_bell) {
            icon_bell = &icon_bell_data;
        }
        /* icon_bluetooth */
        if (!icon_bluetooth) {
            icon_bluetooth = &icon_bluetooth_data;
        }
        /* icon_calendar */
        if (!icon_calendar) {
            icon_calendar = &icon_calendar_data;
        }
        /* icon_camera */
        if (!icon_camera) {
            icon_camera = &icon_camera_data;
        }
        /* icon_check */
        if (!icon_check) {
            icon_check = &icon_check_data;
        }
        /* icon_chevron_down */
        if (!icon_chevron_down) {
            icon_chevron_down = &icon_chevron_down_data;
        }
        /* icon_chevron_left */
        if (!icon_chevron_left) {
            icon_chevron_left = &icon_chevron_left_data;
        }
        /* icon_chevron_right */
        if (!icon_chevron_right) {
            icon_chevron_right = &icon_chevron_right_data;
        }
        /* icon_chevron_up */
        if (!icon_chevron_up) {
            icon_chevron_up = &icon_chevron_up_data;
        }
        /* icon_clock */
        if (!icon_clock) {
            icon_clock = &icon_clock_data;
        }
        /* icon_close */
        if (!icon_close) {
            icon_close = &icon_close_data;
        }
        /* icon_download */
        if (!icon_download) {
            icon_download = &icon_download_data;
        }
        /* icon_edit */
        if (!icon_edit) {
            icon_edit = &icon_edit_data;
        }
        /* icon_heart */
        if (!icon_heart) {
            icon_heart = &icon_heart_data;
        }
        /* icon_home */
        if (!icon_home) {
            icon_home = &icon_home_data;
        }
        /* icon_info */
        if (!icon_info) {
            icon_info = &icon_info_data;
        }
        /* icon_lock */
        if (!icon_lock) {
            icon_lock = &icon_lock_data;
        }
        /* icon_mail */
        if (!icon_mail) {
            icon_mail = &icon_mail_data;
        }
        /* icon_menu */
        if (!icon_menu) {
            icon_menu = &icon_menu_data;
        }
        /* icon_minus */
        if (!icon_minus) {
            icon_minus = &icon_minus_data;
        }
        /* icon_moon */
        if (!icon_moon) {
            icon_moon = &icon_moon_data;
        }
        /* icon_pause */
        if (!icon_pause) {
            icon_pause = &icon_pause_data;
        }
        /* icon_play */
        if (!icon_play) {
            icon_play = &icon_play_data;
        }
        /* icon_plus */
        if (!icon_plus) {
            icon_plus = &icon_plus_data;
        }
        /* icon_power */
        if (!icon_power) {
            icon_power = &icon_power_data;
        }
        /* icon_refresh */
        if (!icon_refresh) {
            icon_refresh = &icon_refresh_data;
        }
        /* icon_search */
        if (!icon_search) {
            icon_search = &icon_search_data;
        }
        /* icon_settings */
        if (!icon_settings) {
            icon_settings = &icon_settings_data;
        }
        /* icon_signal */
        if (!icon_signal) {
            icon_signal = &icon_signal_data;
        }
        /* icon_star */
        if (!icon_star) {
            icon_star = &icon_star_data;
        }
        /* icon_sun */
        if (!icon_sun) {
            icon_sun = &icon_sun_data;
        }
        /* icon_trash */
        if (!icon_trash) {
            icon_trash = &icon_trash_data;
        }
        /* icon_unlock */
        if (!icon_unlock) {
            icon_unlock = &icon_unlock_data;
        }
        /* icon_upload */
        if (!icon_upload) {
            icon_upload = &icon_upload_data;
        }
        /* icon_user */
        if (!icon_user) {
            icon_user = &icon_user_data;
        }
        /* icon_volume */
        if (!icon_volume) {
            icon_volume = &icon_volume_data;
        }
        /* icon_wifi */
        if (!icon_wifi) {
            icon_wifi = &icon_wifi_data;
        }
        /* icon_wifi_high */
        if (!icon_wifi_high) {
            icon_wifi_high = &icon_wifi_high_data;
        }
        /* icon_wifi_low */
        if (!icon_wifi_low) {
            icon_wifi_low = &icon_wifi_low_data;
        }
        /* icon_wifi_zero */
        if (!icon_wifi_zero) {
            icon_wifi_zero = &icon_wifi_zero_data;
        }
    }
    #endif

    /*----------------
     * Global styles
     *----------------*/

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_screen_light);
        lv_style_init(&style_screen_dark);
        lv_style_init(&style_panel_light);
        lv_style_init(&style_panel_dark);
        lv_style_init(&style_text_accent);
        lv_style_init(&style_text_muted);
        lv_style_init(&style_scrollbar);

        lv_style_set_bg_color(&style_screen_light, COLOR_LIGHT_BG);
        lv_style_set_bg_opa(&style_screen_light, (255 * 100 / 100));
        lv_style_set_text_color(&style_screen_light, COLOR_LIGHT_TEXT);
        lv_style_set_text_font(&style_screen_light, font_body);
        lv_style_set_bg_color(&style_screen_dark, COLOR_DARK_BG);
        lv_style_set_bg_opa(&style_screen_dark, (255 * 100 / 100));
        lv_style_set_text_color(&style_screen_dark, COLOR_DARK_TEXT);
        lv_style_set_text_font(&style_screen_dark, font_body);
        lv_style_set_bg_color(&style_panel_light, COLOR_LIGHT_PANEL);
        lv_style_set_bg_opa(&style_panel_light, (255 * 100 / 100));
        lv_style_set_border_color(&style_panel_light, COLOR_LIGHT_TEXT);
        lv_style_set_border_opa(&style_panel_light, (255 * 20 / 100));
        lv_style_set_border_width(&style_panel_light, BORDER_WIDTH);
        lv_style_set_text_color(&style_panel_light, COLOR_LIGHT_TEXT);
        lv_style_set_pad_all(&style_panel_light, SPACE_MD);
        lv_style_set_radius(&style_panel_light, RADIUS_DEFAULT);
        lv_style_set_bg_color(&style_panel_dark, COLOR_DARK_PANEL);
        lv_style_set_bg_opa(&style_panel_dark, (255 * 100 / 100));
        lv_style_set_border_color(&style_panel_dark, COLOR_DARK_TEXT);
        lv_style_set_border_opa(&style_panel_dark, (255 * 20 / 100));
        lv_style_set_border_width(&style_panel_dark, BORDER_WIDTH);
        lv_style_set_text_color(&style_panel_dark, COLOR_DARK_TEXT);
        lv_style_set_pad_all(&style_panel_dark, SPACE_MD);
        lv_style_set_radius(&style_panel_dark, RADIUS_DEFAULT);
        lv_style_set_text_color(&style_text_accent, COLOR_ACCENT);
        lv_style_set_text_opa(&style_text_muted, (255 * 60 / 100));
        lv_style_set_width(&style_scrollbar, SPACE_SM);
        lv_style_set_radius(&style_scrollbar, SPACE_SM);
        lv_style_set_bg_color(&style_scrollbar, COLOR_TRACK);
        lv_style_set_bg_opa(&style_scrollbar, (255 * 80 / 100));
        lv_style_set_pad_all(&style_scrollbar, SPACE_SM);

        style_inited = true;
    }

    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&subject_theme_dark, 0);
    lv_subject_set_min_value_int(&subject_theme_dark, 0);
    lv_subject_set_max_value_int(&subject_theme_dark, 1);
    lv_subject_init_int(&subject_brightness, 60);
    lv_subject_set_min_value_int(&subject_brightness, 0);
    lv_subject_set_max_value_int(&subject_brightness, 100);
    lv_subject_init_int(&subject_show_keyboard, 0);

    /*----------------
     * Translations
     *----------------*/

    #ifndef LV_EDITOR_PREVIEW
        lv_translation_add_static(translation_languages, translation_tags, translation_texts);
        lv_translation_set_language(translation_languages[0]);
    #endif

#if defined(LV_USE_XML) && LV_USE_XML
    /* Register widgets */

    /* Check all fonts / default if needed. This prevents fonts that are used in one target but
       defined in another from causing assertion failures during rendering of the Preview. */
    check_font(&font_body_symbols, "font_body_symbols");
    check_font(&font_body, "font_body");
    check_font(&font_h5, "font_h5");
    check_font(&font_h4, "font_h4");
    check_font(&font_h3, "font_h3");
    check_font(&font_h2, "font_h2");
    check_font(&font_h1, "font_h1");

    /* Register fonts */
    lv_xml_register_font(NULL, "font_body_symbols", font_body_symbols);
    lv_xml_register_font(NULL, "font_body", font_body);
    lv_xml_register_font(NULL, "font_h5", font_h5);
    lv_xml_register_font(NULL, "font_h4", font_h4);
    lv_xml_register_font(NULL, "font_h3", font_h3);
    lv_xml_register_font(NULL, "font_h2", font_h2);
    lv_xml_register_font(NULL, "font_h1", font_h1);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_theme_dark", &subject_theme_dark);
    lv_xml_register_subject(NULL, "subject_brightness", &subject_brightness);
    lv_xml_register_subject(NULL, "subject_show_keyboard", &subject_show_keyboard);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if defined(LV_USE_XML) && LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "icon_arrow_down", icon_arrow_down);
    lv_xml_register_image(NULL, "icon_arrow_left", icon_arrow_left);
    lv_xml_register_image(NULL, "icon_arrow_right", icon_arrow_right);
    lv_xml_register_image(NULL, "icon_arrow_up", icon_arrow_up);
    lv_xml_register_image(NULL, "icon_battery", icon_battery);
    lv_xml_register_image(NULL, "icon_battery_full", icon_battery_full);
    lv_xml_register_image(NULL, "icon_bell", icon_bell);
    lv_xml_register_image(NULL, "icon_bluetooth", icon_bluetooth);
    lv_xml_register_image(NULL, "icon_calendar", icon_calendar);
    lv_xml_register_image(NULL, "icon_camera", icon_camera);
    lv_xml_register_image(NULL, "icon_check", icon_check);
    lv_xml_register_image(NULL, "icon_chevron_down", icon_chevron_down);
    lv_xml_register_image(NULL, "icon_chevron_left", icon_chevron_left);
    lv_xml_register_image(NULL, "icon_chevron_right", icon_chevron_right);
    lv_xml_register_image(NULL, "icon_chevron_up", icon_chevron_up);
    lv_xml_register_image(NULL, "icon_clock", icon_clock);
    lv_xml_register_image(NULL, "icon_close", icon_close);
    lv_xml_register_image(NULL, "icon_download", icon_download);
    lv_xml_register_image(NULL, "icon_edit", icon_edit);
    lv_xml_register_image(NULL, "icon_heart", icon_heart);
    lv_xml_register_image(NULL, "icon_home", icon_home);
    lv_xml_register_image(NULL, "icon_info", icon_info);
    lv_xml_register_image(NULL, "icon_lock", icon_lock);
    lv_xml_register_image(NULL, "icon_mail", icon_mail);
    lv_xml_register_image(NULL, "icon_menu", icon_menu);
    lv_xml_register_image(NULL, "icon_minus", icon_minus);
    lv_xml_register_image(NULL, "icon_moon", icon_moon);
    lv_xml_register_image(NULL, "icon_pause", icon_pause);
    lv_xml_register_image(NULL, "icon_play", icon_play);
    lv_xml_register_image(NULL, "icon_plus", icon_plus);
    lv_xml_register_image(NULL, "icon_power", icon_power);
    lv_xml_register_image(NULL, "icon_refresh", icon_refresh);
    lv_xml_register_image(NULL, "icon_search", icon_search);
    lv_xml_register_image(NULL, "icon_settings", icon_settings);
    lv_xml_register_image(NULL, "icon_signal", icon_signal);
    lv_xml_register_image(NULL, "icon_star", icon_star);
    lv_xml_register_image(NULL, "icon_sun", icon_sun);
    lv_xml_register_image(NULL, "icon_trash", icon_trash);
    lv_xml_register_image(NULL, "icon_unlock", icon_unlock);
    lv_xml_register_image(NULL, "icon_upload", icon_upload);
    lv_xml_register_image(NULL, "icon_user", icon_user);
    lv_xml_register_image(NULL, "icon_volume", icon_volume);
    lv_xml_register_image(NULL, "icon_wifi", icon_wifi);
    lv_xml_register_image(NULL, "icon_wifi_high", icon_wifi_high);
    lv_xml_register_image(NULL, "icon_wifi_low", icon_wifi_low);
    lv_xml_register_image(NULL, "icon_wifi_zero", icon_wifi_zero);
#endif

#if defined(LV_USE_XML) && LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manually from XML using lv_xml_create() */
    /* To allow screens to reference each other, create them all before calling the sceen create functions */
    screen_components = lv_obj_create(NULL);

    screen_components_create();
#endif
}

void lvgl_open_template_set_target(uint32_t target)
{
    lvgl_open_template_target = target;
}

uint32_t lvgl_open_template_get_target(void)
{
    return lvgl_open_template_target;
}

bool lvgl_open_template_check_target(uint32_t target)
{
    return (lvgl_open_template_target & target) ? true : false;
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