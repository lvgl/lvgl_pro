#!/usr/bin/env python3
"""Extract XML examples from lvgl/examples into the lvgl--examples project.

  1. Copy all XMLs from src_dir into screens/ preserving folder structure.
  2. Run `lved-cli.js validate` on the whole project.
  3. If validation fails, remove every file listed in the error output,
     prune empty dirs, and validate again.
  4. Repeat until validation passes (or no new files are removed).
  5. Run `lved-cli.js generate` once on the clean project.

Result layout in screens/:
    screens/
      widgets/
        button/
          button_basic/
            lv_example_button_basic.xml
            lv_example_button_basic_gen.c
            lv_example_button_basic_gen.h
      styles/
        ...

USAGE
-----
    python scripts/extract_lvgl_examples.py --cli /path/to/lved-cli.js <src_dir>
"""

from __future__ import annotations

import argparse
import shutil
import subprocess
import sys
from pathlib import Path

PROJECT_DIR = Path(__file__).resolve().parent.parent  # lvgl--examples/
SCREENS_DIR = PROJECT_DIR / "screens"

ROOT_METADATA = {"project.xml", "globals.xml"}


def find_example_xmls(src_dir: Path) -> list[Path]:
    targets = []
    for xml in sorted(src_dir.rglob("*.xml")):
        if xml.parent == src_dir and xml.name in ROOT_METADATA:
            continue
        if "xml_project" in xml.parts:
            continue
        targets.append(xml)
    return targets


def resolve_cli(cli_arg: str | None) -> str:
    if cli_arg:
        p = Path(cli_arg).expanduser().resolve()
        if not p.exists():
            sys.exit(f"--cli path does not exist: {p}")
        return str(p)
    found = shutil.which("lved-cli.js")
    if found:
        return found
    sys.exit("lved-cli.js not found on PATH; pass --cli /path/to/lved-cli.js")


def run_cli(cli_path: str, command: str, extra_args: list[str] | None = None) -> subprocess.CompletedProcess:
    cmd = ["node", cli_path, command, str(PROJECT_DIR)]
    if extra_args:
        cmd.extend(extra_args)
    return subprocess.run(cmd, capture_output=True, text=True)


def parse_failed_files(output: str) -> list[Path]:
    """Extract file paths from the '[ERROR] Validation failed for files:' block."""
    failed = []
    in_block = False
    for line in output.splitlines():
        if "[ERROR] Validation failed for files:" in line:
            in_block = True
            continue
        if in_block:
            stripped = line.strip()
            if stripped.startswith("- "):
                failed.append(Path(stripped[2:]))
            elif stripped:
                break  # end of the file list
    return failed


def remove_file(path: Path) -> None:
    """Remove a file and prune now-empty parent dirs up to SCREENS_DIR."""
    path.unlink(missing_ok=True)
    for parent in path.parents:
        if parent == SCREENS_DIR:
            break
        try:
            parent.rmdir()
        except OSError:
            break


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(
        description="Extract XML examples from lvgl/examples into the lvgl--examples project."
    )
    parser.add_argument("--cli", help="path to lved-cli.js (default: PATH lookup)")
    parser.add_argument("src_dir", help="source examples directory (e.g. path/to/lvgl/examples)")
    args = parser.parse_args(argv)

    cli_path = resolve_cli(args.cli)

    src_dir = Path(args.src_dir).resolve()
    if not src_dir.is_dir():
        sys.exit(f"Source directory not found: {src_dir}")

    print(f"Source : {src_dir}")
    print(f"Project: {PROJECT_DIR}")
    print(f"Screens: {SCREENS_DIR}")
    print()

    xmls = find_example_xmls(src_dir)
    if not xmls:
        print("No XML examples found.")
        return 0

    print(f"Found {len(xmls)} XML example(s) — copying all...")
    for xml in xmls:
        rel = xml.relative_to(src_dir)
        dest = SCREENS_DIR / rel
        dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(xml, dest)
    print(f"Copied {len(xmls)} files.")
    print()

     # Iteratively validate and remove failing files
    round_num = 1
    total_removed = 0

    while True:
        print(f"Validation round {round_num}...")

        result = run_cli(cli_path, "validate")
        combined = result.stdout + result.stderr

        if result.stdout:
            print(result.stdout)

        if result.stderr:
            print(result.stderr)

        # Success
        if result.returncode == 0 or "[SUCCESS] Validation passed" in combined:
            print("  All files valid.")
            break

        failed = parse_failed_files(combined)

        if not failed:
            print("  Validation failed but no specific files identified.")
            break

        removed_this_round = 0

        for path in failed:
            if path.exists():
                rel = path.relative_to(PROJECT_DIR) if path.is_relative_to(PROJECT_DIR) else path
                print(f"  removing (invalid): {rel}")
                remove_file(path)
                total_removed += 1
                removed_this_round += 1
            else:
                print(f"  already removed: {path}")

        # Prevent infinite loop
        if removed_this_round == 0:
            print("  No new files removed, stopping to avoid infinite loop.")
            break

        round_num += 1
    kept = len(list(SCREENS_DIR.rglob("*.xml")))
    print(f"\n{kept} valid XML(s) kept, {total_removed} removed.")

    if kept == 0:
        print("Nothing to generate.")
        return 0

    print("\nGenerating C code...")
    result = run_cli(cli_path, "generate", ["--skip-resources", "--ignore-fonts", "--ignore-images"])
    if result.stdout:
        print(result.stdout)
    if result.returncode != 0:
        sys.stderr.write(f"Generate failed (exit {result.returncode}):\n{result.stderr}\n")
        return 1

    print("Done.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
