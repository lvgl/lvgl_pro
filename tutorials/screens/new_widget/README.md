# New widget

`wd_segment` is a segmented control: a row of buttons where exactly one is selected. The
selection logic cannot be expressed as composition plus binding, so this one is a
`<widget>` with hand-written C behind it.

## What you'll learn

- When a `<widget>` is the right answer instead of a `<component>`
- What the XML declares and what the C implements
- Which files are generated and which you edit
- Declaring an addable child with `<element access="add">`
- Making a custom widget work with `bind_value`
- Why a widget needs a rebuild before the preview shows it

## Walkthrough

### 1. Widget or component

A `<component>` is pure XML: composition, styles, parameters, events, data binding. It
covers most of a UI, needs no C, and can even be loaded from XML at runtime.

A `<widget>` is for behaviour that XML cannot describe. Here that behaviour is "clicking
one button unchecks the others, updates an index, and writes it to a subject". There is
no XML construct for that loop, so it is C.

A widget also comes with costs: it can extend a widget but not a component, it cannot be
loaded from XML at runtime, and the preview has to be recompiled when it changes.

### 2. The screen side

`screen_widgets/screen_widgets.xml`:

```xml
<view extends="lv_obj">
	<wd_segment width="300" bind_value="subject_segment" style_pad_column="1">
		<wd_segment-button text="Option 1" />
		<wd_segment-button text="Option 2" />
		<wd_segment-button text="Option 3" />
	</wd_segment>
</view>
```

From the outside a custom widget is used exactly like a built-in one, including
`bind_value` against a subject from `globals.xml`. The `wd_segment-button` tag is the
widget's own addable child element, explained below.

### 3. The XML declares the API

`widgets/wd_segment/wd_segment.xml`:

```xml
<api>
	<prop name="selected" type="int" help="The current selected item, -1 for none" />
	<prop name="bind_value" type="subject" help="The subject to bind the selected item" />
	<element name="button" access="add" type="lv_obj" help="Add buttons to the segment">
		<arg name="text" type="string" />
	</element>
</api>
```

- Each `<prop>` becomes a setter in C. `selected` becomes
  `wd_segment_set_selected(obj, int32_t)` and `bind_value` becomes
  `wd_segment_bind_value(obj, lv_subject_t *)`.
- `<element name="button" access="add">` declares a child that can be added to the
  widget. In XML it is written as `<wd_segment-button/>`, the widget's tag plus the
  element name. In C it becomes `wd_segment_add_button(obj, const char * text)`, with the
  `<arg>` list as its parameters.

The rest of the file is ordinary XML: `<styles>` with a `style_base` that sets the flex
row and the rounded clipped background, a `<previews>` block for the Editor, and a
`<view extends="lv_obj">`. A widget can only extend a widget, never a component.

### 4. The C implements the behaviour

`widgets/wd_segment/wd_segment.c` is the only file here you write by hand. It contains:

**Lifecycle hooks**, called by the generated code:

```c
void wd_segment_constructor_hook(lv_obj_t * obj)
{
    wd_segment_t * widget = (wd_segment_t *)obj;
    widget->selected = -1; // default selected item
}
```

`wd_segment_t` is the generated instance struct, and it already has a field per `<prop>`.
There are `_destructor_hook` and `_event_hook` too, empty in this widget.

**The setters declared by the API:**

```c
void wd_segment_bind_value(lv_obj_t * wd_segment, lv_subject_t * bind_value)
{
    wd_segment_t * widget = (wd_segment_t *)wd_segment;
    widget->bind_value = bind_value;
    lv_subject_add_observer_obj(widget->bind_value, value_observer_cb, wd_segment, widget);
}
```

This is what makes `bind_value="subject_segment"` work on a custom widget: register an
observer on the subject, and write the subject back when the selection changes.

**The add function:**

```c
lv_obj_t * wd_segment_add_button(lv_obj_t * wd_segment, const char * text)
{
    wd_segment_t * widget = (wd_segment_t *)wd_segment;
    lv_obj_t * segment_item = segment_item_create(wd_segment, text);
    lv_obj_set_flex_grow(segment_item, 1);
    lv_obj_add_event_cb(segment_item, segment_selected_cb, LV_EVENT_CLICKED, widget);
    ...
}
```

Note `segment_item_create`. The individual buttons are a plain **component**,
`components/widget_items/segment_item/segment_item.xml`, with its own `style_base` and
`style_checked` sheets. The C only creates it and sets flex grow, and the appearance
stays in XML where it belongs.

`segment_selected_cb` walks the children, sets `LV_STATE_CHECKED` on the clicked one,
stores the index, writes the subject and sends `LV_EVENT_VALUE_CHANGED`. That state is
what `style_checked` in `segment_item.xml` reacts to, so C decides the state and XML
decides how the state looks.

### 5. The files

| File | Written by | Purpose |
| --- | --- | --- |
| `wd_segment.xml` | you | API, styles, base view |
| `wd_segment.c` / `.h` | you | the behaviour |
| `wd_segment_gen.c` / `_gen.h` | generated | `_create()`, the setters, the hook calls |
| `wd_segment_private_gen.h` | generated | the `wd_segment_t` instance struct |
| `wd_segment_xml_parser.c` | generated | maps XML attributes onto the C setters |

Everything with `_gen` in the name is overwritten on export. `wd_segment_xml_parser.c` is
what allows the Editor and the runtime XML loader to understand the tag.

### 6. Rebuilding

A component change shows up in the preview as you type. A widget change does not,
because the preview has to run new C. Press **Ctrl+B** to regenerate and recompile, or
**F5** to run it in the simulator.

## Try it

1. Add a fourth `<wd_segment-button text="Option 4" />` to the screen.
2. Open the **Subjects** panel and set `subject_segment` to `2`. The control follows,
   which is `value_observer_cb` at work.
3. Change the colors in `components/widget_items/segment_item/segment_item.xml` and press Ctrl+B.
4. Add `<arg name="icon" type="string" />` to the `button` element, then extend
   `wd_segment_add_button` to take it. Notice the signature in `_gen.h` changes.
5. Set `selected="1"` on `<wd_segment>` in the screen instead of using `bind_value`.
6. Put a `<lv_label bind_text="subject_segment" bind_text-fmt="Selected: %d" />` next to
   the control.
7. Ask whether your next idea really needs C. A radio group of buttons using
   `subject_set_int_event` and `bind_state_if_eq` does the same job in pure XML, see
   `../data_bindings`.

## Common mistakes

- Reaching for a widget when a component and data binding would do.
- Editing a `_gen.*` file, which the next export overwrites.
- `extends` pointing at a component. A widget can only extend a widget.
- Expecting the preview to update without Ctrl+B.
- Putting the visual design in the C code instead of in an XML component like
  `segment_item`.
- Adding a `<prop>` to the XML and not implementing the setter it generates.

## Next

`../testing` for automated UI tests.

## Reference

- [Widgets](https://lvgl.io/docs/pro/syntax/widgets)
- [API and properties](https://lvgl.io/docs/pro/syntax/api)
- [Using exported C code](https://lvgl.io/docs/pro/integration/using-exported-c-code)
