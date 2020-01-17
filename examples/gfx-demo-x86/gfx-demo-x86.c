#include "tGFX.h"
#include "tGFX/565/basic.h"
#include "tGFX/tools.h"

#include "gfx.h"

#include <stdio.h>

int main()
{
  // use 565 color canvas.
  tGFX_Canvas *canvas = tGFX_create_canvas(128, 128, tGFX_COLOR_MODE565);

  tGFX_draw_pixel(canvas, 0, 0, 0xffff);
  tGFX_draw_pixel(canvas, 127, 0, 0xffff);
  tGFX_draw_pixel(canvas, 63, 63, 0xffff);
  tGFX_draw_pixel(canvas, 0, 127, 0xffff);
  tGFX_draw_pixel(canvas, 127, 127, 0xffff);

  tGFX_draw_line(canvas, 10, 10, 100, 30, 0x35d3);

  tGFX_draw_rect(canvas, 20, 20, 80, 40, 0xa25b);

  tGFX_draw_circle(canvas, 30, 50, 5, 0xb1a8);

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
