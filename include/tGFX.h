#ifndef _tGFX_H
#define _tGFX_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tGFX_COLOR_MODE1 1
#define tGFX_COLOR_MODE444 2
#define tGFX_COLOR_MODE565 3
#define tGFX_COLOR_MODE666 4
#define tGFX_COLOR_MODERGB 5
#define tGFX_COLOR_MODERGBA 6

typedef struct {
  uint16_t width;
  uint16_t height;
  uint8_t mode;
#ifndef tGFX_USE_REAL_TIME
  uint8_t *buffer;
#endif
} tGFX_Canvas;

#ifndef tGFX_USE_REAL_TIME
tGFX_Canvas *tGFX_create_canvas(uint16_t width, uint16_t height, uint8_t mode);
#else
uint8_t tGFX_init_canvas(tGFX_Canvas *canvas, uint16_t width, uint16_t height,
                         uint8_t mode);
#endif

#endif