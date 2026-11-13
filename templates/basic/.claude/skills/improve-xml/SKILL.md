---
name: improve-xml
description: Audit an existing LVGL Pro XML project and improve it on request - constants and styles instead of raw values, components for repeated markup, current syntax instead of legacy, comments, tests, and smaller images and fonts. Lists the findings first and changes only what the user selects. Use when the user asks to clean up, refactor, optimize, review, or add tests to XML.
---

# Improve XML

Read `AGENTS.md` at the project root first, if it is not in your context. Follow its
"Working with the user" rules.

The UI must look and work the same after the change, unless the user asks for a
different result. Screenshot tests check this: one for each screen on each target.

## Steps

Show this checklist to the user and keep it up to date.

1. Take the "before" state
2. Audit
3. The user selects
4. Change
5. Compare with "before"
6. Report

### 1. Take the "before" state

```bash
lvglpro validate . --errorlimit 25
lvglpro generate .
lvglpro compile .
lvglpro run-all-tests .
```

If `validate`, `compile`, or the tests fail now, tell the user before you change anything.

Then write a screenshot test for each screen on each target in `project.xml`:

```xml
<test>
    <view extends="<screen>"/>
    <steps>
        <wait ms="300"/>
        <screenshot_compare path="<screen>.png"/>
    </steps>
</test>
```

- First target: `tests/<screen>.xml`. These tests stay in the project. Skip a screen that
  already has a screenshot test.
- Each other target: `improve_check/<target>/<screen>.xml`. `run-all-tests` runs every test
  in `tests/` on one target, so these stay out of `tests/`. Delete the folder in step 5.

Run each new test once. The first run saves the reference images: the "before" state.

```bash
lvglpro run-test . tests/<screen>.xml
lvglpro run-test . improve_check/<target>/<screen>.xml --target <target>
```

### 2. Audit

Read `project.xml`, `globals.xml`, and all the XML files. Look for:

| Area | Finding |
| --- | --- |
| Tokens | Raw colors, sizes, and radii in views and styles. A constant may already exist in `globals.xml` |
| Styles | The same local style properties on many widgets. Make a named style |
| Components | Repeated markup. A `<view>` deeper than about three levels. A component that does two things |
| Syntax | `$prop`, `#const`, `bind_*`, `subject_*_event` (see "Legacy elements" in `AGENTS.md`). Only if `lvgl_version` is 9.6 or newer, and the Editor and the CLI (`lvglpro --version`) are v2.1 or newer. Below that an expression is computed only once, so the legacy form is the correct one |
| Behavior | `<event_cb>` that a subject and `set_subject_event` or a binding can replace |
| API | A `<prop>` with no `help`. An optional `<prop>` with no `default`: a prop with no `default` must be set on every instance, so do not add one to a prop that is required on purpose. A component with no `<previews>` |
| Names | Names that do not follow the naming table in `AGENTS.md`. A `name="..."` that nothing uses |
| Comments | Large blocks with no comment. Comments that repeat the line |
| Tests | Flows and components with no test in `tests/` |
| Images | A PNG larger than the size it is shown at: scale it with `<convert>`. `argb8888` on an image with no transparency: `rgb565` is half the size. `rgb565` on an image with transparency: it makes every pixel opaque. Images that nothing uses |
| Fonts | A `range` wider than the text needs: check the text in the XML and `translations.xml`. Sizes that are almost the same (15 and 16). `bpp` higher than needed. Fonts that nothing uses |

To check the PNG sizes, in subfolders too: `find images -name '*.png' -exec file {} +`.
Compare each with the `width` and `height` where the image is used.

### 3. The user selects

Show the findings as one numbered list. For each one: what, where (file and line), the
gain, and the effort (small, medium, large). Group them by area. Ask which numbers to do.

### 4. Change

Do one finding at a time. After each one, run `lvglpro validate .`, `lvglpro generate .`,
and the screenshot tests, so you know which change made a difference. Do not change what
the user did not select. A renamed constant, subject, or component changes the exported
C names: tell the user, because the application C code may use them.

### 5. Compare with "before"

```bash
lvglpro generate .
lvglpro compile .
lvglpro run-all-tests .
lvglpro run-test . improve_check/<target>/<screen>.xml --target <target>
```

A failed `screenshot_compare` saves the new image next to the reference, with an `_err`
suffix. Look at both, and tell the user if the change was not intended. Smaller fonts and
image formats can change pixels a little; say so. Then delete `improve_check/`.

### 6. Report

- The findings done, and the ones left.
- The C names that changed.
- The screenshot tests added to `tests/`, and the test results on each target.
- What is not verified.
