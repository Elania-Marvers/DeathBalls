#ifndef		___MACRO_H___
#define		___MACRO_H___
#define SETPOS(posx, posy)						\
	({t_bunny_position pos;pos.x = (posx);pos.y = (posy);pos;})

#define BI_TO_1D_POS(pos, width) ((pos.x) + (pos.y) * (width))

#define ABS(number) (((number) < 0) ? -(number) : (number))

#define NUM_OF_LINE 10
#define NBENEMIES 80
#define WIDTH 800
#define HEIGHT 800
#define DEPTH 1200
#define ENTITIES_RADIUS 50.0
#define PLAYER_POSZ 0
#define BASE_SPEED 5
#define MAX_SPEED 12
#define GAME_ACCELERATION 0.2
#endif
