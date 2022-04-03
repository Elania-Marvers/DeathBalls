#include	"display_player.h"

void display_player(t_bunny_zpixelarray *piz,
					t_game *game)
{
	t_bunny_zposition posz;
	game->player_pos = game->pposx + game->pposy * (NUM_OF_LINE / 2);
	posz.x = game->line_pos[game->player_pos].x;
	posz.y = game->line_pos[game->player_pos].y;
	posz.z = PLAYER_POSZ;
	set_zsphere(piz, posz, ENTITIES_RADIUS, GREEN);
}
