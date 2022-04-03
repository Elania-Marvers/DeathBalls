#ifndef ___SET_PIXEL___
#define ___SET_PIXEL___
#include <lapin.h>

bool set_pixel(t_bunny_pixelarray *px,
                	t_bunny_position coords,
                	uint32_t color);
#endif
