# Images

Place your PNG images in this folder (only PNG is supported), then register them
in the `<images>` block of `globals.xml`. Images are external resources: each
entry gets a name that you reference wherever a property expects an `image` type.
`src_path` is relative to the project root (the folder holding `project.xml` and
`globals.xml`).

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

Docs: https://lvgl.io/docs/pro/syntax/images
