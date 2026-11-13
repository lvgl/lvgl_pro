# Image to XML: recipes

Practical steps to measure a UI image and to rebuild its parts: layout, colors, fonts,
icons, photos. Each step uses a script in `scripts/`. Every script prints `--help`.

The scripts were tested on LVGL screenshots, browser screenshots at 1x and 2x, and
upscaled JPEGs. The results are measurements, not facts: check them with a screenshot.

## Setup

```bash
pip install pillow numpy          # all scripts
pip install cairosvg              # icon_match.py only
pip install fonttools             # variable fonts only (step 4)
mkdir -p /tmp/img                 # work folder, outside the project
T=.claude/skills/image-to-xml/scripts
```

Look at a detail with your own eyes: `python3 $T/crop.py ref.png X,Y,W,H /tmp/img/z.png --zoom 6`,
then open the PNG. A full image is shown to you scaled down, so do not read pixel values
or small text from it.

## 1. Scale

1. Read the image size: `python3 -c "from PIL import Image; print(Image.open('ref.png').size)"`.
2. Compare it with the display size in `project.xml`.
   - Same aspect ratio: `scale = image width / display width`. Phone screenshots are
     often 2x or 3x.
   - Other aspect ratio: crop the image to the screen area first, or ask the user how
     to fit it.
3. Make a copy at display size. Use it for layout, colors, and the final comparison.
   Put the display width and height in place of `480, 320`:

   ```bash
   python3 -c "from PIL import Image; Image.open('ref.png').convert('RGB').resize((480, 320), Image.LANCZOS).save('/tmp/img/ref.png')"
   ```

4. Match fonts and icons on the **original** image: more pixels give better results.
   Divide the font size it gives by `scale`.

## 2. Layout

```bash
python3 $T/layout.py /tmp/img/ref.png
```

It prints a tree. For each block: the box `[x,y wxh]`, the background color, the
padding, and how the content is split: `column of N, gaps [...]` or `row of N`. A
panel also gets `radius~N` and, if it has one, `shadow or soft edge: l t r b`.

| Output | XML |
| --- | --- |
| `column of N, gaps [g...]` | `flex_flow="column"`, `style_pad_row` = the common gap |
| `row of N, gaps [g...]` | `flex_flow="row"`, `style_pad_column` = the common gap |
| `padding l t r b` | `style_pad_left` ... of the parent |
| `radius~N` | `style_radius`, ±2 px |
| `shadow l t r b` | Start with `style_shadow_offset_y` = (b − t) / 2 and `style_shadow_width` = 4 × l, then correct in step 7. A CSS blur of 12 px matched `shadow_width="26"` |
| A leaf with `ink=` | A label, an icon, or a small image. Look at it zoomed |

- A text leaf is the **ink box**, smaller than the label. So the gaps between lines of
  text read larger than `pad_row`. Fix them in step 7, do not compute them.
- Similar gaps (11, 12, 12) are one token. Round to the spacing scale.
- JPEG or a photo of a screen: add `--denoise 5 --tol 10`. Without it, noise splits
  every block.
- A low-contrast panel (white on `0xF4F6FA`) needs the default `--tol 4`. A higher
  value hides it.
- Look at one part only: `--region X,Y,W,H`.

## 3. Colors

1. Take the `bg=` values from step 2. On a PNG they are exact.
2. Text `ink=` is less exact. Thin strokes never reach the full color, and JPEG shifts
   the colors by a few steps. Use the value of the thickest text with that color.
3. Merge the colors that differ by 6 or less per channel into one constant.
4. A gradient: run `layout.py --region` on a thin strip at each end of it. Use the two
   `bg=` values for `style_bg_color` and `style_bg_grad_color`, and set
   `style_bg_grad_dir` to `hor` or `ver`.
5. Ask the user for the brand colors, if there are any. Use those over measured ones.

## 4. Fonts

1. Ask the user for the font files first. If they do not know, continue.
2. Read the text of each label from a zoomed crop.
3. Get candidates. Start with the common UI fonts from Google Fonts: Inter, Roboto,
   Open Sans, Lato, Poppins, Montserrat, Nunito, DM Sans, Manrope, Work Sans, Rubik,
   Source Sans 3, Noto Sans. Find the file name, then download it:

   ```bash
   mkdir -p /tmp/img/fonts
   curl -s https://api.github.com/repos/google/fonts/contents/ofl/inter | grep '"name"'
   curl -sLo /tmp/img/fonts/Inter.ttf "https://raw.githubusercontent.com/google/fonts/main/ofl/inter/Inter%5Bopsz,wght%5D.ttf"
   ```

4. Cut one line of text with some background around it, and match it:

   ```bash
   python3 $T/crop.py ref.png X,Y,W,H /tmp/img/t1.png
   python3 $T/font_match.py /tmp/img/t1.png "Good morning" /tmp/img/fonts
   ```

   It prints the families, then the weights and sizes inside the best family. Use a
   long line with many different letters. Match two or three lines of the same style.
   - The family is usually right.
   - The weight can be 100 off, and the size 1 px off. Results less than 0.02 apart are
     a tie.
   - A `width` far from 0% on every result means none of the candidates is right.
     Ask the user, or try more families.
5. A variable font (`Name[wght].ttf`) works in `<bin>` only at its default weight. Make
   one static file per weight you need. If the font has an `opsz` axis, set it to the
   px size: browsers do the same.

   ```bash
   python3 -m fontTools varLib.instancer /tmp/img/fonts/Inter.ttf wght=600 opsz=16 -o fonts/Inter-SemiBold.ttf
   ```

6. Platform fonts cannot be shipped. Use a free font that looks the same:

   | In the image | Use |
   | --- | --- |
   | SF Pro (iOS, macOS). Apple allows it only for Apple-platform mock-ups, and not embedded | Inter |
   | Segoe UI (Windows) | Selawik (Microsoft, OFL) |
   | Roboto (Android, Material) | Roboto (OFL) |

7. Tie or doubt: register each candidate, put one label per candidate on a test
   screen, take a screenshot, and pick with `compare.py` (step 7).
8. Put the license file of each font in `fonts/`.

## 5. Icons

1. Cut the icon with a few pixels of background around it. Find it in icon sets:

   ```bash
   mkdir -p /tmp/img/sets && cd /tmp/img/sets
   curl -sL https://registry.npmjs.org/lucide-static/-/lucide-static-0.460.0.tgz | tar xz && mv package lucide
   curl -sL "$(npm view @tabler/icons dist.tarball)" | tar xz && mv package tabler
   curl -sL "$(npm view @material-symbols/svg-400 dist.tarball)" | tar xz && mv package material
   cd -
   python3 $T/icon_match.py /tmp/img/icon1.png /tmp/img/sets/lucide/icons /tmp/img/sets/tabler/icons/outline /tmp/img/sets/material/outlined
   ```

   Lower is better. An exact icon scores about 0.1 to 0.2. Look at the top three
   before you pick: icons in one set often differ only in a detail. Use one set for
   the whole UI if you can.
2. Copy the SVG to `images/icons/`, replace `currentColor` with `#000000`, and convert
   it at the size it is shown. A one-color icon: `color_format="a8"`, then set the
   color with `style_image_recolor` and `style_image_recolor_opa="100%"`. `a8` uses 1
   byte per pixel, `argb8888` uses 4.
3. No match (a logo, a custom icon): cut it out of the image and remove the background:

   ```bash
   python3 $T/crop.py ref.png X,Y,W,H images/logo.png --alpha auto
   ```

   The edges stay smooth on any background. Cut it from the image at display scale, at
   the size it is shown. Ask the user for the original file: a cut-out is a fallback.

## 6. Photos and backgrounds

1. Ask the user for the original file. A screenshot has low quality, and the user may
   not have the right to use the picture.
2. If there is none, cut it from the image at display scale with `crop.py`, without
   `--alpha`.
3. An opaque picture: `color_format="rgb565"`, 2 bytes per pixel.

## 7. Check and correct

1. Build the screen, then take a screenshot (see `AGENTS.md`).
2. Measure both images, and compare the ink boxes of the same items:

   ```bash
   python3 $T/layout.py /tmp/img/ref.png > /tmp/img/ref.txt
   python3 $T/layout.py /tmp/img/shot.png > /tmp/img/shot.txt
   diff /tmp/img/ref.txt /tmp/img/shot.txt
   ```

   Move each item by the difference, for example `y` +2 or `pad_row` −3. One round
   usually puts every text box at the right pixel.
3. See the remaining differences:

   ```bash
   python3 $T/compare.py /tmp/img/ref.png /tmp/img/shot.png /tmp/img/cmp.png
   ```

   Open `cmp.png`: reference, screenshot, a 50% blend (a shift shows as a double
   edge), and a heat map. The script also lists the boxes that differ most.
4. Glyph edges always differ a little between two renderers. Real differences are:
   a box in the wrong place, a wrong size, a wrong color, a missing part.
