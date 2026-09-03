# Translations

Four labels with no text attribute. The strings come from `translations.xml` and follow
the selected language.

## What you'll learn

- Declaring languages and translated strings in `translations.xml`
- Pulling a string into a widget with `translation_tag`
- What `char_count` is for
- Why the font matters as much as the translation
- Switching language in the Editor and in a test

## Walkthrough

### 1. The translation table

`translations.xml` at the project root:

```xml
<translations languages="en de">
	<translation tag="dog" char_count="40" en="This is a dog" de="Das ist ein Hund" />
	<translation tag="cat" char_count="40" en="A curious little cat" de="Eine neugierige kleine Katze" />
	<translation tag="house" char_count="40" en="The house is cozy and warm" de="Das Haus ist gemütlich und warm" />
	<translation char_count="60" tag="person"
	             en="A kind person with a bright smile"
	             de="Eine freundliche Person mit einem strahlenden Lächeln" />
</translations>
```

- `languages` lists every language code the project supports. Each code then becomes an
  attribute name on `<translation>`.
- `tag` is the key the UI refers to. It is not shown to the user, so it can stay short
  and stable while the strings change.
- `char_count` declares the longest length this tag is expected to reach. It is used to
  size the string storage and to warn when a translation grows past its budget, which is
  how you find out that the German string no longer fits the button before the layout
  breaks on the device.

### 2. Using a tag

```xml
<view flex_flow="column" style_text_font="montserrat_14_c_array">
	<lv_label translation_tag="dog" />
	<lv_label translation_tag="cat" />
	<lv_label translation_tag="house" />
	<lv_label translation_tag="person" />
</view>
```

`translation_tag` replaces `text`. The label looks up the tag in the current language and
updates itself when the language changes, so no `text` attribute is needed and none
should be given.

`translation_tag` works on any widget that takes text, not only `lv_label`.

### 3. The font has to contain the letters

`style_text_font` is set once on the `<view>`, and text styles are inherited, so all four
labels use `montserrat_14_c_array`. In `globals.xml` that font is declared as:

```xml
<bin name="montserrat_14_c_array" as_file="false" bpp="2"
     src_path="fonts/Montserrat_Medium.ttf" size="14" range="0x20-0x7f" symbols="°äü" />
```

`range="0x20-0x7f"` is ASCII only, which does not include `ü` or `ä`. Those are added by
hand through `symbols="°äü"`, which is what lets `gemütlich` and `Lächeln` render. Note
that `ö` is not in the list, so a translation using it would need it added first. Drop them from `symbols` and the German text loses those characters.

Adding a language usually means auditing the font as well: Cyrillic, Greek or CJK need
their own ranges, and CJK is where a `<tiny_ttf>` font starts to look attractive over a
pre-rendered `<bin>`.

### 4. Switching language

In the Editor, use the **Translations** panel under the preview.

In a test, use a step (see `../testing`):

```xml
<set_language name="de" />
```

In C, the exported code exposes the language setter, so the application can switch at
runtime and every `translation_tag` widget updates itself.

## Try it

1. Open the **Translations** panel and switch between `en` and `de`.
2. Add `hu` to `languages` and a `hu="..."` attribute to each `<translation>`.
3. Lower `char_count` on `person` to `20` and look for the warning.
4. Remove `äü` from `montserrat_14_c_array`'s `symbols`, switch to `de` and see the
   missing characters.
5. Add a new tag and use it on a fifth label.
6. Put `translation_tag="dog"` on an `lv_button`'s label and check that it follows the
   language too.

## Common mistakes

- Giving both `text` and `translation_tag` on the same widget.
- A language code in `languages` with no matching attribute on some `<translation>`.
- A font whose `range` and `symbols` do not cover the translated text.
- Sizing a container to the English string only. Use `char_count` and check the longest
  language.
- Renaming a `tag` and leaving the old name in a screen.

## Next

`../new_component` for building your own reusable components.

## Reference

- [Translations](https://lvgl.io/docs/pro/syntax/translations)
- [Fonts](https://lvgl.io/docs/pro/syntax/fonts)
