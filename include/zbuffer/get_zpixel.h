#ifndef __GET_ZPIXEL_H__
#define __GET_ZPIXEL_H__

#include <lapin.h>
#include	"t_bunny_zpixelarray.h"

unsigned int mix_color		(unsigned int		ca,
				 unsigned int		cb,
				 double			percent);


double get_zpos_pixel(t_bunny_zpixelarray	*zpix,
		      t_bunny_position		pos);

#endif
