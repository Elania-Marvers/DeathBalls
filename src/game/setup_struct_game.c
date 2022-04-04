#include	"setup_struct_game.h"

void swap_int (int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b= tmp;
}

t_game *setup_struct_game(void)
{
  t_enemy *enemy;
  t_game *game = malloc(sizeof(*game));

  game->pposx = rand() % (NUM_OF_LINE / 2);
  game->pposy = rand() % 2;
  double decalage = (M_PI * 2) / NUM_OF_LINE;
  double angle;
  for (int i = 0; i < NUM_OF_LINE; ++i)
    {
      angle = (M_PI / NUM_OF_LINE) + decalage * i;
      game->line_pos[i].x = (WIDTH / 2) + (WIDTH / 2.5) * cos(angle);
      game->line_pos[i].y = (HEIGHT / 2) - (HEIGHT / 2.5) * sin(angle);
    }

  for (int i = 0; i < NUM_OF_LINE / 4; ++i)
    {
      swap_int (&(game->line_pos[NUM_OF_LINE / 2 + i].x), &(game->line_pos[NUM_OF_LINE - i - 1].x));
      swap_int (&(game->line_pos[NUM_OF_LINE / 2 + i].y), &(game->line_pos[NUM_OF_LINE - i - 1].y));
    }
  game->player_pos = game->pposx + game->pposy * (NUM_OF_LINE / 2);

  game->enemies = _bunny_new_pool(NBENEMIES, sizeof(t_enemy));
  for (int i = 0; i < NBENEMIES; ++i)
    {
      enemy = (t_enemy*) game->enemies[i].data;
      enemy->show = false;
      enemy->zpos = DEPTH;
    }

  return game;
}
