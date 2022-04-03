#include "mix_color.h"

unsigned int mix_color (unsigned int		ca,
			unsigned int		cb,
			double			percent)
{
  t_bunny_color a, b, c;
  a.full = ca;
  b.full = cb;
  c.argb[ALPHA_CMP] = 255;
  c.argb[RED_CMP] = color_ratiod (a.argb[RED_CMP], b.argb[RED_CMP], percent);
  c.argb[GREEN_CMP] = color_ratiod (a.argb[GREEN_CMP], b.argb[GREEN_CMP], percent);
  c.argb[BLUE_CMP] = color_ratiod (a.argb[BLUE_CMP], b.argb[BLUE_CMP], percent);
  return c.full;
}
