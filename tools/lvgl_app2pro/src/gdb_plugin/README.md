# gdb_plugin

A copy of LVGL's GDB plugin, `lvglgdb`, taken from
[lvgl/lvgl](https://github.com/lvgl/lvgl) master (`scripts/gdb`).

`lvgl_app2pro` reads a running application through this plugin, and relies on
parts of it that are newer than any LVGL release, so the copy is kept here
rather than depending on whatever version happens to be installed.

Keeping it here is also what lets the tool convert an application built with an
older LVGL: the plugin reads the *application's* debug info, so a newer plugin
against an older binary is fine and is the normal case.

- `lvglgdb/` — the plugin itself
- `generators/` — regenerate the constant tables from LVGL headers
- `gdbinit.py` — what you would `source` to use the plugin by hand

To use a different copy instead, pass `--lvgl <path to an lvgl checkout>` and
its `scripts/gdb` is used.

## Updating

Copy `scripts/gdb` from an LVGL checkout over this directory, then run the
tests: `python3 tests/test.py`. Anything the converter depends on that changed
upstream shows up there.
