#ifndef __ZBUFFER_MACRO_H__
#define __ZBUFFER_MACRO_H__

#include "macro.h"

#define GET_PIXEL_ZPOS(z_px, pos_2d) \
(z_px->zcase[BI_TO_1D_POS(pos_2d, z_px->zpix->clipable.buffer.width)])

#endif
