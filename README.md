<p align="center">
  <a href="https://lvgl.io/pro" title="LVGL Pro homepage">Website</a> |
  <a href="https://lvgl.io/docs/pro" title="LVGL Pro documentation">Docs</a> |
  <a href="https://viewer.lvgl.io" title="Try LVGL Pro in your browser">Try Online</a> |
  <a href="https://github.com/lvgl/lvgl_editor/releases" title="Download LVGL Pro">Download</a> |
  <a href="https://forum.lvgl.io/c/lvgl-pro/17" title="Get help and share your work">Forum</a> |
  <a href="https://lvgl.io/pro/pricing" title="Licensing and pricing">Licensing</a>
</p>

<br>

<p align="center">
  <img src="https://lvgl.io/github-assets/logo-colored.png" height="50px" alt="LVGL">
</p>

<h1 align="center">The Complete Workflow for<br/>Professional LVGL UI Development</h1>

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
  <a href="#licensing">Licensing</a> •
  <a href="#why-xml">Why XML</a> •
  <a href="#get-started">Get Started</a>
</p>

<br/>

## LVGL Open vs LVGL Pro

The open-source LVGL library is the foundation for creating scalable and vendor independent UIs in C. LVGL Pro adds the complete workflow around it, **saving 50-80% of the development time**.[^1]

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

**Use LVGL Open directly** when the UI is relatively small, a code-first workflow works well, and one or two developers can comfortably maintain it.

**Add LVGL Pro** when the UI workflow becomes critical, such as when a designer joins, product variants multiply, the screen count grows, or rapid iteration becomes critical.

## What You Get

LVGL Pro is four connected tools: the **Editor**, the **Online Viewer**, **LVGL Flow for Figma**, and the **CLI**. With these, LVGL Pro:

1. **Lowers cost.** Free up every second developer from UI work.
2. **Speeds up time to market.** Ship weeks or months earlier and start making revenue sooner.
3. **Streamlines reviews.** Open the UI in a browser and give feedback whenever it suits you. No meeting needed.
4. **Speeds up iteration.** Working on a clean, organized UI is a pleasure, and backing it with tests lets you move fast without breaking anything.

This is how LVGL Pro achieves them:

### 1 second iterations instead of 2 minutes

Every UI change on a normal embedded workflow means compile, run/flash, navigate to the screen, and look. Ten seconds of thinking, two minutes of waiting. You do it hundreds of times a day.

In the LVGL Pro Editor the preview updates as you type. When something looks wrong, the Inspector shows you the layout, spacing, sizing, click areas, and object hierarchy at runtime, so you stop guessing at why a widget is four pixels off. The editor itself is a familiar VS Code-like environment with file navigation, search, Git integration, extensions, and a terminal, and you can debug the generated and your own C code without leaving it.

<!-- TODO: Screenshot of the inspector exlaining what we see with arrows -->

### Designers and developers work on the same UI

With **LVGL Flow for Figma** you make the Figma components LVGL aware, then export screens, layouts, styles, data bindings, and navigation straight into the project. No more reimplementing someone else's work in code. Read the [Figma Flow docs](https://lvgl.io/docs/pro/figma).

Going the other way, the **Online Viewer** opens any GitHub-hosted LVGL Pro project in a browser, so teammates, managers, and customers can click through the real UI without installing anything. Private repositories stay private: opening one needs a GitHub login, so only the people who already have access to the repository can see it.

<!-- TODO: side by side of a Figma frame and the resulting LVGL screen. -->

### Agents that can see what they build

An AI agent writing C is working blind. It produces code, then stops and waits for a human to compile it, look at it, and describe what came out wrong.

In LVGL Pro the loop closes. The agent writes XML, validates it with the CLI, renders a screenshot, and compares the result against what was actually asked for. An LVGL-aware MCP server gives it grounded access to the documentation instead of half-remembered APIs, and [`lvgl_widgets_xml`](lvgl_widgets_xml) lists every built-in widget with all of its properties, styles, and enums, so it stops inventing attributes.

<!-- TODO: short clip of an agent writing XML, screenshotting the result, and correcting itself. -->

### Tests and builds that run themselves

The **CLI** validates projects, exports C code, runs UI tests, compiles previews, and generates screenshots, locally or in CI. Tests are repeatable interactions checked against screenshots, so a UI regression fails the build instead of reaching a customer. See the full [CLI documentation](https://lvgl.io/docs/pro/cli).

### Big UIs stay maintainable

Screens are built from components you define yourself, with custom properties and a clear public API. Change the component and every screen using it follows immediately. Styles, constants, data bindings through LVGL Subjects, animation timelines, and translated strings all work the same way: defined once, used everywhere, changed in one place.

The same holds across hardware. A single project can carry several targets for different resolutions, hardware configurations, or product variants, so a second display size is a block in the project instead of a fork of it. Images and fonts live alongside the UI, and you can estimate asset memory, assign memory regions, and review access time early on.

<!-- TODO: screenshot of a component with properties and the screens reusing it, plus the target switcher and memory planning view. -->

<!-- TODO: proof section. Nothing here yet, so the whole block is commented out and will not render.
     This is the biggest gap in the README for a paid product. Fill in whatever is true:
       - companies or products shipping with LVGL Pro, with logos
       - one or two customer quotes with a name and a role
       - number of teams or seats, if it is a number worth showing
       - any real before/after figure, for example how long a UI iteration used to take

## Trusted in Production

...
-->

## Licensing

Licensing is per product, not per seat and not per device. A Product license covers the whole team for at least five years, so the yearly cost lands in the low thousands, less than the time saved building a single mid-sized UI. Everything after that first project is gain.

* **Community:** Free, unlimited seats, for makers, personal use, and open-source projects.
* **Evaluation:** Free access for testing LVGL Pro with your own designs, code, and development workflow.
* **Growth:** Custom price for one product, up to 2 active seats. For small and growing companies.
* **Product:** $20,000 for one product, up to 5 active seats, minimum 5 years. Covers the complete product development team.
* **Platform:** Custom, organization-wide across all products.

See the current plans at [lvgl.io/pro/pricing](https://lvgl.io/pro/pricing).

Whatever happens, you own the output. It is **plain LVGL C** that you can keep maintaining by hand, with no royalties and no per-device fees.

It is also possible to load the XML files at runtime, without exporting C code and rebuilding the firmware. Contact us at [lvgl@lvgl.io](mailto:lvgl@lvgl.io) to learn more.

## Why XML?

LVGL Pro stores the UI in readable, declarative XML rather than in a proprietary binary project format. That keeps the project reviewable in a pull request, mergeable in Git, and open to any script, CI job, or AI tool you point at it.

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

[^1]: Modelled on a 10-screen, two-target UI with multi-language support, built by a team of four: two developers, a designer, and a manager. Against hand-written C the model puts the saving near 70% of person-days, and against a team already using an AI assistant to write that C, near 60%. Larger UIs land higher, because most of the saving scales with the number of screens. These are estimates, not measurements, and your project will differ.
