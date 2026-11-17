#!/usr/bin/env python3
"""Rank fonts by how well they match one line of text cut from a UI image.

Each candidate is rendered with the same text at the sizes near the crop's height and
width, and compared with the crop. A variable font is tried at several weights. The
family is ranked by shape and width; the weight inside the best family also by total
ink (stroke thickness). The size printed is the em size in px of the image: the `size`
of a <bin> font if the image is at display scale.

Tested on LVGL, browser, upscaled and JPEG text: the family was right in 14 of 14 cases;
the weight can be 100 off and the size 1 px off. Results less than about 0.02 apart are
a tie: try each of them in LVGL.

Usage: font_match.py CROP.png "the exact text" FONT.ttf|DIR [...] [--weights 300,400]
Needs: pip install pillow numpy
"""
import argparse
import os
import numpy as np
from PIL import Image, ImageDraw, ImageFont


def coverage(img):
    """0..1 ink coverage of a text crop on a plain background."""
    px = np.asarray(img.convert("RGB")).astype(float)
    flat = px.reshape(-1, 3).astype(int)
    keys, counts = np.unique((flat[:, 0] << 16) | (flat[:, 1] << 8) | flat[:, 2],
                             return_counts=True)
    k = int(keys[np.argmax(counts)])
    bg = np.array([(k >> 16) & 255, (k >> 8) & 255, k & 255], float)
    d = np.abs(px - bg).max(axis=2)
    return np.clip(d / max(np.percentile(d, 98), 1), 0, 1)


def trim(cov, thr=0.25):
    ys = np.where((cov > thr).any(axis=1))[0]
    xs = np.where((cov > thr).any(axis=0))[0]
    if len(ys) == 0:
        return None
    return cov[ys[0]:ys[-1] + 1, xs[0]:xs[-1] + 1]


def axis_name(a):
    n = a.get("name", b"")
    return (n.decode() if isinstance(n, bytes) else n).lower()


def render(font_path, text, size, weight):
    f = ImageFont.truetype(font_path, size)
    if weight is not None:
        f.set_variation_by_axes([weight if axis_name(a) in ("weight", "wght") else a["default"]
                                 for a in f.get_variation_axes()])
    l, t, r, b = f.getbbox(text)
    im = Image.new("L", (r - l + 4, b - t + 4), 0)
    ImageDraw.Draw(im).text((2 - l, 2 - t), text, font=f, fill=255)
    return trim(np.asarray(im) / 255.0)


def shrink(cov, w, h):
    return np.asarray(Image.fromarray((cov * 255).astype(np.uint8)).resize((w, h), Image.LANCZOS)) / 255.0


def compare(crop, cand):
    """Shape similarity (1 = same) and ink difference, both at about 20 px high, so a
    blurry or upscaled crop compares fairly with a sharp rendering."""
    h = min(crop.shape[0], 20)
    w = max(1, round(crop.shape[1] * h / crop.shape[0]))
    a, b = shrink(crop, w, h), shrink(cand, w, h)
    shape = 1 - np.abs(a - b).mean() / max(a.mean(), 1e-6) / 2
    return shape, b.mean() / max(a.mean(), 1e-6) - 1


def family(path):
    """'Poppins-SemiBold.ttf' and 'Inter[opsz,wght].ttf' -> 'Poppins', 'Inter'."""
    name = ImageFont.truetype(path, 20).getname()[0]
    return name or os.path.basename(path).split("[")[0].split("-")[0]


def candidates(paths, weights):
    files = []
    for p in paths:
        if os.path.isdir(p):
            files += [os.path.join(p, f) for f in sorted(os.listdir(p))
                      if f.lower().endswith((".ttf", ".otf"))]
        else:
            files.append(p)
    for f in files:
        try:
            font = ImageFont.truetype(f, 20)
        except OSError:
            print(f"skipped {f}: it cannot be loaded as a font")
            continue
        try:
            axes = font.get_variation_axes()
        except Exception:
            axes = []
        wght = [a for a in axes if axis_name(a) in ("weight", "wght")]
        if wght:
            for wt in weights:
                if wght[0]["minimum"] <= wt <= wght[0]["maximum"]:
                    yield f, wt
        else:
            yield f, None


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("crop")
    ap.add_argument("text")
    ap.add_argument("fonts", nargs="+", help="TTF/OTF files or folders")
    ap.add_argument("--weights", default="300,400,500,600,700,800",
                    help="weights to try on variable fonts")
    ap.add_argument("--top", type=int, default=8)
    a = ap.parse_args()

    crop = trim(coverage(Image.open(a.crop)))
    if crop is None:
        ap.error(f"{a.crop} has no text: it is one flat color")
    ch, cw = crop.shape
    weights = [int(w) for w in a.weights.split(",")]
    rows = []
    for f, wt in candidates(a.fonts, weights):
        r = render(f, a.text, 100, wt)
        if r is None:
            continue
        by_h = round(100 * ch / r.shape[0])
        by_w = round(100 * cw / r.shape[1])
        for size in sorted({max(4, by_h + d) for d in (-2, -1, 0, 1, 2)} | {max(4, by_w)}):
            cand = render(f, a.text, size, wt)
            if cand is None:
                continue
            shape, ink_err = compare(crop, cand)
            rows.append(dict(family=family(f), file=os.path.basename(f), wght=wt, size=size,
                             shape=shape, ink=ink_err, width=cand.shape[1] / cw - 1,
                             h=cand.shape[0] - ch))
    if not rows:
        ap.error("no font could be rendered: check the font files, and that --weights is "
                 "inside the weight range of each variable font")

    # Two stages. The family from shape and width only: total ink depends on the
    # renderer (a browser draws text lighter than FreeType). Then, inside that family,
    # the weight and size, where the ink does tell the stroke weight.
    fam_score = lambda r: r["shape"] - abs(r["width"]) - 0.01 * abs(r["h"])
    in_fam_score = lambda r: r["shape"] - abs(r["width"]) - 0.5 * abs(r["ink"])
    best_per_family = {}
    for r in rows:
        if r["family"] not in best_per_family or fam_score(r) > fam_score(best_per_family[r["family"]]):
            best_per_family[r["family"]] = r
    families = sorted(best_per_family.values(), key=fam_score, reverse=True)

    def show(r, s):
        wt = f" wght={r['wght']}" if r["wght"] else ""
        return (f"{s:6.3f}  {r['size']:4d}  {r['width']:+6.1%}  {r['h']:+3d}  {r['ink']:+6.1%}  "
                f"{r['file']}{wt}")

    head = f"{'score':>6}  {'size':>4}  {'width':>6}  {'h':>3}  {'ink':>6}  font"
    print(f"crop ink {cw}x{ch} px, text {a.text!r}\n\nFamilies (shape and width):\n{head}")
    for r in families[:a.top]:
        print(show(r, fam_score(r)))
    top = families[0]["family"]
    print(f"\nWeight and size inside {top} (shape, width and ink):\n{head}")
    seen = set()
    for r in sorted((r for r in rows if r["family"] == top), key=in_fam_score, reverse=True):
        if (r["file"], r["wght"]) not in seen:
            seen.add((r["file"], r["wght"]))
            print(show(r, in_fam_score(r)))
        if len(seen) == 4:
            break


if __name__ == "__main__":
    main()
