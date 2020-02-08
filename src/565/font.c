#include <tGFX/565/font.h>

void tGFX_draw_char(tGFX_Canvas *canvas, uint16_t x, uint16_t y, char c,
                    tGFX_BITMAP_FONT *font, uint16_t color) {
  for (uint8_t i = 0; i < font->count; i++) {
    if (c == font->lookup[i]) {
      uint16_t pos = i * 5;
      uint8_t charBitmap[] = {font->data[pos], font->data[pos + 1],
                              font->data[pos + 2], font->data[pos + 3],
                              font->data[pos + 4]};
      tGFX_draw_bitmap_v(canvas, x, y, 5, 8, charBitmap, color);
      break;
    }
  }
};
