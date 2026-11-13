---
name: image-to-xml
description: Build LVGL Pro XML screens and components from an image of a UI (a screenshot, a mockup, a photo, or a sketch), then compare the rendered result with the image until they match. Use when the user gives one or more UI images and wants XML from them.
---

# Image to XML

Read `AGENTS.md` at the project root first, if it is not in your context. Follow its
"Working with the user" rules.

## Steps

Show this checklist to the user and keep it up to date.

1. Ask
2. List what the image contains
3. Write the goal and spec in `README.md`
4. Set up `project.xml` and `globals.xml`
5. Build the components, then the screens
6. Compare with the image
7. Report

### 1. Ask

Ask in one message:

- Is it one screen, or several screens of one flow? In which order?
- The display size. If the image has another size, the layout is scaled.
- The target in `project.xml` that the image is for, if there are several.
- What must work, not only look right: buttons, sliders, screen changes, live values.
- The input: touch, buttons, or an encoder.
- The fonts and icons. Ask for the TTF and the icon files (SVG or PNG), and the
  original photos and logos. Without them, find the closest free font and icon set
  with the scripts in [recipes.md](recipes.md), and say which ones you picked.

### 2. List what the image contains

Measure the image, do not guess pixel values from it. [recipes.md](recipes.md) has the
steps and scripts: scale, layout tree, colors, fonts, icons, photos. Then write a list:

- **Tokens:** colors, spacing, corner radii, font sizes. Round them to a small scale
  (for example spacing 4, 8, 12, 16, 24). Do not make a token for each pixel value.
- **Components:** blocks that repeat or have a clear role: a list row, a card, a tab
  bar, a header.
- **Widgets:** for each element, the LVGL widget it is: `lv_button`, `lv_slider`,
  `lv_switch`, `lv_arc`, `lv_chart`, and so on. Check the schema before you choose.
- **Layout:** rows and columns (flex), or a grid.
- **Data:** the values that change at runtime. Each one becomes a subject.

Show the list and ask the user to confirm or correct it. This is the cheapest point to
fix a wrong reading.

### 3. Write the goal and spec in `README.md`

Add a `## Goal` and a `## Spec` section near the top of `README.md`. Keep the rest of the
file. The spec holds: the source images, the screens and the flow between them, the
components, and the subjects with their type and who writes them (UI or application).
Tokens are not in the spec: they go in `globals.xml`.

Later sessions read this section first. Update it when the UI changes.

### 4. Set up `project.xml` and `globals.xml`

- `project.xml`: the display size.
- `globals.xml`: the tokens as `<consts>`, the `<fonts>`, the `<subjects>`, the
  `<images>`, and the shared `<styles>`, in this order: `validate` rejects `<styles>`
  before `<fonts>` or `<images>`. Keep the names that are already there.

### 5. Build the components, then the screens

Build from small to large. For each file:

1. Write it. Use the tokens. A raw color or size in a view is correct only for a value
   that is used once.
2. `lvglpro validate . --errorlimit 25`
3. For a screen: `lvglpro generate .` and `lvglpro compile .`, then
   `lvglpro screenshot . screens/<screen>.xml --target <target> --out /tmp/<screen>.png --delay 300`.
   A component screenshot renders at the display size, so check components inside a
   screen.

Lay out with flex or grid, not with `x` and `y`. Then the UI survives a font change and
a new display size.

### 6. Compare with the image

Measure both images with `layout.py` and move each item by the difference. Then run
`compare.py` and look at its output image. See "Check and correct" in
[recipes.md](recipes.md). List the differences: size, position, spacing, color, font
size, missing parts. Fix them and screenshot again.

Stop after 3 rounds and show the remaining differences to the user. Ask whether to
continue. Small differences in fonts and anti-aliasing are normal.

### 7. Report

- The screens, components, subjects, and tokens created.
- The placeholders and `TODO`s: fonts, icons, behavior.
- The differences that remain.
- What is not verified.
