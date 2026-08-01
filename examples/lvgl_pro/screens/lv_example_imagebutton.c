/**
 * @file lv_example_imagebutton.c
 */

#include "../lv_examples.h"

/**
 * @title Image button
 * @brief A button drawn from per-state images instead of a styled rectangle.
 *
 * `<lv_imagebutton-src_left>`, `-src_mid` and `-src_right` set the image for
 * a given `state`. The middle image is tiled to fill the width, so left and
 * right act as fixed end-caps. Here the released and pressed states use the
 * same source to keep the example self-contained.
 */
void lv_example_imagebutton(void)
{
    LV_IMAGE_DECLARE(imgbtn_left);
    LV_IMAGE_DECLARE(imgbtn_mid);
    LV_IMAGE_DECLARE(imgbtn_right);

    static lv_style_t style_pressed;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_pressed);
        lv_style_set_transform_width(&style_pressed, 10);
        lv_style_set_image_recolor(&style_pressed, lv_color_hex3(0x000));
        lv_style_set_image_recolor_opa(&style_pressed, (255 * 20 / 100));

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();

    lv_obj_t * lv_imagebutton_0 = lv_imagebutton_create(screen);
    lv_obj_set_width(lv_imagebutton_0, 160);
    lv_obj_set_align(lv_imagebutton_0, LV_ALIGN_CENTER);
    lv_obj_add_style(lv_imagebutton_0, &style_pressed, LV_STATE_PRESSED);
    lv_imagebutton_set_src_left(lv_imagebutton_0, LV_IMAGEBUTTON_STATE_RELEASED, &imgbtn_left);
    lv_imagebutton_set_src_mid(lv_imagebutton_0, LV_IMAGEBUTTON_STATE_RELEASED, &imgbtn_mid);
    lv_imagebutton_set_src_right(lv_imagebutton_0, LV_IMAGEBUTTON_STATE_RELEASED, &imgbtn_right);
    lv_obj_t * lv_label_0 = lv_label_create(lv_imagebutton_0);
    lv_obj_set_align(lv_label_0, LV_ALIGN_CENTER);
    lv_label_set_text(lv_label_0, "Press");
    lv_obj_set_style_text_color(lv_label_0, lv_color_hex(0xffffff), 0);
    lv_obj_set_y(lv_label_0, -3);
}

