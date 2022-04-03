#ifndef __COLOR_MACRO_H__
#define __COLOR_MACRO_H__

#define COLOR_RATIO(value, min, max) \
	(((double) (value) - (double) (min)) / ((double) (max) - (double) (min)))

#endif