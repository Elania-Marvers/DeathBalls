/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@stu018.cst.bunny.local>
** Ecole 89
**
** - set_line.c -
**
** *****************************************************************************
*/

#include "set_zline.h"

#include <stdio.h>

static uint32_t bext_set_zline_color_ratio(uint32_t *color,
                                   double ratio)
{
  t_bunny_color colors[2];
  t_bunny_color merged_color;
  double invert_ratio;

  colors[0].full = color[0];
  colors[1].full = color[1];
  invert_ratio = (1 - ratio);
  merged_color.argb[0] = (colors[0].argb[0] * invert_ratio) +
                         (colors[1].argb[0] * ratio);
  merged_color.argb[1] = (colors[0].argb[1] * invert_ratio) +
                         (colors[1].argb[1] * ratio);
  merged_color.argb[2] = (colors[0].argb[2] * invert_ratio) +
                         (colors[1].argb[2] * ratio);
  merged_color.argb[3] = (colors[0].argb[3] * invert_ratio) +
                         (colors[1].argb[3] * ratio);
  return (merged_color.full);
}


void setup_line_data(t_bunny_zposition	*pos,
                     t_bunny_zposition *len,
                     double *step)
{
  int longer_len;

  len->x = ABS(pos[0].x - pos[1].x);
  len->y = ABS(pos[0].y - pos[1].y);
  len->z = ABS(pos[0].z - pos[1].z);

  longer_len = (len->x > len->y) ? len->x : len->y;
  longer_len = (longer_len > len->z) ? longer_len : len->z;
  *step = 1 / ((double) longer_len);
}

void		set_zline(t_bunny_zpixelarray *piz,
			     	 t_bunny_zposition	*pos,
			     	 unsigned int	*color)
{
  double i;
  double step;
  t_bunny_zposition len;
  t_bunny_zposition curr_pos;

  setup_line_data(pos, &len, &step);

  i = 0;
  while (i <= 1.0)
  {
    curr_pos.x = pos[0].x + (len.x * i);
    curr_pos.y = pos[0].y + (len.y * i);
    curr_pos.z = pos[0].z + (len.z * i);
    set_zpixel(piz, curr_pos, bext_set_zline_color_ratio(color, i));
    i += step;
  }

}
