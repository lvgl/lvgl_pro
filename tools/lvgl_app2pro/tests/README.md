# Tests

```bash
python3 tests/test.py            # build the example, convert it, compare
python3 tests/test.py build      # fetch LVGL and build the example
python3 tests/test.py convert    # run the converter on the built app
python3 tests/test.py compare    # check the output against reference/
python3 tests/test.py --update   # accept the current output as the reference
```

`build` fetches LVGL itself, so the only prerequisites are a compiler, CMake,
SDL2 and GDB. Everything it produces goes in `.work/`, which is not committed.

| | |
| --- | --- |
| `test.py` | The whole pipeline: build, convert, compare |
| `test_convert.py` | Units, on dumps built in memory; run by `test.py` |
| `example_ui/` | A small C app written to exercise the hard parts of converting |
| `reference/project/` | The XML the conversion is expected to produce |

## The example UI

`example_ui/example_ui.c` is not meant to look good. It exists to cover what is
hard to convert:

- widgets whose XML form is an `<element>`: tabview tabs, chart series
- a container that calls `lv_obj_remove_style_all()` and *then* sets local
  styles, which is the opposite of the order XML applies them in
- a bar with one part's styles removed
- shared styles, two of them applied with a selector (a pressed state, and the
  slider's knob and indicator)
- states and object flags set from code
- a roller, whose options live in an internal label rather than its own struct
- the LVGL logo, compiled in as a C array
- event callbacks

It uses the built-in font only and has no animation, so the two screenshots can
be compared directly. `lv_conf.h` is generated from `lv_conf.defaults`.

## What is checked

**The XML is byte-for-byte what `reference/project` holds.** Any change in the
converter's output fails, so it has to be looked at and accepted on purpose
rather than drifting. `--update` accepts it; read the diff first.

**The converted project renders like the app.** Each tab is rendered twice:
from the running app with `lv_snapshot_take()` through the GDB plugin, and from
the converted project with the Pro CLI. Pass `--cli <path to the CLI>` or set
`LVED_CLI`; without it the step is skipped.

The two renders are not bit-identical and cannot be: the app is built against
one LVGL and the Pro preview runtime against the version in `project.xml`, so
colour blending rounds differently. Every differing pixel is off by at most 2
per channel, which is what `MAX_CHANNEL_DELTA` allows. Anything larger means
something was actually drawn differently, and the test says so.
