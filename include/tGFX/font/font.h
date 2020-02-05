#ifndef _tGFX_BITMAP_FONT_H
#define _tGFX_BITMAP_FONT_H

typedef const struct {
  const char *name;
  const uint8_t width;
  const uint8_t height;
  const uint8_t count;
  const char *lookup;
  const uint8_t *data;
} tGFX_BITMAP_FONT;

#endif
