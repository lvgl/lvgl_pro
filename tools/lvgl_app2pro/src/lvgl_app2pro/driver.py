"""Runs the app under GDB and brings the dump back."""

import json
import os
import subprocess
import sys
import sysconfig
import tempfile
from pathlib import Path

DUMP_SCRIPT = Path(__file__).with_name("gdb_dump.py")


class DumpError(RuntimeError):
    pass


def _host_site_packages():
    """Where this process's packages live, so GDB's own Python can find them.

    GDB embeds its own interpreter and does not see a virtualenv, so lvglgdb
    is imported from here instead.
    """
    paths = {sysconfig.get_paths().get("purelib"), sysconfig.get_paths().get("platlib")}
    return [p for p in paths if p and os.path.isdir(p)]


def check_gdb(gdb_binary="gdb"):
    """Return GDB's Python version, or raise if GDB cannot run Python at all."""
    try:
        done = subprocess.run(
            [gdb_binary, "-batch", "-nx", "-ex",
             "python import sys; print('%d.%d' % sys.version_info[:2])"],
            capture_output=True, text=True, timeout=60,
        )
    except FileNotFoundError:
        raise DumpError(f"{gdb_binary} not found")
    except subprocess.TimeoutExpired:
        raise DumpError(f"{gdb_binary} did not respond")
    version = done.stdout.strip().splitlines()[-1] if done.stdout.strip() else ""
    if not version or "." not in version:
        raise DumpError(
            f"{gdb_binary} has no Python support, so the LVGL plugin cannot load"
        )
    return version


def dump_app(app, lvgl_dir=None, stop_at="lv_timer_handler", gdb_binary="gdb",
             timeout=300, image_dir=None, app_args=None):
    """Run `app` under GDB, stop once, and return the parsed dump."""
    app = Path(app).resolve()
    if not app.exists():
        raise DumpError(f"{app} does not exist")

    env = dict(os.environ)
    env["LVGL_APP2PRO_BREAK"] = stop_at
    if app_args:
        env["LVGL_APP2PRO_ARGS"] = app_args
    env["LVGL_APP2PRO_SYSPATH"] = json.dumps(_host_site_packages())
    if lvgl_dir:
        env["LVGL_APP2PRO_LVGL"] = str(Path(lvgl_dir).resolve())
    if image_dir:
        image_dir = Path(image_dir).resolve()
        image_dir.mkdir(parents=True, exist_ok=True)
        env["LVGL_APP2PRO_IMAGES"] = str(image_dir)

    with tempfile.TemporaryDirectory() as tmp:
        out_file = Path(tmp) / "dump.json"
        env["LVGL_APP2PRO_OUT"] = str(out_file)
        cmd = [gdb_binary, "-batch", "-nx", "-x", str(DUMP_SCRIPT), str(app)]
        try:
            done = subprocess.run(
                cmd, env=env, cwd=app.parent, capture_output=True, text=True,
                timeout=timeout,
            )
        except subprocess.TimeoutExpired:
            raise DumpError(
                f"the app did not reach {stop_at} within {timeout}s. "
                "Pass --stop-at with a function that runs after the UI is built."
            )
        if not out_file.exists():
            sys.stderr.write(done.stdout)
            sys.stderr.write(done.stderr)
            raise DumpError("GDB produced no dump; see its output above")
        return json.loads(out_file.read_text())
