"""Turn the bytes of an lv_image_dsc_t back into a PNG.

An image compiled into a binary is a C array plus an lv_image_header_t, which
is everything a PNG needs. This module only decodes: reading target memory is
the caller's job, so the formats can be tested without a live process.

Byte orders are LVGL's: lv_color_t is {blue, green, red} and lv_color32_t is
{blue, green, red, alpha}, so pixels are BGR(A) in memory.
"""

# lv_color_format_t, from lvgl/draw/lv_color.h
L8 = 0x06
I1, I2, I4, I8 = 0x07, 0x08, 0x09, 0x0A
A8 = 0x0E
RGB888 = 0x0F
ARGB8888 = 0x10
XRGB8888 = 0x11
RGB565 = 0x12
RGB565A8 = 0x14
AL88 = 0x15
ARGB8888_PREMULTIPLIED = 0x1A
RGB565_SWAPPED = 0x1B

# lv_image_dsc.h
FLAG_COMPRESSED = 0x0008

CF_NAMES = {
    L8: "l8", I1: "i1", I2: "i2", I4: "i4", I8: "i8", A8: "a8",
    RGB888: "rgb888", ARGB8888: "argb8888", XRGB8888: "xrgb8888",
    RGB565: "rgb565", RGB565A8: "rgb565a8", AL88: "al88",
    ARGB8888_PREMULTIPLIED: "argb8888", RGB565_SWAPPED: "rgb565",
}

# Bits per pixel of the indexed formats, and how many palette entries precede
# their pixel data (LV_COLOR_INDEXED_PALETTE_SIZE).
_INDEXED = {I1: (1, 2), I2: (2, 4), I4: (4, 16), I8: (8, 256)}

_BPP = {
    L8: 8, A8: 8, AL88: 16, RGB565: 16, RGB565_SWAPPED: 16, RGB565A8: 16,
    RGB888: 24, ARGB8888: 32, XRGB8888: 32, ARGB8888_PREMULTIPLIED: 32,
    I1: 1, I2: 2, I4: 4, I8: 8,
}


class UnsupportedImage(Exception):
    """The image cannot be rebuilt from the binary."""


def stride_for(cf, width):
    """Bytes per row when the header does not say."""
    bpp = _BPP.get(cf)
    if bpp is None:
        raise UnsupportedImage(f"color format {cf:#04x} is not supported")
    return (width * bpp + 7) // 8


def expected_size(cf, width, height, stride):
    """How many bytes the pixel data takes, palette and alpha plane included."""
    size = stride * height
    if cf == RGB565A8:
        size += (stride // 2) * height
    elif cf in _INDEXED:
        size += _INDEXED[cf][1] * 4
    return size


def _rgb565(lo, hi, swapped):
    if swapped:
        lo, hi = hi, lo
    value = lo | (hi << 8)
    r = (value >> 11) & 0x1F
    g = (value >> 5) & 0x3F
    b = value & 0x1F
    return (r << 3) | (r >> 2), (g << 2) | (g >> 4), (b << 3) | (b >> 2)


def _palette(data, entries):
    """The lv_color32_t table that precedes indexed pixel data."""
    out = []
    for i in range(entries):
        b, g, r, a = data[i * 4:i * 4 + 4]
        out.append((r, g, b, a))
    return out


def to_rgba(cf, width, height, stride, data):
    """Decode to a flat RGBA bytearray, row by row, honouring stride."""
    if cf not in _BPP:
        raise UnsupportedImage(f"color format {cf:#04x} is not supported")
    if width <= 0 or height <= 0:
        raise UnsupportedImage(f"implausible size {width}x{height}")

    out = bytearray(width * height * 4)
    offset = 0
    palette = None
    if cf in _INDEXED:
        bits, entries = _INDEXED[cf]
        if len(data) < entries * 4:
            raise UnsupportedImage("indexed image has no palette")
        palette = _palette(data, entries)
        offset = entries * 4

    alpha_plane = None
    if cf == RGB565A8:
        alpha_plane = offset + stride * height

    for y in range(height):
        row = offset + y * stride
        base = y * width * 4
        for x in range(width):
            if cf in (RGB565, RGB565_SWAPPED, RGB565A8):
                i = row + x * 2
                r, g, b = _rgb565(data[i], data[i + 1], cf == RGB565_SWAPPED)
                a = 255
                if alpha_plane is not None:
                    a = data[alpha_plane + y * (stride // 2) + x]
            elif cf == RGB888:
                i = row + x * 3
                b, g, r, a = data[i], data[i + 1], data[i + 2], 255
            elif cf in (ARGB8888, XRGB8888, ARGB8888_PREMULTIPLIED):
                i = row + x * 4
                b, g, r, a = data[i], data[i + 1], data[i + 2], data[i + 3]
                if cf == XRGB8888:
                    a = 255
            elif cf == L8:
                v = data[row + x]
                r = g = b = v
                a = 255
            elif cf == A8:
                r = g = b = 0
                a = data[row + x]
            elif cf == AL88:
                i = row + x * 2
                r = g = b = data[i]
                a = data[i + 1]
            else:  # indexed
                bits = _INDEXED[cf][0]
                if bits == 8:
                    index = data[row + x]
                else:
                    per_byte = 8 // bits
                    byte = data[row + x // per_byte]
                    shift = 8 - bits * (x % per_byte + 1)
                    index = (byte >> shift) & ((1 << bits) - 1)
                r, g, b, a = palette[index]

            out[base + x * 4:base + x * 4 + 4] = bytes((r, g, b, a))
    return out


def to_png(cf, width, height, stride, data, path):
    """Write the image as a PNG. Raises UnsupportedImage if it cannot be read."""
    try:
        from PIL import Image
    except ImportError:
        raise UnsupportedImage("Pillow is not available to write PNGs")

    rgba = to_rgba(cf, width, height, stride, data)
    Image.frombytes("RGBA", (width, height), bytes(rgba)).save(path)
    return path
