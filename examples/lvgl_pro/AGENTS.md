# AGENTS.md

How to work in this LVGL Pro project. The UI is written in LVGL Pro XML: HTML-like markup that the Editor or the CLI turns into plain LVGL C code. You do not hand-write the C.

## Ground rules

1. **Never invent an attribute.** Each widget's exact API is in a schema file, and the schemas are not part of this project. Read the one you need before writing: `lv_slider` is at `https://raw.githubusercontent.com/lvgl/lvgl_pro/master/lvgl_widgets_xml/v<version>/lv_slider.xml`. Style properties and enums are in `globals.xml` in the same folder. [Built-in widgets](https://lvgl.io/docs/pro/built_in_widgets) has the same API as readable pages.
2. **Match this project's LVGL version.** Read `lvgl_version` in `project.xml` and use that schema folder: `lvgl_version="9.6.0"` is the folder `v9.6.0`. Reading a subject in `{ }` needs LVGL v9.6 and Editor v2.1. Below that, an expression is computed only once, so use the [legacy elements](#legacy-elements) instead.
3. **Validate what you write.** `lvglpro validate .` gives precise errors. Then `screenshot` to see it. Guessing is not the same as knowing. See [Verifying](#verifying).
4. **Reuse before you create.** Read this project's `globals.xml` and `components/` first. The constant, the style and the button you were about to invent are often already there.
5. **Read how a feature works before you use it.** The [XML syntax docs](https://lvgl.io/docs/pro/syntax/overview) explain each feature on its own page. For the shape of real, working XML, read this project's own files, then the templates, examples and tutorials in [lvgl/lvgl_pro](https://github.com/lvgl/lvgl_pro).
6. **Ask the LVGL MCP server about LVGL itself.** `.mcp.json` in this folder connects it at `https://lvgl.mcp.kapa.ai/`. Prefer it over recalling LVGL APIs from memory.

## Project layout

```
project.xml          ← the LVGL version, the targets and the display sizes
globals.xml          ← shared consts, styles, fonts, images, subjects
translations.xml     ← optional, the same string in several languages
fonts/               ← TTF files, and the generated bin or C files
images/              ← PNG images, plus the SVG or JPEG sources of `<convert>`, and the generated image files
components/          ← Reusable UI element, pure XML, no C. Can have `<animations>`, `<consts>`, `<api>`, `<subjects>`, `<styles>`, `<view>`, `<previews>`
widgets/             ← A widget backed by handwritten C. Needs a C parser, cannot be loaded from XML at runtime, and needs a recompile of the preview. Can have `<consts>`, `<api>`, `<styles>`, `<view>`, `<previews>`
screens/             ← A full screen created from components and widgets. Can have `<animations>`, `<consts>`, `<subjects>`, `<styles>`, `<view>` (no `<api>`, no `<previews>`)
tests/               ← optional, XML tests
sim/                 ← the PC simulator, nothing in it ships in the firmware
```

`project.xml` and `globals.xml` sit at the root. All `src_path` values are relative to that root.

For components, widgets and screens: One file per element, and the filename becomes the name you use as a tag. `my_button.xml` is used as `<my_button/>`.

**Write components unless you truly need C.** Widgets require a C implementation plus an XML parser; reach for one only when the behavior cannot be expressed as composition plus data binding.


## Example

```xml
<component>
  <api>
    <prop name="title" type="string" default="Untitled"/>
    <prop name="icon" type="image" default=""/>
    <prop name="value" type="int" bindable="true"/>
    <slot name="trailing"/>
    <variants>
      <variant name="size" options="small large" default="small"/>
    </variants>
  </api>

  <consts>
    <int name="gap" value="8"/>
    <int name="limit" value="20"/>
  </consts>

  <styles>
    <style name="style_row" bg_opa="0" pad_all="{space_md}"/>
    <style name="style_row_pressed" bg_opa="50%"/>
    <style name="style_danger" bg_color="0xd33"/>
    <style name="style_large" pad_all="{space_md * 2}"/>
  </styles>

  <view extends="lv_obj" flex_flow="row" width="100%">
    <style name="style_row"/>
    <style name="style_row_pressed" selector="pressed"/>
    <style name="style_danger" enabled="{value > limit}"/>
    <style name="style_large" enabled="{size == large}"/>

    <lv_label text="Just a text"/>
    <lv_label text="{title}"/>
    <lv_label text="{title . ', the value as data binding: ' . value}"/>
    <lv_obj name="trailing" hidden="{size == small}"/>
  </view>
</component>
```

## Syntax summary

### Naming

Attributes are `lower_snake_case`. Compound names use `-`: `lv_chart-series`, `style_bg_color-knob-pressed`.

Colors are `0xff0000`, or the 3-digit short form `0xf00`. **Never `#ff0000`.** A value that starts with `#` is read as a legacy constant name, and when there is no such constant the attribute is silently dropped.

XML reserved characters must be escaped in values: `<` as `&lt;` and `&` as `&amp;`. A `'` needs `&apos;` only inside a value wrapped in `'...'`, so `value="I'm here"` is fine.

### `view` and `extends`

`<view>` is the root object of the element and the parent of everything inside it. `extends` picks what it is built on:

```xml
<view extends="lv_button" width="100%">   <!-- the view IS a button -->
```

- `component` can extend a widget or another component
- `widget` can extend a widget only
- `screen` cannot extend anything


### Types

- `bool`: `true` or `false`
- `int`: the range of an `int32_t`
- `px`: a size in pixels
- `%`: a percent of the parent, `lv_pct(x)` in C
- `content`: only for width and height, to make the size fit all the children
- `string`: normal string, in expressions as `{'hello' . ' world'}`
- `color`: `0xRRGGBB`, or `0xRGB`
- `opa`: 0-255 or 0-100%
- the name-based types `image`, `font`, `subject`, `style`, which resolve against `globals.xml` or the local items
- `enum:<name>`, e.g. `enum:lv_flex_flow`. The options are in the schema folder's `globals.xml`

Combine types with `|`, as `type="px|%|content"`.

A `<prop>` without a `default` is mandatory: every instance has to set it.

Constants in `<consts>` use one tag per type: `<int>`, `<color>`, `<px>`, `<percentage>`, `<string>`, `<opa>` and `<bool>`.

Arrays come in four forms. Items are separated by spaces, and string items are wrapped in `'`. They are not used in components, only in widgets where C code can consume them.
- `int[3]`: Fixed number of elements
- `string[NULL]`: Terminated by an element. The terminator can be any token, e.g. `grid_dsc[LV_GRID_TEMPLATE_LAST]`
- `int[count]`: Length is passed as a separate parameter in C
- `string[]`: No terminator and no count

### Expressions

Expressions are wrapped into `"{ ... }"`. If only constants, literals, or plain component properties are used in it, it is evaluated only once, at creation time. If global or local subjects, variants, or bindable properties are also used, a binding is created that updates the value whenever any of them changes.

`.` concatenates, strings use single quotes, and the result always reaches the attribute as text, so `<lv_label text="{count}"/>` shows `42`. Comparisons cannot be chained (`a < b < c`), a ternary is nested only inside `( )`, `( )` cannot contain a `.` concatenation, and there is no short-circuiting: both sides of an `AND` or `OR` are always evaluated. `&` and `<` must be escaped in an attribute value, so prefer the keywords `AND`, `OR`, `EQ`, `NE`, `LT`, `LE`, `GT`, `GE`: `hidden="{a GT 10 AND a LE 30}"`. They are uppercase only; lowercase `and` is an ordinary name.

Expressions work almost everywhere:

| Where | Example | Note |
|---|---|---|
| Widget property | `<lv_label hidden="{count == 0}"/>` | |
| Component property | `<my_card title="{'Hi ' . name}"/>` | Make the property [bindable](https://lvgl.io/docs/pro/syntax/api#bindable-properties) to let it follow a subject |
| Local style property | `<lv_button style_bg_color="{dark ? 0x000 : 0xfff}"/>` | |
| Style `enabled` | `<style name="style_error" enabled="{subject_error_cnt != 0}"/>` | See [Conditional styles](https://lvgl.io/docs/pro/syntax/styles#conditional-styles) |
| Event trigger | `<play_timeline_event trigger="{subject_error_cnt == 0}" target="self" timeline="timeline_show_up"/>` | See [Triggers](https://lvgl.io/docs/pro/syntax/events#triggers) |
| Constant value | `<int name="size_large" value="{base_size * 4}"/>` | Only literals and other constants |
| Subject value | `<int name="subject_room_temp" value="{const_default_temp}"/>` | Only literals and constants |
| Style property value | `<style name="style_main" radius="{base_unit * 2}"/>` | Only literals and constants |

The last three are read once, when the file is registered, before any instance exists. A property, subject or variant has no value at that point, so only literals and constants can be used there.

Widget specific bindings are usually two way bindings. E.g. `<lv_slider bind_value="subject_1"/>` updates the subject when the slider is dragged, and moves the slider when the subject is written.

There is no syntax to read a property of another UI element. E.g. this is not supported: `<lv_slider width="slider2.width"/>`. Use styles, layouts, and constants to describe these.

A `name="..."` is the only attribute that never binds: a literal or a `{ }` the Editor can resolve at build time.

Before LVGL Pro v2.1 and LVGL v9.6: `$name` was used to pass an API property to a UI element. E.g. `<lv_label text="$title"/>`. Similarly `#name` was used for constants. E.g. `pad="#space_md"`. These didn't support expressions, so `"{...}"` is preferred.


### Global and Local subjects

Subjects are the interface between the UI and the application. Define them in `globals.xml` (global subjects) or inside a `<component>` or `<screen>` (per-instance local subjects):

```xml
<subjects>
  <int name="subject_brightness" value="50" min_value="0" max_value="100"/>
  <string name="subject_user" value="John"/>
</subjects>
```

The types are `int`, `float`, `string`, `color` and `pointer` (which holds a name of an image or font). `int` and `float` take `min_value`/`max_value`, and every write is clamped to them. A `float` subject needs `LV_USE_FLOAT` in `lv_conf.h`, or the generated code does not compile.

A local subject is private to the instance, always starts at its declared value, and shadows a global of the same name. To let the caller pick which subject an instance follows, take it as a property: `<prop name="temp" type="subject"/>`, used as `<room_card temp="subject_kitchen"/>`.

In C a global subject is exported as `extern lv_subject_t * subject_brightness;`, so the application writes it with `lv_subject_set_int(subject_brightness, 80)`. **Binding beats callbacks.** A radio group, a theme switch, or a value readout needs no C at all: write the subject with `<set_subject_event>`, read it with an expression.

### Styling

Styles can be added to parts (`main`, `indicator`, `scrollbar`, etc) and states (e.g.: `default`, `checked`, `pressed`, `scrolled`, `disabled`, etc.) of the UI elements.

Style sheets and local styles can be used:

```xml
<!-- Named style, defined once in <globals>, <screen>, <component>, <widget>, and reused.
     In {} only constants and literals can be used, as styles are initialized only once. -->
<styles>
  <style name="style_base" bg_color="0xeee" radius="{size_sm * 2}">
       <!-- Animate when going into this state. A transition on the default style is used for
            every state change, so add one to another state only if it needs to differ.
            One transition per style, add more styles to animate different props differently -->
       <transition props="bg_color bg_opa" duration="200" delay="100" easing="ease_in_out"/>
  </style>
  <style name="style_pressed" bg_color="0xaaa" bg_opa="40%"/>
  <style name="style_scrollbar_pressed" bg_color="{primary_color}"/>
  <style name="style_warning" bg_color="{color_yellow}"/>
</styles>

<view>
  <!-- Selectors combine parts and states with `|` -->
  <style name="style_base"/>
  <style name="style_pressed" selector="pressed"/>
  <style name="style_scrollbar_pressed" selector="scrollbar|pressed"/>

  <!-- `enabled` switches a style on and off from a condition, as a binding -->
  <style name="style_warning" enabled="{subject_temp GT 10 AND subject_temp LE 30}"/>
</view>

<!-- Local style property, for one-off values -->
<lv_slider style_bg_opa-indicator-pressed="80%"/>
<lv_label style_text_color-pressed="{subject_error ? 0xf00 : 0xaaa}"/>
<my_button style_bg_color="{prop_color}"/>
```

Switching a style on and off with `enabled` is not a state change, so it never animates. Use one `enabled` per style and selector: with two, the last one wins.

The legacy syntax for `<style enabled="{}">` is `<bind_style name="style_1" subject="subject_1" ref_value="10"/>`, meaning enable the style when `subject_1 == 10`.


### Variants

A component's named visual states, declared in `<api>`. Per-instance and reactive, so they are the component-scoped counterpart of global subjects. A variant is a local subject under the hood, so it can be used in data bindings.

```xml
<api>
  <variants>
    <variant name="size" options="small large" default="small"/>
    <variant name="tone" options="normal danger" default="normal"/>
  </variants>
</api>

<view extends="lv_button">
  <style name="style_normal"/>
  <style name="style_danger" enabled="{tone == danger}"/>
  <style name="style_large"  enabled="{size == large}"/>
  <lv_label text="Subtitle" hidden="{size == small}"/>
</view>
```

On the instance:
```xml
<my_badge size="large" tone="{subject_level > 100 ? danger : normal}"/>
```

Two variants may share an option name. A variant can only be compared with `==`/`!=`/`EQ`/`NE` (either order) to something that evaluates to one of its own option names, e.g. `size == large` or `size == (x GT 9 ? large : small)`; the name is looked up in that variant. Any other use of a variant (arithmetic, `<`/`>`, `!`, as a value) is an error, and a bare option name elsewhere is just a word. From C a variant is set with the generated `my_badge_set_size(obj, MY_BADGE_SIZE_LARGE)`, and reordering `options` breaks already exported C.

### Slots

Expose an internal UI element so that children can be added to it on an instance:

```xml
<!-- card.xml -->
<component>
  <api>
    <slot name="body"/>
  </api>

  <view flex_flow="column">
    <lv_label text="Title"/>
    <lv_obj name="body" flex_flow="column"/>
  </view>
</component>

<!-- caller -->
<card>
  <card-body style_bg_color="0xf00">
    <lv_label text="Anything"/>
  </card-body>
</card>
```

The slot tag is `<component_name-slot_name>`, and normal widget properties can be set on it.

### Previews

A `<previews>` block lets the Editor show a component or widget on its own, in the sizes and on the backgrounds it is used with. Previews are not exported to C and not loaded at runtime. A screen has no previews: it uses the displays in `project.xml`.

```xml
<previews>
  <preview name="small_dark" width="240" height="240" style_bg_color="0x333" style_pad_all="32"/>
  <preview name="large_light" width="800" height="480" style_bg_color="0xeeeeee"/>
</previews>
```

### Animations

```xml
<animations>
  <timeline name="timeline_load">
    <animation prop="translate_x" target="self" start="-30" end="0" duration="500" easing="ease_out"/>
    <animation prop="opa" target="label" start="0" end="255" duration="500" delay="200"/>

    <!-- Add the `show_up` timeline of `icon` here -->
    <include_timeline target="icon" timeline="show_up" delay="300"/>
  </timeline>
</animations>
```

`target="self"` is the `view`; anything else is matched against a child's `name`. Play with `<play_timeline_event>`.

An `<animation>` needs `prop`, `target`, `start` and `end`. `duration` defaults to 1000 ms. `selector` picks the part and state to animate, like on a style. Only the style properties LVGL can interpolate work: the numeric ones, `opa`, and colors. Enums, bools, fonts and image sources cannot be animated.

`easing` (on `<animation>` and `<transition>`) is `linear` (default), `ease_in`, `ease_out`, `ease_in_out`, `overshoot`, `bounce`, `step`, `bezier(x1 y1 x2 y2)` with `x` in `0..1`, or a callback registered with `lv_xml_register_easing_cb()`.

Play an animation with `<play_timeline_event target="self" timeline="timeline_load" trigger="clicked"/>`. That plays the `timeline_load` timeline of `self` (the view) on click. `target` can also be the name of a child, but then the timeline has to be defined by that child. `reverse="true/false"` and `delay="some_ms"` are optional. See more below.

### Events

Events are children of a widget. All take `trigger`, which can be

1. An event name. E.g. `clicked`, `value_changed`, `long_pressed`. The full list is in the schema folder's `globals.xml`, in the `lv_event` enum. Without a `trigger` the event is `clicked`
2. Or an expression. The action runs on every false-to-true change, and right away if it is already true at creation. With no subject in it the expression is evaluated once: true runs the action immediately, false attaches nothing, and any other result is used as an event name, e.g. `trigger="{compact ? long_pressed : clicked}"`

```xml
<!-- call a callback -->
<event_cb callback="my_handler" trigger="clicked" user_data="some_string"/>

<!-- load a <screen permanent="true"> -->
<screen_load_event   screen="settings" trigger="clicked" anim_type="fade_in" duration="300"/>

<!-- create a <screen permanent="false"> -->
<screen_create_event screen="about"    trigger="long_pressed"/>

<!-- set subject, on click as there is no trigger -->
<set_subject_event subject="subject_lamp" value="2"/>

<!-- toggle subject -->
<set_subject_event subject="subject_open" value="{!subject_open}"/>

<!-- decrement subject -->
<set_subject_event subject="subject_vol"  value="{subject_vol - 5}"/>

<!-- timeline play on click -->
<play_timeline_event timeline="timeline_load" target="self" trigger="clicked"/>

<!-- trigger is a data binding, plays when it gets true -->
<play_timeline_event timeline="timeline_load" target="self" trigger="{subject_error_cnt > 10}"/>

<!-- play backwards when it gets false -->
<play_timeline_event timeline="timeline_load" target="self" trigger="{subject_error_cnt &lt;= 10}" reverse="true"/>

<!-- always start on creation -->
<play_timeline_event timeline="timeline_infinite" target="self" trigger="{true}"/>
```

`permanent` on a `<screen>` defaults to `false`. A permanent screen is created once at startup and loaded with `screen_load_event`. Any other screen is created with `screen_create_event`, and deleted when another screen replaces it.

`set_subject_event`'s `value` is re-evaluated on every fire when it is written as `{ }`, and the subject's own `min_value`/`max_value` clamp the result. A bare literal is written as it is, every time.

`event_cb` assumes you implement `void my_handler(lv_event_t * e)` in C. With an expression trigger there is no real LVGL event behind the call, so don't read the event code in it.

### Images

Images are external resources: register them in the `<images>` block of `globals.xml`, then use the name. `<data>` is compiled into the firmware as a C array, `<file>` is loaded from a file system at runtime. Both point at a **PNG**.

```xml
<images>
  <!-- Make a PNG from an SVG or a JPEG, and scale it. Runs before <data> and <file>,
       so `dest` doesn't have to exist yet. `width`, `height` or `scale`, and a
       missing axis keeps the aspect ratio -->
  <convert src="images/icons/home.svg" dest="images/icons/home.png" width="24"/>

  <data name="icon_home" src_path="images/icons/home.png" color_format="argb8888"/>
  <data name="logo"      src_path="images/logo.png"       color_format="rgb565"/>
  <file name="avatar"    src_path="images/avatar1.png"/>
</images>
```

```xml
<lv_image src="icon_home"/>
<lv_obj style_bg_image_src="logo"/>
```

All the usual color formats work: `i1`-`i8`, `a1`-`a8`, `rgb565`, `rgb565a8`, `rgb888`, `argb8888`. Every `src_path` is relative to the project root.

### Fonts

Fonts are registered in the `<fonts>` block of `globals.xml`, from TTF files. Three engines: `<bin>` renders the glyphs to bitmaps in one size, `<tiny_ttf>` renders from the TTF at runtime and works on MCUs too, `<freetype>` does the same for MPUs. `as_file="false"` compiles the font into the firmware, `as_file="true"` loads it from a file.

```xml
<fonts>
  <bin name="font_body" src_path="fonts/Montserrat-Regular.ttf" size="16" bpp="4"
       range="0x20-0x7F" symbols="°" as_file="false"/>
  <tiny_ttf name="font_cjk" src_path="fonts/NotoSansSC.ttf" size="24" as_file="false"/>
</fonts>
```

```xml
<styles>
  <style name="style_title" text_font="font_body"/>
</styles>

<view>
  <lv_label text="Title" style_text_font="font_body"/>
</view>
```

A `<bin>` font takes `range` and `symbols` to pick the glyphs to include, and `fallback="<other_font>"` to look up the ones it does not have in another font.

### Translations

Translated strings live in `translations.xml`. `languages` lists the language codes, and each `<translation>` has a `tag` that the UI refers to:

```xml
<translations languages="en de hu">
  <translation tag="dog" en="The dog" de="Der Hund" hu="A kutya"/>
  <translation tag="cat" en="The cat" de="Die Katze" hu="A cica"/>
</translations>
```

```xml
<lv_label translation_tag="dog"/>
```

`translation_tag` is a property of `lv_label`, and setting it makes the label follow the active language. Missing translations fall back, as described in [LVGL's translation module](https://lvgl.io/docs/open/main-modules/translation). The application picks the language with `lv_translation_set_language("de")`.

For Chinese, Japanese or Korean prefer a `<tiny_ttf>` font, which loads any glyph on demand from one TTF. With `<bin>` fonts, chain one font per language with `fallback`.

### Targets

`<targets>` in `project.xml` describes the hardware the UI is built for, and `if_target` then includes or excludes a block for the named targets. Use it to ship different assets, styles or views per display size, instead of writing a second project.

```xml
<!-- project.xml -->
<project name="my_ui" lvgl_version="9.6.0">
  <targets>
    <target name="large">
      <display width="800" height="480"/>
    </target>
    <target name="small">
      <display width="480" height="320"/>
    </target>
  </targets>
</project>
```

```xml
<!-- globals.xml: the large icons only on the large display.
     The specific block first, the one without `if_target` last -->
<consts if_target="large">
  <int name="icon_size" value="24"/>
</consts>

<consts>
  <int name="icon_size" value="16"/>
</consts>

<images if_target="large">
  <data name="logo" src_path="images/logo_large.png" color_format="rgb565"/>
</images>

<images>
  <data name="logo" src_path="images/logo_normal.png" color_format="rgb565"/>
</images>
```

`if_target` works on `<images>`, `<fonts>`, `<styles>`, `<consts>` and, most importantly, `<view>`. Name several targets as `if_target="large|medium"`.

**The first matching block wins, and a block with no `if_target` matches every target.** So the unconditional block has to come last. Put it anywhere earlier and it captures every target, and the specific blocks after it are never reached. Read [Targets](https://lvgl.io/docs/pro/syntax/targets) before using it on a view.

### Legacy elements

Still supported, and common in older projects. Prefer the current form in new XML:

| Legacy | Current |
| --- | --- |
| `$prop`, `#const` | `{prop}`, `{const}` |
| `<bind_style name="s" subject="x" ref_value="1"/>` | `<style name="s" enabled="{x == 1}"/>` |
| `<bind_style_prop prop="bg_color" subject="x" .../>` | an expression on a local style property |
| `<bind_flag_if_eq subject="x" flag="hidden" ref_value="0"/>` | `hidden="{x == 0}"` |
| `<bind_state_if_gt subject="x" state="checked" ref_value="30"/>` | `checked="{x > 30}"` |
| `<subject_set_int_event>`, `<subject_toggle_event>`, `<subject_increment_event>` | `<set_subject_event value="{...}"/>` |

`bind_flag_*` takes a `flag`, `bind_state_*` takes a `state`, and both come in `if_eq`, `if_not_eq`, `if_gt`, `if_ge`, `if_lt`, `if_le`. The old subject events take an event name in `trigger`, never a condition, and `<subject_increment_event>` is the only one with `rollover`.

## Verifying

### In the Editor

The preview updates as you type. **Ctrl+E** exports the C code, **Ctrl+B** exports and recompiles it, and **F5** builds and starts the simulator in VS Code.

### With the CLI

The CLI is an npm package, not part of this project. Install it once, globally:

```bash
npm install --global @lvgl/lvglpro
```

This puts `lvglpro` on your `PATH`. Node 18 or newer is required.

The CLI needs a Professional license: it does not work with the Community and Evaluation licenses. Set `LVGLPRO_CLI_TOKEN` to the license token, or pass `--token`. Prefer the environment variable so the token stays out of shell history and logs, and never commit it.

```bash
export LVGLPRO_CLI_TOKEN="..."

lvglpro validate   . --errorlimit 25
lvglpro generate   .
lvglpro compile    .
lvglpro screenshot . screens/<your_screen>.xml --out /tmp/shot.png --delay 200
lvglpro run-all-tests .
```

Every command needs the token. If it isn't set, say the XML is unverified rather than implying it was checked. `lvglpro <command> --help` lists the current options for any command.

`run-all-tests` and `run-test` compile the project themselves, but they build the exported C, so run `generate` after every XML change and before the tests.

### In the simulator

`sim/` builds this project into a desktop program with SDL. Run it from the project root, so the `A:` asset paths resolve:

```bash
cmake -S sim -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j
cmake --build build --target run
```

To show another screen, edit the `lv_screen_load(...)` line in `sim/main.c`. AddressSanitizer is on where the toolchain supports it, so a memory error stops the program with a stack trace. That is the tool working, not a broken build. `-DENABLE_ASAN=OFF` turns it off.

### Tests

Tests are XML too: a `<test>` root, with the same `<consts>`, `<styles>` and `<view>` as a component, plus a `<steps>` block. Keep them in `tests/`.

A test's `<view>` is built exactly like a component's, so the usual test extends a real screen of the project and drives the actual UI:

```xml
<test>
  <view extends="screen_main"/>

  <steps>
    <!-- Pin every subject the assertions depend on, instead of inheriting
         whatever globals.xml defaults to today -->
    <subject_set subject="subject_theme_dark" value="0"/>
    <wait ms="50"/>
    <screenshot_compare path="theme_light.png"/>

    <click_at x="436" y="30"/>
    <wait ms="100"/>
    <subject_compare subject="subject_theme_dark" value="1"/>
    <screenshot_compare path="theme_dark.png"/>
  </steps>
</test>
```

A `<view>` of its own works too, and is the right choice to exercise one component without depending on where it sits on a screen:

```xml
<test width="480" height="320">
  <view width="100%" height="100%" flex_flow="column" style_pad_all="20">
    <slider subject="subject_brightness" width="200"/>
  </view>

  <steps>
    <subject_set subject="subject_brightness" value="0"/>
    <wait ms="50"/>
    <move_to x="40" y="24"/>
    <wait ms="30"/>
    <press/>
    <wait ms="30"/>
    <move_to x="260" y="24"/>
    <wait ms="30"/>
    <release/>
    <subject_compare subject="subject_brightness" value="100"/>
  </steps>
</test>
```

Give every pointer step a few ms of its own. `move_to` only updates the input position, and LVGL needs a tick to read it, so a press in the same instant registers at the previous position and the drag silently does nothing.

The steps are `click_at` (`x`, `y`), `click_on` (`name` of a widget), `move_to` (`x`, `y`), `press`, `release`, `wait` (`ms`, LVGL keeps running), `freeze` (`ms`, LVGL's time stops), `subject_set`, `subject_compare`, `set_language` (`name` of the language) and `screenshot_compare` (`path`). `subject_set` and `subject_compare` work on `int` and `string` subjects only. A missing reference screenshot is created on the first run, and a failed one is saved next to it with an `_err` suffix, so look at that image before changing the test.

```bash
lvglpro generate .
lvglpro run-all-tests .
lvglpro run-test . tests/my_test.xml
```

## AI Workflow

The loop, per change:

1. **Look it up.** The tag's schema, this project's `globals.xml` and `components/`, then the syntax docs for the feature. LVGL questions go to the MCP server.
2. **Write the XML.** Small steps, one file at a time.
3. **`lvglpro validate .`** Fix every error, then re-run. The errors name the file, the line and the attribute.
4. **`lvglpro screenshot`, then look at the image.** Validation says the XML is legal, not that the UI is right. Check the sizes, the alignment, and that nothing is missing or clipped.
5. **`lvglpro generate .` and `lvglpro compile .`** every few iterations, to catch what only shows up in the C.
6. **`lvglpro generate .`, then `lvglpro run-all-tests .`** if the project has tests, and add a test for what you changed.
7. **Report what you could not check.** Without a token nothing was verified, so say so.

Where to look things up:

| Question | Where |
| --- | --- |
| What can this tag accept? | `lvgl_widgets_xml/v<version>/lv_*.xml` in [lvgl/lvgl_pro](https://github.com/lvgl/lvgl_pro/tree/master/lvgl_widgets_xml), or [Built-in widgets](https://lvgl.io/docs/pro/built_in_widgets) |
| What style properties and enums exist, including the event names? | `lvgl_widgets_xml/v<version>/globals.xml`, same repo |
| How does feature X work? | [XML syntax](https://lvgl.io/docs/pro/syntax/overview), one page per topic |
| All CLI commands and options | [CLI](https://lvgl.io/docs/pro/cli) |
| What does real, good XML look like? | This project's own files, then in [lvgl/lvgl_pro](https://github.com/lvgl/lvgl_pro): `examples/lvgl_open/` (130+ small example screens), `tutorials/` (one screen per concept), `templates/basic/` (a small design system with reusable components) |
| Anything about LVGL itself | The MCP server in `.mcp.json` |

## Authoring tips

What good XML looks like:

- **Start from `globals.xml`.** Use the constants, styles and fonts that are already there. A raw `8` or `0x1E232E` in a view is almost always a token that exists.
- **One idea per file, and keep it small.** If a component does two things, or its `<view>` nests more than about three levels deep, split it. A repeated block of markup is a component waiting to be written.
- **Extend instead of wrapping.** If the component is one styled widget, write `<view extends="lv_label" style_text_font="font_h3"/>` rather than a container with one child in it.
- **Named styles for anything reused, local style properties for one-offs.** A local style property is right for a single value on a single widget, not for the look of a component.
- **Lay out with flex or grid.** `width="100%"`, `height="content"` and `flex_grow` survive a font change and a different display size; hard-coded `x`/`y` do not.
- **Give every `<prop>` a `help` and a sensible `default`.** The Editor and the next reader both use them.
- **Bind, don't call back.** Reach for `<event_cb>` only when C really has to run.
- **Name only what is referenced.** A `name="..."` is for animation targets, slots, `click_on` in a test, and C lookups. Naming everything is noise.
- **Add a `<previews>` block** to a component so the Editor can show it on its own, in the sizes it is used at.
- **Read the diff of your own XML** before handing it over, the same way you would read C.

Naming:

| What | How | Example |
| --- | --- | --- |
| File, and so the tag | `lower_snake_case.xml` | `list_item.xml` used as `<list_item/>` |
| Style | `style_` prefix, state last | `style_card`, `style_card_pressed` |
| Subject | `subject_` prefix | `subject_brightness` |
| Timeline | `timeline_` prefix | `timeline_load` |
| Constant | what it means, not what it is worth | `space_md`, `color_dark_panel`, `radius_default` |
| Property, variant, slot | what it is, from the caller's side | `title`, `size`, `body` |

## Common mistakes

- Inventing an attribute instead of reading the schema.
- Writing a color as `#ff0000`. It is read as a constant name and silently dropped; write `0xff0000`.
- Putting a `prop` or a subject into a `<style>`. Styles are initialized once, before any instance exists. Use a local style property instead.
- Expecting a `{ }` to update at runtime when it reads no subject, variant, or bindable property.
- Expecting a plain prop inside a binding to update. It is snapshotted at creation, so add `bindable="true"` if it has to change.
- Writing `set_subject_event`'s `value` without braces when it has to be re-evaluated on every fire.
- `screen_load_event` on a screen that isn't `permanent="true"`.
- Hard-coding `pad="8"` and `bg_color="0x1E232E"` when `{space_md}` and `{color_dark_panel}` already exist in `globals.xml`.
- Creating a `<widget>` and C when a component with expressions would do the job.
- Centering with flex and forgetting `style_flex_track_place="center"`, which centers the tracks themselves.
