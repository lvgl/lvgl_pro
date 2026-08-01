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

## Learn more

Check out the docs at **<https://lvgl.io/docs/pro>**. These are the key pages to learn XML:

- [XML overview](https://lvgl.io/docs/pro/syntax/overview): Basics of the syntax
- [Components](https://lvgl.io/docs/pro/syntax/components), [Widgets](https://lvgl.io/docs/pro/syntax/widgets) and [Screens](https://lvgl.io/docs/pro/syntax/screens): The basic building blocks of a UI
- [Built-in widgets](https://lvgl.io/docs/pro/built_in_widgets): the XML API of `lv_obj`, `lv_button`, `lv_slider`, etc, and all the style properties
- [Styles](https://lvgl.io/docs/pro/syntax/styles) and [Constants](https://lvgl.io/docs/pro/syntax/constants): To make UIs more maintainable
- [Data binding](https://lvgl.io/docs/pro/syntax/data-binding): Connect the UI to your application data
- [Testing](https://lvgl.io/docs/pro/syntax/testing) and the [CLI](https://lvgl.io/docs/pro/cli): To validate your work automatically
- [AI integration](https://lvgl.io/docs/pro/ai): For agents to learn how to work effectively with LVGL Pro and the XML

This project is on GitHub too, in the [**lvgl/lvgl_pro**](https://github.com/lvgl/lvgl_pro) repository,
together with [130+ small examples](https://github.com/lvgl/lvgl_pro/tree/master/examples/lvgl_open), the
[project templates](https://github.com/lvgl/lvgl_pro/tree/master/templates), and
[`lvgl_widgets_xml/`](https://github.com/lvgl/lvgl_pro/tree/master/lvgl_widgets_xml) with the XML schema of
LVGL's built-in widgets. Both humans and agents can check exactly which properties, enums, styles, and other
elements are available. See
[lv_slider.xml](https://github.com/lvgl/lvgl_pro/blob/master/lvgl_widgets_xml/v9.5.0/lv_slider.xml) as an
example. AI agents can clone the whole repo or get only one file.
