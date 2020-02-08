#ifndef _tGFX_TOOLS_H
#define _tGFX_TOOLS_H

#include <tGFX.h>

/**
 * simply convert 565 color to RGB color format.
 */
void tGFX_565_to_RGB(uint16_t color, uint8_t *r, uint8_t *g, uint8_t *b);

#endif
