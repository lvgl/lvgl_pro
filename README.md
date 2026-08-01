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

<h1 align="center">The Professional Way to Build Embedded UIs</h1>

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
  <a href="#lvgl-open-vs-lvgl-pro">Open vs Pro</a> •
  <a href="#what-you-get">What You Get</a> •
  <a href="#whats-in-the-box">What's in the Box</a> •
  <a href="#what-you-own">What You Own</a> •
  <a href="#licensing">Licensing</a> •
  <a href="#why-xml">Why XML</a> •
  <a href="#get-started">Get Started</a>
</p>

<br/>

## LVGL Open vs LVGL Pro

The open-source LVGL library is the foundation for creating scalable and vendor independent UIs in C. LVGL Pro adds the complete workflow around it, **saving 50-80% of the development time**.

| | LVGL Open | LVGL Pro |
|---|---|---|
| **Seeing a change** | 1 minute to compile and run/flash | Instant, as you type |
| **Inspecting layouts** | Manual, trial and error | See bounding boxes, paddings, margins, and more, live |
| **Building a screen** | Write and wire up the C by hand | Compose it in XML, or import it from Figma |
| **Adding a second display size** | Fork, copy, or `#ifdef` magic | In the same project, preview with 1 click |
| **Reimplementing designs** | Days to weeks to write the C code | 1 click |
| **Handover to a designer** | Screenshots and meetings | Send a link they open in a browser |
| **Reliability** | Manual testing, or tests in C with a custom pipeline | Craft tests in seconds and run them in CI |
| **Asset memory** | Trial and error | Estimate and plan as you go, for each memory region |
| **Translations** | Custom string table in C, compile to test | Clean format, edit and test it live |
| **Data bindings** | Wire up in C, test on hardware or simulator | Test live as you build the UI |
| **Work with AI** | Agents generate C code, you compile and report what's wrong | Full workflow: generate, validate, screenshot, fine tune |

Both produce the same thing in the end: plain LVGL C code that you compile into your application.

**Stay on LVGL Open** if you are one or two developers on a single product, the screens are few, and there is no time pressure.

**Move to LVGL Pro** when the UI becomes the bottleneck. That usually happens when a designer joins, when the second product variant appears, when the screen count passes what one person can hold in their head, or when a deadline makes the compile-and-flash loop too expensive to keep paying.

## What You Get

### 1 second iterations instead of 2 minutes

Every UI change on a normal embedded workflow means compile, run/flash, navigate to the screen, and look. Ten seconds of thinking, two minutes of waiting. You do it hundreds of times a day.

In LVGL Pro the preview updates as you type. When something looks wrong, the Inspector shows you the layout, spacing, sizing, click areas, and object hierarchy at runtime, so you stop guessing at why a widget is four pixels off. The editor itself is a familiar VS Code-like environment with file navigation, search, Git integration, extensions, and a terminal, and you can debug the generated and your own C code without leaving it.

<!-- TODO: GIF or screenshot of the Inspector in action. This section is the strongest argument in the README and currently has no visual. -->

### Big UIs stay maintainable

Screens are built from components you define yourself, with custom properties and a clear public API. Change the component, every screen using it follows immediately.

Styling is defined once and shared, or kept local. Custom component properties can be defined and calculated from constants or from other properties. Properties can bind directly to application data through LVGL Subjects, animations are organized into reusable timelines, and localized strings are managed in the project and previewed per language while you work.

<!-- TODO: screenshot of a component with properties, plus the screens reusing it. -->

### One project, many products

A single UI project can carry several targets: different products, resolutions, hardware configurations, or architectures. Images and fonts live alongside the UI, and you can estimate asset memory usage, assign memory regions, and review the expected access costs before committing to a design.

<!-- TODO: screenshot of the target switcher and the memory planning view. -->

### Designers and developers work on the same UI

Make the Figma components LVGL aware, then export screens, layouts, styles, data bindings, and navigation straight into the project. No more reimplementing someone else's work in code.

When showing your work to the designer, any GitHub-hosted LVGL Pro project opens in the browser, so teammates, managers, and customers can click through the real UI without installing anything.

<!-- TODO: side by side of a Figma frame and the resulting LVGL screen. -->

### The repetitive parts run themselves

The CLI validates projects, exports C code, runs UI tests, compiles previews, and generates screenshots, locally or in CI. Tests are repeatable interactions checked against screenshots, so a UI regression fails the build instead of reaching a customer.

The same CLI is what makes AI agents useful here. An agent writes XML, validates it, renders it, and looks at the screenshot, instead of guessing from text. An LVGL-aware MCP server gives it grounded access to the documentation, and [`lvgl_widgets_xml`](lvgl_widgets_xml) lists every built-in widget with all of its properties, styles, and enums.

<!-- TODO: proof section. Nothing here yet, so the whole block is commented out and will not render.
     This is the biggest gap in the README for a paid product. Fill in whatever is true:
       - companies or products shipping with LVGL Pro, with logos
       - one or two customer quotes with a name and a role
       - number of teams or seats, if it is a number worth showing
       - any real before/after figure, for example how long a UI iteration used to take

## Trusted in Production

...
-->

## What's in the Box

1. **Editor** - A VS Code-like desktop environment for building screens and components visually in XML, managing assets and translations, creating tests, debugging C code, and previewing every change. Learn more about the [XML syntax](https://lvgl.io/docs/pro/syntax).

2. **Online Viewer** - Open GitHub hosted LVGL Pro projects in a browser to share a working UI with teammates, designers, managers, or customers without requiring an installation. Check out the [examples online](https://viewer.lvgl.io).

3. **LVGL Flow for Figma** - Make the Figma components LVGL aware, then export screens, layouts, styles, data bindings, and navigation into an LVGL Pro project. Read the [Figma Flow docs](https://lvgl.io/docs/pro/figma).

4. **CLI** - Validate projects, export C code, run UI tests, compile previews, and generate screenshots locally or in CI/CD. See the full [CLI documentation](https://lvgl.io/docs/pro/cli).

## What You Own

Buying a tool that generates your source code raises a fair question: what happens to the product if you stop using it? So, to be explicit:

* **The output is plain LVGL C.** It compiles and integrates exactly like handwritten code.
* **There is no extra runtime.** Nothing from LVGL Pro has to ship on your device.
* **There are no royalties** and no per-device fees.
* **The project is text.** XML files, in your repository, readable and diffable without our tools.
* **It works on your existing codebase.** Application behavior and hardware-specific logic stay in C. XML only describes the UI.
* **If you walk away, you keep the code.** The C you have exported is yours to maintain like any other source file.

## Licensing

LVGL Pro comes with flexible licensing for both makers and professionals.

* **Community:** Free for makers, personal use, and open-source projects.
* **Evaluation:** Free access for testing LVGL Pro with your own designs, code, and development workflow.
* **Growth:** Custom offer for small and growing companies.
* **Product:** One per-product license covering the complete product development team.
* **Platform:** Organization-wide access for companies standardizing UI development on LVGL across multiple products.

See the current plans at [lvgl.io/pro#pricing](https://lvgl.io/pro#pricing).

## Why XML?

LVGL Pro stores the UI in readable, declarative XML rather than in a proprietary binary project format. That keeps the project reviewable in a pull request, mergeable in Git, and open to any script, CI job, or AI tool you point at it. Devices can also load the XML at runtime when changing the UI without recompiling is useful.

If you are already familiar with the C API of LVGL, XML will be familiar too, because it exposes the same properties under the same names:

<img width="394" height="188" alt="A dashboard screen with a title, a slider bound to a subject, and a button" src="https://github.com/user-attachments/assets/c9a1e690-2844-465d-925d-3da26c3ceee2" />

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

See the [XML syntax documentation](https://lvgl.io/docs/pro/syntax) for the full reference.

## Get Started

### Try it in your browser

Open the [LVGL Pro Online Viewer](https://viewer.lvgl.io) and select an example or tutorial. No installation is required.

### Install the Editor

1. Download LVGL Pro for Windows, Linux, or macOS from the [GitHub Releases](https://github.com/lvgl/lvgl_editor/releases) page or the [LVGL Pro website](https://lvgl.io/pro#download).
2. Launch the editor and select the free **Community** or **Evaluation** license.
3. Click the Learn more button, open a screen, change a property, and see the preview update immediately.
4. Explore the generated C code and run the project on your target.

### Examples in the Docs

The examples in the documentation of [LVGL Open](https://lvgl.io/docs/open/widgets) and [LVGL Pro](https://lvgl.io/docs/pro/built_in_widgets) contain both the XML and the C code.

## Feedback

LVGL Pro is developed together with the LVGL community and the teams using it in real products.

Please [open an issue](https://github.com/lvgl/lvgl_editor/issues) to report a bug, suggest an improvement, or request a feature.

You can also reach us through the [LVGL Forum](https://forum.lvgl.io) or at [lvgl@lvgl.io](mailto:lvgl@lvgl.io).

Thank you! ❤️
