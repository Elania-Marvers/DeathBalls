#ifndef __SET_ZSPHERE__
#define __SET_ZSPHERE__
#include	<lapin.h>
#include	"t_bunny_zpixelarray.h"

void set_zpixel(t_bunny_zpixelarray *piz,
		t_bunny_zposition   pos,
		unsigned int        col);

void set_zsphere(t_bunny_zpixelarray		*pix,
		 t_bunny_zposition		pos,
		 double				r,
		 unsigned int			color);


#endif
