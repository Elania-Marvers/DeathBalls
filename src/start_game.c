#include "start_game.h"


static void kill_enemies(t_prog *prog)
{
  t_enemy *en;
  for (int i = 0; i < NBENEMIES; ++i)
    {
      en = (t_enemy *) prog->game->enemies[i].data;
      en->show = false;
    }
}

void start_game(t_prog *prog)
{
  if (prog->game->on == false)
    {
      kill_enemies(prog);
      prog->game->on = true;
      prog->e = 0.0;
      prog->game->score = 0;
      spawn_horde(prog);
    }
}
