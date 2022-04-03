#include "get_pixel.h"

unsigned int get_pixel(t_bunny_pixelarray	*_px,
		       t_bunny_position		pos)
{
  unsigned int *caze = (unsigned int *) _px->pixels;
  return caze[pos.x + pos.y * _px->clipable.buffer.width];
}
