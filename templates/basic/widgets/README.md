# Widgets

Widgets are the low-level building blocks of UIs. Custom widgets and LVGL's
own built-in widgets (`lv_slider`, `lv_label`, …) are always compiled
into the application as C code. Once compiled (using the hammer icon or `Ctrl+B`),
widgets can be used in components and screens.

Use them when you need custom or complex logic and a rich `set`/`get`/`add`
API that goes beyond what a pure-XML component can express. Create one folder per
widget here and place an XML file with a `<widget>` root tag inside it.

Unlike components, widgets cannot be instantiated directly from XML at runtime:
each widget also needs a C XML parser that maps its XML attributes to C function
calls (LVGL's built-in widgets already ship with theirs). The `<widget>` XML
defines the structure, API, styles, and previews the Editor uses for validation
and autocomplete.

```xml
<!-- my_gauge/my_gauge.xml -->
<widget>
  <api>
    <prop name="value" type="int" default="0"/>
  </api>
  <view extends="lv_arc">
    <lv_label name="value_label" text="0"/>
  </view>
</widget>
```

Docs: https://lvgl.io/docs/pro/syntax/widgets
