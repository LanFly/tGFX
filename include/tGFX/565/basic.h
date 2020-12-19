#ifndef _tGFX_BASIC_H
#define _tGFX_BASIC_H

#include <tGFX.h>

/**
 * draw a pixel.
 */
#ifndef tGFX_USE_REAL_TIME
void tGFX_draw_pixel(tGFX_Canvas *canvas, uint16_t x, uint16_t y,
                     uint16_t color);
#else
extern void tGFX_draw_pixel(tGFX_Canvas *canvas, uint16_t x, uint16_t y,
                            uint16_t color);
#endif

#ifndef tGFX_USE_REAL_TIME
void tGFX_get_pixel_RGB(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint8_t *r,
                        uint8_t *g, uint8_t *b);
#endif

/**
 * draw a line with bresenham line algorithm.
 * copyright: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
 */
void tGFX_draw_line(tGFX_Canvas *canvas, uint16_t x1, uint16_t y1, uint16_t x2,
                    uint16_t y2, uint16_t color);

/**
 * draw a rectangle with tGFX_draw_line func.
 */
void tGFX_draw_rect(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint16_t w,
                    uint16_t h, uint16_t color);

/**
 * draw a filled rectangle with tGFX_draw_line func.
 */
void tGFX_fill_rect(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint16_t w,
                    uint16_t h, uint16_t color);

/**
 * draw a circle with Midpoint circle algorithm.
 * copyright: https://rosettacode.org/wiki/Bitmap/Midpoint_circle_algorithm#C
 */
void tGFX_draw_circle(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint16_t r,
                      uint16_t color);

/**
 * draw a arc in a multiple of a quarter with Midpoint circle algorithm.
 * copyright: https://rosettacode.org/wiki/Bitmap/Midpoint_circle_algorithm#C
 */
void tGFX_draw_arc_quarter(tGFX_Canvas *canvas, uint16_t xc, uint16_t yc,
                           uint16_t r, uint8_t angle, uint16_t color);

/**
 * draw a ellipse with midpoint ellipse algorithm.
 * copyright: https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/
 */
void tGFX_draw_ellipse(tGFX_Canvas *canvas, uint16_t xc, uint16_t yc,
                       uint16_t rx, uint16_t ry, uint16_t color);

/**
 * draw a rounded reacangle with tGFX_draw_line func.
 */
void tGFX_draw_rect_radius(tGFX_Canvas *canvas, uint16_t x, uint16_t y,
                           uint16_t w, uint16_t h, uint16_t r, uint16_t color);

/**
 * draw a polygon with tGFX_draw_line func.
 * @param points {x1, y1, x2, y2, ..., xn, yn}
 */
void tGFX_draw_polygon(tGFX_Canvas *canvas, uint16_t *points, uint8_t edge,
                       uint16_t color);

/**
 * draw a bitmap in vertical order with tGFX_draw_pixel func.
 * @param h h must be a multiple of 8
 */
void tGFX_draw_bitmap_v(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint16_t w,
                        uint16_t h, const uint8_t *bitmap, uint16_t color);

/**
 * draw a bitmap in horizontal order with tGFX_draw_pixel func.
 * @param w w must be a multiple of 8
 */
void tGFX_draw_bitmap(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint16_t w,
                      uint16_t h, const uint8_t *bitmap, uint16_t color);

/**
 * draw a image in horizontal order with tGFX_draw_pixel func.
 * @param buffer image data in horizontal order. One pixel takes two bytes with
 * 565 format.
 */
void tGFX_draw_image(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint16_t w,
                     uint16_t h, const uint8_t *buffer);
#endif
