# All LVGL Open XML examples in one project

Every example from the LVGL documentation, as XML, in a single project. Open any screen under
`screens/` and it renders live in the preview. The examples are grouped by topic:

- `screens/widgets/`: One folder per built-in widget, from `lv_arc` to `lv_textarea`
- `screens/layouts/`: Flex and grid
- `screens/styles/`: Styles and style properties
- `screens/scroll/`: Scrolling behavior
- `screens/libs/`: Optional libraries

Each example is small on purpose, so it is a good place to copy a working snippet from. The same
examples are also in the [LVGL docs](https://lvgl.io/docs/open/examples) next to their C equivalents,
and you can run them in the browser in the [Online Viewer](https://viewer.lvgl.io).

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
together with the [tutorials](https://github.com/lvgl/lvgl_pro/tree/master/tutorials), the
[project templates](https://github.com/lvgl/lvgl_pro/tree/master/templates), and
[`lvgl_widgets_xml/`](https://github.com/lvgl/lvgl_pro/tree/master/lvgl_widgets_xml) with the XML schema of
LVGL's built-in widgets. Both humans and agents can check exactly which properties, enums, styles, and other
elements are available. See
[lv_slider.xml](https://github.com/lvgl/lvgl_pro/blob/master/lvgl_widgets_xml/v9.5.0/lv_slider.xml) as an
example. AI agents can clone the whole repo or get only one file.
