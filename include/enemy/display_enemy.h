#ifndef		__DISPLAY_ENEMY_H__
#define		__DISPLAY_ENEMY_H__
#include <lapin.h>
#include "t_prog.h"
#include "macro.h"
#include "set_zsphere.h"

bool display_enemy(t_bunny_zpixelarray *piz,
				   t_game *game,
				   t_bunny_pool *enemy);

#endif		//__DISPLAY_ENEMY_H__