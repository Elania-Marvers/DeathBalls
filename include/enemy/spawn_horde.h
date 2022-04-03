#ifndef		__SPAWN_HORDE_H__
#define		__SPAWN_HORDE_H__
#include <lapin.h>
#include "t_prog.h"
#include "macro.h"
bool spawn_enemy_choose(t_bunny_pool *enemy, int pos);
void spawn_horde (t_prog *prog);


#endif		//__SPAWN_HORDE_H__
