#include "move_enemy.h"

void move_enemy(t_bunny_pool *enemy,
		double step)
{
  int i;
  t_enemy *enemy_data;

  i = 0;
  while (i < NBENEMIES)
    {
      enemy_data = (t_enemy*) enemy[i].data;
      enemy_data->zpos -= (enemy_data->show) * step;
      i++;
    }
}
