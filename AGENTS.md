# AGENTS.md

How to write LVGL Pro XML. This is the UI language of LVGL Pro: HTML-like markup that the Editor or the CLI turns into plain LVGL C code.

## Ground rules

1. **Never invent an attribute.** Every widget's exact API lives in `lvgl_widgets_xml/<version>/lv_*.xml`. Read it before writing. Style properties and enums are in `globals.xml` in the same folder.
2. **Match the project's LVGL version.** If `project.xml` declares `lvgl_version="9.5.0"` use the `v9.5.0/` schema folder.
3. **Validate what you write.** `node lved-cli.js validate <project>` gives precise errors. Then `screenshot` to see it. Guessing is not the same as knowing.
4. **Reuse before you create.** Look at the project's existing components and `globals.xml` first. A design system usually already has the button, the card, and the spacing scale you were about to reinvent.

## The three file kinds

| Root tag | What it is | Can hold |
| --- | --- | --- |
| `<component>` | Reusable UI element, pure XML, no C. The workhorse. | `animations`, `consts`, `api`, `styles`, `view`, `previews` |
| `<screen>` | A full screen. Created as-is, no parameters. | `consts`, `styles`, `view` (no `api`, no `previews`) |
| `<widget>` | A widget backed by handwritten C. Needs a C parser, cannot be loaded from XML at runtime, and needs a recompile of the preview. | `consts`, `api`, `styles`, `view`, `previews` |

One file per element, and the filename becomes the name you use as a tag. `my_button.xml` is used as `<my_button/>`.

**Write components unless you truly need C.** Widgets require a C implementation plus an XML parser; reach for one only when the behavior cannot be expressed as composition plus data binding.

## Project layout

```
my_project/
├── project.xml          ← targets and display sizes
├── globals.xml          ← shared consts, styles, fonts, images, subjects
├── translations.xml     ← optional
├── fonts/  images/
├── widgets/  components/  screens/
```

`project.xml` and `globals.xml` sit at the root. All `src_path` values are relative to that root.

## Syntax essentials

```xml
<component>
  <api>
    <prop name="title" type="string" default="Untitled"/>
    <prop name="icon" type="image" default=""/>
    <slot name="trailing"/>
  </api>

  <consts>
    <int name="gap" value="8"/>
  </consts>

  <styles>
    <style name="style_row" bg_opa="0" pad_all="#space_md"/>
  </styles>

  <view extends="lv_obj" flex_flow="row" width="100%">
    <style name="style_row"/>
    <style name="style_row_pressed" selector="pressed"/>
    <lv_label text="$title"/>
    <lv_label text="{title . ' with expression'}"/>
    <lv_obj name="trailing"/>
  </view>
</component>
```

### The three sigils

| Prefix | Means | Example |
| --- | --- | --- |
| `$name` | An `<api>` property of this element | `<lv_label text="$title"/>` |
| `#name` | A constant from `<consts>` or `globals.xml` | `pad="#space_md"` |
| `{ ... }` | An expression, evaluated once at creation | `hidden="{!icon}"` |

Inside `{ }` you write bare identifiers, no `$` or `#`.

### `view` and `extends`

`<view>` is the root object of the element and the parent of everything inside it. `extends` picks what it is built on:

```xml
<view extends="lv_button" width="100%">   <!-- the view IS a button -->
```

- `component` can extend a widget or another component
- `widget` can extend a widget only
- `screen` cannot extend anything

### Naming

Attributes are `lower_snake_case`. Compound names use `-`: `lv_chart-series`, `style_bg_color-knob-pressed`. Colors accept `0xff0000`, or the 3-digit short forms, like `0xf00`.

XML reserved characters must be escaped in values. `value="I'm here"` is invalid, write `I&apos;m here`.

### Types

`bool`, `int`, `px`, `%`, `content`, `string`, `color`, `opa`, plus the name-based types `image`, `font`, `subject`, `style` that resolve against `globals.xml`. Combine with `|`: `type="px|%|content"`.

Arrays come in four forms. Items are separated by spaces, and string items are wrapped in `'`.

| Form | Meaning | Real example |
| --- | --- | --- |
| `int[3]` | Fixed number of elements | |
| `string[NULL]` | Terminated by an element. The terminator can be any token, e.g. `grid_dsc[LV_GRID_TEMPLATE_LAST]` | `lv_buttonmatrix` `map` |
| `int[count]` | Length is passed as a separate parameter in C | `lv_chart` `values`, `lv_line` `points` |
| `string[]` | No terminator and no count | |

## Styling

Three ways, in order of preference:

```xml
<!-- 1. Named style, defined once, reused -->
<styles>
  <style name="style_card" bg_color="#color_panel" radius="#radius_default"/>
</styles>
<view>
  <style name="style_card"/>
  <style name="style_card" selector="pressed"/>
  <style name="style_card" selector="knob|focused"/>
</view>

<!-- 2. Local style property, for one-off values -->
<lv_slider style_bg_opa-indicator-pressed="200"/>

<!-- 3. Bound style, applied when a subject matches -->
<bind_style name="style_dark" subject="subject_dark_theme_on" ref_value="1"/>
```

Prefix style names with `style_`. Selectors combine parts and states with `|`.

**Styles are initialized once, so `$api_props` cannot go into a `<style>`.** This fails:

```xml
<style name="style_main" border_width="$thickness"/>   <!-- invalid -->
```
But constants can be used:

```xml
<style name="style_main" border_width="#thickness"/>   <!-- valid -->
```

Pass the property to a *local* style property instead: `<lv_slider style_border_width-knob="$thickness"/>`.

## Data binding

Subjects are the interface between the UI and the application. Define them in `globals.xml`:

```xml
<subjects>
  <int name="subject_brightness" value="50"/>
  <string name="subject_user" value="John"/>
</subjects>
```

Only `int`, `string` and `float` are supported.

```xml
<!-- Simple: attribute binding -->
<lv_slider bind_value="subject_brightness"/>
<lv_label bind_text="subject_brightness" bind_text-fmt="%d %%"/>

<!-- Conditional: child element binding -->
<bind_flag_if_eq  subject="subject_mode" flag="hidden"  ref_value="0"/>
<bind_state_if_gt subject="subject_temp" state="checked" ref_value="30"/>
```

`bind_flag_*` takes a `flag`, `bind_state_*` takes a `state`. Both come in `_eq`, `_not_eq`, `_gt`, `_ge`, `_lt`, `_le`. The `lv_obj-` prefix is optional.

States: `default`, `checked`, `focused`, `focus_key`, `edited`, `hovered`, `pressed`, `scrolled`, `disabled`.
Common flags: `hidden`, `clickable`, `checkable`, `scrollable`, `floating`, `ignore_layout`.

**Binding beats callbacks.** A radio group, a theme switch, or a value readout needs no C at all: write the subject with `subject_set_int_event`, read it with `bind_state_if_eq`.

## Events

All are children of a widget, all take `trigger` (`clicked`, `long_pressed`, `value_changed`, ...):

```xml
<event_cb callback="my_handler" trigger="clicked" user_data="ctx"/>
<screen_load_event   screen="settings" trigger="clicked" anim_type="fade_in" duration="300"/>
<screen_create_event screen="about"    trigger="long_pressed"/>
<subject_set_int_event subject="subject_lamp" value="2" trigger="clicked"/>
<subject_increment_event subject="subject_vol" step="-5" min_value="0" max_value="100"/>
<play_timeline_event timeline="timeline_load" target="self" trigger="clicked"/>
```

`screen_load_event` needs `<screen permanent="true">` on the target; `screen_create_event` needs `permanent="false"` (the default). `event_cb` assumes you implement `void my_handler(lv_event_t * e)` in C.

## Expressions

Evaluated **once at creation**, not reactive. For anything that changes at runtime, use data binding.

```xml
<lv_obj width="{columns * 100 + (columns - 1) * gap}"/>
<lv_label text="{'Room ' . room_id . ': ' . temp . ' °C'}"/>
<lv_obj hidden="{count == 0}"/>
<lv_obj style_bg_color="{is_on ? 0x00ff00 : 0x333333}"/>
```

`.` concatenates. Strings use single quotes. There is no `&&` or `||`, comparisons cannot be chained, and ternaries cannot be nested.

## Animations

```xml
<animations>
  <timeline name="timeline_load">
    <animation prop="translate_x" target="self" start="-30" end="0" duration="500"/>
    <animation prop="opa" target="label" start="0" end="255" duration="500" delay="200"/>
    <include_timeline target="icon" timeline="show_up" delay="300"/>
  </timeline>
</animations>
```

`target="self"` is the `view`; anything else is matched against a child's `name`. Play with `<play_timeline_event>`.

## Slots

Expose an internal object as a place where the caller can add children:

```xml
<!-- card.xml -->
<api><slot name="body"/></api>
<view>
  <lv_obj name="body" flex_flow="column"/>
</view>

<!-- caller -->
<card>
  <card-body>
    <lv_label text="Anything"/>
  </card-body>
</card>
```

The slot target is `<component_name-slot_name>`, and you can set normal object properties on it.

## Common mistakes

- Inventing an attribute instead of reading `lvgl_widgets_xml/`.
- Putting `$prop` into a `<style>`. Use a local style property.
- Expecting `{ }` to update at runtime. It does not, that's data binding.
- Using `bind_state_*` with a `flag=` attribute, or `bind_flag_*` with `state=`.
- `screen_load_event` on a screen that isn't `permanent="true"`.
- Hard-coding `pad="8"` and `bg_color="0x1E232E"` when `#space_md` and `#color_dark_panel` already exist in `globals.xml`.
- Building a component whose only job is one styled widget. Extend it instead: `<view extends="lv_label" style_text_font="font_h3"/>`.
- Reaching for `<widget>` and C when composition plus binding would do.
- Centering with flex and forgetting `style_flex_track_place="center"`, which centers the tracks themselves.

## Verifying

### Getting the CLI

The CLI is a self-contained Node script, `lved-cli.js`. It is not part of a UI project, so download it once and reuse it:

1. Grab the archive for your platform from the [LVGL Pro releases page](https://github.com/lvgl/lvgl_pro/releases), named `LVGL_Pro_CLI-<version>-<platform>.zip`.
2. Unzip it anywhere and run it with Node 18 or newer (CI uses 22).
3. Set `LVGL_CLI_TOKEN` to a Product or Platform license token, or pass `--token`. Prefer the environment variable so the token stays out of shell history and logs, and never commit it.

```bash
curl -L https://github.com/lvgl/lvgl_pro/releases/latest/download/LVGL_Pro_CLI-linux.zip -o cli.zip
unzip cli.zip -d lvgl-cli
export LVGL_CLI_TOKEN="..."
node lvgl-cli/lved-cli.js --help
```

Check the releases page for the exact asset name; it carries the version number.

### Running it

```bash
node lved-cli.js validate   <project> --errorlimit 25
node lved-cli.js generate   <project>
node lved-cli.js screenshot <project> screens/home.xml --out /tmp/home.png --delay 200
node lved-cli.js run-all-tests <project>
```

Every command needs the token. If it isn't set, say the XML is unverified rather than implying it was checked. `node lved-cli.js <command> --help` lists the current options for any command.

Tests are XML too, a `<test>` root with a `<view>` and a `<steps>` block of `click_at`, `wait`, `subject_set`, `subject_compare`, and `screenshot_compare`.

## Where to look things up

| Question | Answer |
| --- | --- |
| What can this tag accept? | `lvgl_widgets_xml/<version>/lv_*.xml` |
| What style properties and enums exist? | `lvgl_widgets_xml/<version>/globals.xml` |
| How does feature X work? | `docs/syntax/*.mdx` |
| What does real, good XML look like? | `templates/basic/`, `examples/lvgl_open/`, `tutorials/` |
| Anything about LVGL itself | The LVGL MCP server at `https://lvgl.mcp.kapa.ai/`, preconfigured in each project's `.mcp.json`. Prefer it over recalling LVGL APIs from memory. |
