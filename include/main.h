#ifndef		___MAIN_H___
#define		___MAIN_H___
#include <lapin.h>
#include <assert.h>
#include "t_prog.h"
#include "macro.h"
#include "time.h"
#include "spawn_enemy.h"

t_game *setup_struct_game(void);

t_bunny_zpixelarray *new_zpixelarray(int  width,
				     int height,
				     int depth);
void clear_zpixelarray(t_bunny_zpixelarray *px,
		       unsigned int color);

t_bunny_response	key(t_bunny_event_state	state,
			    t_bunny_keysym	key,
			    void		*data);
t_bunny_response	mainloop(void		*p);

void spawn_horde (t_prog *prog);

#endif		//___MAIN_H___
