#ifndef ___MAINLOOP___
#define ___MAINLOOP___
#include		<lapin.h>
#include		<stdio.h>
#include		"t_prog.h"
#include		"set_zline.h"
#include		"clear_zpixelarray.h"
#include		"set_game_line.h"
#include		"display_player.h"
#include		"display_enemy.h"
#include 		"move_enemy.h"
#include 		"spawn_enemy.h"
#include		"check_enemy_collide.h"
#include		"spawn_pipe.h"

t_bunny_response	mainloop(void		*p);
void set_zpixel(t_bunny_zpixelarray *piz,
		t_bunny_zposition   pos,
		unsigned int        col);

void set_zsphere(t_bunny_zpixelarray		*pix,
		 t_bunny_zposition		pos,
		 double				r,
		 unsigned int			color);

void spawn_horde (t_prog *prog);

#endif
