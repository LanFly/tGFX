#ifndef _tGFX_BITMAP_FONT_H
#define _tGFX_BITMAP_FONT_H

#include <stdint.h>

/**
 * Bitmap font in vertical order.
 * The height of font must be a multiple of 8.
 */
#define tGFX_BITMAP_FONT_ORDER_V 0

/**
 * Bitmap font in horizontal order.
 * The width of font must be a multiple of 8.
 */
#define tGFX_BITMAP_FONT_ORDER_H 1

typedef const struct {
  const char *name;
  const uint8_t order;
  const uint8_t width;
  const uint8_t height;
  const uint8_t count;
  const char *lookup;
  const uint8_t *data;
} tGFX_BITMAP_FONT;

#endif
