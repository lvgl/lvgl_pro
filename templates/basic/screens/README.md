# Screens

Screens are the top-level containers for complete UI views. Each `.xml` file here
defines one screen with a `<screen>` root tag, and the file name becomes the
screen's name. They work much like components — built from widgets and
components, with their own `consts`, `styles`, and `view` — but they take no `api`
parameters and are always created as-is. Navigate between them with
`<screen_load_event>` / `<screen_create_event>` triggers, and mark a screen
`permanent="true"` to keep its state in memory across transitions.

Screens are previewed against the display targets defined in `project.xml`, so
you can verify responsive layouts across resolutions. When exported, each screen
generates a `<name>_create()` function.

```xml
<!-- home.xml -->
<screen>
  <view flex_flow="column">
    <my_header label="Main menu"/>
    <lv_button>
      <lv_label text="Settings"/>
      <screen_load_event screen="settings" trigger="clicked" anim_type="fade"/>
    </lv_button>
  </view>
</screen>
```

Docs: https://lvgl.io/docs/pro/syntax/screens
