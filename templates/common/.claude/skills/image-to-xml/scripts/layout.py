#!/usr/bin/env python3
"""Print the layout tree of a UI image: boxes, colors, corner radii, gaps and padding.

Each region is cut into rows or columns where a full line of its background color
separates the parts (recursive XY-cut). A column of parts maps to a flex column, a row
to a flex row, the gaps to pad_row / pad_column, and the margins to padding. Parts side
by side closer than 0.6 of their height are kept together, so a line of text stays one
box. A block with its own background color is a panel: its corner radius and shadow
are measured, and its corners are not counted as content.

Text boxes are ink boxes: smaller than the label, so gaps between text read larger
than pad_row. Correct them after the first screenshot (measure both, subtract).

Usage: layout.py IMAGE [--region X,Y,W,H] [--depth N] [--tol T] [--denoise 3|5]
Needs: pip install pillow numpy
"""
import argparse
import numpy as np
from PIL import Image, ImageFilter


def hexc(c):
    return "0x%02X%02X%02X" % tuple(int(round(v)) for v in c[:3])


def dominant(px):
    """The most common color of a pixel block, and its share. Colors are counted in
    bins of 8 per channel, so JPEG noise does not split one color into many."""
    flat = px.reshape(-1, 3).astype(np.int64)
    q = flat >> 3
    keys = (q[:, 0] << 10) | (q[:, 1] << 5) | q[:, 2]
    vals, counts = np.unique(keys, return_counts=True)
    top = flat[keys == vals[np.argmax(counts)]]
    return np.median(top, axis=0).round().astype(int), counts.max() / flat.shape[0]


def ink(px, bg):
    """Color of the pixels farthest from the background: the text or icon color."""
    flat = px.reshape(-1, 3).astype(int)
    d = np.abs(flat - bg).max(axis=1)
    if d.max() == 0:
        return None
    return np.median(flat[d >= d.max() * 0.9], axis=0)


def radius(img, x, y, w, h, bg):
    """Corner radius of a panel from where its top-left diagonal reaches 50% coverage.
    The corner pixel itself is outside the arc, so it gives the color around it."""
    outer = img[y, x].astype(int)
    span = np.abs(bg.astype(int) - outer.astype(int)).max()
    if span < 8:
        return 0
    cov = []
    for i in range(min(w, h) // 2):
        p = img[y + i, x + i].astype(int)
        c = np.abs(p - outer).max() / span
        cov.append(min(c, 1.0))
        if c >= 0.99:
            break
    for i, c in enumerate(cov):
        if c >= 0.5:
            t = i if i == 0 else i - 1 + (0.5 - cov[i - 1]) / max(c - cov[i - 1], 1e-6)
            r = (t + 0.5) * 2 ** 0.5 / (2 ** 0.5 - 1)
            return int(round(r)) if t > 0.2 else 0
    return 0


def runs(empty, merge):
    """[start, end) of the content bands in a 1-D 'empty line' array. Gaps < merge join."""
    out, start = [], None
    for i, e in enumerate(empty):
        if not e and start is None:
            start = i
        if e and start is not None:
            out.append([start, i])
            start = None
    if start is not None:
        out.append([start, len(empty)])
    joined = []
    for r in out:
        if joined and r[0] - joined[-1][1] < merge:
            joined[-1][1] = r[1]
        else:
            joined.append(r)
    return joined


def tight(diff):
    ys = np.where(diff.any(axis=1))[0]
    xs = np.where(diff.any(axis=0))[0]
    return xs[0], ys[0], xs[-1] - xs[0] + 1, ys[-1] - ys[0] + 1


def ring(px, k=0):
    """The 1 px border ring of a block, k px inside its edge."""
    b = px[k:px.shape[0] - k, k:px.shape[1] - k]
    return np.concatenate([b[0], b[-1], b[:, 0], b[:, -1]])[None]


def background(px, tol, outer):
    """The background color of a block: the color of its border ring. If the ring is not
    one color (a shadow or a gradient edge), step inward until it is. Returns the color,
    how many px were skipped, and the share of the block that has that color."""
    first = None
    # The whole image (no outer color) has no shadow: its edge is the background.
    last = 0 if outer is None else min(px.shape[:2]) // 4
    for k in range(0, last + 1):
        bg, ring_share = dominant(ring(px, k))
        if ring_share < 0.6:
            continue
        share = (np.abs(px.astype(int) - bg).max(axis=2) <= tol).mean()
        if share > 0.5 or outer is None:
            return bg, k, share
        if first is None:
            first = (bg, 0, share)
    # No color fills most of the block (an icon, a short text): use the edge color.
    if first is not None:
        return first
    bg, share = dominant(px)
    return bg, 0, share


def cut(img, x, y, w, h, outer, depth, tol, indent=0):
    px = img[y:y + h, x:x + w]
    bg, shadow, share = background(px, tol, outer)
    pad = "  " * indent
    if shadow:
        # Skip the shadow: the block is where its own color is.
        bx, by, bw, bh = tight(np.abs(px.astype(int) - bg).max(axis=2) <= tol)
        if (bx, by, bw, bh) != (0, 0, w, h):
            print(f"{pad}[{x},{y} {w}x{h}] shadow or soft edge: l={bx} t={by} "
                  f"r={w - bx - bw} b={h - by - bh}")
        x, y, w, h = x + bx, y + by, bw, bh
        px = img[y:y + h, x:x + w]
    diff = np.abs(px.astype(int) - bg).max(axis=2) > tol
    line = f"{pad}[{x},{y} {w}x{h}] bg={hexc(bg)}"

    # A panel: its own color fills most of it. Mask the corners so they are not content.
    r = 0
    if outer is not None and share > 0.5 and np.abs(bg - outer).max() > tol:
        r = radius(img, x, y, w, h, bg)
        line += f" radius~{r}"
        if r:
            # Pixels outside the rounded corner (plus 2.5 px of anti-aliasing and of
            # radius error) are not content.
            yy, xx = np.mgrid[0:r, 0:r]
            out = np.hypot(r - xx - 0.5, r - yy - 0.5) > r - 2.5
            diff[:r, :r] &= ~out
            diff[:r, w - r:] &= ~out[:, ::-1]
            diff[h - r:, :r] &= ~out[::-1, :]
            diff[h - r:, w - r:] &= ~out[::-1, ::-1]

    if not diff.any():
        print(line + " (flat)")
        return
    cx, cy, cw, ch = tight(diff)
    line += f" padding l={cx} t={cy} r={w - cx - cw} b={h - cy - ch}"

    rows = runs(~diff.any(axis=1), 2)
    cols = runs(~diff.any(axis=0), max(3, round(ch * 0.6)))
    if depth == 0 or (len(rows) == 1 and len(cols) == 1 and (cw, ch) == (w, h)):
        c = ink(px[cy:cy + ch, cx:cx + cw], bg)
        print(line + (f" ink={hexc(c)}" if c is not None else "") + " (leaf)")
        return

    if len(rows) > 1 and len(rows) >= len(cols):
        parts = [(x, y + a, w, b - a) for a, b in rows]
        gaps = [rows[i + 1][0] - rows[i][1] for i in range(len(rows) - 1)]
        print(line + f" -> column of {len(parts)}, gaps {gaps}")
    elif len(cols) > 1:
        parts = [(x + a, y, b - a, h) for a, b in cols]
        gaps = [cols[i + 1][0] - cols[i][1] for i in range(len(cols) - 1)]
        print(line + f" -> row of {len(parts)}, gaps {gaps}")
    else:
        # One block inside: go into it, with this region's color as its outside.
        print(line)
        cut(img, x + cx, y + cy, cw, ch, bg, depth - 1, tol, indent + 1)
        return

    for px_, py_, pw, ph in parts:
        sub = diff[py_ - y:py_ - y + ph, px_ - x:px_ - x + pw]
        tx, ty, tw, th = tight(sub)
        cut(img, px_ + tx, py_ + ty, tw, th, bg, depth - 1, tol, indent + 1)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("image")
    ap.add_argument("--region", help="X,Y,W,H: look at one part only")
    ap.add_argument("--depth", type=int, default=8)
    ap.add_argument("--tol", type=int, default=4,
                    help="largest channel difference still counted as background. "
                         "Raise it for JPEGs (with --denoise 5: 8-12)")
    ap.add_argument("--denoise", type=int, default=0,
                    help="median filter size (3 or 5) for JPEGs and photos of screens")
    a = ap.parse_args()

    im = Image.open(a.image).convert("RGB")
    if a.denoise:
        im = im.filter(ImageFilter.MedianFilter(a.denoise))
    img = np.asarray(im)
    x, y, w, h = 0, 0, img.shape[1], img.shape[0]
    if a.region:
        x, y, w, h = map(int, a.region.split(","))
    print(f"image {img.shape[1]}x{img.shape[0]}")
    cut(img, x, y, w, h, None, a.depth, a.tol)


if __name__ == "__main__":
    main()
