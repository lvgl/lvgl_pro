---
name: open-to-xml
description: Convert an existing LVGL C application (LVGL Open) into LVGL Pro XML with the lvgl_app2pro tool, then migrate its event callbacks to XML events and data bindings. Use when the user wants to move a C UI, a running LVGL app, or lv_demo code to XML.
---

# LVGL C app to XML

Read `AGENTS.md` at the project root first, if it is not in your context. Follow its
"Working with the user" rules.

The tool `lvgl_app2pro` does not parse C. It starts the app under GDB, stops it when the
UI is up, and reads the live widget tree. Docs:
[Migration from C code](https://lvgl.io/docs/pro/migration/from-c-code).

## Steps

Show this checklist to the user and keep it up to date.

1. Check the prerequisites
2. Get the tool
3. Convert
4. Read the report
5. Migrate the event callbacks
6. Do the other manual work
7. Check
8. Report

### 1. Check the prerequisites

Ask for these, all in one message:

- The path of the app binary, and of its C sources. You need the sources in step 5.
- The command-line arguments of the app, if any.
- Where the output goes: a new folder, or this project. Recommend a new folder, then
  copy the files in after a review.

Check, and stop with a clear message if one fails:

- Linux. macOS is not supported.
- GDB with Python 3.10 or newer:
  `gdb -batch -ex "python import sys; print(sys.version)"`
- `python3` 3.10 or newer.
- The app uses LVGL v9.6 or newer, and is built with `-O0 -g3`. Older versions are
  rejected by the tool.
- Network access on the first run. The tool downloads LVGL's GDB plugin once.

### 2. Get the tool

The tool is in the `lvgl/lvgl_pro` repo, not in this project:

```bash
git clone --depth 1 https://github.com/lvgl/lvgl_pro /tmp/lvgl_pro
cd /tmp/lvgl_pro/tools/lvgl_app2pro
```

<!-- Until lvgl/lvgl_pro PR #463 is merged, add: --branch lvgl_open_to_xml -->

Read `README.md` there. If it disagrees with this skill, the README is right.

### 3. Convert

```bash
python3 lvgl_app2pro.py <app binary> -o <outdir>
```

Useful options (check `--help`):

- `--app-args "..."`: arguments for the app.
- `--stop-at LOCATION`: stop at another place. The default is the second
  `lv_timer_handler()` call, so the layout is ready.
- `--timeout <s>`: default 300.

Only the screens that exist at the stop are converted. If the app creates screens later,
ask the user where to stop, or run the tool more than once.

### 4. Read the report

The tool prints a report: fonts to declare, images to supply, callbacks and their
triggers, and fields it could not map. In the XML, the same items are `TODO` comments.
Show the user a short summary: counts per type, and the screens.

### 5. Migrate the event callbacks

Each callback is now `<event_cb callback="X" trigger="..."/>` with
`<!-- TODO: implement X() -->`. Find the body of `X` in the C sources. Then replace it
with XML where you can:

| The C body does | XML |
| --- | --- |
| `lv_screen_load(scr)` or `lv_screen_load_anim(...)` | `<screen_load_event screen="..."/>`. The screen needs `permanent="true"` |
| Creates a new screen and loads it | `<screen_create_event screen="..."/>` |
| Writes a variable or a subject | A subject in `globals.xml` and `<set_subject_event>` |
| Copies a widget value to a label (`lv_label_set_text_fmt(label, "%d", lv_slider_get_value(...))`) | A subject: `bind_value` on the widget, `text="{subject}"` on the label. No event |
| Shows, hides, enables, or disables a widget | A subject, and `hidden="{...}"` or `disabled="{...}"` |
| Adds or removes a style or state | `<style enabled="{...}"/>` or `checked="{...}"` |
| Starts an `lv_anim_t` | A `<timeline>` and `<play_timeline_event>` |
| Talks to hardware, files, or the network | Keep `<event_cb>`. The body stays in C |

Rules:

- Ask before you replace a callback that does more than one thing.
- Keep one `<event_cb>` per callback that stays in C. Remove its `TODO` comment, and
  list it in the report: the user must add `void X(lv_event_t * e)` to the C code.
- Show the user the planned mapping as a table before you edit.

### 6. Do the other manual work

Ask which of these to do. Each one costs time:

- **Fonts:** register them in `<fonts>` and set `style_text_font` where the TODOs point.
  Ask for the TTF files.
- **Images:** the tool writes PNGs only for C-array images. Ask for the others.
- **Components:** each screen is one flat file. Find repeated subtrees and propose
  components.
- **Constants:** the tool names constants by value. Rename them by meaning, for example
  `color_primary`, not `color_1`.
- **Animations, timers, translations:** the tool does not convert them.

### 7. Check

```bash
lvglpro validate . --errorlimit 25
lvglpro generate .
lvglpro compile .
lvglpro screenshot . screens/<screen>.xml --out /tmp/<screen>.png --delay 300
```

Ask the user for a screenshot of each screen from the original app. Compare it with the
`lvglpro screenshot` result, and list the differences.

### 8. Report

- The screens, components, and subjects created.
- The callbacks moved to XML, and the ones still in C, with their names.
- The open TODOs: fonts, images, animations.
- What is not verified.
