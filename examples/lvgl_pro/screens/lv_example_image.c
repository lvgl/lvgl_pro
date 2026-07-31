/**
 * @file lv_example_image.c
 */

#include "../lv_examples.h"

/**
 * @title Image
 * @brief The same source shown plain, rotated + scaled, and recoloured.
 *
 * `src` points at a registered image. The second copy sets `rotation` (in
 * 0.1° steps) with `scale_x`/`scale_y` (256 = 100 %) around a centred pivot.
 * The third uses the `image_recolor` style properties to tint the pixels.
 */
void lv_example_image(void)
{
    LV_IMAGE_DECLARE(img_logo);

    static lv_style_t style_tint;

    static bool inited = false;

    if (!inited) {
        lv_style_init(&style_tint);
        lv_style_set_image_recolor(&style_tint, lv_color_hex(0x3b82f6));
        lv_style_set_image_recolor_opa(&style_tint, (255 * 80 / 100));

        inited = true;
    }

    lv_obj_t * screen = lv_screen_active();
    lv_obj_set_style_pad_all(screen, 0, 0);
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_flex_main_place(screen, LV_FLEX_ALIGN_SPACE_EVENLY, 0);
    lv_obj_set_style_flex_cross_place(screen, LV_FLEX_ALIGN_CENTER, 0);
    lv_obj_set_style_flex_track_place(screen, LV_FLEX_ALIGN_CENTER, 0);

    lv_obj_t * lv_image_0 = lv_image_create(screen);
    lv_image_set_src(lv_image_0, &img_logo);

    lv_obj_t * lv_image_1 = lv_image_create(screen);
    lv_image_set_src(lv_image_1, &img_logo);
    lv_image_set_rotation(lv_image_1, 300);
    lv_image_set_scale_x(lv_image_1, 580);
    lv_image_set_scale_y(lv_image_1, 180);

    lv_obj_t * lv_image_2 = lv_image_create(screen);
    lv_image_set_src(lv_image_2, &img_logo);
    lv_obj_add_style(lv_image_2, &style_tint, 0);
}

