/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@stu018.cst.bunny.local>
** Ecole 89
**
** - set_line.c -
**
** *****************************************************************************
*/

#include "set_line.h"

#include <stdio.h>

static uint32_t bext_set_line_color_ratio(uint32_t *color,
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

static void bext_hor_longer_set_line(t_bunny_pixelarray	*px,
				     t_bunny_position	start_pos,
				     unsigned int	*color,
				     t_bunny_position len)
{
  int		i;
  double ratio;
  uint32_t merged_color;
  t_bunny_position	pixel_pos;

  i = 0;
  while (i <= len.x)
    {
      ratio = (double) i / len.x;
      pixel_pos = SETPOS(start_pos.x + i,
			 start_pos.y + ((double) len.y) * ratio);
      merged_color = bext_set_line_color_ratio(color, ratio);
      set_pixel(px, pixel_pos, merged_color);
      ++i;
    }
}

static void bext_ver_longer_set_line(t_bunny_pixelarray	*px,
				     t_bunny_position	start_pos,
				     unsigned int	*color,
				     t_bunny_position len)
{
  int		i;
  double ratio;
  uint32_t merged_color;
  t_bunny_position	pixel_pos;

  i = 0;
  while (i <= len.y)
    {
      ratio = (double) i / len.y;
      pixel_pos = SETPOS(start_pos.x + ((double) len.x) * ratio,
			 start_pos.y + i);
      merged_color = bext_set_line_color_ratio(color, ratio);
      set_pixel(px, pixel_pos, merged_color);
      ++i;
    }
}

void		set_line(t_bunny_pixelarray	*px,
			 t_bunny_position	*pos,
			 unsigned int	*color)
{
  bool orientation;
  t_bunny_position	len;

  len.x = pos[1].x - pos[0].x;
  len.y = pos[1].y - pos[0].y;
  orientation = (ABS(len.y) <= ABS(len.x));
  if (orientation)
    bext_hor_longer_set_line(px, pos[0], color, len);
  bext_ver_longer_set_line(px, pos[0], color, len);
}
