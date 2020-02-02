#include "tGFX.h"
#include "tGFX/565/basic.h"

#include "gfx.h"

#include <stdio.h>

int main()
{
  // use 565 color canvas.
  tGFX_Canvas *canvas = tGFX_create_canvas(128, 128, tGFX_COLOR_MODE565);

  tGFX_draw_pixel(canvas, 63, 63, 0xffff);

  tGFX_draw_line(canvas, 10, 10, 100, 30, 0x35d3);

  tGFX_draw_rect(canvas, 90, 16, 30, 20, 0xff20);

  tGFX_draw_rect_radius(canvas, 12, 12, 68, 28, 14, 0xa25b);

  tGFX_draw_circle(canvas, 30, 50, 5, 0xb1a8);

  tGFX_draw_arc_quarter(canvas, 90, 80, 30, 0x05, 0xfc00);
  tGFX_draw_arc_quarter(canvas, 90, 80, 30, 0x0a, 0x03bf);

  tGFX_draw_ellipse(canvas, 30, 60, 20, 10, 0x6512);
  tGFX_draw_ellipse(canvas, 30, 60, 10, 20, 0x6512);

  uint16_t triangle[] = {10, 80, 20, 90, 0, 90};
  tGFX_draw_polygon(canvas, triangle, 3, 0xf802);

  uint16_t arrow[] = {40, 90, 50, 105, 40, 100, 30, 105};
  tGFX_draw_polygon(canvas, arrow, 4, 0x05ca);

  gfx_open(128, 128, "tGFX demo for X86");

  uint8_t r, g, b;
  for (size_t y = 0; y < 128; y++)
  {
    for (size_t x = 0; x < 128; x++)
    {
      tGFX_get_pixel_RGB(canvas, x, y, &r, &g, &b);
      gfx_color(r, g, b);
      gfx_point(x, y);
    }
  }

  char c;
  while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') {
			break;
		}
	}

  printf("completed!\n");
  return 0;
}