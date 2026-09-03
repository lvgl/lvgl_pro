# Styles

Four sliders' worth of styling in one screen: reusable style sheets, per-part
selectors, local overrides, and a style that switches at runtime.

## What you'll learn

- Declaring screen-local constants in `<consts>` and referencing them with `#`
- Attaching one style sheet to several widgets
- Targeting a widget's **parts** and **states** with `selector`
- Overriding a style sheet with a local style property
- Swapping a style at runtime with `bind_style`

## Walkthrough

### 1. Constants

```xml
<consts>
	<color name="main_color" value="0x7a00ff" />
	<color name="secondary_color" value="0xfaab44" />
</consts>
```

A `<consts>` block defines values for this screen only. Reference them with a `#`
prefix: `bg_color="#main_color"`. Constants shared by several files go into the
project's `globals.xml` instead, where `#unit_small`, `#dark_blue` and friends already
live.

`<consts>` are resolved when the C is generated, so they cost nothing at runtime.

### 2. Style sheets

```xml
<styles>
	<style name="style_main" bg_color="0x333" bg_opa="30%" radius="2" />
	<style name="style_main_dark" bg_color="#main_color" />
	<style name="style_indicator" bg_color="#main_color" radius="2" />
	<style name="style_knob" bg_color="#main_color" radius="4" pad_all="6" />
</styles>
```

Each `<style>` is a standalone sheet of properties, created once and shared. Note that
the property names here have no `style_` prefix: inside a `<style>` tag you write
`bg_color`, while on a widget you write `style_bg_color`.

A style is initialized once at startup, so it cannot contain an `$api` property. If a
value has to come from a parameter, put it on the widget as a local style property.

### 3. Parts and states: `selector`

```xml
<lv_slider align="center" y="-20" value="20">
	<style name="style_main" />
	<style name="style_indicator" selector="indicator" />
	<style name="style_knob" selector="knob" />
</lv_slider>
```

An `lv_slider` is drawn from three parts: the main background, the `indicator` that
fills up to the value, and the `knob`. Without a `selector` the style lands on the main
part. With one, it lands on the named part.

States work the same way, and parts and states combine with `|`:

```xml
<style name="style_knob_pressed" selector="knob|pressed" />
```

Both sliders on the screen attach the same three sheets, so one edit in `<styles>`
changes both.

### 4. Local overrides

```xml
<lv_slider align="center" y="20" value="30" style_bg_color-indicator="#secondary_color">
	<style name="style_indicator" selector="indicator" />
	...
</lv_slider>
```

`style_bg_color-indicator` is a **local style property**: the `style_` prefix marks it
as styling, and the `-indicator` suffix is the same selector in attribute form. Local
properties are applied after style sheets, so this one wins and the second slider gets
an orange indicator while keeping everything else from `style_indicator`.

The suffix takes states too: `style_bg_color-knob-pressed="0x000"`.

### 5. A style that changes at runtime

```xml
<bind_style name="style_main_dark" subject="subject_dark_mode" ref_value="1" />
```

`bind_style` adds a style sheet while a subject holds a given value and removes it when
it no longer does. `subject_dark_mode` is declared in `globals.xml`, so this works
without a line of C.

Open the **Subjects** panel under the preview and set `subject_dark_mode` to `1` to see
both sliders turn purple.

## Try it

1. Change `main_color` to `0x00a86b`. Every style using `#main_color` follows.
2. Add `<style name="style_knob" selector="knob|pressed" />` variants and add a
   `style_knob_pressed` sheet with a bigger `pad_all`, then press a knob.
3. Give the first slider `style_radius-knob="4"` and compare with the sheet value.
4. Add a third slider that attaches only `style_main`, and see what the default
   indicator and knob look like.
5. Point `bind_style` at `ref_value="0"` and watch the logic invert.

## Common mistakes

- Writing `style_bg_color` inside a `<style>` tag. Drop the prefix there.
- Putting `$some_api_prop` into a `<style>`. Styles are initialized once, so pass the
  value as a local style property instead.
- Forgetting the `selector`, which sends the style to the main part.
- Expecting `<styles>` alone to do something. A sheet only takes effect where it is
  attached with `<style name="..."/>`.

## Next

`../layout` for arranging widgets with flex containers.

## Reference

- [Styles](https://lvgl.io/docs/pro/syntax/styles)
- [Constants](https://lvgl.io/docs/pro/syntax/constants)
- [Built-in widgets](https://lvgl.io/docs/pro/built_in_widgets) for the full list of style properties, parts and states
