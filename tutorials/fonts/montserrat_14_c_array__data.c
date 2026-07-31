/*******************************************************************************
 * Size: 14 px
 * Bpp: 2
 * Opts: --font /fonts/Montserrat_Medium.ttf -o /fonts/montserrat_14_c_array__data.c --size 14 --bpp 2 --format lvgl --no-compress --symbols ° --range 0x20-0x7f
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef MONTSERRAT_14_C_ARRAY__DATA
#define MONTSERRAT_14_C_ARRAY__DATA 1
#endif

#if MONTSERRAT_14_C_ARRAY__DATA

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x38, 0xe3, 0x8e, 0x38, 0x92, 0x40, 0x28, 0xe0,

    /* U+0022 "\"" */
    0x32, 0x8c, 0xa3, 0x28, 0xca, 0x00, 0x00,

    /* U+0023 "#" */
    0x03, 0x03, 0x00, 0x30, 0x60, 0x3f, 0xff, 0xd0,
    0x70, 0x90, 0x06, 0x0c, 0x00, 0xa0, 0xc0, 0xbf,
    0xff, 0xc0, 0xd0, 0xc0, 0x0c, 0x0c, 0x00, 0xc1,
    0x80,

    /* U+0024 "$" */
    0x00, 0x40, 0x00, 0x30, 0x00, 0x0c, 0x00, 0x2f,
    0xe0, 0x3d, 0xd9, 0x0d, 0x30, 0x03, 0x8c, 0x00,
    0x7f, 0x40, 0x01, 0xfd, 0x00, 0x32, 0xc0, 0x0c,
    0x71, 0xe7, 0x78, 0x1f, 0xf8, 0x00, 0x30, 0x00,
    0x04, 0x00,

    /* U+0025 "%" */
    0x2f, 0x00, 0x90, 0x60, 0xc1, 0xc0, 0x50, 0xc3,
    0x00, 0x60, 0xc9, 0x00, 0x1f, 0x1d, 0xf0, 0x00,
    0x33, 0x0c, 0x00, 0x92, 0x08, 0x01, 0xc2, 0x08,
    0x03, 0x03, 0x0c, 0x09, 0x01, 0xf4,

    /* U+0026 "&" */
    0x07, 0xf0, 0x00, 0xd2, 0xc0, 0x0c, 0x1c, 0x00,
    0xa7, 0x40, 0x07, 0xc0, 0x01, 0xde, 0x08, 0x30,
    0x3a, 0x87, 0x00, 0xf4, 0x39, 0x6f, 0xc0, 0xbf,
    0x48, 0x00, 0x00, 0x00,

    /* U+0027 "'" */
    0x30, 0xc3, 0x0c, 0x00,

    /* U+0028 "(" */
    0x0c, 0x28, 0x34, 0x70, 0x70, 0xa0, 0xa0, 0xa0,
    0xa0, 0x70, 0x70, 0x34, 0x28, 0x0c,

    /* U+0029 ")" */
    0x70, 0x34, 0x2c, 0x1c, 0x0c, 0x0d, 0x0d, 0x0d,
    0x0d, 0x0c, 0x1c, 0x2c, 0x34, 0x70,

    /* U+002A "*" */
    0x08, 0x0a, 0x9c, 0x2f, 0x47, 0xf8, 0x48, 0x40,
    0x40,

    /* U+002B "+" */
    0x01, 0x40, 0x02, 0x80, 0x02, 0x80, 0x3f, 0xfc,
    0x02, 0x80, 0x02, 0x80, 0x02, 0x80,

    /* U+002C "," */
    0x00, 0xd3, 0x4c, 0x30,

    /* U+002D "-" */
    0x00, 0x0f, 0xe0, 0x00,

    /* U+002E "." */
    0x00, 0xd3, 0x40,

    /* U+002F "/" */
    0x00, 0x34, 0x01, 0xc0, 0x0a, 0x00, 0x34, 0x01,
    0xc0, 0x0a, 0x00, 0x34, 0x00, 0xc0, 0x0a, 0x00,
    0x34, 0x00, 0xc0, 0x0a, 0x00, 0x34, 0x00, 0xc0,
    0x00,

    /* U+0030 "0" */
    0x07, 0xf4, 0x07, 0x9b, 0x83, 0x80, 0x70, 0xd0,
    0x0d, 0x70, 0x03, 0x9c, 0x00, 0xe3, 0x40, 0x34,
    0xe0, 0x1c, 0x1e, 0x6e, 0x01, 0xfd, 0x00,

    /* U+0031 "1" */
    0xfe, 0x5e, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a,
    0x0a, 0x0a,

    /* U+0032 "2" */
    0x1f, 0xe0, 0xb9, 0x7c, 0x00, 0x1c, 0x00, 0x1c,
    0x00, 0x38, 0x00, 0xf0, 0x03, 0xc0, 0x0e, 0x00,
    0x3d, 0x54, 0x7f, 0xfe,

    /* U+0033 "3" */
    0x7f, 0xfc, 0x15, 0x78, 0x00, 0xb0, 0x02, 0xc0,
    0x03, 0xe0, 0x01, 0x7c, 0x00, 0x0d, 0x00, 0x0d,
    0xb5, 0x7c, 0x2f, 0xe0,

    /* U+0034 "4" */
    0x00, 0x38, 0x00, 0x0b, 0x00, 0x01, 0xc0, 0x00,
    0x74, 0x00, 0x0d, 0x0d, 0x03, 0x80, 0xd0, 0x7f,
    0xff, 0xc0, 0x00, 0xd0, 0x00, 0x0d, 0x00, 0x00,
    0xd0,

    /* U+0035 "5" */
    0x2f, 0xfc, 0x29, 0x54, 0x38, 0x00, 0x34, 0x00,
    0x3f, 0xf4, 0x01, 0x7c, 0x00, 0x0d, 0x00, 0x0d,
    0xb9, 0x7c, 0x2f, 0xe0,

    /* U+0036 "6" */
    0x02, 0xfd, 0x03, 0xd5, 0x43, 0xc0, 0x00, 0xd0,
    0x00, 0x76, 0xf8, 0x1f, 0x97, 0xc3, 0x80, 0x30,
    0xe0, 0x0c, 0x1e, 0x5f, 0x01, 0xfe, 0x00,

    /* U+0037 "7" */
    0xbf, 0xff, 0xb5, 0x5e, 0xb0, 0x1c, 0x00, 0x28,
    0x00, 0x34, 0x00, 0xb0, 0x00, 0xd0, 0x02, 0xc0,
    0x03, 0x80, 0x07, 0x00,

    /* U+0038 "8" */
    0x0b, 0xf8, 0x0b, 0x47, 0xc3, 0x40, 0x70, 0xf0,
    0x2c, 0x0f, 0xfc, 0x0f, 0x47, 0xc7, 0x00, 0x35,
    0xc0, 0x0d, 0x3d, 0x1f, 0x02, 0xfe, 0x00,

    /* U+0039 "9" */
    0x0b, 0xe0, 0x39, 0x6c, 0xb0, 0x0e, 0xb0, 0x0f,
    0x74, 0x2f, 0x1f, 0xfb, 0x00, 0x0b, 0x00, 0x0d,
    0x15, 0xb8, 0x2f, 0xd0,

    /* U+003A ":" */
    0x34, 0xd0, 0x00, 0x00, 0x03, 0x4d,

    /* U+003B ";" */
    0x34, 0xd0, 0x00, 0x00, 0x03, 0x4d, 0x30, 0xc0,
    0x00,

    /* U+003C "<" */
    0x00, 0x00, 0x00, 0x7c, 0x0b, 0xd0, 0x3c, 0x00,
    0x2e, 0x40, 0x01, 0xf4, 0x00, 0x1c, 0x00, 0x00,

    /* U+003D "=" */
    0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3f, 0xfc, 0x00, 0x00,

    /* U+003E ">" */
    0x10, 0x00, 0x3d, 0x00, 0x07, 0xe0, 0x00, 0x2c,
    0x00, 0xb8, 0x1f, 0x80, 0x34, 0x00, 0x00, 0x00,

    /* U+003F "?" */
    0x1f, 0xe0, 0xb5, 0x7c, 0x00, 0x1c, 0x00, 0x2c,
    0x00, 0xb0, 0x01, 0xc0, 0x02, 0x40, 0x00, 0x00,
    0x02, 0x80, 0x03, 0x80,

    /* U+0040 "@" */
    0x00, 0x7f, 0xe4, 0x00, 0x39, 0x01, 0xe0, 0x0d,
    0x2f, 0xae, 0x82, 0x8b, 0x4b, 0xcc, 0x30, 0xc0,
    0x3c, 0x63, 0x1c, 0x01, 0xc2, 0x61, 0xc0, 0x1c,
    0x33, 0x0c, 0x03, 0xc6, 0x30, 0xb4, 0xbc, 0xd2,
    0x82, 0xf8, 0xf8, 0x0d, 0x00, 0x00, 0x00, 0x39,
    0x02, 0x00, 0x00, 0x7f, 0xe0, 0x00,

    /* U+0041 "A" */
    0x00, 0x3c, 0x00, 0x00, 0x3d, 0x00, 0x00, 0xa7,
    0x00, 0x00, 0xc3, 0x40, 0x02, 0x81, 0xc0, 0x03,
    0x00, 0xd0, 0x07, 0xff, 0xe0, 0x0d, 0x00, 0x70,
    0x1c, 0x00, 0x38, 0x38, 0x00, 0x1c,

    /* U+0042 "B" */
    0xbf, 0xfd, 0x2c, 0x06, 0xcb, 0x00, 0x36, 0xc0,
    0x2c, 0xbf, 0xfe, 0x2c, 0x01, 0xdb, 0x00, 0x2e,
    0xc0, 0x0b, 0xb0, 0x17, 0x6f, 0xff, 0x40,

    /* U+0043 "C" */
    0x01, 0xfe, 0x40, 0xf9, 0x6d, 0x2c, 0x00, 0x03,
    0x40, 0x00, 0x70, 0x00, 0x07, 0x00, 0x00, 0x34,
    0x00, 0x02, 0xc0, 0x00, 0x0f, 0x96, 0xd0, 0x1f,
    0xe4,

    /* U+0044 "D" */
    0xbf, 0xf9, 0x0b, 0x55, 0xf4, 0xb0, 0x01, 0xcb,
    0x00, 0x0e, 0xb0, 0x00, 0xbb, 0x00, 0x0b, 0xb0,
    0x00, 0xeb, 0x00, 0x1c, 0xb5, 0x5b, 0x4b, 0xff,
    0x90,

    /* U+0045 "E" */
    0xbf, 0xfd, 0xb5, 0x54, 0xb0, 0x00, 0xb0, 0x00,
    0xbf, 0xfc, 0xb0, 0x00, 0xb0, 0x00, 0xb0, 0x00,
    0xb5, 0x54, 0xbf, 0xfe,

    /* U+0046 "F" */
    0xbf, 0xfd, 0xb5, 0x54, 0xb0, 0x00, 0xb0, 0x00,
    0xb0, 0x00, 0xbf, 0xfc, 0xb0, 0x00, 0xb0, 0x00,
    0xb0, 0x00, 0xb0, 0x00,

    /* U+0047 "G" */
    0x01, 0xff, 0x40, 0xf9, 0x6d, 0x2c, 0x00, 0x03,
    0x40, 0x00, 0x70, 0x00, 0x07, 0x00, 0x0a, 0x34,
    0x00, 0xa2, 0xc0, 0x0a, 0x0f, 0x96, 0xe0, 0x1f,
    0xf4,

    /* U+0048 "H" */
    0xb0, 0x02, 0xec, 0x00, 0xbb, 0x00, 0x2e, 0xc0,
    0x0b, 0xbf, 0xff, 0xec, 0x00, 0xbb, 0x00, 0x2e,
    0xc0, 0x0b, 0xb0, 0x02, 0xec, 0x00, 0xb0,

    /* U+0049 "I" */
    0xbb, 0xbb, 0xbb, 0xbb, 0xbb,

    /* U+004A "J" */
    0x0f, 0xfc, 0x15, 0xb0, 0x02, 0xc0, 0x0b, 0x00,
    0x2c, 0x00, 0xb0, 0x02, 0xc0, 0x0a, 0x39, 0xb4,
    0x3f, 0x80,

    /* U+004B "K" */
    0xb0, 0x07, 0x4b, 0x01, 0xd0, 0xb0, 0x34, 0x0b,
    0x0e, 0x00, 0xb3, 0xc0, 0x0b, 0xfd, 0x00, 0xb8,
    0x70, 0x0b, 0x02, 0xc0, 0xb0, 0x0f, 0x0b, 0x00,
    0x38,

    /* U+004C "L" */
    0xb0, 0x00, 0xb0, 0x00, 0xb0, 0x00, 0xb0, 0x00,
    0xb0, 0x00, 0xb0, 0x00, 0xb0, 0x00, 0xb0, 0x00,
    0xb5, 0x54, 0xbf, 0xfc,

    /* U+004D "M" */
    0xb0, 0x00, 0x2e, 0xd0, 0x00, 0xfb, 0xc0, 0x0b,
    0xef, 0x80, 0x7b, 0xb3, 0x03, 0x9e, 0xcb, 0x1c,
    0x7b, 0x0d, 0xd1, 0xec, 0x1f, 0x07, 0xb0, 0x20,
    0x1e, 0xc0, 0x00, 0x70,

    /* U+004E "N" */
    0xb0, 0x02, 0xef, 0x00, 0xbb, 0xe0, 0x2e, 0xdd,
    0x0b, 0xb2, 0xc2, 0xec, 0x3c, 0xbb, 0x03, 0xae,
    0xc0, 0x3f, 0xb0, 0x07, 0xec, 0x00, 0xb0,

    /* U+004F "O" */
    0x01, 0xfe, 0x40, 0x0f, 0x96, 0xe0, 0x2c, 0x00,
    0x74, 0x34, 0x00, 0x2c, 0x70, 0x00, 0x1c, 0x70,
    0x00, 0x1c, 0x34, 0x00, 0x2c, 0x2c, 0x00, 0x74,
    0x0f, 0x96, 0xe0, 0x01, 0xfe, 0x40,

    /* U+0050 "P" */
    0xbf, 0xf4, 0x2d, 0x5b, 0x8b, 0x00, 0x72, 0xc0,
    0x0d, 0xb0, 0x03, 0x6c, 0x07, 0xcb, 0xff, 0x82,
    0xc0, 0x00, 0xb0, 0x00, 0x2c, 0x00, 0x00,

    /* U+0051 "Q" */
    0x01, 0xfe, 0x40, 0x0f, 0x96, 0xe0, 0x2c, 0x00,
    0x74, 0x34, 0x00, 0x2c, 0x70, 0x00, 0x1c, 0x70,
    0x00, 0x1c, 0x34, 0x00, 0x2c, 0x2c, 0x00, 0x74,
    0x0f, 0x96, 0xe0, 0x02, 0xff, 0x40, 0x00, 0x0f,
    0x09, 0x00, 0x02, 0xfc, 0x00, 0x00, 0x00,

    /* U+0052 "R" */
    0xbf, 0xf4, 0x2d, 0x5b, 0x8b, 0x00, 0x72, 0xc0,
    0x0d, 0xb0, 0x03, 0x2c, 0x07, 0xcb, 0xff, 0xc2,
    0xc0, 0xe0, 0xb0, 0x0d, 0x2c, 0x01, 0xc0,

    /* U+0053 "S" */
    0x0b, 0xf8, 0x0f, 0x56, 0x43, 0x40, 0x00, 0xe0,
    0x00, 0x1f, 0x90, 0x00, 0x6f, 0x40, 0x00, 0xb0,
    0x00, 0x1c, 0x39, 0x5e, 0x06, 0xfe, 0x00,

    /* U+0054 "T" */
    0xff, 0xff, 0x15, 0xb5, 0x40, 0x2c, 0x00, 0x0b,
    0x00, 0x02, 0xc0, 0x00, 0xb0, 0x00, 0x2c, 0x00,
    0x0b, 0x00, 0x02, 0xc0, 0x00, 0xb0, 0x00,

    /* U+0055 "U" */
    0xb0, 0x02, 0xac, 0x00, 0xab, 0x00, 0x2a, 0xc0,
    0x0a, 0xb0, 0x02, 0xac, 0x00, 0xab, 0x00, 0x39,
    0xd0, 0x0d, 0x3e, 0x6f, 0x02, 0xfe, 0x00,

    /* U+0056 "V" */
    0x38, 0x00, 0x2c, 0x70, 0x00, 0xd0, 0xe0, 0x0b,
    0x02, 0xc0, 0x34, 0x03, 0x41, 0xc0, 0x0b, 0x0e,
    0x00, 0x0d, 0x30, 0x00, 0x3a, 0xc0, 0x00, 0x7d,
    0x00, 0x00, 0xf0, 0x00,

    /* U+0057 "W" */
    0x70, 0x03, 0x80, 0x0c, 0x34, 0x03, 0xc0, 0x2c,
    0x28, 0x0a, 0xd0, 0x34, 0x1c, 0x0d, 0xa0, 0x30,
    0x0d, 0x0c, 0x70, 0xb0, 0x0e, 0x28, 0x34, 0xe0,
    0x07, 0x34, 0x28, 0xc0, 0x03, 0xb0, 0x1e, 0xc0,
    0x03, 0xe0, 0x0f, 0x80, 0x01, 0xd0, 0x0b, 0x00,

    /* U+0058 "X" */
    0x74, 0x03, 0x82, 0xc0, 0xb0, 0x0f, 0x1c, 0x00,
    0x3b, 0x40, 0x01, 0xf0, 0x00, 0x2f, 0x00, 0x07,
    0x78, 0x00, 0xe0, 0xd0, 0x2c, 0x07, 0x07, 0x00,
    0x2c,

    /* U+0059 "Y" */
    0x38, 0x00, 0xb0, 0x34, 0x03, 0x00, 0xb0, 0x38,
    0x00, 0xe1, 0xc0, 0x01, 0xcd, 0x00, 0x03, 0xf0,
    0x00, 0x03, 0x40, 0x00, 0x0c, 0x00, 0x00, 0x30,
    0x00, 0x00, 0xc0, 0x00,

    /* U+005A "Z" */
    0x7f, 0xff, 0x85, 0x56, 0xc0, 0x00, 0xd0, 0x00,
    0xe0, 0x00, 0xf0, 0x00, 0xb0, 0x00, 0x74, 0x00,
    0x34, 0x00, 0x3d, 0x55, 0x1f, 0xff, 0xf0,

    /* U+005B "[" */
    0xbd, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0,
    0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xbd,

    /* U+005C "\\" */
    0x70, 0x00, 0xc0, 0x02, 0x80, 0x07, 0x00, 0x0c,
    0x00, 0x28, 0x00, 0x70, 0x00, 0xc0, 0x02, 0x40,
    0x07, 0x00, 0x0c, 0x00, 0x24, 0x00, 0x70, 0x00,
    0xc0,

    /* U+005D "]" */
    0xbc, 0x1c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c,
    0x0c, 0x0c, 0x0c, 0x0c, 0x1c, 0xbc,

    /* U+005E "^" */
    0x0b, 0x00, 0x3d, 0x02, 0x98, 0x0c, 0x30, 0x60,
    0x92, 0x40, 0xc0,

    /* U+005F "_" */
    0xff, 0xfc,

    /* U+0060 "`" */
    0x2c, 0x02, 0x80,

    /* U+0061 "a" */
    0x1f, 0xe0, 0x25, 0x78, 0x00, 0x1c, 0x1f, 0xfc,
    0x38, 0x1c, 0x70, 0x1c, 0x34, 0x3c, 0x1f, 0xdc,

    /* U+0062 "b" */
    0xa0, 0x00, 0xa0, 0x00, 0xa0, 0x00, 0xab, 0xf0,
    0xbd, 0x6c, 0xb0, 0x0e, 0xa0, 0x07, 0xa0, 0x07,
    0xb0, 0x0e, 0xbd, 0x6c, 0xab, 0xf0,

    /* U+0063 "c" */
    0x07, 0xf4, 0x2d, 0x6d, 0x34, 0x00, 0x70, 0x00,
    0x70, 0x00, 0x34, 0x00, 0x2d, 0x6d, 0x07, 0xf4,

    /* U+0064 "d" */
    0x00, 0x03, 0x40, 0x00, 0xd0, 0x00, 0x34, 0x2f,
    0xdd, 0x2d, 0x6f, 0x4d, 0x01, 0xd7, 0x00, 0x35,
    0xc0, 0x0d, 0x34, 0x07, 0x4b, 0x47, 0xd0, 0xbf,
    0x74,

    /* U+0065 "e" */
    0x0b, 0xf4, 0x2d, 0x2d, 0x30, 0x0b, 0x7f, 0xff,
    0x70, 0x00, 0x34, 0x00, 0x2e, 0x5d, 0x07, 0xf8,

    /* U+0066 "f" */
    0x0b, 0xc1, 0xd4, 0x2c, 0x0f, 0xfc, 0x2c, 0x02,
    0xc0, 0x2c, 0x02, 0xc0, 0x2c, 0x02, 0xc0, 0x2c,
    0x00,

    /* U+0067 "g" */
    0x07, 0xf7, 0x4b, 0x57, 0xd3, 0x40, 0x75, 0xc0,
    0x0d, 0x70, 0x03, 0x4d, 0x01, 0xd2, 0xd5, 0xf4,
    0x1f, 0xdd, 0x00, 0x03, 0x0e, 0x57, 0x80, 0xbf,
    0x80,

    /* U+0068 "h" */
    0xa0, 0x00, 0xa0, 0x00, 0xa0, 0x00, 0xab, 0xe0,
    0xbd, 0x7c, 0xb0, 0x0c, 0xa0, 0x0d, 0xa0, 0x0d,
    0xa0, 0x0d, 0xa0, 0x0d, 0xa0, 0x0d,

    /* U+0069 "i" */
    0xaa, 0x0a, 0xaa, 0xaa, 0xaa, 0xa0,

    /* U+006A "j" */
    0x02, 0x80, 0xa0, 0x00, 0x0a, 0x02, 0x80, 0xa0,
    0x28, 0x0a, 0x02, 0x80, 0xa0, 0x28, 0x0a, 0x17,
    0x4f, 0x80,

    /* U+006B "k" */
    0xa0, 0x00, 0xa0, 0x00, 0xa0, 0x00, 0xa0, 0x3c,
    0xa0, 0xf0, 0xa3, 0xc0, 0xaf, 0x40, 0xbe, 0xc0,
    0xb0, 0xf0, 0xa0, 0x34, 0xa0, 0x1c,

    /* U+006C "l" */
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xa0,

    /* U+006D "m" */
    0xab, 0xe1, 0xfd, 0x2e, 0x5f, 0xd6, 0xcb, 0x01,
    0xd0, 0x36, 0x80, 0x70, 0x0e, 0xa0, 0x0c, 0x03,
    0xa8, 0x03, 0x00, 0xea, 0x00, 0xc0, 0x3a, 0x80,
    0x30, 0x0e,

    /* U+006E "n" */
    0xab, 0xe0, 0xb9, 0x7c, 0xb0, 0x0c, 0xa0, 0x0d,
    0xa0, 0x0d, 0xa0, 0x0d, 0xa0, 0x0d, 0xa0, 0x0d,

    /* U+006F "o" */
    0x07, 0xf4, 0x0b, 0x5b, 0x43, 0x40, 0x71, 0xc0,
    0x0c, 0x70, 0x03, 0x0d, 0x01, 0xc2, 0xd6, 0xd0,
    0x1f, 0xd0,

    /* U+0070 "p" */
    0xab, 0xf0, 0xbd, 0x2c, 0xb0, 0x0e, 0xa0, 0x07,
    0xa0, 0x07, 0xb0, 0x0e, 0xbd, 0x6c, 0xa7, 0xf0,
    0xa0, 0x00, 0xa0, 0x00, 0xa0, 0x00,

    /* U+0071 "q" */
    0x0b, 0xf3, 0x4b, 0x5b, 0xd3, 0x40, 0x75, 0xc0,
    0x0d, 0x70, 0x03, 0x4d, 0x01, 0xd2, 0xd6, 0xf4,
    0x2f, 0xdd, 0x00, 0x03, 0x40, 0x00, 0xd0, 0x00,
    0x34,

    /* U+0072 "r" */
    0xab, 0x6f, 0x4b, 0x02, 0x80, 0xa0, 0x28, 0x0a,
    0x02, 0x80,

    /* U+0073 "s" */
    0x1f, 0xe0, 0xd1, 0x87, 0x00, 0x0f, 0x90, 0x06,
    0xf0, 0x00, 0xe7, 0x57, 0x4b, 0xf4,

    /* U+0074 "t" */
    0x2c, 0x02, 0xc0, 0xff, 0xc2, 0xc0, 0x2c, 0x02,
    0xc0, 0x2c, 0x02, 0xc0, 0x1d, 0x40, 0xbc,

    /* U+0075 "u" */
    0xe0, 0x0c, 0xe0, 0x0c, 0xe0, 0x0c, 0xe0, 0x0c,
    0xe0, 0x0c, 0xa0, 0x1c, 0x78, 0x7c, 0x1f, 0xdc,

    /* U+0076 "v" */
    0x38, 0x02, 0x87, 0x00, 0xc0, 0xd0, 0x70, 0x2c,
    0x34, 0x03, 0x1c, 0x00, 0xea, 0x00, 0x1f, 0x00,
    0x03, 0xc0,

    /* U+0077 "w" */
    0xe0, 0x1c, 0x03, 0x5c, 0x0f, 0x40, 0xc3, 0x03,
    0xb0, 0xa0, 0xa1, 0x8c, 0x34, 0x1c, 0xd3, 0x5c,
    0x03, 0x70, 0x7a, 0x00, 0xb8, 0x0f, 0x40, 0x1d,
    0x02, 0xc0,

    /* U+0078 "x" */
    0x70, 0x1c, 0x2c, 0x34, 0x0e, 0xe0, 0x03, 0xc0,
    0x07, 0xc0, 0x0d, 0xa0, 0x28, 0x34, 0x70, 0x1c,

    /* U+0079 "y" */
    0x38, 0x02, 0x87, 0x00, 0xc0, 0xd0, 0x70, 0x2c,
    0x34, 0x03, 0x1c, 0x00, 0xea, 0x00, 0x1f, 0x00,
    0x03, 0xc0, 0x00, 0xd0, 0x09, 0xb0, 0x02, 0xf0,
    0x00,

    /* U+007A "z" */
    0x7f, 0xf8, 0x01, 0xd0, 0x0d, 0x00, 0xe0, 0x0b,
    0x00, 0x74, 0x03, 0x80, 0x1f, 0xff,

    /* U+007B "{" */
    0x07, 0x83, 0x80, 0xd0, 0x34, 0x0d, 0x03, 0x03,
    0xc0, 0x70, 0x0d, 0x03, 0x40, 0xd0, 0x34, 0x0e,
    0x01, 0xe0,

    /* U+007C "|" */
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,

    /* U+007D "}" */
    0xb4, 0x0b, 0x01, 0xc0, 0x70, 0x1c, 0x07, 0x00,
    0xf0, 0x74, 0x1c, 0x07, 0x01, 0xc0, 0x70, 0x2c,
    0x2d, 0x00,

    /* U+007E "~" */
    0x1f, 0x49, 0x31, 0xfc, 0x00, 0x00,

    /* U+00B0 "°" */
    0x1f, 0x02, 0x0c, 0x50, 0x82, 0x0c, 0x1f, 0x00
};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 60, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 60, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8, .adv_w = 88, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 15, .adv_w = 157, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 40, .adv_w = 139, .box_w = 9, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 74, .adv_w = 189, .box_w = 12, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 104, .adv_w = 154, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 132, .adv_w = 47, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 136, .adv_w = 75, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 150, .adv_w = 76, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 164, .adv_w = 90, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 173, .adv_w = 130, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 187, .adv_w = 51, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 191, .adv_w = 86, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 195, .adv_w = 51, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 79, .box_w = 7, .box_h = 14, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 223, .adv_w = 149, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 246, .adv_w = 83, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 129, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 296, .adv_w = 150, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 129, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 138, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 144, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 407, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 51, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 51, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 442, .adv_w = 130, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 458, .adv_w = 130, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 470, .adv_w = 130, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 486, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 232, .box_w = 14, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 552, .adv_w = 164, .box_w = 12, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 170, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 162, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 630, .adv_w = 185, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 655, .adv_w = 150, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 675, .adv_w = 142, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 695, .adv_w = 173, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 182, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 743, .adv_w = 69, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 115, .box_w = 7, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 766, .adv_w = 161, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 791, .adv_w = 133, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 811, .adv_w = 214, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 839, .adv_w = 182, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 862, .adv_w = 188, .box_w = 12, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 892, .adv_w = 162, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 188, .box_w = 12, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 954, .adv_w = 163, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 977, .adv_w = 139, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1000, .adv_w = 131, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1023, .adv_w = 177, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1046, .adv_w = 159, .box_w = 11, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1074, .adv_w = 252, .box_w = 16, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1114, .adv_w = 151, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1139, .adv_w = 145, .box_w = 11, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1167, .adv_w = 147, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1190, .adv_w = 75, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1204, .adv_w = 79, .box_w = 7, .box_h = 14, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 1229, .adv_w = 75, .box_w = 4, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1243, .adv_w = 131, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1254, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1256, .adv_w = 134, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 1259, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1275, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1297, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1313, .adv_w = 153, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1338, .adv_w = 137, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1354, .adv_w = 79, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1371, .adv_w = 155, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1396, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1418, .adv_w = 62, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1424, .adv_w = 64, .box_w = 5, .box_h = 14, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 1442, .adv_w = 138, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1464, .adv_w = 62, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1470, .adv_w = 237, .box_w = 13, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1496, .adv_w = 153, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1512, .adv_w = 142, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1530, .adv_w = 153, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1552, .adv_w = 153, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1577, .adv_w = 92, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1587, .adv_w = 112, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1601, .adv_w = 93, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1616, .adv_w = 152, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1632, .adv_w = 125, .box_w = 9, .box_h = 8, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1650, .adv_w = 201, .box_w = 13, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1676, .adv_w = 124, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1692, .adv_w = 125, .box_w = 9, .box_h = 11, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 1717, .adv_w = 117, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1731, .adv_w = 79, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1749, .adv_w = 67, .box_w = 2, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1756, .adv_w = 79, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1774, .adv_w = 130, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1780, .adv_w = 94, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 176, .range_length = 1, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/

/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 1, 2, 0, 3, 4, 5,
    2, 6, 7, 8, 9, 10, 9, 10,
    11, 12, 0, 13, 14, 15, 16, 17,
    18, 19, 12, 20, 20, 0, 0, 0,
    21, 22, 23, 24, 25, 22, 26, 27,
    28, 29, 29, 30, 31, 32, 29, 29,
    22, 33, 34, 35, 3, 36, 30, 37,
    37, 38, 39, 40, 41, 42, 43, 0,
    44, 0, 45, 46, 47, 48, 49, 50,
    51, 45, 52, 52, 53, 48, 45, 45,
    46, 46, 54, 55, 56, 57, 51, 58,
    58, 59, 58, 60, 41, 0, 0, 9,
    61
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 1, 2, 0, 3, 4, 5,
    2, 6, 7, 8, 9, 10, 9, 10,
    11, 12, 13, 14, 15, 16, 17, 12,
    18, 19, 20, 21, 21, 0, 0, 0,
    22, 23, 24, 25, 23, 25, 25, 25,
    23, 25, 25, 26, 25, 25, 25, 25,
    23, 25, 23, 25, 3, 27, 28, 29,
    29, 30, 31, 32, 33, 34, 35, 0,
    36, 0, 37, 38, 39, 39, 39, 0,
    39, 38, 40, 41, 38, 38, 42, 42,
    39, 42, 39, 42, 43, 44, 45, 46,
    46, 47, 46, 48, 0, 0, 35, 9,
    49
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 2, 0, 0, 0,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 10, 0, 6, -5, 0, 0,
    0, 0, -12, -13, 2, 11, 5, 4,
    -9, 2, 11, 1, 9, 2, 7, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 13, 2, -2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 4, 0, -7, 0, 0, 0, 0,
    0, -4, 4, 4, 0, 0, -2, 0,
    -2, 2, 0, -2, 0, -2, -1, -4,
    0, 0, 0, 0, -2, 0, 0, -3,
    -3, 0, 0, -2, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    -2, 0, -3, 0, -6, 0, -27, 0,
    0, -4, 0, 4, 7, 0, 0, -4,
    2, 2, 7, 4, -4, 4, 0, 0,
    -13, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, -3, -11, 0, -9,
    -2, 0, 0, 0, 0, 0, 9, 0,
    -7, -2, -1, 1, 0, -4, 0, 0,
    -2, -17, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -18, -2, 9,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 7,
    0, 2, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 9, 2,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -8, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 2,
    4, 2, 7, -2, 0, 0, 4, -2,
    -7, -31, 2, 6, 4, 0, -3, 0,
    8, 0, 7, 0, 7, 0, -21, 0,
    -3, 7, 0, 7, -2, 4, 2, 0,
    0, 1, -2, 0, 0, -4, 18, 0,
    18, 0, 7, 0, 9, 3, 4, 7,
    0, 0, 0, -8, 0, 0, 0, 0,
    1, -2, 0, 2, -4, -3, -4, 2,
    0, -2, 0, 0, 0, -9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -15, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, -12, 0, -14, 0, 0, 0,
    0, -2, 0, 22, -3, -3, 2, 2,
    -2, 0, -3, 2, 0, 0, -12, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -22, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -14, 0, 13, 0, 0, -8, 0,
    7, 0, -15, -22, -15, -4, 7, 0,
    0, -15, 0, 3, -5, 0, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 6, 7, -27, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 11, 0, 2, 0, 0, 0,
    0, 0, 2, 2, -3, -4, 0, -1,
    -1, -2, 0, 0, -2, 0, 0, 0,
    -4, 0, -2, 0, -5, -4, 0, -6,
    -7, -7, -4, 0, -4, 0, -4, 0,
    0, 0, 0, -2, 0, 0, 2, 0,
    2, -2, 0, 1, 0, 0, 0, 2,
    -2, 0, 0, 0, -2, 2, 2, -1,
    0, 0, 0, -4, 0, -1, 0, 0,
    0, 0, 0, 1, 0, 3, -2, 0,
    -3, 0, -4, 0, 0, -2, 0, 7,
    0, 0, -2, 0, 0, 0, 0, 0,
    -1, 1, -2, -2, 0, 0, -2, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, -1, 0, -2, -3, 0,
    0, 0, 0, 0, 1, 0, 0, -2,
    0, -2, -2, -2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, 0, -2, -3, 0, -3, 0, -7,
    -2, -7, 4, 0, 0, -4, 2, 4,
    6, 0, -6, -1, -3, 0, -1, -11,
    2, -2, 2, -12, 2, 0, 0, 1,
    -12, 0, -12, -2, -19, -2, 0, -11,
    0, 4, 6, 0, 3, 0, 0, 0,
    0, 0, 0, -4, -3, 0, -7, 0,
    0, 0, -2, 0, 0, 0, -2, 0,
    0, 0, 0, 0, -1, -1, 0, -1,
    -3, 0, 0, 0, 0, 0, 0, 0,
    -2, -2, 0, -2, -3, -2, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -2, 0, -3,
    0, -2, 0, -4, 2, 0, 0, -3,
    1, 2, 2, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 2,
    0, 0, -2, 0, -2, -2, -3, 0,
    0, 0, 0, 0, 0, 0, 2, 0,
    -2, 0, 0, 0, 0, -2, -3, 0,
    -4, 0, 7, -2, 1, -7, 0, 0,
    6, -11, -12, -9, -4, 2, 0, -2,
    -15, -4, 0, -4, 0, -4, 3, -4,
    -14, 0, -6, 0, 0, 1, -1, 2,
    -2, 0, 2, 0, -7, -9, 0, -11,
    -5, -5, -5, -7, -3, -6, 0, -4,
    -6, 1, 0, 1, 0, -2, 0, 0,
    0, 2, 0, 2, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, -1, 0, -1, -2, 0, -4, -5,
    -5, -1, 0, -7, 0, 0, 0, 0,
    0, 0, -2, 0, 0, 0, 0, 1,
    -1, 0, 0, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 11, 0, 0,
    0, 0, 0, 0, 2, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    -4, 0, 0, 0, 0, -11, -7, 0,
    0, 0, -3, -11, 0, 0, -2, 2,
    0, -6, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, -4, 0,
    0, 0, 0, 3, 0, 2, -4, -4,
    0, -2, -2, -3, 0, 0, 0, 0,
    0, 0, -7, 0, -2, 0, -3, -2,
    0, -5, -6, -7, -2, 0, -4, 0,
    -7, 0, 0, 0, 0, 18, 0, 0,
    1, 0, 0, -3, 0, 2, 0, -10,
    0, 0, 0, 0, 0, -21, -4, 7,
    7, -2, -9, 0, 2, -3, 0, -11,
    -1, -3, 2, -16, -2, 3, 0, 3,
    -8, -3, -8, -7, -9, 0, 0, -13,
    0, 13, 0, 0, -1, 0, 0, 0,
    -1, -1, -2, -6, -7, 0, -21, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, -1, -2, -3, 0, 0,
    -4, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, -4, 0, 0, 4,
    -1, 3, 0, -5, 2, -2, -1, -6,
    -2, 0, -3, -2, -2, 0, -3, -4,
    0, 0, -2, -1, -2, -4, -3, 0,
    0, -2, 0, 2, -2, 0, -5, 0,
    0, 0, -4, 0, -4, 0, -4, -4,
    2, 0, 0, 0, 0, 0, 0, 0,
    0, -4, 2, 0, -3, 0, -2, -3,
    -7, -2, -2, -2, -1, -2, -3, -1,
    0, 0, 0, 0, 0, -2, -2, -2,
    0, 0, 0, 0, 3, -2, 0, -2,
    0, 0, 0, -2, -3, -2, -2, -3,
    -2, 0, 2, 9, -1, 0, -6, 0,
    -2, 4, 0, -2, -9, -3, 3, 0,
    0, -11, -4, 2, -4, 2, 0, -2,
    -2, -7, 0, -3, 1, 0, 0, -4,
    0, 0, 0, 2, 2, -4, -4, 0,
    -4, -2, -3, -2, -2, 0, -4, 1,
    -4, -4, 7, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -3, 0, 0, -3,
    0, 0, -2, -2, 0, 0, 0, 0,
    -2, 0, 0, 0, 0, -1, 0, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    -3, 0, -4, 0, 0, 0, -7, 0,
    2, -5, 4, 0, -2, -11, 0, 0,
    -5, -2, 0, -9, -6, -6, 0, 0,
    -10, -2, -9, -9, -11, 0, -6, 0,
    2, 15, -3, 0, -5, -2, -1, -2,
    -4, -6, -4, -8, -9, -5, -2, 0,
    0, -2, 0, 1, 0, 0, -16, -2,
    7, 5, -5, -8, 0, 1, -7, 0,
    -11, -2, -2, 4, -21, -3, 1, 0,
    0, -15, -3, -12, -2, -16, 0, 0,
    -16, 0, 13, 1, 0, -2, 0, 0,
    0, 0, -1, -2, -9, -2, 0, -15,
    0, 0, 0, 0, -7, 0, -2, 0,
    -1, -6, -11, 0, 0, -1, -3, -7,
    -2, 0, -2, 0, 0, 0, 0, -10,
    -2, -7, -7, -2, -4, -6, -2, -4,
    0, -4, -2, -7, -3, 0, -3, -4,
    -2, -4, 0, 1, 0, -2, -7, 0,
    4, 0, -4, 0, 0, 0, 0, 3,
    0, 2, -4, 9, 0, -2, -2, -3,
    0, 0, 0, 0, 0, 0, -7, 0,
    -2, 0, -3, -2, 0, -5, -6, -7,
    -2, 0, -4, 2, 9, 0, 0, 0,
    0, 18, 0, 0, 1, 0, 0, -3,
    0, 2, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, -4, 0, 0, 0, 0, 0, -1,
    0, 0, 0, -2, -2, 0, 0, -4,
    -2, 0, 0, -4, 0, 4, -1, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 3, 4, 2, -2, 0, -7,
    -4, 0, 7, -7, -7, -4, -4, 9,
    4, 2, -19, -2, 4, -2, 0, -2,
    2, -2, -8, 0, -2, 2, -3, -2,
    -7, -2, 0, 0, 7, 4, 0, -6,
    0, -12, -3, 6, -3, -9, 1, -3,
    -7, -7, -2, 9, 2, 0, -3, 0,
    -6, 0, 2, 7, -5, -8, -9, -6,
    7, 0, 1, -16, -2, 2, -4, -2,
    -5, 0, -5, -8, -3, -3, -2, 0,
    0, -5, -5, -2, 0, 7, 5, -2,
    -12, 0, -12, -3, 0, -8, -13, -1,
    -7, -4, -7, -6, 6, 0, 0, -3,
    0, -4, -2, 0, -2, -4, 0, 4,
    -7, 2, 0, 0, -12, 0, -2, -5,
    -4, -2, -7, -6, -7, -5, 0, -7,
    -2, -5, -4, -7, -2, 0, 0, 1,
    11, -4, 0, -7, -2, 0, -2, -4,
    -5, -6, -6, -9, -3, -4, 4, 0,
    -3, 0, -11, -3, 1, 4, -7, -8,
    -4, -7, 7, -2, 1, -21, -4, 4,
    -5, -4, -8, 0, -7, -9, -3, -2,
    -2, -2, -5, -7, -1, 0, 0, 7,
    6, -2, -15, 0, -13, -5, 5, -9,
    -15, -4, -8, -9, -11, -7, 4, 0,
    0, 0, 0, -3, 0, 0, 2, -3,
    4, 2, -4, 4, 0, 0, -7, -1,
    0, -1, 0, 1, 1, -2, 0, 0,
    0, 0, 0, 0, -2, 0, 0, 0,
    0, 2, 7, 0, 0, -3, 0, 0,
    0, 0, -2, -2, -3, 0, 0, 0,
    1, 2, 0, 0, 0, 0, 2, 0,
    -2, 0, 9, 0, 4, 1, 1, -3,
    0, 4, 0, 0, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 7, 0, 6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -13, 0, -2, 4, 0, 7,
    0, 0, 22, 3, -4, -4, 2, 2,
    -2, 1, -11, 0, 0, 11, -13, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, -15, 9, 31, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -13, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -4, 0, 0, -4,
    -2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, 0, -6, 0,
    0, 1, 0, 0, 2, 29, -4, -2,
    7, 6, -6, 2, 0, 0, 2, 2,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -29, 6, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -6,
    0, 0, 0, -6, 0, 0, 0, 0,
    -5, -1, 0, 0, 0, -5, 0, -3,
    0, -11, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -15, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0,
    0, -2, 0, 0, -4, 0, -3, 0,
    -6, 0, 0, 0, -4, 2, -3, 0,
    0, -6, -2, -5, 0, 0, -6, 0,
    -2, 0, -11, 0, -2, 0, 0, -18,
    -4, -9, -2, -8, 0, 0, -15, 0,
    -6, -1, 0, 0, 0, 0, 0, 0,
    0, 0, -3, -4, -2, -4, 0, 0,
    0, 0, -5, 0, -5, 3, -2, 4,
    0, -2, -5, -2, -4, -4, 0, -3,
    -1, -2, 2, -6, -1, 0, 0, 0,
    -20, -2, -3, 0, -5, 0, -2, -11,
    -2, 0, 0, -2, -2, 0, 0, 0,
    0, 2, 0, -2, -4, -2, 4, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 3, 0, 0, 0, 0, 0,
    0, -5, 0, -2, 0, 0, 0, -4,
    2, 0, 0, 0, -6, -2, -4, 0,
    0, -6, 0, -2, 0, -11, 0, 0,
    0, 0, -22, 0, -4, -8, -11, 0,
    0, -15, 0, -2, -3, 0, 0, 0,
    0, 0, 0, 0, 0, -2, -3, -1,
    -3, 1, 0, 0, 4, -3, 0, 7,
    11, -2, -2, -7, 3, 11, 4, 5,
    -6, 3, 9, 3, 6, 5, 6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 14, 11, -4, -2, 0, -2,
    18, 10, 18, 0, 0, 0, 2, 0,
    0, 8, 0, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, -2, 0,
    0, 0, 0, 0, 0, 0, 0, 3,
    0, 0, 0, 0, -19, -3, -2, -9,
    -11, 0, 0, -15, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 0, 0, 0, 0, -19, -3, -2,
    -9, -11, 0, 0, -9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -2, 0, 0, 0, -5, 2, 0, -2,
    2, 4, 2, -7, 0, 0, -2, 2,
    0, 2, 0, 0, 0, 0, -6, 0,
    -2, -2, -4, 0, -2, -9, 0, 14,
    -2, 0, -5, -2, 0, -2, -4, 0,
    -2, -6, -4, -3, 0, 0, 0, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    0, 0, 3, 0, 0, 0, 0, -19,
    -3, -2, -9, -11, 0, 0, -15, 0,
    0, 0, 0, 0, 0, 11, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -4, 0, -7, -3, -2, 7, -2, -2,
    -9, 1, -1, 1, -2, -6, 0, 5,
    0, 2, 1, 2, -5, -9, -3, 0,
    -9, -4, -6, -9, -9, 0, -4, -4,
    -3, -3, -2, -2, -3, -2, 0, -2,
    -1, 3, 0, 3, -2, 0, 7, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, -2, -2, 0, 0,
    -6, 0, -1, 0, -4, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    -13, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -2, -2, 0, -3,
    0, 0, 0, 0, -2, 0, 0, -4,
    -2, 2, 0, -4, -4, -2, 0, -6,
    -2, -5, -2, -3, 0, -4, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -15, 0, 7, 0, 0, -4, 0,
    0, 0, 0, -3, 0, -2, 0, 0,
    -1, 0, 0, -2, 0, -5, 0, 0,
    9, -3, -7, -7, 2, 2, 2, 0,
    -6, 2, 3, 2, 7, 2, 7, -2,
    -6, 0, 0, -9, 0, 0, -7, -6,
    0, 0, -4, 0, -3, -4, 0, -3,
    0, -3, 0, -2, 3, 0, -2, -7,
    -2, 8, 0, 0, -2, 0, -4, 0,
    0, 3, -5, 0, 2, -2, 2, 0,
    0, -7, 0, -2, -1, 0, -2, 2,
    -2, 0, 0, 0, -9, -3, -5, 0,
    -7, 0, 0, -11, 0, 8, -2, 0,
    -4, 0, 1, 0, -2, 0, -2, -7,
    0, -2, 2, 0, 0, 0, 0, -2,
    0, 0, 2, -3, 1, 0, 0, -3,
    -2, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, -14, 0, 5, 0,
    0, -2, 0, 0, 0, 0, 0, 0,
    -2, -2, 0, 0, 0, 4, 0, 5,
    0, 0, 0, 0, 0, -14, -13, 1,
    10, 7, 4, -9, 2, 9, 0, 8,
    0, 4, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 12, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0
};

/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 61,
    .right_class_cnt     = 49,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 2,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t montserrat_14_c_array__data = {
#else
lv_font_t montserrat_14_c_array__data = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif

#if LV_VERSION_CHECK(9, 3, 0)
    .static_bitmap = 1,    /*Bitmaps are stored as const so they are always static if not compressed */
#endif

    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if MONTSERRAT_14_C_ARRAY__DATA*/
