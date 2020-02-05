#ifndef _tGFX_FONT_H
#define _tGFX_FONT_H

#include <tGFX.h>
#include <tGFX/font/font.h>

#include <stdint.h>

void tGFX_draw_char(tGFX_Canvas *canvas, uint16_t x, uint16_t y, char c,
                    tGFX_BITMAP_FONT *font, uint16_t color);

#endif
