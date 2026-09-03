# New component

A screen made only of components: `section`, `button_normal` and `button_warning`. This
tutorial is about the three component files behind it, in `components/`.

## What you'll learn

- What `<component>` gives you that `<screen>` does not
- Declaring parameters with `<api>` and reading them with `$`
- The file name to tag name rule
- Extending a widget, and extending another component to make a variant
- `remove_style_all` and starting from a blank widget
- Why the API is not inherited

## Walkthrough

### 1. The screen is only composition

```xml
<view flex_flow="column" style_pad_all="#unit_small" style_flex_cross_place="center">
	<section text="Normal buttons" />
	<button_normal />
	<button_normal label_text="Custom text" />
	<button_normal label_text="Full width" width="100%" />

	<section text="Warning buttons" />
	<button_warning />
	<button_warning label_text="Upps!" />
</view>
```

Every tag here is a file in `components/`. `<button_normal />` with no attributes still
renders a button with text, because the component declares a default.

`#unit_small` is a constant from `globals.xml`.

### 2. The smallest component

`components/section.xml`:

```xml
<component>
	<view
		extends="lv_label"
		style_width="100%"
		style_text_align="center"
		style_border_side="bottom"
		style_border_width="1"
		style_margin_top="12"
	/>
</component>
```

`extends="lv_label"` means the component **is** a label with extra styling. It has no
`<api>` of its own, yet the screen writes `<section text="Normal buttons" />`: a
component that extends a widget accepts that widget's own attributes.

This is worth remembering. A component whose only job is one styled widget needs no
`<api>` and no children, only an `extends` and some style properties.

### 3. The file name is the tag name

`components/section.xml` becomes `<section/>`. One element per file, and the folder
structure does not matter: `components/buttons/button_normal.xml` is still
`<button_normal/>`.

### 4. Parameters

`components/buttons/button_normal.xml`:

```xml
<api>
	<prop name="label_text" type="string" default="Click me" />
</api>
```

```xml
<view extends="lv_button">
	<remove_style_all />
	<style name="style_base" />
	<style name="style_pressed" selector="pressed" />

	<lv_label text="$label_text" align="center" />
</view>
```

A `<prop>` declares a parameter with a `type` (`string`, `int`, `px`, `color`, `bool`,
`subject`, an enum, ...) and an optional `default`. Inside the component, `$label_text`
reads it.

`<prop>` also takes `help="..."`, which shows up in the Editor and is worth writing for
anything not obvious from the name.

The three sigils, all visible in this project:

| Prefix | Means | Example |
| --- | --- | --- |
| `$name` | an `<api>` property of this element | `text="$label_text"` |
| `#name` | a constant from `<consts>` or `globals.xml` | `bg_color="#dark_blue"` |
| `{ ... }` | an expression, evaluated once at creation | `hidden="{!icon}"` |

Inside `{ }` write bare identifiers, with no `$` and no `#`.

### 5. Starting from a blank widget

```xml
<remove_style_all />
```

`lv_button` arrives with the theme's styles already applied. `remove_style_all` strips
them so the component's own `style_base` is the only thing painted, which is how a
project gets a consistent look regardless of the active theme. The `column` and `row`
components do the same to get a container with no background at all.

Note the ordering inside `<view>`: `remove_style_all` first, then the styles.

### 6. A variant by extending

`components/buttons/button_warning.xml`:

```xml
<component>
	<api>
		<prop name="label_text" type="string" default="Warning!" />
	</api>

	<view extends="button_normal" style_bg_color="#yellow" label_text="$label_text" />
</component>
```

A component can extend another component. `button_warning` is a `button_normal` with one
color changed, so its styles, its `pressed` state and its `show_up` animation all come
along.

The `<api>` is **not** inherited. `button_warning` has to declare `label_text` again and
forward it explicitly with `label_text="$label_text"`. That is the price of the
redeclaration, and it also lets the variant change the default, here from `Click me` to
`Warning!`.

### 7. What a component may contain

| Block | Purpose |
| --- | --- |
| `<api>` | parameters |
| `<consts>` | local constants |
| `<styles>` | local style sheets |
| `<animations>` | local timelines, see `../animations` |
| `<previews>` | how the Editor should preview it |
| `<view>` | the element itself, exactly one |

A `<screen>` has no `<api>` and no `extends`, which is the main difference. A component
is instantiable and parameterized, a screen is not.

## Try it

1. Add `<prop name="icon" type="string" default="" />` to `button_normal` and a second
   label using `$icon`.
2. Give that label `hidden="{!icon}"` so it disappears when no icon is passed.
3. Make a `button_success` by copying `button_warning` and changing the color.
4. Delete `<remove_style_all />` from `button_normal` and see the theme styles return.
5. Change `default="Click me"` and watch the bare `<button_normal />` on the screen
   follow.
6. Add `help="Text shown on the button"` to the `label_text` prop and hover it in the
   Editor.
7. Give `section` an `<api>` prop and try to use it. It will conflict with the inherited
   `lv_label` attributes if you pick a name like `text`.

## Common mistakes

- Expecting the `<api>` of the extended component to be inherited.
- Putting `$some_prop` inside a `<style>` tag. Styles are initialized once, so pass the
  value as a local style property instead.
- Writing `$` or `#` inside `{ }`.
- Forgetting `remove_style_all` and then fighting the theme's styles.
- A file name that does not match the tag used in the screen.
- Two elements in one `<view>` where a single root was intended. `<view>` is the root
  object, and everything inside it is its child.

## Next

`../new_widget` for a widget backed by hand-written C.

## Reference

- [Components](https://lvgl.io/docs/pro/syntax/components)
- [API and properties](https://lvgl.io/docs/pro/syntax/api)
- [View and extends](https://lvgl.io/docs/pro/syntax/view)
- [Constants](https://lvgl.io/docs/pro/syntax/constants)
