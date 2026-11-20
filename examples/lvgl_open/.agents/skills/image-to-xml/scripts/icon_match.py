#!/usr/bin/env python3
"""Find an icon from a UI image in a folder of SVG icons (Lucide, Tabler, Material...).

Every SVG is rendered at the crop's size and its shape is compared with the crop. Color
does not matter. Prints the best matches. Look at the top ones before you pick: icons
in one set often differ only in a small detail.

Usage: icon_match.py CROP.png ICON_DIR [ICON_DIR ...] [--top 10]
Needs: pip install pillow numpy cairosvg
"""
import argparse
import io
import os
import numpy as np
from PIL import Image
import cairosvg

SIZE = 48


def coverage(img):
    """0..1 shape of an icon crop: its alpha, or its distance from the edge color."""
    img = img.convert("RGBA")
    px = np.asarray(img).astype(float)
    if px[..., 3].min() < 250:
        return px[..., 3] / 255
    rgb = px[..., :3]
    edge = np.concatenate([rgb[0], rgb[-1], rgb[:, 0], rgb[:, -1]])
    bg = np.median(edge, axis=0)
    d = np.abs(rgb - bg).max(axis=2)
    return np.clip(d / max(d.max(), 1), 0, 1)


def fit(cov):
    """Crop to the shape and center it in a SIZE x SIZE square, keeping the aspect."""
    ys = np.where((cov > 0.25).any(axis=1))[0]
    xs = np.where((cov > 0.25).any(axis=0))[0]
    if len(ys) == 0:
        return None
    cov = cov[ys[0]:ys[-1] + 1, xs[0]:xs[-1] + 1]
    h, w = cov.shape
    k = (SIZE - 4) / max(h, w)
    im = Image.fromarray((cov * 255).astype(np.uint8)).resize(
        (max(1, round(w * k)), max(1, round(h * k))), Image.LANCZOS)
    out = Image.new("L", (SIZE, SIZE), 0)
    out.paste(im, ((SIZE - im.width) // 2, (SIZE - im.height) // 2))
    return np.asarray(out) / 255.0


def render_svg(path):
    svg = open(path, encoding="utf-8").read().replace("currentColor", "#000000")
    png = cairosvg.svg2png(bytestring=svg.encode(), output_width=SIZE * 2, output_height=SIZE * 2)
    return np.asarray(Image.open(io.BytesIO(png)).convert("RGBA"))[..., 3] / 255.0


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("crop")
    ap.add_argument("dirs", nargs="+")
    ap.add_argument("--top", type=int, default=10)
    a = ap.parse_args()

    target = fit(coverage(Image.open(a.crop)))
    if target is None:
        ap.error(f"{a.crop} has no icon: it is one flat color")
    rows = []
    for d in a.dirs:
        for root, _, files in os.walk(d):
            for f in files:
                if not f.endswith(".svg"):
                    continue
                path = os.path.join(root, f)
                try:
                    cand = fit(render_svg(path))
                except Exception:
                    continue
                if cand is None:
                    continue
                diff = np.abs(target - cand).sum() / max(target.sum() + cand.sum(), 1e-6)
                rows.append((diff, path))
    rows.sort()
    print(f"{len(rows)} icons compared. Lower is better.")
    for diff, path in rows[:a.top]:
        print(f"{diff:6.3f}  {path}")


if __name__ == "__main__":
    main()
