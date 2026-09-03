# Animations

A list that slides in with its buttons staggered behind it, played automatically when
the screen loads and replayable forwards or backwards from two buttons.

## What you'll learn

- Declaring a `<timeline>` and putting `<animation>` steps in it
- Which properties to animate, and why `translate_x` beats `x`
- Composing timelines out of other timelines with `<include_timeline>`
- Staggering children with `delay`
- Starting a timeline from an event, including `screen_loaded`
- Playing a timeline in reverse

## Walkthrough

### 1. A timeline on a component

Animations are declared where the animated widget lives. `components/buttons/button_normal.xml`
defines its own show up animation:

```xml
<animations>
	<timeline name="show_up">
		<animation target="self" prop="opa" start="0" end="255" duration="200" early_apply="true" />
		<animation target="self" prop="translate_y" start="20" end="0" duration="200" early_apply="true" />
	</timeline>
</animations>
```

- `target="self"` animates the component's own root object. Any other value is the
  `name` of a child.
- `prop` is the property to animate: `opa`, `translate_x`, `translate_y`, `width`,
  `height`, `x`, `y`, and the style properties.
- `start` and `end` are in the property's own unit. `opa` runs `0` to `255`.
- `duration` is milliseconds, and `delay` (used below) offsets the start.
- `early_apply="true"` writes the `start` value immediately, before the animation runs.
  Without it the button would flash at full opacity for one frame.

`translate_y` shifts the widget from wherever the layout put it, so the animation works
no matter where the button ends up. Animating `y` would need to know the final
coordinate.

Declaring the timeline does not play it. It is a named recipe that something else
triggers.

### 2. A timeline built from other timelines

`components/list/list.xml` animates itself and then pulls in each button's `show_up`:

```xml
<timeline name="list_open">
	<animation prop="opa" start="0" end="255" duration="300" early_apply="true" target="self" />
	<animation prop="translate_x" start="-60" end="0" duration="300" early_apply="true" target="self" />

	<include_timeline target="button_0" timeline="show_up" delay="0" />
	<include_timeline target="button_1" timeline="show_up" delay="100" />
	<include_timeline target="button_2" timeline="show_up" delay="200" />
	...
</timeline>
```

`<include_timeline>` runs a timeline that a child already defines, and `delay` shifts it
in time. Increasing the delay per child is the whole stagger effect. The child buttons
are addressable because each one was given a `name`:

```xml
<button_normal name="button_0" label_text="Button 0" />
```

### 3. The screen composes one level higher

```xml
<animations>
	<timeline name="screen_open">
		<include_timeline target="show" timeline="show_up" />
		<include_timeline target="hide" timeline="show_up" />
		<include_timeline target="button_list" timeline="list_open" />
	</timeline>
</animations>
```

The screen's `screen_open` timeline includes the two buttons' `show_up` and the list's
`list_open`, which itself includes eight more. Each component owns its own animation and
the parent only decides when it runs.

### 4. Triggering

```xml
<play_timeline_event target="self" timeline="screen_open" trigger="screen_loaded" />
```

Placed directly in the screen's `<view>`, this plays `screen_open` on the screen
(`target="self"`) when the screen finishes loading. `trigger` accepts the LVGL event
names: `clicked`, `pressed`, `value_changed`, `screen_loaded`, and so on.

```xml
<button_normal label_text="Show" name="show" align="top_right" x="-10" y="10">
	<play_timeline_event target="button_list" timeline="list_open" />
</button_normal>
```

Inside a widget and with no `trigger`, the default is `clicked`. `target="button_list"`
points at the named list, so the button plays someone else's timeline.

```xml
<play_timeline_event target="button_list" timeline="list_open" reverse="true" />
```

`reverse="true"` plays the same timeline backwards, which turns the open animation into
a close animation. One timeline, two directions, no second definition.

## Try it

1. Raise the `duration` in `show_up` to `800` to watch the stagger in slow motion.
2. Give `button_5`, `button_6` and `button_7` delays of `500`, `600` and `700` instead
   of all `400`.
3. Remove `early_apply="true"` from one animation and look for the flash on the first
   frame.
4. Change `translate_x` in `list_open` from `-60` to `-300` so the list comes in from
   off screen.
5. Animate something else: add `<animation target="self" prop="width" start="0" end="240" duration="300" />`
   to `list_open`.
6. Remove the `trigger="screen_loaded"` line and reload. Nothing animates until you
   press **Show**.

## Common mistakes

- Declaring a timeline and never triggering it.
- Leaving off `early_apply="true"` on a fade in.
- Using `target="some_child"` where the child has no `name` attribute.
- Animating `x` or `y` on a child of a flex layout, where the layout owns those values.
  `translate_x` and `translate_y` are additive and stay out of the layout's way.

## Next

`../assets` for fonts and images.

## Reference

- [Animations](https://lvgl.io/docs/pro/syntax/animations)
- [Components](https://lvgl.io/docs/pro/syntax/components)
