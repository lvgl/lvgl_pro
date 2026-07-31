# Tests

Headless UI tests written in XML. Full reference:
<https://lvgl.io/docs/pro/syntax/testing>.

```bash
lved run-all-tests .                        # every test in the project
lved run-test . tests/test_slider_drag.xml  # just one
lved run-all-tests . --slowdown 5           # slow it down to watch it
```

Any file named `test*.xml` anywhere in the project is picked up by
`run-all-tests`, so the folder name doesn't matter — the **filename prefix**
does. `test_theme_toggle.xml` is found; `theme_toggle_test.xml` is not.

## Structure

A test file is a component with a `<steps>` block appended:

```xml
<test width="480" height="320">
  <view ... />      <!-- same syntax as a <component> view -->
  <steps> ... </steps>
</test>
```

The two tests here show the two useful shapes:

- **`test_theme_toggle.xml`** — `<view extends="screen_components" />` drives the
  real screen. Use this for integration-level checks.
- **`test_slider_drag.xml`** — builds its own small view, so the test doesn't
  break when a screen gets rearranged. Use this for one component.

## Steps

| Step | Notes |
| --- | --- |
| `<move_to x y />` | Moves the input position only |
| `<click_at x y />` | Press + release at a point |
| `<press />` / `<release />` | At the current position |
| `<wait ms />` | LVGL keeps running — animations and timers advance |
| `<freeze ms />` | Pauses LVGL's clock; for debugging |
| `<subject_set subject value />` | Int or string |
| `<subject_compare subject value />` | Equality only — no `>` / `<` |
| `<screenshot_compare path />` | See the caveat below |

## Things that will bite you

**Give pointer steps their own `wait`.** `move_to` updates the input position;
LVGL only reads it on the next tick. `move_to` immediately followed by `press`
registers the press at the *previous* position and the interaction silently does
nothing — the test still passes every other step, so it looks fine.

**`subject_compare` is equality-only.** Assert on clamped endpoints rather than
mid-range positions: drag past the end of a slider and compare against
`max_value`, which is exact regardless of knob width or aim.

**Pin your subjects first.** Every test here starts with `subject_set` for
anything it asserts on, so changing a default in `globals.xml` can't quietly
change what the test means.

**`screenshot_compare` does not currently fail under the CLI.** The reference
images next to this file are never copied into the runtime's virtual
filesystem, so each run recreates them from the frame it just rendered and
always reports success — replacing a reference with a completely different image
still passes. Treat the image steps here as documentation of the syntax, not as
working regression coverage, and rely on `subject_compare` for assertions that
must hold. Also note that `path` is flattened to its basename (a `path="imgs/a.png"`
becomes `a.png` beside the test file), so subfolders don't work.

**`<test width=… height=…>` doesn't resize the canvas here.** Both tests render
at the `project.xml` display size (480×320) regardless, which is why the
coordinates in `test_slider_drag.xml` assume that size.
