#include "main.h"

int main (void)
{
  t_prog		prog;
  clock_t clock_var;

  clock_var = clock();
  srand(clock_var);

  prog.game = NULL;
  assert ((prog.win = bunny_start(WIDTH, HEIGHT, false, "DEATHBALLS"))		!= NULL);
  assert((prog.zpx = new_zpixelarray(WIDTH, HEIGHT, DEPTH))			!= NULL);
  assert((prog.game = setup_struct_game())					!= NULL);
  assert((prog.font = bunny_load_picture("font.png"))				!= NULL);
  prog.font->scale.x = 3;
  prog.font->scale.y = 3;
  prog.game->on = false;

  prog.e = 0.0;
  prog.game->score = 0;
  prog.game->hight_score = 0;  



  
  clear_zpixelarray(prog.zpx, BLACK);


  set_game_line(prog.zpx, prog.game);
  display_player(prog.zpx, prog.game);

      
  bunny_set_key_response(key);
  bunny_set_loop_main_function(mainloop);
  assert (bunny_loop(prog.win, 60, &prog)					!= EXIT_ON_ERROR);
  bunny_delete_pool(prog.game->enemies);
  return (EXIT_SUCCESS);
}
