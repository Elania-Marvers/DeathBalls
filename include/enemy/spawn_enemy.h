#ifndef		__SPAWN_ENEMY_H__
#define		__SPAWN_ENEMY_H__
#include <lapin.h>
#include "t_prog.h"
#include "macro.h"

bool spawn_enemy(t_bunny_pool *enemy);

bool spawn_enemy_choose(t_bunny_pool *enemy,
						int pos);

bool spawn_enemy_choose_depth(t_bunny_pool *enemy,
							  int pos,
							  int depth);

#endif		//__SPAWN_ENEMY_H__
