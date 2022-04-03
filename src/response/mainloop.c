#include "mainloop.h"
#include <string.h>
#include <stdlib.h>


void			say(t_bunny_picture		*font,
			    t_bunny_buffer		*pic,
			    const t_bunny_position	*p,
			    const char			*str)
{
  t_bunny_position	pos;
  t_bunny_position	siz;
  int			i;

  siz.x = (5 + 1) * font->scale.x;
  siz.y = 7 * font->scale.y;
  font->clip_y_position = 0;
  font->clip_width = 5;
  font->clip_height = 7;
  pos.x = p->x;
  pos.y = p->y;
  for (i = 0; str[i]; ++i)
    {
      if (str[i] == ' ')
	pos.x += siz.x;
      else
	{
	  font->clip_x_position = str[i] * 5;
	  bunny_blit(pic, font, &pos);
	  pos.x += siz.x;
	}
    }
}

t_bunny_response	mainloop(void		*p)
{
  t_prog		*prog = (t_prog *) p;
  double increment_speed = BASE_SPEED + prog->game->score * 0.2;
  char *score_str;

  if (prog->game->on == true)
    {
      if (increment_speed > MAX_SPEED)
	increment_speed = MAX_SPEED;
      clear_zpixelarray(prog->zpx, BLACK);
      set_game_line(prog->zpx, prog->game);
      display_player(prog->zpx, prog->game);
      display_enemy(prog->zpx, prog->game, prog->game->enemies);
      move_enemy(prog->game->enemies, increment_speed);

      if (prog->e > 1000.0 / increment_speed)
	{
	  prog->e = 0.0;
	  spawn_horde(prog);
	}
      else
	prog->e += 1.0;
      if (check_enemy_collide(prog->game->enemies, prog->game->player_pos))
        prog->game->on = false;
          }

  t_bunny_position po;

  po.y = 10;
  bunny_blit(&prog->win->buffer, &prog->zpx->zpix->clipable, NULL);
  char scr[11], num[5];
  memcpy(scr, "SCORE:\0", 7);
  sprintf(num, "%d", prog->game->score);
  score_str = strcat(scr, num);
  po.x = WIDTH - 5 * (11  + 1 ) * prog->font->scale.x;
  say (prog->font, &prog->win->buffer, &po, score_str);

  if (prog->game->hight_score < prog->game->score)
    prog->game->hight_score = prog->game->score;


  po.y = 40;
  char hscr[16], hnum[5];
  memcpy(hscr, "HIGH SCORE:\0", 12);
  sprintf(hnum, "%d", prog->game->hight_score);
  score_str = strcat(hscr, hnum);
  po.x = WIDTH - 5 * (17  + 1 ) * prog->font->scale.x;
  say (prog->font, &prog->win->buffer, &po, score_str);

  if (prog->game->on == false)
    {
      po.x = 200;
      po.y = 200;
      say (prog->font, &prog->win->buffer, &po, "Press space to start !!!");

      po.x = WIDTH / 2 - 5 * (6) * prog->font->scale.x;
      po.y = 400;
      say (prog->font, &prog->win->buffer, &po, "DEATHBALLS");
    }

  bunny_display(prog->win);
  return (GO_ON);
}
