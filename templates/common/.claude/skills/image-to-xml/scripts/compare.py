#!/usr/bin/env python3
"""Compare a reference image (the design) with an LVGL screenshot.

Writes one PNG with four panels: reference, screenshot, a 50% blend (offsets show as
double edges), and a heat map of the difference. Prints the mean difference and the
boxes where the two differ most, largest first, in screenshot pixels.

The reference is scaled to the screenshot's size first. If their aspect ratios differ,
crop the reference to the display area before you compare.

Usage: compare.py REFERENCE SCREENSHOT OUT.png [--thr 40] [--cell 8] [--top 10]
Needs: pip install pillow numpy
"""
import argparse
import numpy as np
from PIL import Image


def boxes(mask, cell):
    """Group the cells that differ into boxes (4-connected), in pixels."""
    h, w = mask.shape
    gh, gw = (h + cell - 1) // cell, (w + cell - 1) // cell
    grid = np.zeros((gh, gw))
    for gy in range(gh):
        for gx in range(gw):
            grid[gy, gx] = mask[gy * cell:(gy + 1) * cell, gx * cell:(gx + 1) * cell].sum()
    seen = np.zeros_like(grid, bool)
    out = []
    for gy in range(gh):
        for gx in range(gw):
            if grid[gy, gx] == 0 or seen[gy, gx]:
                continue
            stack, cells = [(gy, gx)], []
            seen[gy, gx] = True
            while stack:
                cy, cx = stack.pop()
                cells.append((cy, cx))
                for ny, nx in ((cy + 1, cx), (cy - 1, cx), (cy, cx + 1), (cy, cx - 1)):
                    if 0 <= ny < gh and 0 <= nx < gw and grid[ny, nx] and not seen[ny, nx]:
                        seen[ny, nx] = True
                        stack.append((ny, nx))
            ys = [c[0] for c in cells]
            xs = [c[1] for c in cells]
            px = sum(grid[c] for c in cells)
            out.append((px, min(xs) * cell, min(ys) * cell,
                        min((max(xs) + 1) * cell, w) - min(xs) * cell,
                        min((max(ys) + 1) * cell, h) - min(ys) * cell))
    return sorted(out, reverse=True)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("reference")
    ap.add_argument("screenshot")
    ap.add_argument("out")
    ap.add_argument("--thr", type=int, default=40, help="channel difference that counts")
    ap.add_argument("--cell", type=int, default=8, help="grid size for grouping, px")
    ap.add_argument("--top", type=int, default=10)
    a = ap.parse_args()
    if a.cell < 1:
        ap.error("--cell must be 1 or more")

    shot = Image.open(a.screenshot).convert("RGB")
    ref = Image.open(a.reference).convert("RGB")
    ra, sa = ref.width / ref.height, shot.width / shot.height
    if abs(ra / sa - 1) > 0.02:
        print(f"warning: aspect ratios differ (reference {ref.width}x{ref.height}, "
              f"screenshot {shot.width}x{shot.height}). Crop the reference first.")
    ref = ref.resize(shot.size, Image.LANCZOS)

    r = np.asarray(ref).astype(int)
    s = np.asarray(shot).astype(int)
    d = np.abs(r - s).max(axis=2)
    mask = d > a.thr

    heat = np.zeros_like(s)
    heat[..., 0] = np.clip(d * 3, 0, 255)
    heat[..., 1] = np.clip(d * 3 - 255, 0, 255)
    blend = (r + s) // 2
    panels = [r, s, blend, heat]
    gap = 4
    w, h = shot.size
    sheet = np.full((h, 4 * w + 3 * gap, 3), 128, np.uint8)
    for i, p in enumerate(panels):
        sheet[:, i * (w + gap):i * (w + gap) + w] = p.astype(np.uint8)
    Image.fromarray(sheet).save(a.out)

    print(f"{a.out}: reference | screenshot | blend | difference")
    print(f"mean difference {d.mean():.1f}, pixels over {a.thr}: {mask.mean():.1%}")
    for px, x, y, bw, bh in boxes(mask, a.cell)[:a.top]:
        print(f"  [{x},{y} {bw}x{bh}] {int(px)} px differ")


if __name__ == "__main__":
    main()
