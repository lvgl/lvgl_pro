#!/usr/bin/env python3
"""Generate C files for the XML examples by driving `lved-cli.js`.

`examples/lvgl_pro/` is itself a valid LVGL Pro project (`project.xml`,
`globals.xml`, `screens/*.xml`). A single CLI run converts every screen XML into
a sibling `lv_example_<name>_gen.{c,h}`. This script then:

1. Runs `lved-cli.js generate examples/lvgl_pro` to (re)create those `_gen` files.
2. Drops the `_gen` suffix from each per-example `screens/lv_example_*_gen.c`
   and deletes the per-example `_gen.h` headers (the project-level `*_gen.*`
   scaffolding at the project root is left alone, it's part of the build).
3. Runs the `cleanup_examples.py` transformations so the result reads like a
   hand-written example.
4. Writes a single `examples/lvgl_pro/lv_examples.h` declaring every example's
   prototype (the header each cleaned `.c` includes via `../lv_examples.h`).

USAGE
-----
    python docs/scripts/generate_examples.py [--cli /path/to/lved-cli.js]
"""

from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

# Reuse the transformation pipeline from the sibling cleanup script directly.
sys.path.insert(0, str(Path(__file__).resolve().parent))
import cleanup_examples  # noqa: E402

REPO_ROOT = Path(__file__).resolve().parents[2]
EXAMPLES_DIR = REPO_ROOT / "examples" / "lvgl_pro"
SCREENS_DIR = EXAMPLES_DIR / "screens"
EXAMPLES_HEADER = EXAMPLES_DIR / "lv_examples.h"

# Shared header listing every example prototype. `cleanup_examples.py`
# collapses each example's includes to a single `../lv_examples.h`, so this is
# the one header the generated `.c` files compile against.
EXAMPLES_HEADER_TEMPLATE = """\
/**
 * @file lv_examples.h
 *
 */

#ifndef LV_EXAMPLES_H
#define LV_EXAMPLES_H

#ifdef __cplusplus
extern "C" {{
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lvgl.h"

{prototypes}

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
}} /*extern "C"*/
#endif

#endif /*LV_EXAMPLES_H*/
"""


def resolve_cli(cli_arg: str | None) -> str:
    """Resolve the lved-cli.js path. Use --cli if given, else search PATH."""
    if cli_arg:
        p = Path(cli_arg).expanduser().resolve()
        if not p.exists():
            sys.exit(f"--cli path does not exist: {p}")
        return str(p)
    found = shutil.which("lved-cli.js")
    if found:
        return found
    sys.exit("lved-cli.js not found on PATH; pass --cli /path/to/lved-cli.js")


def generate(cli_path: str) -> bool:
    """Run `lved-cli.js generate examples/lvgl_pro` against the examples project."""
    result = subprocess.run(
        ["node", cli_path, "generate", str(EXAMPLES_DIR.relative_to(REPO_ROOT))],
        cwd=REPO_ROOT,
    )
    return result.returncode == 0


def strip_gen_suffix() -> list[Path]:
    """Normalize the per-example files the CLI emitted into `screens/`.

    Renames each `lv_example_*_gen.c` to drop the `_gen` suffix and deletes
    the matching `_gen.h` (every prototype lives in the shared
    `lv_examples.h` instead). Scoped to the per-example files in `screens/`,
    so the project-level `examples_gen.*` / `*_list_gen.cmake` scaffolding at
    the project root keeps its name.

    Returns the renamed `.c` paths.
    """
    # No per-example header survives — every prototype lives in the shared
    # `lv_examples.h`. Remove both the freshly generated `_gen.h` and any
    # stale plain `.h` left by an earlier run.
    for header in SCREENS_DIR.glob("lv_example_*.h"):
        header.unlink()

    renamed: list[Path] = []
    for src in sorted(SCREENS_DIR.glob("lv_example_*_gen.c")):
        dst = src.with_name(src.stem[: -len("_gen")] + src.suffix)
        src.replace(dst)
        renamed.append(dst)
    return renamed


def write_examples_header(example_cs: list[Path]) -> None:
    """Write `examples/lvgl_pro/lv_examples.h` with a prototype per example `.c`.

    Each `screens/lv_example_<name>.c` defines `void lv_example_<name>(void)`;
    the function name is the file stem, so prototypes derive straight from the
    filenames.
    """
    prototypes = "\n".join(
        f"void {c.stem}(void);" for c in sorted(example_cs, key=lambda p: p.stem)
    )
    EXAMPLES_HEADER.write_text(
        EXAMPLES_HEADER_TEMPLATE.format(prototypes=prototypes)
    )


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(
        description="Generate C files for the XML examples via lved-cli.js."
    )
    parser.add_argument(
        "--cli",
        help="path to lved-cli.js (defaults to a PATH lookup)",
    )
    args = parser.parse_args(argv)

    cli_path = resolve_cli(args.cli)

    print("generating C from examples/lvgl_pro/ via lved-cli.js")
    if not generate(cli_path):
        sys.stderr.write("  ! lved-cli generation failed\n")
        return 1

    renamed = strip_gen_suffix()
    for p in renamed:
        print(f"  renamed: {p.relative_to(REPO_ROOT)}")

    print("cleaning generated C via cleanup_examples.py")
    rc = cleanup_examples.main([])

    write_examples_header(renamed)
    print(f"wrote header: {EXAMPLES_HEADER.relative_to(REPO_ROOT)}")
    return rc


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
