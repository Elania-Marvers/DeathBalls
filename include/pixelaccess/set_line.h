#ifndef __SET_LINE_H__
#define __SET_LINE_H__

#include	<lapin.h>
#include	"macro.h"
#include	"set_pixel.h"

void		set_line(t_bunny_pixelarray	*px,
			     	 t_bunny_position	*pos,
			     	 unsigned int	*color);

#endif