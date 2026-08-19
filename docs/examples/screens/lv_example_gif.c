/**
 * @file lv_example_gif.c
 */

#include "../lv_examples.h"

/**
 * @title GIF
 * @brief An animated GIF, embedded as a raw C array.
 *
 * `src` names an image from `globals.xml`, registered there with
 * `color_format="raw"`, so the export embeds the GIF file itself instead of
 * converting it. `loop_count` sets how many times it repeats; leave it unset to
 * use the count stored in the GIF.
 */
void lv_example_gif(void)
{
    LV_IMAGE_DECLARE(img_bulb);

    lv_obj_t * screen = lv_screen_active();

    lv_obj_t * lv_gif_0 = lv_gif_create(screen);
    lv_gif_set_src(lv_gif_0, &img_bulb);
    lv_gif_set_loop_count(lv_gif_0, 10);
    lv_obj_set_align(lv_gif_0, LV_ALIGN_CENTER);
}

