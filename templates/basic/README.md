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
lved run-all-tests .
lved run-test . tests/test_slider_drag.xml
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

## Docs

Full documentation: **<https://lvgl.io/docs/pro>**
