# Hello World

The smallest possible LVGL Pro screen: a colored background, a button, and a label.
Start here, every other tutorial screen builds on these three ideas.

## What you'll learn

- What a `<screen>` file looks like and what its parts are
- The difference between a **named style** and a **local style property**
- How widgets nest to become children of each other
- How to use a font defined in `globals.xml`

## Walkthrough

### 1. The screen root

```xml
<screen>
	<styles> ... </styles>
	<view> ... </view>
</screen>
```

A `<screen>` is a full-display UI created as-is: it takes no parameters and cannot
`extend` anything. It may hold `<consts>`, `<styles>` and exactly one `<view>`.

`<view>` **is** the screen object itself, not a container inside it. Everything you put
inside `<view>` becomes a child of the screen.

### 2. A named style

```xml
<styles>
	<style name="style_main" bg_color="0x00688a" />
</styles>
```

`<styles>` declares reusable style sheets. Nothing is applied yet: a style only takes
effect where it is attached:

```xml
<view>
	<style name="style_main" />
	...
</view>
```

Here it paints the screen background teal. The same `style_main` could be attached to
any number of widgets; change the color once and every user updates. Prefix style names
with `style_` and put styles shared across screens in the project's `globals.xml`.

### 3. Widgets and nesting

```xml
<lv_button align="center" style_bg_color="0x111">
	<lv_label text="Hello world" style_text_font="montserrat_16_bin_file" />
</lv_button>
```

- `lv_button` is a built-in widget. `align="center"` centers it inside its parent (the
  screen).
- The `lv_label` is written *inside* the button, so it is the button's child and is
  centered in it automatically.
- `style_bg_color="0x111"` is a **local style property**: a one-off style applied
  directly to this widget, no `<styles>` entry needed. A named style suits a value that
  is shared, a local property a value that is used once.
- `montserrat_16_bin_file` is a font declared in `globals.xml`. Widgets refer to assets
  by the name given there, never by file path.

### 4. Where the C comes from

XML is converted to C by pressing **Ctrl+B** (or the hammer icon), which writes
`screen_hello_world_gen.c` and recompiles the preview. **F5** runs it in the simulator. Open the generated file once
out of curiosity: it is plain, readable `lv_obj_create()` / `lv_label_set_text()` code,
ready to drop into firmware.

## Try it

1. Change `bg_color="0x00688a"` to `0x7a00ff` and watch the preview update as you type.
2. Give the button a size: `width="200" height="60"`. Notice the label stays centered.
3. Move the button with `align="top_left" x="20" y="20"`.
4. Add a second label under the button and align it with `align="bottom_mid" y="-20"`.
5. Swap the font for `montserrat_14_c_array` (also in `globals.xml`) and compare.
6. Replace the local `style_bg_color="0x111"` with a second named style in `<styles>`.

## Common mistakes

- Treating `<view>` as a container *inside* the screen. It is the screen.
- Declaring a style in `<styles>` and forgetting to attach it with `<style name="..."/>`.
- Editing `*_gen.c`, which the next export overwrites.

## Next

`../styles` for reusable style sheets, per-part selectors and `bind_style`.

## Reference

- [Screens](https://lvgl.io/docs/pro/syntax/screens)
- [Styles](https://lvgl.io/docs/pro/syntax/styles)
- [Built-in widgets](https://lvgl.io/docs/pro/built_in_widgets) for the full XML API of `lv_button`, `lv_label`, and the rest
