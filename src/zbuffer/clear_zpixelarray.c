#include "clear_zpixelarray.h"


void clear_zpixelarray(t_bunny_zpixelarray *px, 
		       unsigned int color)
{
  unsigned int *caze = px->zpix->pixels;
  for (int i = 0; i < px->zpix->clipable.buffer.width * px->zpix->clipable.buffer.height; ++i)
    caze[i] = color;  
  for (int i = 0; i < px->zpix->clipable.buffer.width * px->zpix->clipable.buffer.height; ++i)
    px->zcase[i] = px->depth;
}
