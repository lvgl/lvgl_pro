# LVGL Pro Empty Project

A clean **LVGL Pro** project with nothing in it yet. Everything is set up, so you can
start adding your own screens and components right away.

## What's inside

- `project.xml`: Display targets and the LVGL version to build against
- `globals.xml`: The place for project-wide constants, colors, fonts, styles, and subjects
- `screens/`, `components/`, `widgets/`: Your UI files, one per XML file. Each folder has a
  README describing what belongs in it
- `images/`, `fonts/`: Assets, converted and compiled in by the Editor
- `sim/`: The built-in simulator, see [`sim/README.md`](sim/README.md)

## Where to start

Create your first screen in `screens/` (e.g. `screens/home.xml` with a `<screen>` root tag)
and watch it render live in the preview. **Ctrl+B** or the hammer icon exports the C code and
compiles it, **F5** runs it in the simulator.

If you would rather start from something that already works, create a project from the
**basic** template, or from any of the examples and tutorials on the Editor's launch screen.

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
