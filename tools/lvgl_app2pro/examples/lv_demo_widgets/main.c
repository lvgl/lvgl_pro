/**
 * LVGL's widgets demo in an SDL window, to have something to convert.
 *
 * Build it, then point lvgl_app2pro at the binary. See the README next to
 * this file.
 *
 * The window size and the tab to open have build-time defaults that the
 * command line overrides:
 *
 *     ./lv_demo_widgets --width 800 --height 1400 --tab 2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lvgl.h"
#include "demos/lv_demos.h"

#ifndef DEMO_WIDTH
#define DEMO_WIDTH  800
#endif

#ifndef DEMO_HEIGHT
#define DEMO_HEIGHT 480
#endif

#ifndef DEMO_TAB
#define DEMO_TAB    0
#endif

/* The converter calls lv_snapshot_take() from GDB. Nothing here calls it, so
 * without a reference the linker leaves it out of the binary. */
void * const demo_keep_snapshot = (void *)(uintptr_t)lv_snapshot_take;

static void usage(const char * program)
{
    printf("usage: %s [--width N] [--height N] [--tab N]\n", program);
}

/*The demo builds one tabview under the screen; find it rather than assume an index.*/
static lv_obj_t * find_tabview(lv_obj_t * parent)
{
    uint32_t i;
    for(i = 0; i < lv_obj_get_child_count(parent); i++) {
        lv_obj_t * child = lv_obj_get_child(parent, i);
        if(lv_obj_check_type(child, &lv_tabview_class)) return child;
    }
    return NULL;
}

int main(int argc, char ** argv)
{
    int32_t width = DEMO_WIDTH;
    int32_t height = DEMO_HEIGHT;
    uint32_t tab = DEMO_TAB;

    for(int i = 1; i < argc; i++) {
        int has_value = i + 1 < argc;
        if(!strcmp(argv[i], "--width") && has_value) width = atoi(argv[++i]);
        else if(!strcmp(argv[i], "--height") && has_value) height = atoi(argv[++i]);
        else if(!strcmp(argv[i], "--tab") && has_value) tab = (uint32_t)atoi(argv[++i]);
        else {
            usage(argv[0]);
            return strcmp(argv[i], "--help") ? 1 : 0;
        }
    }

    lv_init();

    lv_display_t * display = lv_sdl_window_create(width, height);
    lv_display_set_default(display);

    lv_indev_t * mouse = lv_sdl_mouse_create();
    lv_indev_set_display(mouse, display);

    lv_demo_widgets();

    if(tab > 0) {
        lv_obj_t * tabview = find_tabview(lv_screen_active());
        if(tabview) lv_tabview_set_active(tabview, tab, LV_ANIM_OFF);
    }

    while(1) {
        uint32_t wait = lv_timer_handler();
        if(wait == LV_NO_TIMER_READY) wait = LV_DEF_REFR_PERIOD;
        lv_delay_ms(wait);
    }

    return 0;
}
