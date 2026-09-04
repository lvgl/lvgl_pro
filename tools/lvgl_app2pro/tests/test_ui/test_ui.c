/**
 * A small UI built to exercise the converter, not to look good.
 *
 * It deliberately covers the things that are hard to convert:
 *   - widgets whose XML form is an <element>: tabview tabs, chart series
 *   - a container that removes its styles and then sets local ones, which is
 *     the opposite order from XML
 *   - a widget with one part's styles removed
 *   - a shared lv_style_t used by two widgets, which has to reach globals.xml
 *   - states set from code, and object flags cleared from code
 *   - an image compiled in as a C array
 *   - an event callback
 *
 * Everything is fixed: no animation, no random data, and the built-in font
 * throughout, so a screenshot of this and a screenshot of the converted
 * project can be compared pixel by pixel.
 */

#include "lvgl/lvgl.h"
#include "lvgl/src/drivers/sdl/lv_sdl_window.h"
#include "lvgl/src/drivers/sdl/lv_sdl_mouse.h"

/*A real image compiled into the binary, for the converter to rebuild as a PNG.*/
LV_IMAGE_DECLARE(img_lvgl_logo);

/* Shared styles. style_card is plain; the others are applied with a selector,
 * which is what forces a named <style> rather than inline attributes. */
static lv_style_t style_card;
static lv_style_t style_pressed;
static lv_style_t style_knob;
static lv_style_t style_indicator;

/* The test harness calls lv_snapshot_take() from GDB. Nothing in this file
 * calls it, so without a reference the linker leaves it out of the binary. */
void * const test_ui_keep_snapshot = (void *)(uintptr_t)lv_snapshot_take;

static void button_clicked_cb(lv_event_t * e)
{
    LV_UNUSED(e);
}

static void slider_changed_cb(lv_event_t * e)
{
    LV_UNUSED(e);
}

/**
 * A card that removes every style first and then sets its own.
 * In XML the order is the other way round, which is what makes this useful.
 */
static lv_obj_t * bare_card_create(lv_obj_t * parent)
{
    lv_obj_t * card = lv_obj_create(parent);
    lv_obj_remove_style_all(card);
    lv_obj_set_size(card, lv_pct(100), LV_SIZE_CONTENT);
    lv_obj_set_style_bg_color(card, lv_color_hex(0xeeeeee), 0);
    lv_obj_set_style_bg_opa(card, LV_OPA_COVER, 0);
    lv_obj_set_style_pad_all(card, 8, 0);
    lv_obj_set_flex_flow(card, LV_FLEX_FLOW_ROW_WRAP);
    return card;
}

static void controls_tab_create(lv_obj_t * parent)
{
    lv_obj_set_flex_flow(parent, LV_FLEX_FLOW_COLUMN);

    lv_obj_t * title = lv_label_create(parent);
    lv_label_set_text(title, "Controls");

    lv_obj_t * card = bare_card_create(parent);

    lv_obj_t * button = lv_button_create(card);
    lv_obj_add_style(button, &style_pressed, LV_STATE_PRESSED);
    lv_obj_add_event_cb(button, button_clicked_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_t * button_label = lv_label_create(button);
    lv_label_set_text(button_label, "Send");

    lv_obj_t * disabled = lv_button_create(card);
    lv_obj_add_state(disabled, LV_STATE_DISABLED);
    lv_obj_t * disabled_label = lv_label_create(disabled);
    lv_label_set_text(disabled_label, "Off");

    lv_obj_t * sw = lv_switch_create(card);
    lv_obj_add_state(sw, LV_STATE_CHECKED);

    lv_obj_t * cb = lv_checkbox_create(card);
    lv_checkbox_set_text(cb, "Enabled");
    lv_obj_add_state(cb, LV_STATE_CHECKED);

    lv_obj_t * slider = lv_slider_create(parent);
    lv_slider_set_range(slider, 0, 200);
    lv_slider_set_value(slider, 120, LV_ANIM_OFF);
    lv_obj_set_width(slider, lv_pct(80));
    lv_obj_add_style(slider, &style_knob, LV_PART_KNOB);
    lv_obj_add_style(slider, &style_indicator, LV_PART_INDICATOR);
    lv_obj_add_event_cb(slider, slider_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);

    /*A bar with the knob styles removed, so <remove_style selector="knob"/> is needed*/
    lv_obj_t * bar = lv_bar_create(parent);
    lv_bar_set_range(bar, 0, 50);
    lv_bar_set_value(bar, 35, LV_ANIM_OFF);
    lv_obj_set_width(bar, lv_pct(80));
    lv_obj_remove_style(bar, NULL, LV_PART_KNOB);

    lv_obj_t * dropdown = lv_dropdown_create(parent);
    lv_dropdown_set_options(dropdown, "One\nTwo\nThree");
    lv_dropdown_set_selected(dropdown, 1);

    lv_obj_t * roller = lv_roller_create(parent);
    lv_roller_set_options(roller, "Red\nGreen\nBlue", LV_ROLLER_MODE_NORMAL);
    lv_roller_set_selected(roller, 2, LV_ANIM_OFF);
}

static void data_tab_create(lv_obj_t * parent)
{
    lv_obj_set_flex_flow(parent, LV_FLEX_FLOW_COLUMN);

    lv_obj_t * chart = lv_chart_create(parent);
    lv_obj_set_size(chart, lv_pct(90), 160);
    lv_chart_set_type(chart, LV_CHART_TYPE_BAR);
    lv_chart_set_point_count(chart, 5);
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);

    lv_chart_series_t * first =
        lv_chart_add_series(chart, lv_color_hex(0x2196f3), LV_CHART_AXIS_PRIMARY_Y);
    lv_chart_series_t * second =
        lv_chart_add_series(chart, lv_color_hex(0xf44336), LV_CHART_AXIS_PRIMARY_Y);
    const int32_t first_values[5] = {10, 40, 30, 70, 55};
    const int32_t second_values[5] = {60, 20, 80, 25, 45};
    for(uint32_t i = 0; i < 5; i++) {
        lv_chart_set_value_by_id(chart, first, i, first_values[i]);
        lv_chart_set_value_by_id(chart, second, i, second_values[i]);
    }

    lv_obj_t * scale = lv_scale_create(parent);
    lv_obj_set_size(scale, lv_pct(90), 60);
    lv_scale_set_mode(scale, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
    lv_scale_set_total_tick_count(scale, 11);
    lv_scale_set_major_tick_every(scale, 5);
    lv_scale_set_range(scale, 0, 100);

    lv_obj_t * image = lv_image_create(parent);
    lv_image_set_src(image, &img_lvgl_logo);

    /*The shared style is used twice, so it belongs in globals.xml*/
    lv_obj_t * note = lv_obj_create(parent);
    lv_obj_set_size(note, lv_pct(90), 40);
    lv_obj_add_style(note, &style_card, 0);
    lv_obj_remove_flag(note, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t * note2 = lv_obj_create(parent);
    lv_obj_set_size(note2, lv_pct(90), 40);
    lv_obj_add_style(note2, &style_card, 0);
    lv_obj_remove_flag(note2, LV_OBJ_FLAG_SCROLLABLE);
}

void test_ui_create(void)
{
    lv_style_init(&style_card);
    lv_style_set_bg_color(&style_card, lv_color_hex(0xfff3e0));
    lv_style_set_border_width(&style_card, 2);
    lv_style_set_border_color(&style_card, lv_color_hex(0xff9800));
    lv_style_set_radius(&style_card, 6);

    lv_style_init(&style_pressed);
    lv_style_set_bg_color(&style_pressed, lv_color_hex(0x1565c0));
    lv_style_set_translate_y(&style_pressed, 2);

    lv_style_init(&style_knob);
    lv_style_set_bg_color(&style_knob, lv_color_hex(0xff9800));
    lv_style_set_pad_all(&style_knob, 4);

    lv_style_init(&style_indicator);
    lv_style_set_bg_color(&style_indicator, lv_color_hex(0x4caf50));

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_style_pad_all(screen, 0, 0);

    lv_obj_t * tabview = lv_tabview_create(screen);
    lv_tabview_set_tab_bar_size(tabview, 48);

    lv_obj_t * controls = lv_tabview_add_tab(tabview, "Controls");
    lv_obj_t * data = lv_tabview_add_tab(tabview, "Data");

    controls_tab_create(controls);
    data_tab_create(data);
}

int main(void)
{
    lv_init();

    lv_display_t * display = lv_sdl_window_create(800, 480);
    lv_display_set_default(display);
    lv_sdl_mouse_create();

    test_ui_create();

    while(1) {
        uint32_t wait = lv_timer_handler();
        if(wait == LV_NO_TIMER_READY) wait = LV_DEF_REFR_PERIOD;
        lv_delay_ms(wait);
    }

    return 0;
}
