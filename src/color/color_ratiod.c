#include "color_ratiod.h"

unsigned char color_ratiod(unsigned char	from, 
			   unsigned char	to,
			   double		ratio)
{
  unsigned char result;
  result = (int) ((double) from * (1.0 - ratio) + (double) to * ratio);
  return result;
}
