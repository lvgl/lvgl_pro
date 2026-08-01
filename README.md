<p align="center">
  <a href="https://lvgl.io/pro" title="LVGL Pro homepage">Website</a> |
  <a href="https://lvgl.io/docs/pro" title="LVGL Pro documentation">Docs</a> |
  <a href="https://viewer.lvgl.io" title="Try LVGL Pro in your browser"><b>Try Online</b></a> |
  <a href="https://github.com/lvgl/lvgl_editor/releases" title="Download LVGL Pro">Download</a> |
  <a href="https://forum.lvgl.io" title="Get help and share your work">Forum</a> |
  <a href="https://lvgl.io/pro#pricing" title="Licensing and pricing">Pricing</a>
</p>

<br>

<p align="center">
  <img src="https://lvgl.io/github-assets/logo-colored.png" height="50px" alt="LVGL">
</p>

<h1 align="center">The Professional Way to Build LVGL UIs</h1>

<p align="center">
  Design, develop, test, debug, and ship production-ready embedded UIs with an LVGL-native editor, Figma integration, online collaboration, and CI/CD tools.
  LVGL Pro Export plain LVGL code, so no additonal runtime is needed.
</p>

<p align="center">
  <a href="https://viewer.lvgl.io"><b>Try it in your browser</b></a>
  &nbsp;•&nbsp;
  <a href="https://github.com/lvgl/lvgl_editor/releases"><b>Download the Editor</b></a>
</p>

<p align="center">
  Free for evaluation, personal use, and open-source projects.
</p>

<br/>

<div align="center">
  <img src="https://github.com/user-attachments/assets/8cef0f05-0ff1-4766-8dfd-1d15e47f181a" height="500" alt="Building an embedded UI in LVGL Pro with instant preview">
</div>

<br/>

<p align="center">
  <a href="#why-lvgl-pro">Why LVGL Pro</a> •
  <a href="#how-it-works">How It Works</a> •
  <a href="#features">Features</a> •
  <a href="#lvgl-open-and-lvgl-pro">Open and Pro</a> •
  <a href="#why-xml">Why XML</a> •
  <a href="#get-started">Get Started</a> •
  <a href="#licensing">Licensing</a>
</p>

<br/>

## Why LVGL Pro

The LVGL engine gives you the flexibility to create any embedded UI in C. LVGL Pro adds the **complete workflow for professional UI development**, so you can build larger interfaces, build UIs much faster, support multiple products, and collaborate more easily across engineering and design teams.

You can create screens and reusable components, share styles and assets, add animations, translations, and data bindings, and see every change instantly without repeatedly recompiling and flashing the target. You can also import designs from Figma, inspect layouts and interaction areas, and share working projects in the browser without requiring any local setup.

Your custom widgets, callbacks, application logic, and hardware integrations can stay in C, and the same code can run in both the Editor preview and on the target device. You can export ordinary LVGL C code or load XML dynamically, automate validation and testing with the CLI, and use AI tools with LVGL documentation, examples, and iterative preview workflows.

## The LVGL Pro Toolkit

LVGL Pro consists of 4 connected tools:

1. **Editor** - A VS Code-like desktop environment for building components and screens and components visualy, managing assets and translations, creating tests, debugging C code, and previewing every change. Learn more about the [XML syntax](https://lvgl.io/docs/pro/syntax).

2. **Online Viewer** - Open GitHub hosted LVGL Pro projects in a browser to share a working UI with teammates, designers, managers, or customers without requiring an installation. Check out the [Examples Online](https://viewer.lvgl.io).
 
3. **LVGL Flow for Figma**  MAke the components in Figma LVGL aware, then export screens, layouts, styles, data bindings, and navigation into an LVGL Pro project. Read the docs of [Figma Flowhttps://lvgl.io/docs/pro/figma)

4. **CLI**   Validate projects, export C code, run UI tests, compile previews, and generate screenshots locally or in CI/CD. Also useful agents to work on their on XML files, and validate the result. See the full [CLI documentation](https://lvgl.io/docs/pro/cli)



## Features

### Development environment

* **VS Code-like editor:** File navigation, search, Git integration, extensions, and an integrated terminal.
* **Powerful XML language** Build UIs using a HTML-like XML language 
* **Instant preview:** See changes immediately without repeatedly compiling and flashing the target.
* **Inspector:** Examine layout, spacing, sizing, click areas, and object hierarchy.
* **C debugging:** Debug generated and custom C code directly inside the editor.

### UI architecture

* **Component-oriented XML:** Create reusable components with custom properties and a clear public API.
* **Shared styles:** Define consistent styling once and reuse it throughout the project.
* **Expressions:** Calculate property values from constants, component properties, and the active target.
* **Data binding:** Connect widgets to application data through LVGL Subjects.
* **Animations:** Organize animations into reusable timelines.
* **Translations:** Manage localized strings and preview languages during development.

### Cross Product developemnt

* **Multiple targets:** Support different products, resolutions, hardware configurations, or architectures in one UI project.
* **Asset management:** Organize images and fonts alongside the UI.
* **Memory planning:** Estimate asset memory usage, assign memory regions, and review expected access costs.

### Design and collaboration

* **Figma import:** Export LVGL-aware screens, layouts, styles, data bindings, and navigation from Figma.
* **Online sharing:** Open projects in the browser and share them without requiring local setup.
* **Git-friendly projects:** Store the UI as readable text files that can be reviewed, merged, and versioned.

### Integration and automation

* **Plain C export:** Generate ordinary LVGL C code that can be compiled into an existing application.
* **Runtime XML loading:** Load UI definitions dynamically when changing the UI without recompilation is useful.
* **UI testing:** Define repeatable interactions and screenshot-based tests.
* **Headless CLI:** Validate XML, execute tests, generate code, and create screenshots in CI/CD.

### AI-assisted development

* **LVGL-aware MCP server:** Give compatible AI agents grounded access to LVGL documentation.
* **Validation loop:** Let agents generate XML, validate it locally, render it, and inspect screenshots instead of relying only on text output.
* **Public Schema:** LVGL Pro uses the built-in LVGL Widgets. In [lvgl_widget_xmls]() you an find all widget and stlyes properties with all the enums

  
## LVGL Open and LVGL Pro

[LVGL Open](https://github.com/lvgl/lvgl) is the open-source graphics engine and C API used by the application on the target device.

LVGL Pro works on top of LVGL Open and adds development tools for visual creation, maintainable UI architecture, design collaboration, testing, sharing, and automation.

|                                         | LVGL Open | LVGL Pro       |
| --------------------------------------- | --------- | -------------- |
| Embedded graphics engine                | ✅         | Uses LVGL Open |
| Complete C API                          | ✅         | ✅              |
| Visual UI development                   |           | ✅              |
| Instant desktop preview                 |           | ✅              |
| Reusable XML components                 |           | ✅              |
| Figma integration                       |           | ✅              |
| UI testing                              |           | ✅              |
| Online project sharing                  |           | ✅              |
| CI/CD tools                             |           | ✅              |
| Plain LVGL C export                     |           | ✅              |
| Additional proprietary runtime required | No        | No             |

Use LVGL Open directly when a code-first workflow is the best fit.

Add LVGL Pro when visual development, reusable components, design integration, multiple targets, automated testing, or team collaboration become important.

## Why XML

LVGL Pro stores the UI in readable, declarative XML rather than in a proprietary binary project format.

This provides several practical benefits:

* **Readable:** The HTML-like structure is easy to understand and navigate.
* **Version-control friendly:** Changes appear as ordinary text diffs in Git.
* **Reusable:** Components, styles, and snippets can be shared between screens and projects.
* **Reviewable:** Developers can inspect exactly what changed in a pull request.
* **Automation ready:** Scripts and CI/CD tools can validate and transform the project.
* **AI compatible:** AI tools can generate and refactor a compact, schema-checked format and receive precise validation errors.
* **Cross-platform:** The same UI definitions can be used across LVGL-supported targets.
* **Runtime capable:** Devices can optionally load XML without recompiling the application.

Application behavior and hardware-specific logic can remain in C, while XML describes the UI structure and configuration.

## Get Started

### Try it in your browser

Open the [LVGL Pro Online Viewer](https://viewer.lvgl.io) and select an example or tutorial.

No installation is required.

### Install the Editor

1. Download LVGL Pro for Windows, Linux, or macOS from the [GitHub Releases](https://github.com/lvgl/lvgl_editor/releases) page or the [LVGL Pro website](https://lvgl.io/pro#download).
2. Launch the editor and select the free **Community** or **Evaluation** license.
3. Click the Learn more button and open a screen, change a property, and see the preview update immediately.
5. Explore the generated C code and run the project on your target.


### Example in the Docs

The examples in documentation of [LVGL Open](https://lvgl.io/docs/open/widgets) and [LVGL Pro](https://lvgl.io/docs/pro/built_in_widgets) contains both the XML and C code.

## Licensing

LVGL Pro comes with flexible liceneing for both makers and proessionals. 

* **Community:** Free for makers, personal use, and open-source projects.
* **Evaluation:** Free access for testing LVGL Pro with your own designs, code, and development workflow.
* **Growth:** Custom offer for small and growing companies.
* **Product:** One per-product license covering the complete product development team.
* **Platform:** Organization-wide access for companies standardizing UI development on LVGL accross multiple products.

See the current plans at [lvgl.io/pro#pricing](https://lvgl.io/pro#pricing).

## Documentation and Support

## Feedback

LVGL Pro is developed together with the LVGL community and the teams using it in real products.

Please [open an issue](https://github.com/lvgl/lvgl_editor/issues) to report a bug, suggest an improvement, or request a feature.

You can also reach us through the [LVGL Forum](https://forum.lvgl.io) or at [lvgl@lvgl.io](mailto:lvgl@lvgl.io).

Thank you! ❤️
