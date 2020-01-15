#ifndef _tGFX_BASIC_H
#define _tGFX_BASIC_H

#include "../../tGFX.h"

void tGFX_draw_pixel(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint16_t color);

void tGFX_get_pixel_RGB(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint8_t *r, uint8_t *g, uint8_t *b);

/**
 * draw a line use bresenham line algorithm.
 * copyright: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
 */
void tGFX_draw_line(tGFX_Canvas *canvas, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

void tGFX_draw_rect(tGFX_Canvas *canvas, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

#endif