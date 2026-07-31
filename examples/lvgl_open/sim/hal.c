/**
 * @file hal.c
 */

/* Built only by sim/CMakeLists.txt; lets a glob-based embedded build skip it. */
#ifdef LVGL_PRO_SIMULATOR_BUILD

#include "hal.h"

#ifdef _WIN32

/*==================
 *   Windows driver
 *==================*/

#include <windows.h>

lv_display_t * hal_init(int32_t hor_res, int32_t ver_res)
{
    lv_display_t * disp = lv_windows_create_display(
        L"LVGL Simulator", hor_res, ver_res,
        100,    /*Zoom level: 100 = 100%*/
        false,  /*allow_dpi_override*/
        false); /*simulator_mode*/

    lv_group_t * group = lv_group_create();
    lv_group_set_default(group);

    lv_indev_t * pointer = lv_windows_acquire_pointer_indev(disp);
    lv_indev_set_group(pointer, group);

    lv_indev_t * keypad = lv_windows_acquire_keypad_indev(disp);
    lv_indev_set_group(keypad, group);

    lv_indev_t * encoder = lv_windows_acquire_encoder_indev(disp);
    lv_indev_set_group(encoder, group);

    return disp;
}

#else

/*==================
 *    SDL driver
 *==================*/

#include <SDL.h>

lv_display_t * hal_init(int32_t hor_res, int32_t ver_res)
{
    lv_display_t * disp = lv_sdl_window_create(hor_res, ver_res);

    lv_group_t * group = lv_group_create();
    lv_group_set_default(group);

    lv_indev_t * mouse = lv_sdl_mouse_create();
    lv_indev_set_group(mouse, group);

    lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
    lv_indev_set_group(mousewheel, group);

    lv_indev_t * keyboard = lv_sdl_keyboard_create();
    lv_indev_set_group(keyboard, group);

    return disp;
}

#endif

#endif /*LVGL_PRO_SIMULATOR_BUILD*/
