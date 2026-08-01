# Components

Components are the main reusable building blocks of an XML UI. Each `.xml` file
in this folder defines one component with a `<component>` root tag, and the file
name becomes the component's name (e.g. `my_button.xml` → `<my_button>`). They
are built purely from widgets and other components — no C code — yet they can
carry their own styles, constants, data bindings, animations, and a small `api`
of properties forwarded to their children.

Components can be exported to C (one `<name>_create()` function each) or loaded
from XML at runtime. Reference a component anywhere in another component's,
screen's, or widget's `<view>` simply by using its file name as a tag.

```xml
<!-- my_button.xml -->
<component>
  <api>
    <prop name="label" type="string" default="OK"/>
  </api>
  <styles>
    <style name="rounded" radius="8" bg_color="0x2196f3" text_color="0xffffff"/>
  </styles>
  <view extends="lv_button" flex_flow="row">
    <style name="rounded"/>
    <lv_label text="$label"/>
  </view>
</component>
```

Docs: https://lvgl.io/docs/pro/syntax/components
