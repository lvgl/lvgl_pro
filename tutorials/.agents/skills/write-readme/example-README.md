# Thermostat

## Goal

A wall thermostat for a living room. The user sees the room temperature and the target
temperature at a glance, and changes the target on a touch screen. The application
measures the temperature and drives the heater.

## Spec

- **Screens:**
  - `screen_home`: the room and the target temperature, a "Heating" label while the
    heater runs, and a Settings button.
  - `screen_settings`: the target temperature, a slider to change it, and a Save button.
- **Flow:**
  - `screen_home` → `screen_settings`: the Settings button.
  - `screen_settings` → `screen_home`: the Save button.
- **Components:** `temp_card` shows a title and one temperature. Used twice on
  `screen_home` and once on `screen_settings`.
- **Subjects:**
  - Written by the application: `subject_room_temp`, `subject_heating`.
  - Written by the UI: `subject_target_temp`.
- **Open questions:** none.

<!-- write-readme:begin -->

## Overview

The UI has two screens. It is made for a 320 x 240 touch display and LVGL v9.6.0.

| Screen | Permanent | Purpose |
| --- | --- | --- |
| `screen_home` | yes | Shows the room and the target temperature |
| `screen_settings` | no | Changes the target temperature |

A permanent screen is created once, at init, and is never deleted. Any other screen is
created when it opens and deleted when another screen replaces it.

## Build

With CMake, add LVGL first, then this folder, and link `lib-ui`:

```cmake
add_subdirectory(lvgl)
add_subdirectory(thermostat)
target_link_libraries(my_app PRIVATE lib-ui)
```

The order is important: `lib-ui` links to the `lvgl` target only if it exists at that
point. To give the library another name, set `LVGL_COMPONENT_LIB_NAME` before
`add_subdirectory()`.

Without CMake, compile the files listed in `file_list_gen.cmake` and in
`user_config.cmake`, and add this folder to the include path.

Set these in `lv_conf.h`:

| Option | Why |
| --- | --- |
| `LV_USE_OBJ_NAME 1` | The generated code names the widgets |
| `LV_USE_TRANSLATION 1` | The UI is in English and German |
| `LV_USE_TINY_TTF 1` | `font_big` is rendered from a TTF file at runtime |
| `LV_TINY_TTF_FILE_SUPPORT 1` | `font_big` loads the TTF from a file, not from a C array |
| `LV_USE_FS_STDIO 1`, `LV_FS_STDIO_LETTER 'A'` | A file system driver for the asset files. Use the driver of your platform, with the same letter as in `asset_path` |

## Start the UI

```c
#include "thermostat.h"

lv_init();
/* Create the display and the input devices here */
thermostat_init("A:");
lv_screen_load(screen_home);
/* Call lv_timer_handler() in a loop */
```

`screen_home` is only an example. The application can load any screen first: a
permanent screen with `lv_screen_load(screen_home)`, any other screen with
`lv_screen_load(screen_settings_create())`.

`"A:"` is the folder of the asset files. See [Asset files](#asset-files).

## Screens and flow

The UI changes screens by itself. The application does nothing for it.

- `screen_home`: the Settings button opens `screen_settings`.
- `screen_settings`: the Save button calls `on_save()`, then loads `screen_home`.

## Subjects

Subjects are the interface between the UI and the application. The application writes
a subject to update the UI, and observes a subject to learn what the user changed.

A write outside the range of a subject is clamped to it.

### Written by the application

The UI only shows these. The application must keep them up to date.

| Subject | Type | Range | Start value | Unit |
| --- | --- | --- | --- | --- |
| `subject_room_temp` | int | -20 to 50 | 21 | °C |
| `subject_heating` | int | 0 to 1 | 0 | 1 = heater on |

For example, after a new measurement:

```c
lv_subject_set_int(subject_room_temp, 23);
```

### Written by the UI

The user changes these. The application reads or observes them. It can also set them,
for example to restore a saved value at startup.

| Subject | Type | Range | Start value | Unit | Changed with |
| --- | --- | --- | --- | --- | --- |
| `subject_target_temp` | int | 10 to 30 | 22 | °C | the slider on `screen_settings` |

React when the user changes the target:

```c
static void target_temp_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    LV_UNUSED(observer);
    heater_set_target(lv_subject_get_int(subject));  /* Your code */
}

/* In thermostat_init(), after thermostat_init_gen() */
lv_subject_add_observer(subject_target_temp, target_temp_cb, NULL);
```

`lv_subject_add_observer()` calls the callback once right away, with the current value.

LVGL is not thread safe. Write subjects from the thread that calls
`lv_timer_handler()`, or between `lv_lock()` and `lv_unlock()`.

## Callbacks to implement

| Function | Where | Trigger | `user_data` |
| --- | --- | --- | --- |
| `void on_save(lv_event_t * e)` | Save button on `screen_settings` | clicked | none |

`on_save()` must store the target temperature, for example in flash. Read it with
`lv_subject_get_int(subject_target_temp)`. The generated code calls this function, so
the application must define it.

## Translations

The languages are `en` and `de`. Init selects `en`. To change the language:

```c
lv_translation_set_language("de");
```

## Asset files

Copy these files to the device, under the path given to `thermostat_init()`:

| File | Used by |
| --- | --- |
| `fonts/Montserrat-Medium.ttf` | `font_big` |

With `thermostat_init("A:")` the UI opens `A:fonts/Montserrat-Medium.ttf`.

The licenses of the fonts and images are in [ASSET_LICENSES.md](ASSET_LICENSES.md).

## Tests

The tests are XML files in `tests/`. They run the real UI, click and drag on it, and
compare subjects and screenshots.

| Test | What it checks |
| --- | --- |
| `test_target_slider.xml` | Dragging the slider on `screen_settings` from left to right sets `subject_target_temp` to 30. Compares the screen with `target_30.png` |

The tests run on the PC, not on the device, with the LVGL Pro CLI. Install it once
(Node 18 or newer):

```bash
npm install --global @lvgl/lvglpro
```

The CLI needs an LVGL Pro license token. Set it in the environment, not on the command
line, and never commit it:

```bash
export LVGLPRO_CLI_TOKEN="..."
lvglpro generate .
lvglpro run-all-tests .
```

Run `generate` first: the tests build the exported C. To run one test:
`lvglpro run-test . tests/test_target_slider.xml`.

A missing reference screenshot is created on the first run, and that step passes. Look
at the new image, then commit it with the test. When a compare fails, the CLI saves
what it saw next to the reference, with an `_err` suffix.

### In CI

`run-all-tests` exits with code 1 when a step fails, so it can stop a pull request.
Store the token as an encrypted repository secret named `LVGLPRO_CLI_TOKEN`, then use
this GitHub Actions workflow, for example in `.github/workflows/ui-tests.yml`:

```yaml
name: UI tests
on: [push, pull_request]

jobs:
  ui-tests:
    runs-on: ubuntu-latest
    env:
      LVGLPRO_CLI_TOKEN: ${{ secrets.LVGLPRO_CLI_TOKEN }}
    steps:
      - uses: actions/checkout@v4
      - uses: actions/setup-node@v4
        with:
          node-version: '24'
      - run: npm install --global @lvgl/lvglpro
      - run: lvglpro generate .
      - run: lvglpro run-all-tests .
```

If the UI is in a subfolder of the repository, use that path instead of `.`.

## Change the UI

1. Edit the XML files. The syntax is in `AGENTS.md` and in the
   [XML docs](https://lvgl.io/docs/pro/syntax/overview).
2. Run `lvglpro generate .`, or export the code in the Editor.

Never edit a `*_gen.c` or `*_gen.h` file: `generate` overwrites them. Put your own code
in `thermostat.c`, or in new files that you add to `user_config.cmake`.

To try the UI on a PC, run it in the simulator, from this folder:

```bash
cmake -S sim -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
cmake --build build --target run
```

<!-- write-readme:end -->
