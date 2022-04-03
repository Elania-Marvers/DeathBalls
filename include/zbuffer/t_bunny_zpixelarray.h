#ifndef ___T_BUNNY_ZPIXELARRAY___
#define ___T_BUNNY_ZPIXELARRAY___
typedef struct s_bunny_zpixelarray
{
  t_bunny_pixelarray  *zpix;
  double              *zcase;
  double              depth;
}         t_bunny_zpixelarray;

#endif
