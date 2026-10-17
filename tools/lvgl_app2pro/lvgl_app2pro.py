#!/usr/bin/env python3
"""Convert a running LVGL Open application into an LVGL Pro XML project.

    python3 lvgl_app2pro.py ./my_app -o my_project

Nothing has to be installed: this adds src/ to the path and runs the package
from there. See README.md.
"""

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent / "src"))

from lvgl_app2pro.cli import main  # noqa: E402  (needs the path set first)

if __name__ == "__main__":
    sys.exit(main())
