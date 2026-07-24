<p align="center">
  <a href="https://lvgl.io/pro" title="LVGL Pro homepage">Website</a> |
  <a href="https://lvgl.io/docs/pro" title="LVGL Pro documentation">Docs</a> |
  <a href="https://viewer.lvgl.io" title="Run LVGL Pro in your browser">Online Viewer</a> |
  <a href="https://forum.lvgl.io" title="Get help and share your work">Forum</a> |
  <a href="https://lvgl.io/pro#pricing" title="Licensing and pricing">Pricing</a>
</p>

<br>

<p align="center">
  <img src="https://lvgl.io/github-assets/logo-colored.png" height=50px>
</p>

<h1 align="center">LVGL Pro</h1>

<p align="center">
  LVGL Pro is a professional toolkit to speed up UI development with LVGL.
  It includes an Editor, Figma integration, Online sharing, and a CLI.
</p>

<br/>

<div align="center">
  <img src="https://github.com/user-attachments/assets/8cef0f05-0ff1-4766-8dfd-1d15e47f181a" height="500" alt="Building a UI in LVGL Pro with live preview">
</div>

<br/>

<p align="center">
  <a href="#overview" title="What LVGL Pro is">Overview</a> •
  <a href="#features" title="What LVGL Pro can do">Features</a> •
  <a href="#why-xml" title="Why LVGL Pro uses XML">Why XML</a> •
  <a href="#workflow" title="How the pieces fit together">Workflow</a> •
  <a href="#get-started" title="Try it now">Get Started</a> •
  <a href="#licensing" title="Licensing and pricing">Licensing</a> •
  <a href="#feedback" title="How to reach us">Feedback</a>
</p>

<br/>

## Overview

You can build any UI with LVGL in C. LVGL Pro lets you build the same UIs visually, preview every change
instantly, and export plain LVGL C code that drops into an existing project with no extra runtime or dependency.

It consists of four tightly related tools:

1. **Editor**: The heart of LVGL Pro. A desktop app to build components and screens in XML, and manage data bindings, translations, animations, tests, assets, and more. See the [Editor docs](https://lvgl.io/docs/pro/editor) and the [XML syntax](https://lvgl.io/docs/pro/syntax).
2. **Online Viewer**: Run the editor in your browser, open GitHub projects, and share with teammates, designers, or customers without any local setup. Visit [viewer.lvgl.io](https://viewer.lvgl.io) or read the [docs](https://lvgl.io/docs/pro/online-viewer).
3. **Figma plugin (LVGL Flow)**: Bring a Figma design into LVGL Pro, including layouts, widgets, data bindings, and screen navigation. See how it works [here](https://lvgl.io/docs/pro/figma).
4. **CLI**: Export C code and run UI tests in CI/CD pipelines. See the [CLI docs](https://lvgl.io/docs/pro/cli).

Together, these tools let you build UIs faster, test them reliably, and collaborate with your team.

## Features

- **Familiar environment**: A VS Code-like editor with file navigation, search, Git integration, an integrated terminal, and extensions.
- **Component-oriented XML**: Build reusable components with a custom API in a readable, HTML-like syntax.
- **Instant preview**: A pixel-perfect preview that updates as you edit, with an inspector for spacing, click areas, and sizing.
- **Design mode**: Edit UIs visually with a curated set of exposed properties.
- **Expressions**: Compute property values from constants, custom properties, and the active target.
- **Animations, data binding, and translations**: Organize animations into timelines, bind widgets to app data, and manage localization.
- **Assets and memory management**: Track images and fonts, plan memory regions, and estimate usage and access times.
- **Multiple targets**: Handle several resolutions or architectures in a single project.
- **Figma import**: Bring in layouts, widgets, data bindings, and navigation with the LVGL Flow plugin.
- **AI integration**: Use AI assistants with an LVGL-aware [MCP server](https://lvgl.io/docs/pro/ai).
- **C export and runtime loading**: Export plain LVGL C code, or load the XML at runtime without recompiling.
- **Testing and debugging**: Create UI tests and debug the exported C code inside the editor.
- **Online sharing**: Open projects in the browser and share them without any local setup.

## Why XML

Describing UIs in XML rather than only through drag-and-drop editing has several advantages:

- **Familiar**: HTML-like syntax that is easy to learn and read.
- **Version-control friendly**: plain text with readable diffs, no binary files.
- **Easy to share**: copy, paste, and send as text.
- **Reusable**: copy snippets across projects and compose UIs from smaller components.
- **Automation ready**: scripts and CI/CD systems can process XML directly.
- **AI compatible**: AI tools can parse, generate, and refactor XML.
- **Fast to edit**: quicker to type and refactor than dragging elements.
- **Runtime loading**: parse XML on the target device without recompiling.
- **Cross-platform**: the same XML works across all LVGL targets.

## Workflow

1. **Create reusable components** in the [editor](https://lvgl.io/docs/pro/editor) and use the instant, pixel-perfect preview to see them render live.
2. **Build screens** from those components, then add tests, transitions, data bindings, and translations in [XML](https://lvgl.io/docs/pro/syntax).
3. **Add custom logic or widgets** in C, then recompile the editor's preview so your C runs both in preview and on the target.
4. **Import from Figma** with the [LVGL Flow plugin](https://lvgl.io/docs/pro/figma) to bring in styles, layouts, data bindings, and navigation.
5. **Integrate the UI** into your project by [exporting LVGL C code or loading the XML at runtime](https://lvgl.io/docs/pro/integration).
6. **Collaborate** by pushing to a GitHub repo and opening it in the [Online Viewer](https://lvgl.io/docs/pro/online-viewer), so teammates, designers, or managers need no local setup.
7. **Automate** in CI/CD with the [CLI](https://lvgl.io/docs/pro/cli) to export C code and run UI tests as part of your pipeline.

## Get Started

### In your browser

Open the [Online Viewer](https://viewer.lvgl.io), then pick an example or tutorial to explore. No install needed.

### Locally

1. Download the LVGL Pro Editor for Windows, Linux, or macOS from the [Releases](https://github.com/lvgl/lvgl_editor/releases) page, or from [lvgl.io/pro](https://lvgl.io/pro#download).
2. On first launch, pick the free Community or Evaluation license.
3. Create an example or tutorial project and open a screen to start from. `Hello World` is a good first stop.

The [Learn by Examples](https://lvgl.io/docs/pro/learn-by-examples) projects cover animations, assets, data bindings, components, widgets, screens, styles, testing, and translations. The same examples also appear interactively in the [LVGL docs](https://lvgl.io/docs/open/examples), alongside their equivalent C code.

## Licensing

LVGL Pro has a royalty-free licensing model designed for open-source projects, startups, and enterprises alike:

- **Community**: free for makers, personal use, and open-source projects.
- **Evaluation**: free. Select it when launching the editor to try LVGL Pro before committing.
- **Product**: a per-product license with no seat counting and no yearly renewal, covering your whole team for the product's development lifetime.
- **Platform**: for organizations standardizing UI development on LVGL and LVGL Pro across multiple products, with options such as floating licenses and on-premise license servers.

See the current plans and details at [lvgl.io/pro#pricing](https://lvgl.io/pro#pricing). For a quote or a startup-friendly price, use the contact button there or email [lvgl@lvgl.io](mailto:lvgl@lvgl.io).

## Feedback

We are building this tool for you, and your feedback drives its development.

Please [open an issue](https://github.com/lvgl/lvgl_editor/issues) to share suggestions, report bugs, or request features. You can also reach us on the [forum](https://forum.lvgl.io) or at [lvgl@lvgl.io](mailto:lvgl@lvgl.io).

Thank you! ❤️
