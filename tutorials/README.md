# LVGL Pro — Tutorial Project

A hands-on tutorial project for getting started with **LVGL Pro Editor**.
Each screen demonstrates one core concept. Open them, read the XML, tweak things, and
watch the result live in the built-in simulator.

## Where to start

Open **`screens/hello_world/screen_hello_world.xml`** first. It's the smallest possible
UI (a styled screen with a button and a label). Once it makes sense, work through the
other screens:

- `hello_world` — the minimal screen, styles and widgets
- `styles` — defining and reusing styles
- `layout` — flex / grid layouts
- `animations` — animating properties
- `assets` — images and fonts
- `data_bindings` — subjects and binding UI to data
- `translations` — multi-language text
- `new_component` — building a reusable component from XML
- `new_widget` — a custom widget backed by hand-written C code (see `widgets/wd_segment`)
- `testing` — writing UI tests

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
