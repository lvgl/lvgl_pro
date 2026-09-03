# Screens

Two screens and a round trip between them. One is permanent and keeps its state, the
other is created fresh every time it opens.

## What you'll learn

- The difference between a permanent screen and a dynamically created one
- Which event to use for each: `screen_load_event` vs `screen_create_event`
- Animating a screen transition
- Why widget state survives on one screen and not on the other
- Writing a newline inside an XML attribute

## Walkthrough

### 1. A permanent screen

```xml
<screen permanent="true">
	<view>
		<lv_label text="Main screen  (permanent)" align="top_mid" y="10" />
		<lv_slider align="center" />
		...
	</view>
</screen>
```

`permanent="true"` means the screen object is created once when the UI starts and is
never deleted. It costs RAM for the whole run of the program, and in exchange every
widget keeps its state: scroll position, slider value, checkbox marks.

### 2. A dynamically created screen

```xml
<screen>
	<view style_bg_color="0x041d3a" style_text_color="0xfff">
	...
</screen>
```

`permanent` defaults to `false`. The screen is built when it is opened and deleted when
it is closed, so it uses RAM only while visible and every widget starts from its XML
defaults again.

Note `style_text_color` on the `<view>`: text color is an inherited style property, so
setting it on the screen colors every label inside it.

### 3. Opening a screen

The event tag has to match how the target screen is declared.

```xml
<!-- on the Main screen, opening the non-permanent About screen -->
<screen_create_event screen="screen_about" anim_type="move_top" duration="500" />
```

```xml
<!-- on the About screen, returning to the permanent Main screen -->
<screen_load_event screen="screen_main" anim_type="move_bottom" duration="500" />
```

| Tag | Use for | What it does |
| --- | --- | --- |
| `screen_create_event` | `permanent="false"` screens | builds the screen, then shows it |
| `screen_load_event` | `permanent="true"` screens | shows the screen that already exists |

Both tags are written **inside** the widget that triggers them, here the `lv_button`,
and both accept `anim_type` (`move_top`, `move_bottom`, `move_left`, `move_right`,
`fade_in`, `over_top`, ...) and `duration` in milliseconds.

The screen name is the file name without the extension: `screen_about.xml` becomes
`screen="screen_about"`.

### 4. Seeing the difference

Move the slider on the Main screen, press **About**, then press **Back**: the slider is
where you left it. Move the slider on the About screen, go back and open About again:
it has reset to zero.

### 5. Newlines in attributes

```xml
text="I'm on a permanent screen,&#10; so my state will stay"
```

XML attributes cannot hold a literal newline, so `&#10;` is used. The same escaping
applies to the other reserved characters: `&amp;`, `&lt;`, `&gt;`, `&quot;` and
`&apos;`. An apostrophe inside a double-quoted attribute is fine, as above.

## Try it

1. Change `anim_type` on both buttons to `fade_in` and `duration` to `1000`.
2. Add `permanent="true"` to `screen_about.xml`, then change its `screen_create_event`
   in `screen_main.xml` to `screen_load_event`. Its slider now keeps its value too.
3. Swap only the tag without changing `permanent` and watch the transition break. This
   is the most common screen bug.
4. Add a third screen and chain the navigation Main to About to the new one.
5. Set `duration="0"` for an instant switch.

## Common mistakes

- `screen_load_event` on a screen that is not `permanent="true"`. There is nothing to
  load yet.
- `screen_create_event` on a permanent screen, which builds a second copy.
- Expecting a non-permanent screen to remember anything. Store the state in a subject
  in `globals.xml` and bind to it, see `../data_bindings`.
- Putting the event tag next to the button instead of inside it.

## Next

`../animations` for timelines and animated transitions inside a screen.

## Reference

- [Screens](https://lvgl.io/docs/pro/syntax/screens)
- [XML overview](https://lvgl.io/docs/pro/syntax/overview)
