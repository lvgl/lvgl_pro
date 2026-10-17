# lv_demo_widgets

LVGL's widgets demo in an SDL window: something real to point the converter at.

```bash
cmake -B build
cmake --build build -j
```

That fetches LVGL, generates `lv_conf.h` from `lv_conf.defaults`, and builds
`build/lv_demo_widgets`. Nothing has to be installed first except a compiler,
CMake and SDL2.

Then, from `tools/lvgl_app2pro`:

```bash
python3 -m lvgl_app2pro examples/lv_demo_widgets/build/lv_demo_widgets -o widgets_demo
```

Run the binary on its own to see what is being converted:

```bash
./build/lv_demo_widgets
```

## Notes

`-g` is forced on, LVGL included. The converter reads the application's debug
info, and without symbols in LVGL itself it cannot find anything.

LVGL v9.5.0 is used, matching the widget schemas in `lvgl_widgets_xml/`. To try
another:

```bash
cmake -B build -DLVGL_TAG=master
```
