#ifndef _tGFX_H
#define _tGFX_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define tGFX_COLOR_MODE1 1
#define tGFX_COLOR_MODE444 2
#define tGFX_COLOR_MODE565 3
#define tGFX_COLOR_MODE666 4
#define tGFX_COLOR_MODERGB 5
#define tGFX_COLOR_MODERGBA 6

typedef struct
{
  uint16_t width;
  uint16_t height;
  uint8_t mode;
  uint8_t *buffer;
} tGFX_Canvas;


tGFX_Canvas *tGFX_create_canvas(uint16_t width, uint16_t height, uint8_t mode);

#endif