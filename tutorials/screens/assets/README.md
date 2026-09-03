# Assets

Four labels in four differently built fonts and the same PNG loaded two different ways.
The interesting part of this tutorial is in `globals.xml`, not in the screen.

## What you'll learn

- Declaring fonts and images in `globals.xml` and referring to them by name
- The four ways to get a font into a build, and what each costs
- Limiting a font to the characters you need with `range` and `symbols`
- C array assets vs runtime files
- What `memory="int_flash"` is for

## Walkthrough

### 1. The screen only uses names

```xml
<lv_label text="I'm from a C array: °" style_text_font="montserrat_14_c_array" />
<lv_label text="I'm TinyTTF from data: Schöne" style_text_font="montserrat_18_tiny_ttf_data" />

<lv_image src="flower_data" />
<lv_image src="flower_file" />
```

No paths, no file extensions. Every asset is declared once in `globals.xml` with a
`name`, and the UI refers to that name. Change how an asset is built and no screen has
to be touched.

### 2. Fonts, four ways

```xml
<fonts memory="int_flash">
	<bin name="montserrat_14_c_array" as_file="false" bpp="2"
	     src_path="fonts/Montserrat_Medium.ttf" size="14" range="0x20-0x7f" symbols="°äü" />

	<bin name="montserrat_16_bin_file" as_file="true" bpp="2"
	     src_path="fonts/Montserrat_Medium.ttf" size="16" range="0x20-0x7f" symbols="°" />

	<tiny_ttf name="montserrat_18_tiny_ttf_data" as_file="false" size="18"
	          src_path="fonts/Montserrat_Medium.ttf" />

	<tiny_ttf name="montserrat_20_tiny_ttf_file" as_file="true" size="20"
	          src_path="fonts/Montserrat_Medium.ttf" />
</fonts>
```

| Tag | `as_file` | What is produced | Rendering |
| --- | --- | --- | --- |
| `<bin>` | `false` | the glyph bitmaps as a C array, linked into the binary | pre-rendered, fastest |
| `<bin>` | `true` | a `.bin` file loaded at runtime | pre-rendered, needs a filesystem |
| `<tiny_ttf>` | `false` | the raw TTF bytes as a C array | rendered on demand by TinyTTF |
| `<tiny_ttf>` | `true` | the TTF loaded from the filesystem | rendered on demand by TinyTTF |

The `<bin>` forms convert glyphs at build time, so a size is baked in and the size
attribute is required. The `<tiny_ttf>` forms carry the outlines, so one source can
serve any size, at the cost of runtime rendering work.

`bpp="2"` is bits per pixel of anti-aliasing: `1`, `2`, `4` or `8`, trading file size
for smoothness.

### 3. Only the characters you need

```xml
range="0x20-0x7f" symbols="°äü"
```

`range` takes Unicode code point ranges, here printable ASCII. `symbols` adds
individual characters on top. Everything left out is simply absent from the font, which
is why a label showing `°` or `Schöne` needs those characters listed. This is the usual
cause of a label rendering as empty boxes.

Compare the labels in the preview: the two `<bin>` fonts only include `°` and the
`montserrat_14_c_array` also has `äü` for the German text used in `../translations`,
while the TinyTTF fonts can render anything the TTF contains.

### 4. Images, two ways

```xml
<images memory="int_flash">
	<data src_path="images/orange-flower.png" name="flower_data" color_format="argb8888" />
	<file src_path="images/orange-flower.png" name="flower_file" />
</images>
```

`<data>` decodes the PNG at build time into a raw pixel array in the given
`color_format` and links it in. It draws immediately with no decoder needed, and it is
large: an `argb8888` image is 4 bytes per pixel.

`<file>` keeps the PNG as a file to be read at runtime. Small in flash, and it needs a
filesystem driver and a PNG decoder in the LVGL config.

`color_format` accepts the LVGL formats: `argb8888`, `rgb565`, `rgb565a8`, `l8`, `i8`
and others. `rgb565` halves the memory of `argb8888` and drops the alpha channel.

Both images look identical in the preview, which is the point: the choice is about
memory and dependencies, not appearance.

### 5. `memory="int_flash"`

The `memory` attribute names one of the memory regions declared in `project.xml`:

```xml
<memory name="int_flash" size="2MB" bandwidth="100MB/s" />
```

Assigning assets to a region lets the Editor track how much of it they consume, which
is how you find out that a set of `argb8888` images does not fit before the linker
tells you.

## Try it

1. Change `color_format` on `flower_data` to `rgb565` and check the memory figures.
2. Add `symbols="€"` to `montserrat_16_bin_file` and put a `€` in its label.
3. Remove `°` from `montserrat_16_bin_file`'s `symbols` and see the character vanish.
4. Set `bpp="1"` on a `<bin>` font and look at the glyph edges.
5. Add a font at `size="28"` and use it on a new label.
6. Add your own PNG to `images/`, declare it as `<file>`, and show it.

## Common mistakes

- Using a character that the font's `range` and `symbols` do not cover.
- Setting `style_text_font` to a file path instead of the declared `name`.
- Choosing `as_file="true"` or `<file>` without a filesystem driver configured.
- Filling flash with `argb8888` images where `rgb565` would do.
- Declaring `<bin>` without `size`.

## Next

`../data_bindings` for connecting the UI to data.

## Reference

- [Fonts](https://lvgl.io/docs/pro/syntax/fonts)
- [Images](https://lvgl.io/docs/pro/syntax/images)
- [Project and targets](https://lvgl.io/docs/pro/syntax/project)
