#include <tGFX/565/font.h>

/**
 * Set the global line height.
 */
void tGFX_Set_line_height(uint8_t line_height) { LINE_HEIGHT = line_height; }

/**
 * Set the global letter spacing.
 */
void tGFX_Set_letter_spacing(uint8_t letter_spacing) {
  LETTER_SPACING = letter_spacing;
}

/**
 * draw a char use the given font.
 */
void tGFX_draw_char(tGFX_Canvas *canvas, uint16_t x, uint16_t y, char c,
                    tGFX_BITMAP_FONT *font, uint16_t color) {
  uint8_t i = 0;
  for (i = 0; i < font->count; i++) {
    if (c == font->lookup[i]) {
      break;
    }
  }
  if (i == font->count) {
    // not found char
    return;
  }

  uint16_t byte_per_char;
  uint16_t pos;
  if (font->order == tGFX_BITMAP_FONT_ORDER_V) {
    byte_per_char = font->height / 8 * font->width;
    pos = i * byte_per_char;
    uint8_t char_bitmap[byte_per_char];
    for (uint16_t c = 0; c < byte_per_char; c++) {
      char_bitmap[c] = font->data[pos + c];
    }
    tGFX_draw_bitmap_v(canvas, x, y, font->width, font->height, char_bitmap,
                       color);
  } else if (font->order == tGFX_BITMAP_FONT_ORDER_H) {
    byte_per_char = font->width / 8 * font->height;
    pos = i * byte_per_char;
    uint8_t char_bitmap[byte_per_char];
    for (uint16_t c = 0; c < byte_per_char; c++) {
      char_bitmap[c] = font->data[pos + c];
    }
    tGFX_draw_bitmap(canvas, x, y, font->width, font->height, char_bitmap,
                     color);
  }
};

/**
 * draw text without word wrap. Overflow will hidden. Support format characters.
 * support format: '\n'
 */
void tGFX_draw_text(tGFX_Canvas *canvas, uint16_t x, uint16_t y, char *text,
                    uint16_t len, tGFX_BITMAP_FONT *font, uint16_t color) {
  uint16_t cx = x, cy = y;
  for (uint16_t i = 0; i < len; i++) {
    if (text[i] == '\n') {
      cx = x;
      cy = cy + font->height + LINE_HEIGHT;
      continue;
    }
    tGFX_draw_char(canvas, cx, cy, text[i], font, color);
    cx = cx + font->width + LETTER_SPACING;
  }
}
