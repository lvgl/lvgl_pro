# Testing

One test that drives the layout screen: it clicks checkboxes, drags to scroll, switches
language, sets a subject, and compares a screenshot after every step.

## What you'll learn

- The structure of a `<test>` file
- Reusing an existing screen as the test's view, with extra widgets added
- The step vocabulary: clicking, dragging, waiting, setting subjects and languages
- How `screenshot_compare` works and where the reference images come from
- Running tests in the Editor and from the CLI

## Walkthrough

### 1. The test root

```xml
<test>
	<view extends="screen_layouts"> ... </view>
	<steps> ... </steps>
</test>
```

A test is XML like everything else: a `<view>` describing what to run against, and
`<steps>` describing what to do to it.

### 2. The view

```xml
<view extends="screen_layouts">
	<lv_label translation_tag="dog" align="center" />
	<lv_slider bind_value="subject_volume" align="center" y="40" x="20" />
</view>
```

`extends="screen_layouts"` reuses the screen from `../layout` as it is, so the test does
not duplicate the UI. The two widgets written inside are added on top of it, which is
how a test can set up the extra state it needs, here a translated label and a bound
slider to exercise language switching and subjects.

### 3. Establishing a known state

```xml
<set_language name="en" />
<subject_set subject="subject_volume" value="30" />
<wait ms="200" />
<screenshot_compare path="start.png" />
```

A test starts by pinning down everything that could drift: language, subject values,
anything else that has a default it would rather not depend on. `<wait ms="200" />`
lets the screen's open animations settle, since comparing a screenshot mid-animation is
the classic flaky test.

### 4. Interacting

```xml
<!-- by coordinate -->
<click_at x="20" y="125" />
<wait ms="500" />
<screenshot_compare path="checkbox_1.png" />

<!-- by name -->
<click_on name="lv_checkbox_5" />
<wait ms="500" />
<screenshot_compare path="checkbox_2.png" />
```

`click_at` takes display coordinates. `click_on` takes a widget `name`, which survives a
layout change and is the more durable of the two. `lv_checkbox_5` is the auto-assigned
name from `screen_layouts`; giving a widget an explicit `name` makes the test easier to
read.

A drag is spelled out from primitives:

```xml
<move_to x="430" y="176" />
<press />
<wait ms="100" />
<move_to x="430" y="136" />
<wait ms="100" />
<release />
<wait ms="500" />
<screenshot_compare path="scroll.png" />
```

`move_to`, `press`, `release` map onto the pointer events, and the intermediate
`move_to` between press and release is what makes LVGL read it as a scroll gesture
rather than a click. The waits give the scroll momentum time to finish.

### 5. Driving the UI from outside

```xml
<set_language name="de" />
<screenshot_compare path="german.png" />

<subject_set subject="subject_volume" value="50" />
<screenshot_compare path="half_volume.png" />
```

`set_language` and `subject_set` change state the way the application would, without
touching the input device. No `wait` is needed here because neither triggers an
animation.

`subject_compare` is the read side, for asserting that an interaction produced the
expected value:

```xml
<subject_compare subject="subject_volume" value="50" />
```

### 6. Screenshots

`screenshot_compare` renders the current display and compares it against the PNG at
`path`, relative to the test file. This folder holds the six references: `start.png`,
`checkbox_1.png`, `checkbox_2.png`, `scroll.png`, `german.png`, `half_volume.png`.

If the reference does not exist yet, the run saves the current frame as the new
reference. That is also the way to update a test after an intentional UI change: delete
the affected PNG, run once, and inspect the new image before committing it. A failing
comparison means either a regression or a stale reference, and looking at the image is
how you tell which.

Screenshot tests are sensitive to fonts, animation timing and anti-aliasing, so keep the
waits generous and pin every input the test depends on.

### 7. Running

In the Editor, use the **Tests** panel under the preview.

From the command line, with the CLI installed and `LVGLPRO_CLI_TOKEN` set:

```bash
lvglpro run-all-tests .
```

This is the form that belongs in CI. `lvglpro validate .` is worth running next to it,
since it catches invalid XML without rendering anything.

## Try it

1. Run the test from the **Tests** panel and watch it drive the screen.
2. Change a color in `../layout` and run again. Several comparisons fail, which is the
   test doing its job.
3. Delete `german.png` and run once to regenerate it.
4. Add `<subject_compare subject="subject_volume" value="50" />` at the end.
5. Give a checkbox in `screen_layouts` an explicit `name` and click it with `click_on`
   instead of `click_at`.
6. Remove a `<wait ms="500" />` and see whether the comparison after it becomes flaky.
7. Write a second test file against `screen_data_bindings` that presses a `round_button`
   and asserts the subject with `subject_compare`.

## Common mistakes

- Comparing a screenshot before an animation has finished.
- Committing a regenerated PNG without looking at it, which locks in the bug.
- Depending on the default language or a subject's initial value instead of setting both
  at the start.
- `click_at` coordinates that a layout change silently invalidates.
- A drag written as `press` then `release` with no `move_to` in between, which LVGL reads
  as a click.

## Next

Back to the [project README](../../README.md), or straight to the
[docs](https://lvgl.io/docs/pro).

## Reference

- [Testing](https://lvgl.io/docs/pro/syntax/testing)
- [CLI](https://lvgl.io/docs/pro/cli)
