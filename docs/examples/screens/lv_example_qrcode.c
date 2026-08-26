/**
 * @file lv_example_qrcode.c
 */

#include "../lv_examples.h"

/**
 * @title QR code
 * @brief Two QR codes with custom colours, size and quiet zone.
 *
 * `data` is the encoded UTF-8 string and `size` sets the square side in
 * pixels. `dark_color`/`light_color` recolour the modules and background,
 * and `quiet_zone="true"` adds the recommended margin so scanners read it
 * reliably.
 */
void lv_example_qrcode(void)
{
    lv_obj_t * screen = lv_screen_active();

    lv_obj_t * lv_qrcode_0 = lv_qrcode_create(screen);
    lv_qrcode_set_size(lv_qrcode_0, 120);
    lv_obj_set_align(lv_qrcode_0, LV_ALIGN_CENTER);
    lv_obj_set_x(lv_qrcode_0, -100);
    lv_qrcode_set_dark_color(lv_qrcode_0, lv_color_hex(0x1f2937));
    lv_qrcode_set_light_color(lv_qrcode_0, lv_color_hex(0xffffff));
    lv_qrcode_set_quiet_zone(lv_qrcode_0, true);
    lv_qrcode_set_data(lv_qrcode_0, "https://lvgl.io");

    lv_obj_t * lv_qrcode_1 = lv_qrcode_create(screen);
    lv_qrcode_set_size(lv_qrcode_1, 100);
    lv_obj_set_align(lv_qrcode_1, LV_ALIGN_CENTER);
    lv_obj_set_x(lv_qrcode_1, 100);
    lv_qrcode_set_dark_color(lv_qrcode_1, lv_color_hex(0x2563eb));
    lv_qrcode_set_light_color(lv_qrcode_1, lv_color_hex(0xeff6ff));
    lv_qrcode_set_quiet_zone(lv_qrcode_1, true);
    lv_qrcode_set_data(lv_qrcode_1, "https://lvgl.io");
}

