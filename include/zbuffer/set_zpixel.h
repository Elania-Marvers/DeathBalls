#ifndef ___SETZPIXEL___
#define ___SETZPIXEL___

#include	<lapin.h>
#include	"t_bunny_zpixelarray.h"
#include	"zbuffer_macro.h"
#include	"tri_to_bidimensional.h"
#include	"mix_color.h"
#include	"macro.h"


bool set_pixel(t_bunny_pixelarray *px,
                	t_bunny_position coords,
                	uint32_t color);
t_bunny_position	tri_to_bidimensional(t_bunny_zposition pos_3d,
					     t_bunny_position flee_point);
void set_zpixel(t_bunny_zpixelarray *piz,
		t_bunny_zposition   pos,
		unsigned int        col);

#endif
