#ifndef _tGFX_FONT_H
#define _tGFX_FONT_H

#include <tGFX.h>
#include <tGFX/565/basic.h>
#include <tGFX/font/font.h>

#include <stdint.h>

// line height
static uint8_t LINE_HEIGHT = 2;
// letter spacing
static uint8_t LETTER_SPACING = 1;

/**
 * Set the global line height.
 */
void tGFX_Set_line_height(uint8_t line_height);

/**
 * Set the global letter spacing.
 */
void tGFX_Set_letter_spacing(uint8_t letter_spacing);

/**
 * draw a char use the given font.
 */
void tGFX_draw_char(tGFX_Canvas *canvas, uint16_t x, uint16_t y, char c,
                    tGFX_BITMAP_FONT *font, uint16_t color);

/**
 * draw text without word wrap. Overflow will hidden. Support format characters.
 * support format: '\n'
 */
void tGFX_draw_text(tGFX_Canvas *canvas, uint16_t x, uint16_t y, char *text,
                    uint16_t len, tGFX_BITMAP_FONT *font, uint16_t color);

#endif
