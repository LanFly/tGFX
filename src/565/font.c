#include <tGFX/565/font.h>

void tGFX_draw_char(tGFX_Canvas *canvas, uint16_t x, uint16_t y, char c,
                    tGFX_BITMAP_FONT *font, uint16_t color) {
  for (uint8_t i = 0; i < font->count; i++) {
    if (c == font->lookup[i]) {
      printf("char: %c index: %d\n", c, i);
      break;
    }
  }
};
