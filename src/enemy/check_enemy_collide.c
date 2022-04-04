#include "check_enemy_collide.h"

bool check_enemy_collide(t_bunny_pool *enemy,
						 int player_pos)
{
	int i;
	t_enemy *enemy_data;

	i = 0;
	while (i < NBENEMIES)
	{
		enemy_data = (t_enemy*) enemy[i].data;
		if (enemy_data->enemy_pos == player_pos &&
			enemy_data->show == true &&
			(enemy_data->zpos + ENTITIES_RADIUS) > (PLAYER_POSZ - ENTITIES_RADIUS) &&
			(enemy_data->zpos - ENTITIES_RADIUS) < (PLAYER_POSZ + ENTITIES_RADIUS))
			return (true);
		i++;
	}
	return (false);
}