#ifndef __TRI_TO_BIDIMENSIONAL_H__
#define __TRI_TO_BIDIMENSIONAL_H__

#define ISOMETRY_COEF 1000

#define Z_DEPTH_COEF(z) ({double z_calc; z_calc = -(z) - ISOMETRY_COEF; \
(z_calc >= 0) ? (ISOMETRY_COEF * (z_calc + 1)) : (1 / ((-z_calc) / ISOMETRY_COEF));})

#include	<lapin.h>
#include	"macro.h"

t_bunny_position	tri_to_bidimensional(t_bunny_zposition pos_3d,
					     t_bunny_position flee_point);

#endif
