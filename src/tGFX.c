#include "tGFX.h"

tGFX_Canvas *tGFX_create_canvas(uint16_t width, uint16_t height, uint8_t mode)
{
  tGFX_Canvas *canvas = (tGFX_Canvas *)malloc(sizeof(tGFX_Canvas));
  if (canvas == NULL)
  {
    return NULL;
  }
  memset(canvas, 0, sizeof(tGFX_Canvas));

  uint32_t buffer_size = 0;
  switch (mode)
  {
  case tGFX_COLOR_MODE1:
    buffer_size = width * height / 8;
    break;
  case tGFX_COLOR_MODE444:
    buffer_size = width * height * 1.5;
    break;
  case tGFX_COLOR_MODE565:
    buffer_size = width * height * 2;
    break;
  case tGFX_COLOR_MODE666:
    buffer_size = width * height * 3;
    break;
  case tGFX_COLOR_MODERGB:
    buffer_size = width * height * 3;
    break;
  case tGFX_COLOR_MODERGBA:
    buffer_size = width * height * 4;
    break;
  }

  uint8_t *buffer = (uint8_t *)malloc(buffer_size);
  if (buffer == NULL)
  {
    free(canvas);
    return NULL;
  }
  memset(buffer, 0, buffer_size);

  canvas->width = width;
  canvas->height = height;
  canvas->mode = mode;
  canvas->buffer = buffer;

  return canvas;
}
