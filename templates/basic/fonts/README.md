# Fonts

Place your `.ttf` (or `.woff`) files in this folder, then register the specific
fonts and sizes you need in the `<fonts>` block of `globals.xml`. Fonts are
external resources: each entry gets a name that you reference later in styles and
`api` properties. Three engines are available — `<bin>` (glyphs baked to bitmaps
at the requested size), `<tiny_ttf>` (renders TTF glyphs at runtime, MCU-friendly),
and `<freetype>` (TTF rendering for MPUs).

Use `as_file="false"` to embed the font as a C array compiled into the firmware,
or `as_file="true"` to load it from the filesystem at runtime. Once registered, a
font is referenced by name, e.g. `style_text_font="title_large"`.

```xml
<!-- in globals.xml -->
<fonts>
  <bin name="title_large" src_path="fonts/Montserrat-Medium.ttf"
       size="32" bpp="4" as_file="false"/>
  <tiny_ttf name="body" src_path="fonts/Montserrat-Regular.ttf" size="18"/>
</fonts>
```

Docs: https://lvgl.io/docs/pro/syntax/fonts
