# LVGL Pro — Project Template

A ready-to-use starting point for a new **LVGL Pro** project. Instead of an empty
folder, you get a small **design system**, a set of reusable **components**, and an
example screen — already wired up so you can start building your own UI right away.

Target display: **480 × 320**, `lvgl_version` 9.5.0.

## What's inside

- `globals.xml` — the design system: spacing/shape constants, colors, fonts, styles,
  and the subjects the UI binds to (theme, brightness, …)
- `components/` — thin, reusable wrappers with a minimal API:
  - `layout/` — `base_box`, `container`, `panel`, `row`, `column`
  - `typography/` — `h1`…`h5`, `text`
  - `controls/` — `button`, `slider`, `arc`, `bar`, `switch`, `checkbox`,
    `dropdown`, `text_input`, `text_box`, `keyboard`
  - `list/` — `list`, `list_item`, `list_section`, `list_separator`
- `screens/` — `screen_components`, a demo screen showing the components in use
- `tests/` — two example UI tests; see [`tests/README.md`](tests/README.md)
- `fonts/` — Montserrat (Regular/Medium/SemiBold/Bold), compiled in
- `images/icons/` — Lucide icons as **SVG**, rasterized to size by `<convert>`;
  see [`images/icons/README.md`](images/icons/README.md)

## Where to start

Open **`screens/screen_components.xml`** to see the components in action, then look at
**`globals.xml`** to understand the design system everything is built on. Edit the XML,
add your own screens and components, and watch the result live in the built-in simulator.

## Testing

Tests are XML files named `test*.xml`. Run them headlessly — no Editor needed,
which is what makes them useful in CI and for AI agents:

```bash
lvglpro run-all-tests .
lvglpro run-test . tests/test_slider_drag.xml
```

See [`tests/README.md`](tests/README.md) for the step reference and the
gotchas worth knowing before you write your own.

## Export, Compile, Run

- **Ctrl+B or Hammer icon** exports C code from XML and recompiles the custom C code. The first time, the Editor installs
  **emsdk** to compile your C to **WASM** that the Editor can run in the preview. The exported C code is ready
  to be integrated in your application. See the [Integration guide](https://lvgl.io/docs/pro/integration/using-exported-c-code)

- **F5** (or **Run / Start Debugging**) launches the built-in simulator in a new window so you can
  run and debug the C code. See [`sim/README.md`](sim/README.md) for how the simulator works and how
  to build it from the command line.

## Design mode

Switch to **Design mode** from the top header to lay out screens visually with
**drag-and-drop** editing instead of writing XML by hand.

## Learn more

Check out the docs at **<https://lvgl.io/docs/pro>**. These are the key pages to learn XML:

- [XML overview](https://lvgl.io/docs/pro/syntax/overview): Basics of the syntax
- [Components](https://lvgl.io/docs/pro/syntax/components), [Widgets](https://lvgl.io/docs/pro/syntax/widgets) and [Screens](https://lvgl.io/docs/pro/syntax/screens): The basic building blocks of a UI
- [Built-in widgets](https://lvgl.io/docs/pro/built_in_widgets): the XML API of `lv_obj`, `lv_button`, `lv_slider`, etc, and all the style properties
- [Styles](https://lvgl.io/docs/pro/syntax/styles) and [Constants](https://lvgl.io/docs/pro/syntax/constants): To make UIs more maintainable
- [Data binding](https://lvgl.io/docs/pro/syntax/data-binding): Connect the UI to your application data
- [Testing](https://lvgl.io/docs/pro/syntax/testing) and the [CLI](https://lvgl.io/docs/pro/cli): To validate your work automatically
- [AI integration](https://lvgl.io/docs/pro/ai): For agents to learn how to work effectively with LVGL Pro and the XML

The [**lvgl/lvgl_pro**](https://github.com/lvgl/lvgl_pro) repository is also worth checking. It contains examples, tutorials, and 
[`lvgl_widgets_xml/`](https://github.com/lvgl/lvgl_pro/tree/master/lvgl_widgets_xml) with the XML schema of LVGL's built-in widgets. 
Both humans and agents can check exactly which properties, enums, styles, and other elements are available. See
[lv_slider.xml](https://github.com/lvgl/lvgl_pro/blob/master/lvgl_widgets_xml/v9.5.0/lv_slider.xml) as an example. 
AI agents can clone the whole repo or get only one file.


