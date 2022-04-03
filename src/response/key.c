#include "key.h"

t_bunny_response	key(t_bunny_event_state	state,
			    t_bunny_keysym	key,
			    void		*data)
{
  (void)state;
  t_prog *prog = data;
  const bool *keys;
  keys = bunny_get_keyboard();
  if (keys[BKS_ESCAPE])
    return (EXIT_ON_SUCCESS);
  if (keys[BKS_LEFT])
    {
      if (prog->game->pposx < NUM_OF_LINE / 2 - 1)
	prog->game->pposx++;
    }
  if (keys[BKS_RIGHT])
    {
      if (prog->game->pposx > 0)
	prog->game->pposx--;
    }


  if (keys[BKS_DOWN])
    {
      if (prog->game->pposy < 1)
	prog->game->pposy++;
    }
  if (keys[BKS_UP])
    {
      if (prog->game->pposy > 0)
	prog->game->pposy--;
    }

  if (keys[BKS_SPACE])
    start_game(prog);

  return (GO_ON);
}
