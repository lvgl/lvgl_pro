/**
 * @file lv_example_led.c
 */

#include "../lv_examples.h"

/**
 * @title LED
 * @brief A row of LEDs with different colors and brightness levels.
 *
 * `color` sets the LED hue (used for its fill, border and glow) and
 * `brightness` (an opacity 0–255 or %) controls how dark or bright it
 * appears. The same colour at low vs. high brightness shows the dimming
 * effect.
 */
void lv_example_led(void)
{
    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(screen, 32, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    lv_obj_t * lv_led_0 = lv_led_create(screen);
    lv_obj_set_size(lv_led_0, 36, 36);
    lv_led_set_color(lv_led_0, lv_color_hex(0x22c55e));
    lv_led_set_brightness(lv_led_0, 60);

    lv_obj_t * lv_led_1 = lv_led_create(screen);
    lv_obj_set_size(lv_led_1, 36, 36);
    lv_led_set_color(lv_led_1, lv_color_hex(0x22c55e));
    lv_led_set_brightness(lv_led_1, 180);

    lv_obj_t * lv_led_2 = lv_led_create(screen);
    lv_obj_set_size(lv_led_2, 36, 36);
    lv_led_set_color(lv_led_2, lv_color_hex(0x22c55e));
    lv_led_set_brightness(lv_led_2, 255);

    lv_obj_t * lv_led_3 = lv_led_create(screen);
    lv_obj_set_size(lv_led_3, 36, 36);
    lv_led_set_color(lv_led_3, lv_color_hex(0xef4444));
    lv_led_set_brightness(lv_led_3, 255);

    lv_obj_t * lv_led_4 = lv_led_create(screen);
    lv_obj_set_size(lv_led_4, 36, 36);
    lv_led_set_color(lv_led_4, lv_color_hex(0x3b82f6));
    lv_led_set_brightness(lv_led_4, 200);
}

