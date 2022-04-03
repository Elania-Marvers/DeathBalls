#include	"player_move.h"

#include	<stdio.h>

void player_move(t_game *game,
				 int move_offset)
{
	move_offset = move_offset % NUM_OF_LINE;
	if (game->player_pos - move_offset < 0)
		
    game->player_pos = (game->player_pos + move_offset) % NUM_OF_LINE;
}