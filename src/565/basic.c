#include <tGFX/565/basic.h>

/**
 * draw a pixel.
 */
void tGFX_draw_pixel(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint16_t color)
{
  // overflow hidden.
  if (x >= canvas->width || y >= canvas->height)
  {
    return;
  }
  uint32_t pos = (canvas->width * y + x) * 2;
  canvas->buffer[pos] = color >> 8;
  canvas->buffer[pos + 1] = color;
}

void tGFX_get_pixel_RGB(tGFX_Canvas *canvas, uint16_t x, uint16_t y, uint8_t *r, uint8_t *g, uint8_t *b)
{
  uint16_t pixel;
  // overflow hidden.
  if (x >= canvas->width || y >= canvas->height)
  {
    *r = *g = *b = 0;
    return;
  }

  uint32_t pos = (canvas->width * y + x) * 2;
  uint8_t msb = canvas->buffer[pos];
  uint8_t lsb = canvas->buffer[pos + 1];
  pixel = (0x0000 | msb) << 8 | lsb;

  *r = (pixel >> 11) << 3;
  *g = (pixel >> 5 & 0x3F) << 2;
  *b = (pixel & 0x1F) << 3;
}

/**
 * draw a line with bresenhams line algorithm.
 * copyright: https://rosettacode.org/wiki/Bitmap/Bresenham%27s_line_algorithm#C
 */
void tGFX_draw_line(tGFX_Canvas *canvas, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
  int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
  int dy = abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
  int err = (dx > dy ? dx : -dy) / 2, e2;

  while (1)
  {
    tGFX_draw_pixel(canvas, x1, y1, color);
    if (x1 == x2 && y1 == y2)
    {
      break;
    }

    e2 = err;
    if (e2 > -dx)
    {
      err -= dy;
      x1 += sx;
    }
    if (e2 < dy)
    {
      err += dx;
      y1 += sy;
    }
  }
}

/**
 * draw a reacangle with tGFX_draw_line func.
 */
void tGFX_draw_rect(tGFX_Canvas *canvas, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color)
{
  tGFX_draw_line(canvas, x1, y1, x2, y1, color);
  tGFX_draw_line(canvas, x2, y1, x2, y2, color);
  tGFX_draw_line(canvas, x2, y2, x1, y2, color);
  tGFX_draw_line(canvas, x1, y2, x1, y1, color);
}

/**
 * draw a circle with Midpoint circle algorithm.
 * copyright: https://rosettacode.org/wiki/Bitmap/Midpoint_circle_algorithm#C
 */
void tGFX_draw_circle(tGFX_Canvas *canvas, uint16_t xc, uint16_t yc, uint16_t r, uint16_t color)
{
  int f = 1 - r;
  int ddF_x = 0;
  int ddF_y = -2 * r;
  int x = 0;
  int y = r;

  tGFX_draw_pixel(canvas, xc, yc + r, color);
  tGFX_draw_pixel(canvas, xc, yc - r, color);
  tGFX_draw_pixel(canvas, xc + r, yc, color);
  tGFX_draw_pixel(canvas, xc - r, yc, color);

  while (x < y)
  {
    if (f >= 0)
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }
    x++;
    ddF_x += 2;
    f += ddF_x + 1;
    tGFX_draw_pixel(canvas, xc + x, yc + y, color);
    tGFX_draw_pixel(canvas, xc - x, yc + y, color);
    tGFX_draw_pixel(canvas, xc + x, yc - y, color);
    tGFX_draw_pixel(canvas, xc - x, yc - y, color);
    tGFX_draw_pixel(canvas, xc + y, yc + x, color);
    tGFX_draw_pixel(canvas, xc - y, yc + x, color);
    tGFX_draw_pixel(canvas, xc + y, yc - x, color);
    tGFX_draw_pixel(canvas, xc - y, yc - x, color);
  }
}

/**
 * draw a ellipse with midpoint ellipse algorithm.
 * copyright: https://www.geeksforgeeks.org/midpoint-ellipse-drawing-algorithm/
 */
void tGFX_draw_ellipse(tGFX_Canvas *canvas, uint16_t xc, uint16_t yc, uint16_t rx, uint16_t ry, uint16_t color)
{

  float dx, dy, d1, d2, x, y;
  x = 0;
  y = ry;

  // Initial decision parameter of region 1
  d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
  dx = 2 * ry * ry * x;
  dy = 2 * rx * rx * y;

  // For region 1
  while (dx < dy)
  {

    // Print points based on 4-way symmetry
    tGFX_draw_pixel(canvas, x + xc, y + yc, color);
    tGFX_draw_pixel(canvas, -x + xc, y + yc, color);
    tGFX_draw_pixel(canvas, x + xc, -y + yc, color);
    tGFX_draw_pixel(canvas, -x + xc, -y + yc, color);

    // Checking and updating value of
    // decision parameter based on algorithm
    if (d1 < 0)
    {
      x++;
      dx = dx + (2 * ry * ry);
      d1 = d1 + dx + (ry * ry);
    }
    else
    {
      x++;
      y--;
      dx = dx + (2 * ry * ry);
      dy = dy - (2 * rx * rx);
      d1 = d1 + dx - dy + (ry * ry);
    }
  }

  // Decision parameter of region 2
  d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);

  // Plotting points of region 2
  while (y >= 0)
  {

    // printing points based on 4-way symmetry
    tGFX_draw_pixel(canvas, x + xc, y + yc, color);
    tGFX_draw_pixel(canvas, -x + xc, y + yc, color);
    tGFX_draw_pixel(canvas, x + xc, -y + yc, color);
    tGFX_draw_pixel(canvas, -x + xc, -y + yc, color);

    // Checking and updating parameter
    // value based on algorithm
    if (d2 > 0)
    {
      y--;
      dy = dy - (2 * rx * rx);
      d2 = d2 + (rx * rx) - dy;
    }
    else
    {
      y--;
      x++;
      dx = dx + (2 * ry * ry);
      dy = dy - (2 * rx * rx);
      d2 = d2 + dx - dy + (rx * rx);
    }
  }
}
