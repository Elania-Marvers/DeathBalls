#ifndef		___MACRO_H___
#define		___MACRO_H___
#define SETPOS(posx, posy)						\
	({t_bunny_position pos;pos.x = (posx);pos.y = (posy);pos;})

#define BI_TO_1D_POS(pos, width) ((pos.x) + (pos.y) * (width))

#define ABS(number) (((number) < 0) ? -(number) : (number))

#define NBENEMIES 28
#define WIDTH 800
#define HEIGHT 800
#define DEPTH 1200
#endif
