#include "display_enemy.h"

bool display_enemy(t_bunny_zpixelarray *piz,
		   t_game *game,
		   t_bunny_pool *enemy)
{
  int i;
  t_enemy *enemy_data;
  t_bunny_zposition posz;
  unsigned int color;
  bool is = false;
  i = 0;
  color = COLOR(255, 255, 0, 255);
  while (i < NBENEMIES)
    {
      enemy_data = (t_enemy*) enemy[i].data;
      if (enemy_data->show)
	{
	  posz.x = game->line_pos[enemy_data->enemy_pos].x;
	  posz.y = game->line_pos[enemy_data->enemy_pos].y;
	  posz.z = enemy_data->zpos;
	  if (posz.z < -400)
	    set_zsphere(piz, posz, ENTITIES_RADIUS, RED);
	  else
	    set_zsphere(piz, posz, ENTITIES_RADIUS, color);
	  if (posz.z < -450)
	    {
	      is = true;
	      enemy_data->show = false;
	    }
	}
      i++;
    }

  if (is)
    game->score++;
  return (false);
}
