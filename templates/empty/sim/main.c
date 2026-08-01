/**
 * @file main.c
 *
 * PC simulator entry point for a UI exported from LVGL Pro: opens a window,
 * initializes the exported UI library and starts the LVGL loop.
 */

/* Built only by sim/CMakeLists.txt; lets a glob-based embedded build skip it. */
#ifdef LVGL_PRO_SIMULATOR_BUILD

#include "lvgl.h"
#include "hal.h"
#include UI_HEADER   /* exported UI library: header, UI_INIT and size come from
                        project.xml via sim/CMakeLists.txt */

int main(void)
{
    lv_init();

    /* Hold the LVGL mutex while building the UI: a no-op without an OS, but
     * required to stay off the Windows driver's render thread. */
    lv_lock();

    hal_init(UI_WIDTH, UI_HEIGHT);
    UI_INIT("A:");      /* "A:" = file-system drive for file-based assets */

    /* Load a screen from your project, e.g.:
     * lv_screen_load(my_screen_create()); */

    lv_unlock();

    while(1) {
        uint32_t idle_ms = lv_timer_handler();
        if(idle_ms == LV_NO_TIMER_READY) idle_ms = LV_DEF_REFR_PERIOD;
        lv_sleep_ms(idle_ms);
    }

    return 0;
}

#endif /*LVGL_PRO_SIMULATOR_BUILD*/
