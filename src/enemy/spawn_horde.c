#include "spawn_horde.h"

void spawn_horde (t_prog *prog)
{
  int r = rand() % NUM_OF_LINE;  
  for (int i = 0; i < NUM_OF_LINE; ++i)
    if (i != r)
      spawn_enemy_choose(prog->game->enemies, i);
}
