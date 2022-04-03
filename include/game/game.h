#ifndef __GAME_H__
#define __GAME_H__

#include "macro.h"
#include <lapin.h>

typedef struct	s_enemy
{
	bool show;
	int enemy_pos;
	int zpos;
	int type;
}				t_enemy;

typedef struct	s_game
{
  bool				on;
  int				score;
  int				hight_score;
  int				player_pos;
  int				pposx;
  int				pposy;
  t_bunny_position		line_pos[NUM_OF_LINE];
  t_bunny_pool			*enemies;
}				t_game;

#endif
