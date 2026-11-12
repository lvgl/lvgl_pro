#!/usr/bin/env python3
"""Cut a box out of a UI image.

  crop.py IMAGE X,Y,W,H OUT.png                 plain crop
  crop.py IMAGE X,Y,W,H OUT.png --zoom 8        enlarged, sharp pixels: to look at details
  crop.py IMAGE X,Y,W,H OUT.png --alpha auto    remove a flat background: icons, logos
  crop.py IMAGE X,Y,W,H OUT.png --alpha 0x1E232E      the same, with a given background

--alpha unmixes the background color out of every pixel (like "color to alpha" in
GIMP), so anti-aliased edges stay smooth on any new background. `auto` takes the most
common color of the crop's border. --pad adds transparent pixels around the result.
For a one-color icon, load the result as `a8` and color it with `image_recolor`: LVGL
reads only the alpha.

Needs: pip install pillow numpy
"""
import argparse
import numpy as np
from PIL import Image


def parse_color(s, px):
    if s != "auto":
        v = int(s, 16)
        return np.array([(v >> 16) & 255, (v >> 8) & 255, v & 255], float)
    border = np.concatenate([px[0], px[-1], px[:, 0], px[:, -1]]).astype(int)
    keys, counts = np.unique((border[:, 0] << 16) | (border[:, 1] << 8) | border[:, 2],
                             return_counts=True)
    k = int(keys[np.argmax(counts)])
    return np.array([(k >> 16) & 255, (k >> 8) & 255, k & 255], float)


def color_to_alpha(px, bg):
    """Smallest alpha that explains each pixel as a color over bg, and that color."""
    p = px.astype(float)
    up = np.where(p > bg, (p - bg) / np.maximum(255 - bg, 1e-6), 0)
    down = np.where(p < bg, (bg - p) / np.maximum(bg, 1e-6), 0)
    a = np.clip(np.maximum(up, down).max(axis=2), 0, 1)
    safe = np.maximum(a, 1e-6)[..., None]
    rgb = np.clip((p - bg) / safe + bg, 0, 255)
    rgb[a == 0] = 0
    return rgb, a


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("box", help="X,Y,W,H")
    ap.add_argument("out")
    ap.add_argument("--zoom", type=int, default=1)
    ap.add_argument("--alpha", help="background color 0xRRGGBB, or auto")
    ap.add_argument("--pad", type=int, default=0)
    a = ap.parse_args()

    x, y, w, h = map(int, a.box.split(","))
    img = Image.open(a.image).convert("RGB").crop((x, y, x + w, y + h))
    if a.alpha:
        px = np.asarray(img)
        rgb, alpha = color_to_alpha(px, parse_color(a.alpha, px))
        out = np.dstack([rgb, alpha * 255]).round().astype(np.uint8)
        img = Image.fromarray(out, "RGBA")
        bg_count = int((alpha == 0).sum())
        print(f"transparent pixels: {bg_count}/{alpha.size}")
    if a.pad:
        mode = img.mode
        big = Image.new(mode, (img.width + 2 * a.pad, img.height + 2 * a.pad),
                        (0, 0, 0, 0) if mode == "RGBA" else (0, 0, 0))
        big.paste(img, (a.pad, a.pad))
        img = big
    if a.zoom > 1:
        img = img.resize((img.width * a.zoom, img.height * a.zoom), Image.NEAREST)
    img.save(a.out)
    print(f"{a.out}: {img.width}x{img.height} {img.mode}")


if __name__ == "__main__":
    main()
