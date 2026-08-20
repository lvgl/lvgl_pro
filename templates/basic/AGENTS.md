# AGENTS.md

How to work in this LVGL Pro project. The UI is written in XML — HTML-like markup that
the Editor or the CLI turns into plain LVGL C code. You do not hand-write the C.

## Ground rules

1. **Never invent an attribute.** Each widget's API is defined by a schema file, and the
   schema is not part of a UI project. Read it before you write — fetch
   `raw.githubusercontent.com/lvgl/lvgl_pro/master/lvgl_widgets_xml/v<version>/lv_slider.xml`
   for `lv_slider`, or read `lvgl_widgets_xml/` directly if you are in the
   [lvgl_pro](https://github.com/lvgl/lvgl_pro) repo. Style properties and enums are in
   `globals.xml` in the same folder, and
   [Built-in widgets](https://lvgl.io/docs/pro/built_in_widgets) has the same API as
   readable pages.
2. **Match this project's LVGL version.** Read `lvgl_version` from `project.xml` and use
   that schema folder — `lvgl_version="9.5.0"` is the folder `v9.5.0`.
3. **Validate what you write.** Guessing is not the same as knowing. See *Verifying*.
4. **Reuse before you create.** Read `globals.xml` and `components/` first. The
   constant, the style and the button you were about to invent are often already there.
5. **Ask the MCP server about LVGL itself.** `.mcp.json` in this folder wires up
   `https://lvgl.mcp.kapa.ai/`. Prefer it over recalling LVGL APIs from memory.

## What is where

```
project.xml       ← display targets and the LVGL version
globals.xml       ← shared consts, styles, fonts, images, subjects
translations.xml  ← optional
components/       ← reusable building blocks, pure XML
screens/          ← full screens
widgets/          ← only for widgets backed by hand-written C
fonts/  images/   ← assets
tests/            ← XML tests, if the project has any
sim/              ← the PC simulator; nothing here ships in firmware
```

`project.xml` and `globals.xml` sit at the root, and every `src_path` is relative to it.

## The three file kinds

| Root tag | What it is | Can hold |
| --- | --- | --- |
| `<component>` | Reusable UI element, pure XML, no C. The workhorse. | `animations`, `consts`, `api`, `styles`, `view`, `previews` |
| `<screen>` | A full screen, created as-is, no parameters. | `consts`, `styles`, `view` |
| `<widget>` | A widget backed by hand-written C. Needs a C parser, cannot be loaded from XML at runtime, and needs the preview recompiled. | `consts`, `api`, `styles`, `view`, `previews` |

One file per element, and the filename becomes the tag: `my_button.xml` is `<my_button/>`.

**Write components unless you truly need C.** Reach for a `<widget>` only when the
behaviour cannot be expressed as composition plus data binding.

## The syntax that gets misread

### The three sigils

| Prefix | Means | Example |
| --- | --- | --- |
| `$name` | An `<api>` property of this element | `<lv_label text="$title"/>` |
| `#name` | A constant from `<consts>` or `globals.xml` | `pad="#space_md"` |
| `{ ... }` | An expression, evaluated once at creation | `hidden="{!icon}"` |

Inside `{ }` write bare identifiers — no `$`, no `#`.

### `view` and `extends`

`<view>` is the root object and the parent of everything inside it. `extends` picks what
it is built on. A `component` can extend a widget or another component, a `widget` can
extend a widget only, and a `screen` cannot extend anything.

### Styles are initialized once

So an `$api_prop` **cannot** go into a `<style>`:

```xml
<style name="style_main" border_width="$thickness"/>   <!-- invalid -->
<style name="style_main" border_width="#thickness"/>   <!-- valid, a constant -->
```

Pass the property to a *local* style property instead:
`<lv_slider style_border_width-knob="$thickness"/>`.

Prefer a named style (`<styles>`, reused via `<style name="..."/>`) over a local style
property, and prefix style names with `style_`. Selectors combine parts and states with
`|`: `selector="knob|focused"`.

### Binding is for runtime, expressions are not

`{ }` is evaluated **once at creation**. Anything that changes while the UI runs needs
data binding against a subject declared in `globals.xml`:

```xml
<lv_slider bind_value="subject_brightness"/>
<lv_label bind_text="subject_brightness" bind_text-fmt="%d %%"/>
<bind_flag_if_eq  subject="subject_mode" flag="hidden"   ref_value="0"/>
<bind_state_if_gt subject="subject_temp" state="checked" ref_value="30"/>
```

`bind_flag_*` takes a `flag`, `bind_state_*` takes a `state`. Both come in `if_eq`,
`if_not_eq`, `if_gt`, `if_ge`, `if_lt`, `if_le`. Subjects can be `int`, `string` or
`float`.

**Binding beats callbacks.** A radio group, a theme switch or a value readout needs no C
at all: write the subject with `subject_set_int_event`, read it with `bind_state_if_eq`.

### Naming and escaping

Attributes are `lower_snake_case`, compound names use `-`
(`style_bg_color-knob-pressed`). Colors accept `0xff0000` or `0xf00`. XML reserved
characters must be escaped: `value="I'm here"` is invalid, write `I&apos;m here`.

## Common mistakes

- Inventing an attribute instead of reading the schema.
- Putting `$prop` into a `<style>`. Use a local style property.
- Expecting `{ }` to update at runtime. It does not — that is data binding.
- Using `bind_state_*` with a `flag=`, or `bind_flag_*` with a `state=`.
- `screen_load_event` on a screen that is not `permanent="true"`.
- Hard-coding `pad="8"` and `bg_color="0x1E232E"` when `#space_md` and a colour
  constant already exist in `globals.xml`.
- Building a component whose only job is one styled widget. Extend instead:
  `<view extends="lv_label" style_text_font="font_h3"/>`.
- Centering with flex and forgetting `style_flex_track_place="center"`, which centers
  the tracks themselves.

## Verifying

**In the Editor.** The preview renders as you type. **Ctrl+B** exports the C and
compiles it, **F5** runs the simulator.

**With the CLI.** An npm package, not part of this project. Set `LVGLPRO_CLI_TOKEN` to a
license token — use the environment variable, never commit it.

```bash
npm install --global @lvgl/lvglpro
export LVGLPRO_CLI_TOKEN="..."

lvglpro validate   . --errorlimit 25
lvglpro generate   .
lvglpro screenshot . screens/<your_screen>.xml --out /tmp/shot.png --delay 200
lvglpro run-all-tests .
```

Node 18 or newer. Every command needs the token; without it, say the XML is unverified
rather than implying it was checked. `lvglpro <command> --help` lists the options.

Tests are XML too: a `<test>` root with a `<view>` and a `<steps>` block of `click_at`,
`wait`, `subject_set`, `subject_compare` and `screenshot_compare`.

**In the simulator.** `cmake -S sim -B build && cmake --build build --target run`.
AddressSanitizer is on where the toolchain supports it, so a memory error aborts the run
with a stack trace — that is the tool working, not a broken build. `-DENABLE_ASAN=OFF`
turns it off.

## Where to look things up

| Question | Answer |
| --- | --- |
| What can this tag accept? | `lvgl_widgets_xml/v<version>/lv_*.xml` in [lvgl/lvgl_pro](https://github.com/lvgl/lvgl_pro/tree/master/lvgl_widgets_xml) |
| What style properties and enums exist? | `lvgl_widgets_xml/v<version>/globals.xml`, same repo |
| How does feature X work? | <https://lvgl.io/docs/pro/syntax/overview> |
| What does real, good XML look like? | This project's own `components/`, then the templates, examples and tutorials in [lvgl/lvgl_pro](https://github.com/lvgl/lvgl_pro) |
| Anything about LVGL itself | The MCP server in `.mcp.json` |
