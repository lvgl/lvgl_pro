# Data bindings

Three slider boxes, each wired to a subject. Moving a slider updates a label, pressing a
button updates the slider, and the screen contains no C and no callbacks.

## What you'll learn

- Declaring subjects in `globals.xml`
- Binding a widget's value and a label's text to a subject
- Formatting a bound value with `bind_text-fmt`
- Writing a subject from an event
- Passing a subject into a component through its `<api>`
- Why binding is not the same as a `{ }` expression

## Walkthrough

### 1. Subjects

```xml
<subjects>
	<int name="subject_dark_mode" value="0" />
	<int name="subject_max_current" value="0" />
	<int name="subject_timeout" value="0" />
	<int name="subject_volume" value="0" />
</subjects>
```

A subject is a named value with an observer list. Anything bound to it is notified when
it changes. Subjects are declared in `globals.xml` and come in `<int>`, `<string>` and
`<float>`, with `value` as the initial content.

Open the **Subjects** panel under the preview to watch and set them live.

### 2. The screen just passes subjects around

```xml
<view flex_flow="column" style_flex_track_place="center">
	<sliderbox subject="subject_max_current" title="Max. current" unit="%d mA" />
	<sliderbox subject="subject_timeout" title="Timeout" unit="%d ms" />
	<sliderbox subject="subject_volume" title="Volume" unit="%d%%" />
</view>
```

`sliderbox` is a component of this project. All three instances are identical except for
the subject they operate on.

### 3. A subject as a component parameter

`components/sliderbox.xml`:

```xml
<api>
	<prop name="title" type="string" default="Title" />
	<prop name="subject" type="subject" default="volume" />
	<prop name="unit" type="string" default="%d" />
</api>
```

`type="subject"` is a real property type, so a component can take a subject as a
parameter and forward it to its children with `$subject`. This is what makes one
`sliderbox` definition serve three different values.

### 4. Reading a subject

```xml
<lv_slider bind_value="$subject" flex_in_new_track="true" width="100%" />
<lv_label flex_grow="1" bind_text="$subject" bind_text-fmt="$unit" style_text_align="center" />
```

`bind_value` on an interactive widget is two way: the slider shows the subject and
moving the slider sets the subject.

`bind_text` on a label is one way, and `bind_text-fmt` gives the `printf` format string
applied to the value. That is where `"%d mA"`, `"%d ms"` and `"%d%%"` from the screen
end up, so the same component renders three different units. `%%` prints a literal
percent sign.

### 5. Writing a subject

`components/round_button.xml`:

```xml
<subject_increment_event subject="$subject" step="$step" trigger="pressed" />
<subject_increment_event subject="$subject" step="$step" trigger="long_pressed_repeat" />
```

`subject_increment_event` adds `step` to a subject when the trigger fires. The `-` and
`+` buttons in a `sliderbox` are the same component with `step="-1"` and `step="1"`.

The second line is what makes the buttons repeat while held: `long_pressed_repeat` fires
over and over during a long press.

To write a fixed value there is `subject_set_int_event`, plus
`subject_set_float_event` and `subject_set_string_event`. Combined with
`bind_state_if_eq` they build a radio group or a mode switch with no application code.

### 6. Binding a style

```xml
<styles>
	<style name="style_dark" bg_color="0x333" text_color="0xfff" border_color="0x111" />
</styles>

<view ...>
	<bind_style name="style_dark" subject="subject_dark_mode" ref_value="1" />
```

A subject does not have to drive a value. `bind_style` adds a style sheet while the
subject equals `ref_value`, which is a complete dark mode with no C.

The comparison family is the same everywhere:

```xml
<bind_flag_if_eq  subject="subject_mode" flag="hidden"   ref_value="0" />
<bind_state_if_gt subject="subject_temp" state="checked" ref_value="30" />
```

`bind_flag_*` takes a `flag`, `bind_state_*` takes a `state`, and both come in `if_eq`,
`if_not_eq`, `if_gt`, `if_ge`, `if_lt` and `if_le`.

### 7. Binding vs expressions

```xml
<lv_label text="$title" />                 <!-- resolved once, when created -->
<lv_label bind_text="$subject" />          <!-- follows the subject forever -->
<lv_obj hidden="{!icon}" />                <!-- evaluated once, when created -->
```

A `{ }` expression and an `$api` property are resolved when the widget is created and
never again. Anything that has to change while the UI runs needs a subject and a
`bind_*` attribute.

### 8. Component previews

```xml
<previews>
	<preview name="light" style_pad_all="20" />
	<preview name="dark" style_pad_all="20" style_bg_color="0x888">
		<set_subject name="subject_dark_mode" value="1" />
	</preview>
</previews>
```

A component can declare the environments it should be previewed in. `<set_subject>`
forces a subject value for that preview only, so `sliderbox.xml` shows its light and
dark appearance side by side while you edit it. Previews are an Editor feature and are
not exported to C.

## Try it

1. Open the **Subjects** panel and set `subject_volume` to `80`. The slider, the label
   and both buttons agree instantly.
2. Set `subject_dark_mode` to `1`.
3. Change a `unit` to `"Vol: %d of 100"` and see it in the label.
4. Add `<int name="subject_brightness" value="50" />` to `globals.xml` and a fourth
   `sliderbox` for it.
5. Pass `step="10"` from `sliderbox.xml` to the two `round_button`s.
6. Add `<lv_label bind_text="subject_volume" bind_text-fmt="Volume is %d" />` directly on
   the screen, outside any component.
7. Add `<bind_flag_if_gt subject="subject_volume" flag="hidden" ref_value="90" />` to one
   of the labels and push the volume past 90.

## Common mistakes

- Expecting `text="$prop"` or `{ }` to update at runtime.
- Using `bind_state_*` with `flag=`, or `bind_flag_*` with `state=`.
- Binding to a subject that is not declared in `globals.xml`.
- Forgetting `bind_text-fmt`, which leaves the label showing the raw number.
- Writing `%d%` instead of `%d%%` for a percent sign.

## Next

`../translations` for multi-language text.

## Reference

- [Data binding](https://lvgl.io/docs/pro/syntax/data-binding)
- [API and properties](https://lvgl.io/docs/pro/syntax/api)
- [Events](https://lvgl.io/docs/pro/syntax/events)
- [Previews](https://lvgl.io/docs/pro/syntax/preview)
