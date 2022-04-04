#include "spawn_pipe.h"
#include <stdio.h>

int r_adjusting(int r)
{
	int half_num_of_line;

	half_num_of_line = (NUM_OF_LINE / 2);
	if (r >= half_num_of_line)
	{
		r -= half_num_of_line;
		return (half_num_of_line + ((half_num_of_line - 1) - r));
	}
	return (r);
}

void spawn_pipe (t_game *game,
				 t_bunny_pool *enemy)
{
	t_enemy *enemy_data;

	int r = rand() % NUM_OF_LINE;
	int adjusted_r;
	int depth = DEPTH;
	int k;
	int j;
	for (int i = 0; i < 4; ++i)
	{
		k = 0;
		adjusted_r = r_adjusting(r);
		while (k < NUM_OF_LINE)
		{
			if (k != adjusted_r)
      			spawn_enemy_choose_depth(enemy, k, depth);
			k++;
		}
		depth += ENTITIES_RADIUS * 12;
		if (rand() % 2)
	  		r++;
		else
		{
			r--;
			if (r < 0)
				r = NUM_OF_LINE - 1;
		}
		r = r % NUM_OF_LINE;
	}
}