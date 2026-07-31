# Images

Place your images in this folder, then register them in the `<images>` block of
`globals.xml`. Images are external resources: each entry gets a name that you
reference wherever a property expects an `image` type. `src_path` is relative to
the project root (the folder holding `project.xml` and `globals.xml`).

Use `<data>` to convert a PNG to a C array compiled into the firmware — pick a
`color_format` such as `rgb565`, `argb8888`, or `i8` — or `<file>` to load the
PNG from the filesystem at runtime. Reference the registered name in an image
widget (`<lv_image src="logo"/>`), a style (`bg_image_src="wallpaper"`), or a
component property.

```xml
<!-- in globals.xml -->
<images>
  <data name="logo"     color_format="argb8888" src_path="images/logo.png"/>
  <file name="avatar"   src_path="images/avatar1.png"/>
</images>
```

## Resizing and SVG

`<convert>` produces a PNG of a given size from a source image, and its source
may be **PNG or SVG**. Vector sources are the better choice for anything you draw
at more than one size — each `<convert>` rasterizes from the SVG at its final
size rather than resampling a bitmap:

```xml
<convert src="images/icons/svg/home.svg" dest="images/icons/home.png" width="#icon_size" color_format="argb8888"/>
<data name="home" src_path="images/icons/home.png" color_format="argb8888"/>
```

`<data>` and `<file>` themselves point at the PNG that `<convert>` emits. See
`icons/README.md` for the full pattern, including multiple size tiers.

Docs: https://lvgl.io/docs/pro/syntax/images
