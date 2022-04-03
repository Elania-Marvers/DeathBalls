#ifndef ___T_PROG___
#define ___T_PROG___
#include "t_bunny_zpixelarray.h"
#include "game.h"

typedef struct		s_prog
{
  t_bunny_window	*win;
  t_bunny_zpixelarray	*zpx;
  t_game		*game;
  double e;
}			t_prog;
#endif
