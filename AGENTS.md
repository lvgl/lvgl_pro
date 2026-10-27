# AGENTS.md

This is the public repo of [LVGL Pro](https://lvgl.io/pro). LVGL Pro UIs are written in XML, and the Editor or the `lvglpro` CLI turns the XML into plain LVGL C code. The Editor's source is not here, but you can download the Editor from this repo's [releases page](https://github.com/lvgl/lvgl_pro/releases), and install the CLI from npm with `npm install --global @lvgl/lvglpro`. This repo holds what you need to read and write that XML correctly.

## What is useful here

| Path | Why it helps |
| --- | --- |
| `lvgl_widgets_xml/v<version>/` | The XML schema of every built-in widget, one `lv_*.xml` per widget, with every property, enum and element and a `help` text. `globals.xml` lists every style property and enum, including the event names. This is the source of truth for "what can I write on this tag?" |
| `docs/` | The source of the [LVGL Pro docs](https://lvgl.io/docs/pro). `docs/syntax/` has one page per XML feature, `docs/cli.mdx` covers the CLI. |
| `examples/lvgl_open/` | 130+ small example screens (widgets, layouts, styles, scrolling), with the exported C committed next to each XML file. |
| `examples/lvgl_pro/` | One example per widget, also with its exported C. |
| `docs/examples/screens/` | The same widget examples as flat `lv_example_*.xml` and `lv_example_*.c` pairs. |
| `tutorials/` | One folder per concept: styles, layout, animations, assets, data bindings, translations, custom components and widgets, testing. Exported C included. |
| `templates/basic/` | A starter project with a small design system: around 30 reusable components, screens, fonts, icons and tests. |
| `templates/common/AGENTS.md` | **The guide to writing LVGL Pro XML.** Every project ships a copy. Read it before you write XML. |

The XML and C pairs show exactly what each XML construct becomes in C.

## Working in this repo

- **Common project files.** `AGENTS.md`, `.mcp.json`, `user_config.cmake`, `.vscode/` and `sim/` are the same in every project. Edit them in `templates/common/`, then run `scripts/sync-common-template-files.sh`. CI fails if a project's copy differs. `sim/main.c` stays per project.
- **Templates carry no exported C.** The top-level `.gitignore` keeps it out. `examples/` and `tutorials/` do commit their exports.
- **Generated docs.** `docs/built_in_widgets/` comes from `docs/scripts/gen_widget_api.ts`, and `docs/examples/` from `docs/scripts/generate_examples.py`. Edit the source, not the output.
- **Verify XML with the CLI.** Run `lvglpro validate <project>`, `generate`, `screenshot` and `run-all-tests`. See `docs/cli.mdx`. Without a license token nothing was verified, so say so.
- **Ask about LVGL itself** through the LVGL MCP server at `https://lvgl.mcp.kapa.ai/` (each project's `.mcp.json` sets it up), not from memory.
