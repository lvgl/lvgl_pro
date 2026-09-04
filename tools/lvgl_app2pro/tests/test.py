#!/usr/bin/env python3
"""Build the test apps, convert them, and check the result.

    python3 tests/test.py            # everything
    python3 tests/test.py build      # fetch LVGL and build the apps
    python3 tests/test.py convert    # run the converter on the built apps
    python3 tests/test.py compare    # check it against reference_xml_projects/
    python3 tests/test.py --update   # accept the current output as the reference
    python3 tests/test.py --app lv_demo_widgets    # just one of them

Everything is end to end: a real app, built and run under GDB, converted, and
the output compared. A case worth testing is a case worth adding to
`test_ui/`, where it is exercised the way a user's code would be.

Two apps are converted: `test_ui`, written to exercise the hard parts, and the
`lv_demo_widgets` example, which is real LVGL code nobody wrote for this.

`build` fetches LVGL itself, so nothing has to be installed or configured
first beyond a compiler, SDL2 and GDB. The converted XML is compared against
`reference_xml_projects/`, which is committed; the screenshots are taken fresh
on both sides each run, so no images are committed.

Screenshot comparison needs the LVGL Pro CLI. Point --cli at it, or set
LVED_CLI; without it that step is skipped and the rest still runs.
"""

import argparse
import os
import re
import shutil
import subprocess
import sys
import xml.etree.ElementTree as ET
from dataclasses import dataclass, field
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
SRC = ROOT / "src"
REFERENCE = HERE / "reference_xml_projects"
SHOTS = HERE / "reference_screenshots"
WORK = HERE / ".work"
LVGL = WORK / "lvgl"

LVGL_REPO = "https://github.com/lvgl/lvgl.git"
LVGL_TAG = "v9.5.0"

# How far a render may drift from its committed screenshot. The same binary
# drawing the same screen is expected to be identical, so this is only slack
# for a differently built libpng or SDL.
REFERENCE_DELTA = 0


@dataclass
class App:
    """One application the suite builds, converts and checks."""

    name: str
    source: Path
    tabs: int
    #: Command line to run it with, so the dump and the screenshots agree.
    args: str = ""
    #: Extra -D flags its CMakeLists needs beyond -DLVGL_DIR.
    cmake_args: list = field(default_factory=list)
    #: How far apart the app and the converted project may render. None means
    #: only report the difference: see compare_the_two_sides().
    max_channel_delta: int = None

    @property
    def build(self):
        return WORK / self.name / "build"

    @property
    def out(self):
        return WORK / self.name / "converted"

    @property
    def reference(self):
        return REFERENCE / self.name

    @property
    def binary(self):
        return self.build / self.name


APPS = [
    App(
        name="test_ui",
        source=HERE / "test_ui",
        tabs=2,
        cmake_args=["-DLV_CONF_DIR={source}",
                    "-DLV_BUILD_CONF_PATH={source}/lv_conf.h"],
        # Built-in font throughout and no animation, so the two renders differ
        # only by colour rounding.
        max_channel_delta=2,
    ),
    App(
        name="lv_demo_widgets",
        source=ROOT / "examples" / "lv_demo_widgets",
        tabs=3,
        # Tall enough to show every tab whole: the longest is Analytics, whose
        # content needs 1045px under a 75px tab bar. The screenshots in the
        # README are a separate 800x600 set, made by hand - see its Contributing
        # section.
        args="--width 800 --height 1150",
        # The demo uses fonts the converter cannot declare and animates a
        # needle, so its two renders are genuinely different pictures.
        max_channel_delta=None,
    ),
]


class Failure(Exception):
    pass


def run(command, **kwargs):
    done = subprocess.run(command, capture_output=True, text=True, **kwargs)
    if done.returncode != 0:
        raise Failure(f"{' '.join(str(c) for c in command)}\n"
                      f"{done.stdout[-4000:]}{done.stderr[-4000:]}")
    # A warning on stderr means the converter could not do something. Hiding it
    # on success is how a broken version probe went unnoticed. GDB's own
    # complaints about system libraries it has no debug info for are not that.
    for line in done.stderr.splitlines():
        if line.strip() and ".gnu_debugaltlink" not in line:
            print(f"  {line}")
    return done.stdout


def step(message):
    print(f"\n== {message}")


# --------------------------------------------------------------------------


def fetch_lvgl():
    WORK.mkdir(exist_ok=True)
    if LVGL.is_dir():
        print(f"  reusing {LVGL}")
        return
    print(f"  fetching {LVGL_TAG}")
    run(["git", "clone", "--depth", "1", "--branch", LVGL_TAG,
         LVGL_REPO, str(LVGL)])


def build(app):
    """Generate the app's lv_conf.h from its defaults, then build it."""
    step(f"Building {app.name} against LVGL {LVGL_TAG}")
    fetch_lvgl()

    # lv_conf.h is generated, so only the handful of options each app needs is
    # kept in the repository.
    run([sys.executable, str(LVGL / "scripts" / "generate_lv_conf.py"),
         "--template", str(LVGL / "lv_conf_template.h"), str(app.source)])

    extra = [a.format(source=app.source) for a in app.cmake_args]
    run(["cmake", "-B", str(app.build), "-S", str(app.source),
         f"-DLVGL_DIR={LVGL}", "-DCMAKE_BUILD_TYPE=Debug", *extra])
    run(["cmake", "--build", str(app.build), "-j", str(os.cpu_count() or 4)])

    if not app.binary.exists():
        raise Failure(f"{app.binary} was not produced")
    print(f"  built {app.binary}")


def convert(app):
    """Run the converter on the built app, through GDB."""
    step(f"Converting {app.name}")
    if not app.binary.exists():
        raise Failure(f"{app.name} is not built; run `test.py build` first")

    shutil.rmtree(app.out, ignore_errors=True)
    # No --lvgl: the plugin shipped in src/gdb_plugin/ is the one to use, and it
    # is deliberately newer than the LVGL the app was built against.
    command = [sys.executable, str(ROOT / "lvgl_app2pro.py"), str(app.binary),
               "-o", str(app.out)]
    if app.args:
        command += ["--app-args", app.args]
    print("  " + run(command).strip().replace("\n", "\n  "))


# --------------------------------------------------------------------------


def compare_xml(app, update=False):
    """The converted XML must be exactly what the reference holds."""
    step(f"Comparing the XML of {app.name}")
    if not app.out.is_dir():
        raise Failure(f"{app.name} is not converted; run `test.py convert` first")

    # Cheap and needs no CLI, so it runs before the reference is even consulted:
    # a malformed file should be reported as malformed, not as a difference.
    for path in sorted(app.out.rglob("*.xml")):
        try:
            ET.parse(path)
        except ET.ParseError as broken:
            raise Failure(f"{path} is not well-formed XML: {broken}")

    if update:
        shutil.rmtree(app.reference, ignore_errors=True)
        shutil.copytree(app.out, app.reference,
                        ignore=shutil.ignore_patterns("preview-*"))
        print(f"  reference updated from {app.out}")
        return

    if not app.reference.is_dir():
        raise Failure(f"no reference at {app.reference}; run with --update")

    expected = {p.relative_to(app.reference)
                for p in app.reference.rglob("*") if p.is_file()}
    produced = {p.relative_to(app.out) for p in app.out.rglob("*") if p.is_file()}

    if expected != produced:
        raise Failure("the set of files changed.\n"
                      f"  missing:    {sorted(str(p) for p in expected - produced)}\n"
                      f"  unexpected: {sorted(str(p) for p in produced - expected)}")

    for relative in sorted(expected):
        if (app.reference / relative).read_bytes() != (app.out / relative).read_bytes():
            raise Failure(
                f"{relative} differs from the reference.\n"
                f"  diff {app.reference / relative} {app.out / relative}\n"
                f"  If the change is intended, rerun with --update."
            )
    print(f"  {len(expected)} files match")


def compare_screenshots(app, cli):
    """Render both sides, check them against the committed screenshots."""
    step(f"Comparing the screenshots of {app.name}")
    if not cli:
        print("  no --cli given, skipped")
        return
    try:
        import PIL  # noqa: F401
    except ImportError:
        print("  Pillow is not installed, skipped")
        return

    failures = []
    app_shots = snapshot_app(app)
    for tab, shot in enumerate(app_shots):
        failures.append(check_against_reference(app, f"app_tab{tab}", shot))

    # The app side is worth keeping even when the Pro CLI cannot render the
    # converted project, so that failure is collected rather than thrown.
    try:
        converted_shots = snapshot_converted(app, cli)
    except Failure as broken:
        failures.append(f"the Pro CLI could not render the project:\n{broken}")
        converted_shots = []

    for tab, shot in enumerate(converted_shots):
        failures.append(check_against_reference(app, f"xml_tab{tab}", shot))
    if converted_shots:
        compare_the_two_sides(app, app_shots, converted_shots)

    failures = [f for f in failures if f]
    if failures:
        raise Failure("\n".join(failures))


def check_against_reference(app, name, fresh):
    """Compare one render with its committed twin, creating it if it is new.

    This is how LVGL's own screenshot tests work: the first run writes the
    reference, every later run has to reproduce it. Returns a message if it
    did not, having written the render beside the reference as *_err.png.
    """
    from PIL import Image, ImageChops

    reference = SHOTS / app.name / f"{name}.png"
    if not reference.exists():
        reference.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(fresh, reference)
        print(f"  {name}: no reference yet, created it")
        return None

    want = Image.open(reference).convert("RGB")
    got = Image.open(fresh).convert("RGB")
    failed = reference.with_name(f"{name}_err.png")
    if want.size != got.size:
        shutil.copyfile(fresh, failed)
        return f"{name}: {got.size} against the reference's {want.size}, see {failed}"

    difference = ImageChops.difference(want, got)
    worst = max((max(pixel) for pixel in difference.getdata()), default=0)
    if worst > REFERENCE_DELTA:
        shutil.copyfile(fresh, failed)
        return (f"{name}: a pixel differs from the reference by {worst}. "
                f"See {failed}. If the change is intended, delete "
                f"{reference} and run again.")

    failed.unlink(missing_ok=True)
    print(f"  {name}: matches its reference")
    return None


def compare_the_two_sides(app, app_shots, converted_shots):
    """Report how far the converted project renders from the app it came from.

    An app whose fonts and animations survive the conversion is expected to
    match within colour rounding. One whose do not cannot be held to that, so
    for those the difference is only reported.
    """
    from PIL import Image, ImageChops

    for tab in range(app.tabs):
        left = Image.open(app_shots[tab]).convert("RGB")
        right = Image.open(converted_shots[tab]).convert("RGB")
        if left.size != right.size:
            raise Failure(f"tab {tab}: {left.size} against {right.size}")

        difference = ImageChops.difference(left, right)
        pixels = list(difference.getdata())
        worst = max((max(p) for p in pixels), default=0)
        differing = sum(1 for p in pixels if p != (0, 0, 0))
        share = differing / len(pixels) * 100
        print(f"  tab {tab}: app and XML differ in {differing} px "
              f"({share:.0f}%), worst channel {worst}")

        if app.max_channel_delta is None:
            continue
        if worst > app.max_channel_delta:
            side_by_side = WORK / app.name / f"mismatch_tab{tab}.png"
            difference.save(side_by_side)
            raise Failure(
                f"tab {tab}: a pixel differs by {worst}, more than colour "
                f"rounding. See {app_shots[tab]}, {converted_shots[tab]} and "
                f"{side_by_side}."
            )


def snapshot_app(app):
    """Render each tab of the running app with lv_snapshot_take()."""
    script = WORK / app.name / "snapshot.gdb"
    script.write_text(f"""
python
import sys
sys.path.insert(0, "{SRC}/gdb_plugin")
import lvglgdb
end
break lv_timer_handler
# The second call: by then LVGL has laid out and drawn a full cycle.
ignore 1 1
run {app.args}
python
import gdb
from lvglgdb.lvgl.core.lv_global import curr_inst
from lvglgdb.lvgl.core.lv_obj import LVObject
from lvglgdb.lvgl.draw.lv_draw_buf import LVDrawBuf

lvgl = curr_inst(); lvgl.ensure_init()
screen = LVObject(lvgl.screen_active())


def find(obj, cls):
    if obj.class_name == cls:
        return obj
    for child in obj.children:
        found = find(child, cls)
        if found is not None:
            return found
    return None


tabview = find(screen, "lv_tabview")
for tab in range({app.tabs}):
    if tabview is not None:
        gdb.parse_and_eval("lv_tabview_set_active(%d, %d, 0)" % (int(tabview), tab))
    gdb.parse_and_eval("lv_obj_update_layout(%d)" % int(screen))
    buf = gdb.parse_and_eval(
        "lv_snapshot_take(%d, LV_COLOR_FORMAT_ARGB8888)" % int(screen))
    LVDrawBuf(buf).data_dump("{WORK / app.name}/app_tab%d.png" % tab)
end
kill
""")
    run(["gdb", "-batch", "-nx", "-x", str(script), str(app.binary)],
        cwd=app.build)
    return [WORK / app.name / f"app_tab{tab}.png" for tab in range(app.tabs)]


def snapshot_converted(app, cli):
    """Render each tab of the converted project with the Pro CLI.

    From a copy, because `generate` writes its C output and an emscripten build
    tree into the project, and because each tab needs the XML edited. What the
    converter produced has to stay exactly as it was for the XML comparison.
    """
    preview = WORK / app.name / "preview"
    shutil.rmtree(preview, ignore_errors=True)
    shutil.copytree(app.out, preview)

    screen = sorted((preview / "screens").glob("*.xml"))[0]
    original = screen.read_text()
    shots = []
    for tab in range(app.tabs):
        screen.write_text(set_active_tab(original, tab))
        run(["node", str(Path(cli) / "lved-cli.js"), "generate", str(preview)])
        shot = WORK / app.name / f"converted_tab{tab}.png"
        run(["node", str(Path(cli) / "lved-cli.js"), "screenshot", str(preview),
             f"screens/{screen.name}", "--out", str(shot)])
        shots.append(shot)
    return shots


def set_active_tab(xml, tab):
    """Point the screen's tabview at `tab`, whether or not it says already."""
    if re.search(r'<lv_tabview\b[^>]*\bactive="', xml):
        return re.sub(r'(<lv_tabview\b[^>]*\bactive=")[^"]*"',
                      rf'\g<1>{tab}"', xml, count=1)
    return xml.replace("<lv_tabview ", f'<lv_tabview active="{tab}" ', 1)


# --------------------------------------------------------------------------


def main():
    parser = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("command", nargs="?", default="all",
                        choices=["all", "build", "convert", "compare"])
    parser.add_argument("--app", choices=[a.name for a in APPS],
                        help="only this app, instead of all of them")
    parser.add_argument("--cli", default=os.environ.get("LVED_CLI"),
                        help="the unpacked LVGL Pro CLI, for the screenshots")
    parser.add_argument("--update", action="store_true",
                        help="accept the current output as the reference")
    args = parser.parse_args()

    apps = [a for a in APPS if args.app in (None, a.name)]
    for app in apps:
        (WORK / app.name).mkdir(parents=True, exist_ok=True)

    try:
        for app in apps:
            if args.command in ("all", "build"):
                build(app)
            if args.command in ("all", "convert"):
                convert(app)
            if args.command in ("all", "compare"):
                compare_xml(app, args.update)
                compare_screenshots(app, args.cli)
    except Failure as failure:
        print(f"\nFAILED\n{failure}", file=sys.stderr)
        return 1

    print("\nOK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
