"""lvgl_app2pro — convert a running LVGL Open app into an LVGL Pro XML project."""

import argparse
import json
import shutil
import sys
from pathlib import Path

from . import consts as consts_mod
from . import emit, model, schema as schema_mod, values
from .driver import DumpError, check_gdb, dump_app


def build_parser():
    parser = argparse.ArgumentParser(
        prog="lvgl_app2pro",
        description="Convert a running LVGL Open app into an LVGL Pro XML project.",
    )
    parser.add_argument("app", nargs="?",
                        help="the compiled application to inspect, unless "
                             "--from-dump is given")
    parser.add_argument("-o", "--out", default="pro_project",
                        help="output directory (default: pro_project)")
    parser.add_argument("--lvgl", metavar="DIR",
                        help="an LVGL checkout to load scripts/gdb from, instead "
                             "of the installed lvglgdb")
    parser.add_argument("--stop-at", default="lv_timer_handler", metavar="LOCATION",
                        help="where to stop the app, any GDB breakpoint location "
                             "(default: lv_timer_handler, the first refresh after "
                             "the UI is built)")
    parser.add_argument("--app-args", metavar="ARGS",
                        help="command line to start the app with, if it takes one")
    parser.add_argument("--gdb", default="gdb", help="the GDB binary to use")
    parser.add_argument("--timeout", type=int, default=300,
                        help="seconds to wait for the app to reach the stop point")
    parser.add_argument("--lvgl-version", metavar="X.Y.Z",
                        help="override the LVGL version read out of the "
                             "application, which decides the schemas to convert "
                             "against and what project.xml declares")
    parser.add_argument("--number-consts", type=int, default=3, metavar="N",
                        help="make a const of any number used N or more times, "
                             "0 to keep numbers inline (default: 3)")
    parser.add_argument("--include-layers", action="store_true",
                        help="also convert the bottom/top/system layers, which "
                             "are LVGL's own and not screens of the UI")
    parser.add_argument("--keep-fonts", action="store_true",
                        help="write text_font even though the font cannot be "
                             "declared, so the project will not build as-is")
    parser.add_argument("--schema", metavar="DIR",
                        help="widget schema directory to read properties and enum "
                             "values from (defaults to the ones shipped here)")
    parser.add_argument("--dump", metavar="FILE",
                        help="write the raw JSON dump here as well")
    parser.add_argument("--from-dump", metavar="FILE",
                        help="convert a saved JSON dump instead of running the app")
    return parser


#: Only used when the application does not report its own LVGL version.
FALLBACK_VERSION = "9.5.0"


def _restore_images(dump, image_dir):
    """Put the images a saved dump rebuilt into this run's project.

    The dump names each image but keeps the pixels in the directory the original
    run wrote them to, so converting the same dump into a different --out has to
    copy them across or globals.xml points at files that are not there.
    """
    source_dir = dump.get("image_dir")
    if not source_dir:
        return
    source_dir = Path(source_dir)
    missing = []
    for info in (dump.get("images") or {}).values():
        name = info.get("file")
        if not name:
            continue
        source = source_dir / name
        target = image_dir / name
        if not source.exists():
            missing.append(name)
            continue
        # Overwrite: a name that is already there may be another conversion's
        # image, and the dump's own pixels are the right ones.
        if source.resolve() == target.resolve():
            continue
        image_dir.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)
    if missing:
        print(f"WARNING: {len(missing)} image(s) the dump rebuilt are no longer "
              f"in {source_dir}: {', '.join(sorted(missing))}", file=sys.stderr)


def report_capabilities(capabilities):
    """Say what the binary's debug info could not confirm, before converting."""
    problems = []
    if not capabilities.get("is_theme"):
        problems.append(
            "this LVGL has no is_theme flag on _lv_obj_style_t, so theme styles "
            "cannot be told apart and will be written into every widget"
        )
    if not (capabilities.get("screens") and capabilities.get("screen_cnt")):
        problems.append(
            "this LVGL's lv_display_t has no screens[] array, so only the active "
            "screen was reachable"
        )
    return problems


def convert(dump, out_dir, lvgl_version, number_consts, include_layers=False,
            schema_dir=None, keep_fonts=False):
    """Turn a dump into a project on disk. Returns the report and the file list."""
    report = values.Report()
    report.schema = schema_mod.load(schema_dir, lvgl_version)
    report.keep_fonts = keep_fonts
    report.class_defaults = dump.get("class_defaults") or {}
    screens = model.build_screens(
        dump,
        values.make_prop_filter(report),
        values.make_widget_filter(report),
        include_layers=include_layers,
    )
    if not screens:
        raise DumpError("the dump contains no screens")

    found = consts_mod.collect(screens, number_repeats=number_consts) \
        if number_consts else consts_mod.Consts()
    if number_consts:
        consts_mod.apply(screens, found)

    model.resolve_flags(screens, dump.get("class_defaults"),
                        report.schema, report, dump.get("theme_reference"))
    book = emit.plan_styles(screens)
    written = emit.write_project(
        Path(out_dir), dump, screens, book, found, report, lvgl_version
    )
    return screens, found, book, report, written


def main(argv=None):
    args = build_parser().parse_args(argv)

    try:
        if args.from_dump:
            dump = json.loads(Path(args.from_dump).read_text())
            _restore_images(dump, Path(args.out) / "images")
        elif not args.app:
            raise DumpError("give an application to convert, or --from-dump FILE")
        else:
            gdb_python = check_gdb(args.gdb)
            print(f"GDB Python: {gdb_python}")
            print(f"Running {args.app} to {args.stop_at} ...")
            dump = dump_app(args.app, lvgl_dir=args.lvgl, stop_at=args.stop_at,
                            gdb_binary=args.gdb, timeout=args.timeout,
                            image_dir=Path(args.out) / "images",
                            app_args=args.app_args, gdb_python=gdb_python)
        if args.dump:
            Path(args.dump).write_text(json.dumps(dump, indent=1))

        for problem in report_capabilities(dump.get("capabilities") or {}):
            print(f"WARNING: {problem}", file=sys.stderr)

        # The application's own LVGL version decides which schemas describe it.
        # --lvgl-version is the override, not the source.
        version = args.lvgl_version or dump.get("lvgl_version")
        if not version:
            version = FALLBACK_VERSION
            print(f"WARNING: the application does not say which LVGL it was built "
                  f"against; converting as {version}", file=sys.stderr)
        print(f"LVGL version: {version}"
              + ("" if args.lvgl_version is None else " (from --lvgl-version)"))

        screens, found, book, report, written = convert(
            dump, args.out, version, args.number_consts,
            args.include_layers, args.schema, args.keep_fonts,
        )
    except DumpError as e:
        print(f"lvgl_app2pro: {e}", file=sys.stderr)
        return 1

    nodes = sum(len(list(model.walk(s.root))) for s in screens)
    print(f"\nWrote {len(written)} files to {args.out}")
    print(f"  {len(screens)} screens, {nodes} widgets")
    print(f"  {len(book.names)} styles ({len(book.global_names())} shared)")
    print(f"  {len(found.colors)} color consts, {len(found.numbers)} number consts")
    if report.schema and report.schema.source:
        print(f"  enum values from {report.schema.source}")

    rebuilt = [n for n, i in (dump.get("images") or {}).items() if "file" in i]
    missing = sorted(set(report.images) - set(rebuilt))
    if rebuilt:
        print(f"  {len(rebuilt)} images rebuilt as PNG")
    if missing:
        print(f"  {len(missing)} images to supply: {', '.join(missing)}")
    if report.fonts:
        print(f"  {len(report.fonts)} fonts to declare: "
              f"{', '.join(sorted(report.fonts))}")

    # The event hooks are in the XML, but the bodies are compiled code and
    # cannot come across, so they are the main thing left to do by hand.
    if report.callbacks:
        total = sum(len(t) for t in report.callbacks.values())
        print(f"\n  {len(report.callbacks)} event callbacks to implement "
              f"({total} attachments):")
        for name in sorted(report.callbacks):
            triggers = ", ".join(sorted(report.callbacks[name]))
            print(f"    {name}(lv_event_t * e)   on {triggers}")

    if report.unmapped:
        print(f"\n  {len(report.unmapped)} widget fields the app set that XML "
              "cannot express:")
        for name, value in sorted(report.unmapped.items()):
            print(f"    {name} = {value}")

    for warning in report.warnings:
        print(f"  note: {warning}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
