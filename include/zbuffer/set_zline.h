#ifndef __SET_ZLINE__
#define __SET_ZLINE__

#include	<lapin.h>
#include	"macro.h"
#include	"tri_to_bidimensional.h"
#include	"t_bunny_zpixelarray.h"


void set_zpixel(t_bunny_zpixelarray *piz,
		t_bunny_zposition   pos,
		unsigned int        col);
void		set_zline(t_bunny_zpixelarray *piz,
			     	 t_bunny_zposition	*pos,
			     	 unsigned int	*color);

#endif
