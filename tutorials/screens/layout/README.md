# Layout

A header, a scrollable body and a footer, built by nesting flex containers. Press
**Alt** in the preview to draw the bounding box of every element.

## What you'll learn

- Stacking widgets with the `column` and `row` components
- Distributing space with the flex placement properties
- Sizing with `100%` and `content`
- Taking a single child out of the layout with `ignore_layout`
- Keeping a widget on screen while the rest scrolls with `floating`
- Where scrolling comes from

## Walkthrough

### 1. `column` and `row`

```xml
<column width="100%">
	<row width="100%" ...> ... </row>
	<column ...> ... </column>
	<row width="100%" ...> ... </row>
</column>
```

`column` and `row` are components of this project (see `components/column/column.xml`),
not built-in widgets. Each is a bare container with `layout="flex"` and a `flex_flow`
already set, so the markup stays short. The same result written out by hand would be
`<lv_obj flex_flow="column">`.

The outer `column` is the screen's only direct child and holds the three bands: header,
content, footer.

### 2. Placing children along the flex axis

```xml
<row
	width="100%"
	style_flex_main_place="space_between"
	style_pad_all="8"
	style_bg_opa="100%"
	style_bg_color="0x002c57"
>
	<button_normal label_text="First" />
	<button_normal label_text="Second" />
	<button_normal label_text="Third" />
</row>
```

Three placement properties control a flex container, and all three are style
properties, so they carry the `style_` prefix on a widget:

| Property | Axis | Effect |
| --- | --- | --- |
| `style_flex_main_place` | along the flow | `start`, `center`, `end`, `space_between`, `space_around`, `space_evenly` |
| `style_flex_cross_place` | across the flow | `start`, `center`, `end` |
| `style_flex_track_place` | the tracks as a block | `start`, `center`, `end`, `space_between`, ... |

`space_between` pushes the first and last child to the edges and spreads the rest.
`style_pad_all="8"` insets the children from the container edge, and `style_pad_row` /
`style_pad_column` set the gap between them.

`style_bg_opa="100%"` is needed here because a container is transparent by default, so
setting only `bg_color` would change nothing visible.

### 3. Sizing

- `width="100%"` fills the parent's content area.
- `height="content"` (and `width="content"`) shrinks to fit the children. This is what
  `column` and `row` use by default.
- A number is pixels: `width="200"`.

### 4. Escaping the layout

```xml
<lv_checkbox text="Third" ignore_layout="true" x="142" y="15" />
```

A flex container positions all of its children. `ignore_layout="true"` tells it to skip
this one, which frees `x`, `y` and `align` to work as absolute coordinates relative to
the parent.

```xml
<button_normal label_text="Floating" floating="true" align="bottom_right" x="-20" y="-12" />
```

`floating="true"` goes further: the widget is not scrolled with its parent's content, so
it stays pinned to the bottom right while the checkboxes scroll behind it. Negative
coordinates offset inward from the alignment corner.

### 5. Scrolling

Nothing on this screen enables scrolling. The inner `column` simply contains more
checkboxes than fit, and an LVGL container scrolls its overflowing content on its own.
Delete a few checkboxes and the scrollbar disappears.

## Try it

1. Change the header's `style_flex_main_place` to `center`, then `space_evenly`.
2. Add `style_flex_cross_place="center"` to the content column and see the checkboxes
   line up on the middle axis.
3. Set the header `height="80"` and add `style_flex_cross_place="end"` to it.
4. Remove `ignore_layout="true"` from the third checkbox and watch `x`/`y` stop having
   any effect.
5. Remove `floating="true"` from the last button and scroll: it now moves with the
   content.
6. Give a checkbox `flex_grow="1"` in a `row` to make it absorb the leftover space.
7. Hold **Alt** over the preview to see how large each container actually is.

## Common mistakes

- Writing `flex_main_place` without the `style_` prefix on a widget.
- Setting `bg_color` on a container and forgetting `bg_opa`.
- Using `x`/`y`/`align` on a child of a flex container without `ignore_layout="true"`.
- Reaching for `style_flex_cross_place` to center a single row of content when
  `style_flex_track_place` is the one that centers the track itself.

## Next

`../screens` for creating several screens and navigating between them.

## Reference

- [Styles](https://lvgl.io/docs/pro/syntax/styles)
- [Built-in widgets](https://lvgl.io/docs/pro/built_in_widgets) for every `flex_*` property and its enum values
