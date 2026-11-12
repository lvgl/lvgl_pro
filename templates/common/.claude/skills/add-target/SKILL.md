---
name: add-target
description: Add a new hardware target (another display size or memory layout) to an LVGL Pro XML project with if_target - per-target constants, fonts, scaled images, and layouts - then check every screen on every target. Use when the user wants to support another display, board, or screen resolution.
---

# Add a target

Read `AGENTS.md` at the project root first, if it is not in your context. Follow its
"Working with the user" rules, and read its "Targets" section. Docs:
[Targets](https://lvgl.io/docs/pro/syntax/targets).

## The rules

- `if_target` works on `<consts>`, `<styles>`, `<fonts>`, `<images>`, and `<view>`. Not on
  a single widget.
- **For each name, the first matching definition wins.** Put the target definition of a
  name before its plain definition. If the plain one comes first, it wins on every target,
  and `validate` does not report it.
- A component can have several `<view if_target>`. A screen can have only one `<view>`.
- `if_target` goes on the `<images>` block, not on `<convert>`.

## Steps

Show this checklist to the user and keep it up to date.

1. Ask
2. Take the "before" state
3. Add the target to `project.xml`
4. Move size values to constants
5. Add the per-target values
6. Change the layout, if needed
7. Check every target
8. Report

### 1. Ask

Ask in one message:

- The name of the new target, and its display size.
- The memory regions, if the user wants the memory overview: `name`, `size`, and
  optional `bandwidth`.
- What changes: only sizes (spacing, fonts, icons), or the layout too.
- The templates name their only target `target1`. Rename it to a real name, for example
  `large`? This changes the C names (`<PROJECT>_TARGET_TARGET1`) that the application may
  use.

### 2. Take the "before" state

```bash
lvglpro validate . --errorlimit 25
lvglpro generate .
lvglpro compile .
lvglpro screenshot . screens/<screen>.xml --target <old target> --out /tmp/before/<screen>.png
```

The old target must look the same at the end.

### 3. Add the target to `project.xml`

```xml
<target name="small">
    <display width="320" height="240"/>
    <memory name="int_flash" size="512kB"/>
</target>
```

The first target is the default of `lvglpro screenshot`.

### 4. Move size values to constants

Raw sizes in views cannot change per target. Raw sizes in styles can, with
`<styles if_target>`, but then each style is written once per target. Find the raw
sizes, and propose a constant for each group (spacing, radius, icon size, font size).
Ask before you change many files. Use the names that already exist in `globals.xml`.

### 5. Add the per-target values

Constants and styles: the target block first, the plain block last. Put per-target
constants in `globals.xml`.

<!-- CLI 2.1.0: <consts if_target> in a component exports broken C
     (`../../<project>_check_target(...)`), so compile fails. Remove when fixed. -->
Do not put `<consts if_target>` in a component: the exported C does not compile.

```xml
<consts if_target="small">
    <int name="space_md" value="6"/>
</consts>
<consts>
    <int name="space_md" value="12"/>
</consts>
```

Fonts: the same `name`, another `size`.

```xml
<fonts if_target="small">
    <bin name="font_body" src_path="fonts/Inter.ttf" size="12" bpp="4" as_file="false"/>
</fonts>
<fonts>
    <bin name="font_body" src_path="fonts/Inter.ttf" size="16" bpp="4" as_file="false"/>
</fonts>
```

In `globals.xml`, all `<consts>`, `<fonts>`, and `<images>` blocks come before `<styles>`.

Images: convert each size once in a plain block, then pick one per target. Set
`color_format` on `<convert>`: the default is `rgb565`, which makes every pixel opaque.

```xml
<images>
    <convert src="images/icons/home.svg" dest="images/icons/home_16.png" width="16" color_format="argb8888"/>
    <convert src="images/icons/home.svg" dest="images/icons/home_24.png" width="24" color_format="argb8888"/>
</images>
<images if_target="small">
    <data name="icon_home" src_path="images/icons/home_16.png" color_format="argb8888"/>
</images>
<images>
    <data name="icon_home" src_path="images/icons/home_24.png" color_format="argb8888"/>
</images>
```

An `<images>` or `<fonts>` block with `if_target` can also take `memory="<region>"`, to
put the data in a memory region of that target.

### 6. Change the layout, if needed

Use flex or grid with `%` and `content` sizes first. They often make a second layout
unnecessary. If the layout must differ, put it in a component with one
`<view if_target="...">` per target, and the plain `<view>` last. Use the component in
the screen.

### 7. Check every target

```bash
lvglpro validate . --errorlimit 25
lvglpro generate .
lvglpro compile .
lvglpro screenshot . screens/<screen>.xml --target <target> --out /tmp/<target>_<screen>.png
```

Screenshot every screen on every target. Look at each image: text that does not fit,
clipped parts, icons with the wrong size. Compare the old target with "before".

### 8. Report

- The target, and the constants, fonts, images, and views added per target.
- How the application selects the target in C. Read the names in `<project>_gen.h`:
  at runtime with `<project>_set_target(<PROJECT>_TARGET_<NAME>)`, or at compile time
  with `-D<PROJECT>_COMPILE_TARGET=<PROJECT>_TARGET_<NAME>` (a bit mask, so targets can
  be ORed). Only compile-time selection removes the other targets' assets from the
  binary.
- The C names that changed, if a target was renamed.
- What is not verified.
