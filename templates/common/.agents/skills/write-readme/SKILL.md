---
name: write-readme
description: Write or update the README.md of an LVGL Pro project for the firmware developer who adds the UI to an application. Covers the build, the init call, the screens, the subjects, the C callbacks, targets, translations, asset files, and running the tests locally and in CI, with the real names from the generated C. Use when the user wants to document the project, its C API, or how to integrate it, or to refresh that README after the UI changed.
---

# Write the README

Read `AGENTS.md` at the project root first, if it is not in your context. Follow its
"Working with the user" rules.

The reader is a firmware developer. They know C and LVGL, but they did not make this
UI. After reading the README they must be able to build the UI, show it, and connect it
to their application. Do not explain the XML syntax: link to `AGENTS.md` and the
[XML docs](https://lvgl.io/docs/pro/syntax/overview) for that.

## Steps

Show this checklist to the user and keep it up to date.

1. Generate the C
2. Collect the facts
3. Ask about what is missing
4. Write or update `README.md`
5. Check the names
6. Report

### 1. Generate the C

The C names in the README must come from the generated files, not from the XML. Run:

```bash
lvglpro generate .
```

If the CLI is not available, take the names from the XML with the rules in step 2, and
mark every C name in the report as not verified.

### 2. Collect the facts

`<project>` is `name` in `project.xml`, or the project folder name if there is no
`name`. `<PROJECT>` is the same in capitals. Read these places:

| Section | Where to find it | What to take |
| --- | --- | --- |
| Goal and spec | `## Goal` and `## Spec` in `README.md`, the user's request | See step 4 |
| Overview | `project.xml`, `screens/` | The screens, the display size of each target, `lvgl_version` |
| Build | `CMakeLists.txt`, `file_list_gen.cmake`, `user_config.cmake` | The library target is `lib-ui`, or the value of `LVGL_COMPONENT_LIB_NAME` if it is set. It links to the `lvgl` target only if that target exists when CMake reads the project, so LVGL must be added first. Without CMake: compile every file in `file_list_gen.cmake` and in `user_config.cmake`, and add the project root to the include path |
| `lv_conf.h` | See the table below | Each option the UI needs that is `0` in LVGL's `lv_conf_template.h` |
| Start the UI | `<project>.h` | `<project>_init(asset_path)`. The application calls it after `lv_init()` and after it creates the display and the input devices |
| Screens | `screens/**/*.xml`, `screens/**/*_gen.h` | Each screen, its `<screen permanent="true">` flag, and its `lv_obj_t * <screen>_create(void)` |
| First screen | The spec, then the screens and the flow | The screen the application shows first. Nothing in the project says which one it is, so pick one: the screen the spec names, else a permanent screen, else a screen named like `main` or `home`, else the screen that no other screen opens. Do not take it from `sim/main.c`: that line only shows one screen in the simulator |
| Flow | `<screen_load_event>` and `<screen_create_event>` in the XML | Which screen opens which, on which trigger. This flow runs in the UI, the application does nothing for it |
| Subjects | `<subjects>` in `globals.xml`, `extern lv_subject_t *` in `<project>_gen.h` | Name, type, `value` (the start value), `min_value`, `max_value`, XML comments for the meaning and the unit |
| Who writes a subject | The XML | The UI writes it if it is in a `<set_subject_event subject=...>`, or in a widget binding such as `bind_value`, which works both ways. Otherwise the application writes it |
| Callbacks | `<event_cb callback=...>` in the XML, the "Event Callbacks" part of `<project>_gen.h` | The function name, the widget and the screen it is on, `trigger`, `user_data`. The application must write each one as `void <name>(lv_event_t * e)` |
| Targets | `<targets>` in `project.xml`, `<project>_gen.h` | `<PROJECT>_TARGET_<NAME>`, `<project>_set_target()`, and `<PROJECT>_COMPILE_TARGET`. The default is all targets. To build fewer, change its `#define` in `<project>.h`, which `generate` does not overwrite. In an older project, `<project>.h` does not have it: add it there, before the `#include` of `<project>_gen.h` |
| Translations | `translations.xml` | The language codes. Init selects the first one |
| Asset files | `asset_path, "` in `<project>_gen.c` | The relative path of each font and image loaded from a file at runtime. These files must be on the device under `asset_path` |
| Licenses | `ASSET_LICENSES.md` | Link to it. If it is missing, tell the user |
| Tests | `tests/*.xml`, `tests/*.png` | Each test file, and what it checks: read its `<view>` and its `<steps>`. The reference screenshots, and whether they are committed (`git ls-files tests`) |
| CI | `.github/workflows/` | Whether a workflow already runs the tests |

The `lv_conf.h` options to check:

| If the project uses | It needs |
| --- | --- |
| any exported C | `LV_USE_OBJ_NAME 1` |
| `translations.xml` | `LV_USE_TRANSLATION 1` |
| a `<float>` subject | `LV_USE_FLOAT 1` |
| a `<tiny_ttf>` font | `LV_USE_TINY_TTF 1`. With `as_file="true"`, also `LV_TINY_TTF_FILE_SUPPORT 1` |
| a `<freetype>` font | `LV_USE_FREETYPE 1` |
| a PNG loaded from a file | `LV_USE_LODEPNG 1` |
| any file in "Asset files" | a file system driver, for example `LV_USE_FS_STDIO 1` with `LV_FS_STDIO_LETTER 'A'`, and `asset_path` starting with that letter: `"A:"` |
| an `lv_<widget>` tag | `LV_USE_<WIDGET> 1`. Most widgets are on by default. Check each one in `lv_conf_template.h` of the project's LVGL version, for example `LV_USE_QRCODE` and `LV_USE_GIF` are off |

`sim/lv_conf_sdl.defaults` shows a working set for the simulator. It also turns on
options for the demos that this project may not need, so do not copy it as a whole.

Facts to state about the generated code:

- Never edit a `*_gen.c` or `*_gen.h` file. `generate` overwrites them.
- `<project>.c` and `<project>.h` are created only once. Put application code that must
  run at init, for example an observer, in `<project>_init()`, after the call to
  `<project>_init_gen()`.
- A permanent screen is a global `lv_obj_t *` with the screen's name. Init creates it
  when `LV_USE_XML` is not defined or is `0`, and the application loads it with
  `lv_screen_load(<screen>)`. LVGL v9.6 has no `LV_USE_XML` in `lv_conf.h`, so this is
  the normal case. Read the comment above "Permanent screens" in
  `<project>_init_gen()` for the case `LV_USE_XML` is `1`.
- Other screens: `lv_screen_load(<screen>_create())`.
- Subjects are pointers: `lv_subject_set_int(subject_volume, 50)`, not
  `&subject_volume`. The functions by type: `int` `lv_subject_set_int` and
  `lv_subject_get_int`, `float` `..._float`, `string` `lv_subject_set_string` and
  `lv_subject_get_string`, `color` `..._color`, `pointer` `..._pointer`. React to a
  change with `lv_subject_add_observer(subject, cb, user_data)`, where `cb` is
  `void cb(lv_observer_t * observer, lv_subject_t * subject)`.
- LVGL is not thread safe. Write subjects from the thread that calls
  `lv_timer_handler()`, or between `lv_lock()` and `lv_unlock()`.
- A subject inside a `<component>` or `<screen>` is local to it. Only the subjects in
  `<project>_gen.h` are reachable from C.

Facts to state about the tests:

- The CLI runs them: `npm install --global @lvgl/lvglpro` (Node 18 or newer). It
  needs an LVGL Pro license token in `LVGLPRO_CLI_TOKEN`, see the
  [CLI docs](https://lvgl.io/docs/pro/cli). Without the token every
  project command stops with "No token provided" and exit code 1. `--help` and
  `--version` work without it.
- Run `lvglpro generate .` first: the tests build the exported C, and a template does
  not commit it. Then `lvglpro run-all-tests .`, or `lvglpro run-test . tests/<file>.xml`
  for one test. `run-all-tests` compiles the project itself.
- The exit code is 1 when a step fails, so CI can use it as a gate.
- A missing reference screenshot is created, and the step passes. So commit the
  reference PNGs, or CI creates new ones on every run and checks nothing. A failed
  compare saves the screen next to the reference, with an `_err` suffix.
- The tests run on the first target in `project.xml` only.
- The CLI uses its own emscripten copy in `~/.config/lvgl-editor/emsdk`, and clones it
  when it is missing. So CI needs no emsdk step.
- In CI, store the token as an encrypted secret, for example a GitHub Actions secret
  named `LVGLPRO_CLI_TOKEN`. Never commit it, and do not pass it with `--token`, which
  can show it in the logs.

### 3. Ask about what is missing

Ask in one message, with a proposed answer for each:

- A subject with no clear meaning or unit.
- A subject where the XML does not show who writes it.
- The purpose of an `<event_cb>`, if its name and place do not show it.
- Where the asset files go on the device, if the project has any.
- The first screen, with your pick as the proposed answer.
- The goal, if there is no `## Goal` yet and the user's request does not describe it.

### 4. Write or update `README.md`

The README has two parts.

**Goal and spec.** `## Goal` and `## Spec` come first, after the title. The
`idea-to-xml` and `image-to-xml` skills write them too, and the user approves them
there, so they are the design intent, not a description of the XML.

- If they exist, keep them as they are. If the UI now does something that the spec
  does not say, do not change the spec: list the difference in the report.
- If one is missing and the user's request describes it, write it from the request.
  The goal is two or three sentences: the product, the user, the main task. The spec
  has the screens, the flow, the components, the subjects, and the open questions.
- If one is missing and the request does not describe it, add the heading and a
  comment under it:

  ```markdown
  ## Goal

  <!-- TODO: Fill in. The product, who uses it, and the main task, in 2-3 sentences. -->
  ```

**The integration part.** Everything else this skill writes goes after the spec,
between these two lines:

```markdown
<!-- write-readme:begin -->
<!-- write-readme:end -->
```

On an update, replace only the text between them. Keep the rest of the file.

[example-README.md](example-README.md) is a finished README for a small thermostat
project. Match its depth and its style. Its names are from that project, not from this
one.

Use these sections in the integration part, in this order. Leave out a section that has
nothing in it, for example "Targets" for a project with one target.

1. **Overview:** two or three sentences. A table of the screens: name, permanent or not,
   purpose. The display size per target.
2. **Build:** the CMake lines, the file list without CMake, the `lv_conf.h` options.
3. **Start the UI:** one short, complete C example with the real names:

   ```c
   #include "<project>.h"

   lv_init();
   /* Create the display and the input devices here */
   <project>_init("A:");
   lv_screen_load(<first_screen>_create());
   /* Call lv_timer_handler() in a loop */
   ```

   For a permanent first screen, write `lv_screen_load(<first_screen>);` instead. Under
   the example, say that `<first_screen>` is only an example and that the application
   can load any screen first.

4. **Screens and flow:** the flow as a list: "`screen_main`: About button opens
   `screen_about`".
5. **Subjects:** two separate tables, each with name, type, range, start value, unit:
   - **Written by the application:** the UI only shows them. Follow the table with a C
     example that writes one.
   - **Written by the UI:** the user changes them. The application reads or observes
     them, and may also set them, for example to restore a saved value. Follow the
     table with a C example that observes one.

   Do not mix the two in one table. Leave out a table that has no subject.
6. **Callbacks to implement:** a table: function, where, trigger, `user_data`. Say
   that the generated code calls each one, so the application must define all of them.
7. **Targets:** the values, and `<project>_set_target()` before `<project>_init()`.
8. **Translations:** the languages, and `lv_translation_set_language("<code>")`.
9. **Asset files:** the paths to copy to the device, and a link to `ASSET_LICENSES.md`.
10. **Tests:** a table: test file, what it checks. How to run them locally, and a CI
    workflow that runs them, with the token as a secret. Use the facts above. If the
    project has no tests, keep the section short: where tests go, and a link to the
    "Tests" part of `AGENTS.md`.
11. **Change the UI:** edit the XML, run `lvglpro generate .`, never edit `*_gen.*`, put
    your code in `<project>.c` or in files listed in `user_config.cmake`. The simulator
    commands from `AGENTS.md`.

Do not list the component `_create` functions or the `#define` constants, except the
target values of item 7. A developer finds them in the headers.

Write short and plain. Use tables for lists of names. Every C name in the README must
be one you read in a generated file.

### 5. Check the names

If step 1 ran the CLI, search for each C name of the README in the generated files, for
example `grep -rn "subject_volume" --include=*.h .`. Remove or fix every name that is not
there. If it did not, keep the names from the XML, and mark them as not verified. Then
read the README from top to bottom once, as the firmware developer.

### 6. Report

- The sections written or updated.
- The answers you assumed in step 3, including the first screen.
- A `## Goal` or `## Spec` left as a TODO.
- The differences between the spec and the UI.
- The `lv_conf.h` options you could not decide.
- Reference screenshots in `tests/` that are not committed.
- What is not verified, for example the C names if the CLI was not available.
