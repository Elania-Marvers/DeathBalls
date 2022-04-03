#include "new_zpixelarray.h"

t_bunny_zpixelarray *new_zpixelarray(int  width,
				     int height,
				     int depth)
{

  t_bunny_zpixelarray *ZPIX;
  ZPIX = malloc(sizeof(t_bunny_zpixelarray));
  ZPIX->zpix = bunny_new_pixelarray(width, height);
  ZPIX->zcase = malloc(sizeof(double) * (width * height));
  ZPIX->depth = depth;
  unsigned int *caze = ZPIX->zpix->pixels;
  for (int i = 0; i < width * height; ++i)
    {
      caze[i] = TRANSPARENT;
      ZPIX->zcase[i] = depth;
    }
  return ZPIX;
}
