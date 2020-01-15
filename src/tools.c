#include <tGFX/tools.h>

void tGFX_565_to_RGB(uint16_t color, uint8_t *r, uint8_t *g, uint8_t *b)
{
  *r = (color >> 11) << 3;
  *g = (color >> 5 & 0x3F) << 2;
  *b = (color & 0x1F) << 3;
}
