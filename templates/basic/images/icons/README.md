# Icons

A set of basic UI icons sourced from [Lucide](https://lucide.dev)
([MIT licensed](https://github.com/lucide-icons/lucide/blob/main/LICENSE)).

## Layout

```
images/icons/
├── svg/            source SVGs — black stroke, transparent background
├── *.png           generated — do not edit
└── README.md       this file
```

`<convert>` accepts **SVG** as well as PNG, so the icons are kept as vectors and
rasterized at their final size:

```xml
<convert src="images/icons/svg/home.svg" dest="images/icons/home.png" width="#icon_size" color_format="argb8888" />
<data name="home" src_path="images/icons/home.png" color_format="argb8888" />
```

That beats shipping large source bitmaps: every size is rendered from the vector
instead of resampled, the sources are ~10× smaller, and adding an icon needs no
image tooling at all.

Icons are drawn black and recolored at the use site — the alpha channel carries
the shape:

```xml
<lv_image src="home" style_image_recolor="#color_accent" style_image_recolor_opa="100%" />
```

Or use the `monoicon` component, which follows the theme's text color.

## Adding an icon

1. Download the SVG from <https://lucide.dev/icons/> into `svg/`:

    ```bash
    curl -o svg/wind.svg https://raw.githubusercontent.com/lucide-icons/lucide/main/icons/wind.svg
    ```

2. Lucide strokes use `currentColor`, which has no value outside a browser.
   Replace it so the rasterizer has a color to draw with:

    ```bash
    sed -i 's/currentColor/#000000/' svg/wind.svg
    ```

3. Add the two lines above to the `<images>` block of `globals.xml`, then export code.

## Multiple sizes

Scaling a 16 px icon up to 28 px at runtime looks soft. Add one `<convert>` per
size instead — each rasterized from the same SVG — and suffix the extra tiers:

```xml
<convert src="images/icons/svg/home.svg" dest="images/icons/lg/home.png" width="#icon_size_lg" color_format="argb8888" />
<data name="home_lg" src_path="images/icons/lg/home.png" color_format="argb8888" />
```

Keep the sizes as consts (`#icon_size`, `#icon_size_lg`, …) so one edit re-tunes
every tier.
