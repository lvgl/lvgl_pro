#!/usr/bin/env python3
"""Build the docs copy of the XML examples.

`examples/lvgl_pro/` is an ordinary LVGL Pro project (`project.xml`,
`globals.xml`, `screens/*.xml`) with an ordinary export. The docs need
something different from that export: no `_gen` suffixes, no per-example
headers, one shared `lv_examples.h`, and C that reads as if a person wrote it.

So this script **copies** the export into `docs/examples/` and transforms the
copy. The project is only read from. That separation matters: the whole
`docs/examples/` folder is dropped into an emscripten checkout as lvgl's own
`examples/` directory by `build_html_examples.sh`, so it must contain nothing
but examples — no `sim/`, no `CMakeLists.txt`, no `_gen` files.

Steps:

1. Run `lvglpro generate examples/lvgl_pro`, producing the project's normal
   export in place.
2. Copy into `docs/examples/`: every `screens/*.xml`, each
   `screens/lv_example_*_gen.c` as `lv_example_*.c`, and the generated font and
   image data.
3. Run the `cleanup_examples.py` transformations over the copy.
4. Write `docs/examples/lv_examples.h` declaring every example's prototype —
   the header each cleaned `.c` includes via `../lv_examples.h`.

Nothing under `examples/lvgl_pro/` is renamed or deleted, so `git status` stays
clean there apart from the export itself.

USAGE
-----
    python docs/scripts/generate_examples.py [--out DIR] [--cli lvglpro]

The CLI is the `lvglpro` binary from `npm install --global @lvgl/lvglpro`, and
it needs `LVGLPRO_CLI_TOKEN` in the environment.
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

# The project, read from only.
PROJECT_DIR = REPO_ROOT / "examples" / "lvgl_pro"
PROJECT_SCREENS_DIR = PROJECT_DIR / "screens"

# The docs copy, written by this script.
DEFAULT_OUT_DIR = REPO_ROOT / "docs" / "examples"

# Folders holding generated asset data that the examples link against. Copied
# from the project as-is; `cleanup_examples.py` drops the `_data` suffix.
ASSET_DIRS = ("fonts", "images")

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


def display(path: Path) -> str:
    """Path for messages: repo-relative when it is inside the repo, else absolute.

    `--out` may point anywhere, and `relative_to` raises for paths outside the repo.
    """
    try:
        return str(path.relative_to(REPO_ROOT))
    except ValueError:
        return str(path)


def resolve_cli(cli_arg: str | None) -> str:
    """Resolve the CLI. Use --cli if given, else find `lvglpro` on PATH."""
    if cli_arg:
        return cli_arg
    found = shutil.which("lvglpro")
    if found:
        return found
    sys.exit(
        "lvglpro not found on PATH. Install it with "
        "`npm install --global @lvgl/lvglpro`, or pass --cli."
    )


def generate(cli_path: str) -> bool:
    """Run `lvglpro generate examples/lvgl_pro` against the examples project."""
    result = subprocess.run(
        [cli_path, "generate", str(PROJECT_DIR.relative_to(REPO_ROOT))],
        cwd=REPO_ROOT,
    )
    return result.returncode == 0


def copy_to_out(out_dir: Path) -> list[Path]:
    """Copy the parts of the export the docs need into `out_dir`.

    Per-example `.c` files lose the `_gen` suffix on the way over, and the
    `_gen.h` headers are not copied at all — every prototype lives in the shared
    `lv_examples.h`. The `.xml` beside each example comes too, because the docs
    site renders it as the XML tab.

    The destination is cleared first, so an example deleted from the project
    does not linger here. Returns the copied `.c` paths.
    """
    if out_dir.exists():
        shutil.rmtree(out_dir)

    screens_out = out_dir / "screens"
    screens_out.mkdir(parents=True)

    copied: list[Path] = []
    for src in sorted(PROJECT_SCREENS_DIR.glob("lv_example_*_gen.c")):
        dst = screens_out / (src.stem[: -len("_gen")] + src.suffix)
        shutil.copyfile(src, dst)
        copied.append(dst)

    for xml in sorted(PROJECT_SCREENS_DIR.glob("*.xml")):
        shutil.copyfile(xml, screens_out / xml.name)

    for asset_dir in ASSET_DIRS:
        for data_c in sorted((PROJECT_DIR / asset_dir).glob("*.c")):
            dst_dir = out_dir / asset_dir
            dst_dir.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(data_c, dst_dir / data_c.name)

    return copied


def write_examples_header(out_dir: Path, example_cs: list[Path]) -> Path:
    """Write `<out_dir>/lv_examples.h` with a prototype per example `.c`.

    Each `screens/lv_example_<name>.c` defines `void lv_example_<name>(void)`;
    the function name is the file stem, so prototypes derive straight from the
    filenames.
    """
    prototypes = "\n".join(
        f"void {c.stem}(void);" for c in sorted(example_cs, key=lambda p: p.stem)
    )
    header = out_dir / "lv_examples.h"
    header.write_text(EXAMPLES_HEADER_TEMPLATE.format(prototypes=prototypes))
    return header


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(
        description="Build the docs copy of the XML examples."
    )
    parser.add_argument(
        "--out",
        type=Path,
        default=DEFAULT_OUT_DIR,
        help=f"where to write the docs copy (default: {display(DEFAULT_OUT_DIR)})",
    )
    parser.add_argument(
        "--cli",
        help="path to the lvglpro binary (defaults to a PATH lookup)",
    )
    args = parser.parse_args(argv)

    out_dir = args.out.resolve()
    # `copy_to_out` clears the destination first, so any path that overlaps the
    # project would delete the source. Equality is not enough: a subfolder of the
    # project, or a parent that contains it, would take the project with it.
    if (
        out_dir == PROJECT_DIR
        or PROJECT_DIR in out_dir.parents
        or out_dir in PROJECT_DIR.parents
    ):
        sys.exit(
            f"--out must not overlap {PROJECT_DIR}; the docs copy is a separate tree."
        )

    cli_path = resolve_cli(args.cli)

    print("generating C from examples/lvgl_pro/ via lvglpro")
    if not generate(cli_path):
        sys.stderr.write("  ! lvglpro generation failed\n")
        return 1

    copied = copy_to_out(out_dir)
    print(f"copied {len(copied)} examples to {display(out_dir)}/screens")

    print("cleaning the copy via cleanup_examples.py")
    rc = cleanup_examples.run(PROJECT_DIR, out_dir)

    header = write_examples_header(out_dir, copied)
    print(f"wrote header: {display(header)}")
    return rc


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
