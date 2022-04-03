#include "spawn_enemy.h"

bool spawn_enemy(t_bunny_pool *enemy)
{
	int i;
	t_enemy *enemy_data;

	i = 0;
	while (i < NBENEMIES)
	{
		enemy_data = (t_enemy*) enemy[i].data;
		if (!enemy_data->show)
		{
			enemy_data->show = true;
			enemy_data->type = 0;
			enemy_data->zpos = DEPTH;
			enemy_data->enemy_pos = rand() % NUM_OF_LINE;
			return (true);
		}
		i++;
	}
	return (false);
}

bool spawn_enemy_choose(t_bunny_pool *enemy, int pos)
{
	int i;
	t_enemy *enemy_data;

	i = 0;
	while (i < NBENEMIES)
	{
		enemy_data = (t_enemy*) enemy[i].data;
		if (!enemy_data->show)
		{
			enemy_data->show = true;
			enemy_data->type = 0;
			enemy_data->zpos = DEPTH;
			enemy_data->enemy_pos = pos;
			return (true);
		}
		i++;
	}
	return (false);
}
