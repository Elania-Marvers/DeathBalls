#ifndef ___COLORMIX___
#define ___COLORMIX___
#include <lapin.h>

unsigned char color_ratiod	(unsigned char		from, 
				 unsigned char		to,
				 double			ratio);

unsigned int mix_color		(unsigned int		ca,
				 unsigned int		cb,
				 double			percent);

#endif
