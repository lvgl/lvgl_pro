<p align="center">
  <a href="https://lvgl.io/pro" title="LVGL Pro homepage">Website</a> |
  <a href="https://lvgl.io/docs/pro" title="LVGL Pro documentation">Docs</a> |
  <a href="https://viewer.lvgl.io" title="Try LVGL Pro in your browser">Try Online</a> |
  <a href="https://github.com/lvgl/lvgl_editor/releases" title="Download LVGL Pro">Download</a> |
  <a href="https://forum.lvgl.io/c/lvgl-pro/17" title="Get help and share your work">Forum</a> |
  <a href="https://lvgl.io/pro#pricing" title="Licensing and pricing">Licensing</a>
</p>

<br>

<p align="center">
  <img src="https://lvgl.io/github-assets/logo-colored.png" height="50px" alt="LVGL">
</p>

<h1 align="center">The Professional Way to Build LVGL UIs</h1>

<p align="center">
  Design, develop, test, debug, and ship production-ready embedded UIs with an LVGL-native editor, Figma integration, online collaboration, and CLI tools.
  LVGL Pro exports plain LVGL code, so no additional runtime is needed.
</p>

<p align="center">
  <a href="https://viewer.lvgl.io"><b>Try it in your browser</b></a>
  &nbsp;•&nbsp;
  <a href="https://github.com/lvgl/lvgl_editor/releases"><b>Download the Editor</b></a>
</p>

<p align="center" >
  Free for evaluation, personal use, and open-source projects.
</p>

<br/>

<div align="center">
  <img src="https://github.com/user-attachments/assets/8cef0f05-0ff1-4766-8dfd-1d15e47f181a" height="500" alt="Building an embedded UI in LVGL Pro with instant preview">
</div>

<br/>

<p align="center">
  <a href="#why-lvgl-pro">Why LVGL Pro</a> •
  <a href="#the-lvgl-pro-toolkit">The Toolkit</a> •
  <a href="#features">Features</a> •
  <a href="#why-xml">Why XML</a> •
  <a href="#get-started">Get Started</a> •
  <a href="#licensing">Licensing</a>
</p>

<br/>

## Why LVGL Pro?

The open-source LVGL library is the foundation for creating scalable and vendor independent UIs in C. LVGL Pro adds the **complete workflow for professional UI development**, so that you can

- build larger interfaces from reusable components easily
- build UIs much faster by seeing a pixel perfect preview as you edit, without recompiling
- manage and test animations, data bindings, and translations
- support multiple products in one project and review asset memory usage
- collaborate easily with designers by importing Figma projects and sharing the project online
- use AI agents to write UIs and validate the result automatically
- use a CLI tool to validate projects, generate code, and run tests in CI/CD

The primary language of the Editor is XML (similar to HTML), from which the Editor or the CLI tool can export plain LVGL C code that you can compile and integrate just like any handwritten C code. If you wish, you can also load the UIs from XML files directly at runtime, without recompiling the application.

Use LVGL Open directly when the projects are not connected, the team is small, development time is not critical, and long term maintainability is not a concern.

Add LVGL Pro when you need to develop products at scale with strict deadlines, in large teams overseeing multiple products, while maintaining high quality standards.

## The LVGL Pro Toolkit

LVGL Pro consists of 4 connected tools:

1. **Editor** - A VS Code-like desktop environment for building screens and components visually in XML, managing assets and translations, creating tests, debugging C code, and previewing every change. Learn more about the [XML syntax](https://lvgl.io/docs/pro/syntax).

2. **Online Viewer** - Open GitHub hosted LVGL Pro projects in a browser to share a working UI with teammates, designers, managers, or customers without requiring an installation. Check out the [examples online](https://viewer.lvgl.io).

3. **LVGL Flow for Figma** - Make the Figma components LVGL aware, then export screens, layouts, styles, data bindings, and navigation into an LVGL Pro project. Read the [Figma Flow docs](https://lvgl.io/docs/pro/figma).

4. **CLI** - Validate projects, export C code, run UI tests, compile previews, and generate screenshots locally or in CI/CD. It also lets AI agents work on the XML files and validate the result on their own. See the full [CLI documentation](https://lvgl.io/docs/pro/cli).

## Features


### 🧩 Build

| | |
|---|---|
| **Component-oriented XML** | Reusable components with custom properties and a clear public API. |
| **Git-friendly projects** | The UI is plain text, so it can be diffed, reviewed, and merged like code. |
| **Expressions** | Calculate property values from constants, component properties, and the active target. |
| **Data binding** | Connect widgets to application data through LVGL Subjects. |
| **Animations** | Organize animations into reusable timelines. |
| **Translations** | Manage localized strings and switch languages right in the preview. |

### ⚡ Iterate

| | |
|---|---|
| **Instant preview** | See every change immediately, with no compiling and flashing in between. |
| **VS Code-like editor** | File navigation, search, Git integration, extensions, and an integrated terminal. |
| **Inspector** | Examine layout, spacing, sizing, click areas, and object hierarchy at runtime. |
| **C debugging** | Debug generated and custom C code without leaving the editor. |

### 🙏 Collaborate

| | |
|---|---|
| **Figma import** | Bring screens, layouts, styles, data bindings, and navigation over from Figma. |
| **Shared styles** | Define consistent styling once and reuse it throughout the project. |
| **Online sharing** | Open a project in the browser and share it without any local setup. |


### 📦 Scale

| | |
|---|---|
| **Multiple targets** | One UI project for many products, resolutions, hardware configurations, or architectures. |
| **Asset management** | Organize images and fonts alongside the UI. |
| **Memory planning** | Estimate asset memory usage, assign memory regions, and review expected access costs. |

### 🚀 Ship

| | |
|---|---|
| **Plain C export** | Ordinary LVGL C code that compiles into your existing application. |
| **Runtime XML loading** | Load UI definitions dynamically when you want to change the UI without recompiling. |
| **UI testing** | Define repeatable interactions and screenshot-based tests. |
| **Headless CLI** | Validate XML, run tests, generate code, and create screenshots in CI/CD. |

### 🤖 AI-assisted development

| | |
|---|---|
| **LVGL-aware MCP server** | Gives compatible AI agents grounded access to the LVGL documentation. |
| **Validation loop** | Agents generate XML, validate it, render it, and inspect the screenshots instead of relying on text alone. |
| **Public schema** | [`lvgl_widgets_xml`](lvgl_widgets_xml) lists every built-in widget with all its properties, styles, and enums. |

## Why XML?

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

If you are already familiar with the C API of LVGL, you will find XML simple too, as it exposes the properties with the same names. For example:

<img width="394" height="188" alt="image" src="https://github.com/user-attachments/assets/c9a1e690-2844-465d-925d-3da26c3ceee2" />

```xml
<screen>
	<view>
		<column gap="#space_lg" pad="#space_lg">
			<lv_label text="Device Dashboard" style_text_font="font_h3" />

			<row vertical_align="center" gap="12" pad="4">
				<lv_slider width="240" bind_value="subject_brightness" />
				<lv_label bind_text="subject_brightness" />
			</row>

			<lv_button>
				<lv_label text="Apply Setting" />
				<event_cb callback="my_callback" trigger="clicked" />
			</lv_button>
		</column>
	</view>
</screen>
```
Here `<row>` and `<column>` are custom components, and `#space_lg` is a constant.

## Get Started

### Try it in your browser

Open the [LVGL Pro Online Viewer](https://viewer.lvgl.io) and select an example or tutorial.

No installation is required.

### Install the Editor

1. Download LVGL Pro for Windows, Linux, or macOS from the [GitHub Releases](https://github.com/lvgl/lvgl_editor/releases) page or the [LVGL Pro website](https://lvgl.io/pro#download).
2. Launch the editor and select the free **Community** or **Evaluation** license.
3. Click the Learn more button, open a screen, change a property, and see the preview update immediately.
4. Explore the generated C code and run the project on your target.

### Examples in the Docs

The examples in the documentation of [LVGL Open](https://lvgl.io/docs/open/widgets) and [LVGL Pro](https://lvgl.io/docs/pro/built_in_widgets) contain both the XML and the C code.

## Licensing

LVGL Pro comes with flexible licensing for both makers and professionals.

* **Community:** Free for makers, personal use, and open-source projects.
* **Evaluation:** Free access for testing LVGL Pro with your own designs, code, and development workflow.
* **Growth:** Custom offer for small and growing companies.
* **Product:** One per-product license covering the complete product development team.
* **Platform:** Organization-wide access for companies standardizing UI development on LVGL across multiple products.

See the current plans at [lvgl.io/pro#pricing](https://lvgl.io/pro#pricing).

## Feedback

LVGL Pro is developed together with the LVGL community and the teams using it in real products.

Please [open an issue](https://github.com/lvgl/lvgl_editor/issues) to report a bug, suggest an improvement, or request a feature.

You can also reach us through the [LVGL Forum](https://forum.lvgl.io) or at [lvgl@lvgl.io](mailto:lvgl@lvgl.io).

Thank you! ❤️
