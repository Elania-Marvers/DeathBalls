#ifndef __CHECK_ENEMY_COLLIDE_H__
#define __CHECK_ENEMY_COLLIDE_H__

#include "game.h"
#include "macro.h"
#include <lapin.h>

bool check_enemy_collide(t_bunny_pool *enemy,
						 int player_pos);

#endif