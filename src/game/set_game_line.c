#include	"set_game_line.h"

void set_game_line(t_bunny_zpixelarray *piz,
				   t_game *game)
{
	t_bunny_zposition posz[2];
	unsigned int colors[2] = {RED, RED};

	posz[0].z = 0;
	posz[1].z = DEPTH;
	for(int i = 0; i < NUM_OF_LINE; i++)
	{
		posz[0].x = game->line_pos[i].x;
		posz[1].x = game->line_pos[i].x;
		posz[0].y = game->line_pos[i].y;
		posz[1].y = game->line_pos[i].y;
		set_zline(piz, posz, colors);
	}
}