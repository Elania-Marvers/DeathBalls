#include "set_zpixel.h"


// t_bunny_position	tri_two(t_bunny_zpixelarray *pz,
// 				t_bunny_zposition pos_3d, // coordonnées pos
// 				t_bunny_position offset) // centre écrans
// {
//   t_bunny_position res;
//   double coefz = 1.0 - (double) pos_3d.z / pz->depth;
//   res.x = offset.x + (double) ((double) pos_3d.x - (double) offset.x) * coefz;
//   res.y = offset.y + (double) ((double) pos_3d.y - (double) offset.y) * coefz;
//   return res;
// }


void set_zpixel (t_bunny_zpixelarray *piz,
		 t_bunny_zposition   pos_3d,
		 unsigned int        col)
{
  t_bunny_position pos_2d;
  t_bunny_color color;

  pos_2d = tri_to_bidimensional(pos_3d, SETPOS(piz->zpix->clipable.buffer.width / 2,
				       piz->zpix->clipable.buffer.height / 2));
  if (pos_2d.x >= 0 && pos_2d.x < piz->zpix->clipable.buffer.width &&
    	pos_2d.y >= 0 && pos_2d.y < piz->zpix->clipable.buffer.height &&
      (double) pos_3d.z < GET_PIXEL_ZPOS(piz, pos_2d))
    {
      piz->zcase[BI_TO_1D_POS(pos_2d, piz->zpix->clipable.buffer.width)] = pos_3d.z;
      if (pos_3d.z >= 0)
      {
        color.full = col;
        color.argb[3] *= (1.0 - ((double) pos_3d.z / piz->depth));
        set_pixel (piz->zpix, pos_2d, color.full);
      }
      else
        set_pixel (piz->zpix, pos_2d, col);
    }
}
