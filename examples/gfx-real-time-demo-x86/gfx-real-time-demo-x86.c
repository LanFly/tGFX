#include "tGFX.h"
#include "tGFX/565/basic.h"

#include "tGFX/565/font.h"
#include "tGFX/font/5x8.h"

#include "tGFX/tools.h"

// X11
#include "gfx.h"

#include <stdio.h>

void X11Open(char *title, tGFX_Canvas *canvas);

void X11Waiting();

void tGFX_draw_pixel(tGFX_Canvas *canvas, uint16_t x, uint16_t y,
                     uint16_t color) {
  // overflow hidden.
  if (x > canvas->width || y > canvas->height) {
    return;
  }
  uint8_t r, g, b;
  // convert 565 color to RGB color.
  tGFX_565_to_RGB(color, &r, &g, &b);
  // gfx_color(r, g, b);
  gfx_color(255, 255, 255);
  gfx_point(x, y);
}

int main() {
  // use 565 color canvas.
  tGFX_Canvas ncanvas;
  tGFX_Canvas *canvas = &ncanvas;
  tGFX_init_canvas(canvas, 128, 128, tGFX_COLOR_MODE565);

  X11Open("tGFX real-time mode demo for X86", canvas);

  tGFX_draw_pixel(canvas, 63, 63, 0xffff);

  tGFX_draw_line(canvas, 10, 10, 100, 30, 0x35d3);

  tGFX_draw_rect(canvas, 90, 16, 30, 20, 0xff20);

  tGFX_fill_rect(canvas, 75, 70, 30, 20, 0xff20);

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

  tGFX_draw_char(canvas, 0, 0, 'A', &FONT_5X8, 0xffff);

  tGFX_draw_text(canvas, 10, 110, "Hello tGFX!\n...", 16, &FONT_5X8, 0xffff);

  uint8_t vertical_bitmap[] = {0xFE, 0x04, 0x18, 0x04, 0xFE}; // W
  tGFX_draw_bitmap_v(canvas, 10, 100, 5, 8, vertical_bitmap, 0xffff);
  tGFX_draw_bitmap(canvas, 18, 100, 8, 5, vertical_bitmap, 0xffff);

  printf("Enter q on the Window to quit:\n");

  X11Waiting();

  printf("completed!\n");
  return 0;
}

void X11Open(char *title, tGFX_Canvas *canvas) {
  // X11 Window
  gfx_open(canvas->width, canvas->height, title);
}

void X11Waiting() {
  char c;
  while (1) {
    // Wait for the user to press a character.
    c = gfx_wait();
    // Quit if it is the letter q.
    if (c == 'q') {
      break;
    }
  }
}
