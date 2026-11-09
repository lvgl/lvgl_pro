---
name: idea-to-xml
description: Design and build an LVGL Pro XML UI from a text description or an idea. Asks the needed questions, writes the goal and spec into README.md for approval, then builds tokens, components, screens, and tests. Use when the user describes a UI or product in words and wants it created.
---

# Idea to XML

Read `AGENTS.md` at the project root first, if it is not in your context. Follow its
"Working with the user" rules.

The spec in `README.md` is the contract. Build nothing before the user approves it.

## Steps

Show this checklist to the user and keep it up to date.

1. Ask
2. Write the goal and spec in `README.md`
3. Get approval
4. Set up `project.xml` and `globals.xml`
5. Build the components, then the screens
6. Add tests
7. Report

### 1. Ask

Read `README.md`, `project.xml`, and `globals.xml` first. Do not ask what is already
there. Then ask what is missing, in one message, with a proposed answer for each:

- What is the product, and who uses it?
- The display size and the input: touch, buttons, or an encoder.
- The screens, and how the user moves between them.
- The data: which values come from the application (a temperature, a battery level),
  and which the user sets (a brightness, a mode).
- The look: light or dark, the main color, a reference product or image.

If the user says "you decide", decide, and write the choice in the spec. Use the
sources below, and show the user what you picked.

### Where to get fonts, images, and ideas

Use what the project and the user already have first: `fonts/`, `images/`, a brand guide.
Then propose sources from this list. Ask before you download anything. Check the
license of each asset, put the license file next to it, and write the source in the
spec.

| Need | Sources |
| --- | --- |
| Fonts | [Google Fonts](https://fonts.google.com): Inter, Roboto, Montserrat. For Chinese, Japanese, or Korean: Noto Sans. `templates/basic` in [lvgl/lvgl_pro](https://github.com/lvgl/lvgl_pro) ships Montserrat |
| Icon fonts | [Font Awesome](https://fontawesome.com) (free set), as in `templates/basic` |
| Icons (SVG) | [Lucide](https://lucide.dev), [Feather](https://feathericons.com), [Heroicons](https://heroicons.com), [Material Symbols](https://fonts.google.com/icons). Convert with `<convert ... color_format="argb8888"/>`. Many use `currentColor`: see [Images](https://lvgl.io/docs/pro/syntax/images) |
| Photos | [Unsplash](https://unsplash.com), [Pexels](https://www.pexels.com). Scale them down with `<convert>` to the size they are shown at |
| LVGL UIs | `examples/`, `tutorials/`, and `templates/basic/` in [lvgl/lvgl_pro](https://github.com/lvgl/lvgl_pro). The `widgets` and `music` demos in [lvgl/lvgl](https://github.com/lvgl/lvgl/tree/master/demos) |
| Inspiration | [Dribbble](https://dribbble.com), [Behance](https://www.behance.net), [Figma Community](https://www.figma.com/community), [Mobbin](https://mobbin.com). Search for the product type, for example "thermostat UI" or "smartwatch dashboard" |

### 2. Write the goal and spec in `README.md`

Add a `## Goal` and a `## Spec` section near the top of `README.md`. Keep the rest of the
file.

- **Goal:** two or three sentences: the product, the user, the main task.
- **Spec:**
  - The screens: name, purpose, main content.
  - The flow: from screen, to screen, the trigger.
  - The components, and where each one is used.
  - The subjects: name, type, range, who writes it (UI or application).
  - Open questions.

Tokens (colors, spacing, fonts) are not in the spec: they go in `globals.xml`. The
display size goes in `project.xml`.

### 3. Get approval

Show the spec. Ask the user to approve or correct it. Repeat until it is approved.

### 4. Set up `project.xml` and `globals.xml`

- `project.xml`: the display size.
- `globals.xml`: the tokens as `<consts>`, the shared `<styles>`, the `<fonts>`, the
  `<images>`, and the `<subjects>` from the spec.

### 5. Build the components, then the screens

Build from small to large. For each file:

1. Write it. Use the tokens and subjects; no raw colors or sizes in a view.
2. `lvglpro validate . --errorlimit 25`
3. For a screen: `lvglpro generate .` and `lvglpro compile .`, then
   `lvglpro screenshot . screens/<screen>.xml --out /tmp/<screen>.png --delay 300`.
   Look at the image. Check sizes, alignment, and that nothing is clipped.

Show the user the first screen before you build the others. A wrong style is cheaper to
fix on one screen than on all of them.

Use subjects and XML events for the flow. Use `<event_cb>` only when C must run.

### 6. Add tests

Write one test in `tests/` for each flow in the spec: set the subjects, click, compare
the subjects, and take a `screenshot_compare`. Then:

```bash
lvglpro generate .
lvglpro run-all-tests .
```

The first run creates the reference screenshots. Look at them before you accept them.

### 7. Report

- The screens, components, subjects, and tests created.
- The `<event_cb>` callbacks the application must implement in C.
- The open questions from the spec.
- What is not verified.
