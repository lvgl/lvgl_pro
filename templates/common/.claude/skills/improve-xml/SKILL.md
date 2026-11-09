---
name: improve-xml
description: Audit an existing LVGL Pro XML project and improve it on request - constants and styles instead of raw values, components for repeated markup, current syntax instead of legacy, comments, tests, and smaller images and fonts. Lists the findings first and changes only what the user selects. Use when the user asks to clean up, refactor, optimize, review, or add tests to XML.
---

# Improve XML

Read `AGENTS.md` at the project root first, if it is not in your context. Follow its
"Working with the user" rules.

The UI must look and work the same after the change, unless the user asks for a
different result.

<!-- TODO: when run-test/run-all-tests can select a target, replace the screenshot
     before/after steps with screenshot_compare tests per screen and target, rerun
     after each change, and keep the tests in the project. -->

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
lvglpro screenshot . screens/<screen>.xml --out /tmp/before/<target>_<screen>.png --target <target>
lvglpro run-all-tests .
```

Screenshot every screen on every target in `project.xml`. If `validate` or the tests
fail now, tell the user before you change anything.

### 2. Audit

Read `project.xml`, `globals.xml`, and all the XML files. Look for:

| Area | Finding |
| --- | --- |
| Tokens | Raw colors, sizes, and radii in views and styles. A constant may already exist in `globals.xml` |
| Styles | The same local style properties on many widgets. Make a named style |
| Components | Repeated markup. A `<view>` deeper than about three levels. A component that does two things |
| Syntax | `$prop`, `#const`, `bind_*`, `subject_*_event` (see "Legacy elements" in `AGENTS.md`). Only if `lvgl_version` is 9.6 or newer |
| Behavior | `<event_cb>` that a subject and `set_subject_event` or a binding can replace |
| API | A `<prop>` with no `help`, or no `default`. A component with no `<previews>` |
| Names | Names that do not follow the naming table in `AGENTS.md`. A `name="..."` that nothing uses |
| Comments | Large blocks with no comment. Comments that repeat the line |
| Tests | Flows and components with no test in `tests/` |
| Images | A PNG larger than the size it is shown at: scale it with `<convert>`. `argb8888` on an image with no transparency: `rgb565` is half the size. A `<convert>` without `color_format`: the default is `rgb565`, which makes every pixel opaque. Images that nothing uses |
| Fonts | A `range` wider than the text needs: check the text in the XML and `translations.xml`. Sizes that are almost the same (15 and 16). `bpp` higher than needed. Fonts that nothing uses |

To check a PNG size: `file images/*.png`. Compare it with the `width` and `height` where
the image is used.

### 3. The user selects

Show the findings as one numbered list. For each one: what, where (file and line), the
gain, and the effort (small, medium, large). Group them by area. Ask which numbers to do.

### 4. Change

Do one finding at a time. After each one, run `lvglpro validate .`. Do not change what
the user did not select. A renamed constant, subject, or component changes the exported
C names: tell the user, because the application C code may use them.

### 5. Compare with "before"

```bash
lvglpro generate .
lvglpro compile .
lvglpro screenshot . screens/<screen>.xml --out /tmp/after/<target>_<screen>.png --target <target>
lvglpro run-all-tests .
```

Compare each "after" image with its "before" image (`cmp` is enough for equal files). If
two images differ, look at both, and tell the user if the change was not intended.
Smaller fonts and image formats can change pixels a little; say so.

### 6. Report

- The findings done, and the ones left.
- The C names that changed.
- The screenshot comparison and the test result.
- What is not verified.
