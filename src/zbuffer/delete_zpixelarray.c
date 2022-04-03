#include "delete_zpixelarray.h"

void delete_zpixelarray(t_bunny_zpixelarray *zpix)
{
  bunny_delete_clipable(zpix->zpix);
  free(zpix->zcase);
  free(zpix);
} 
