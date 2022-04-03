#include "set_pixel.h"

/*
** *****************************************************************************
** lenny.vigeon <lenny.vigeon@stu018.cst.bunny.local>
** Ecole 89
**
** - set_pixel.c -
**
** *****************************************************************************
*/

#include "set_pixel.h"

static uint32_t bext_set_pixel_apply_transparency(uint32_t base_color,
							uint32_t src_color)
{
	t_bunny_color colors[2];
	int calc;
	uint8_t i;
	double alpha;
	double reverse_alpha;

	colors[0].full = base_color;
	colors[1].full = src_color;
	alpha = (double) colors[1].argb[3] / 255;
	reverse_alpha = 1 - alpha;
	i = 0;
	while (i < 3)
	{
		calc = colors[0].argb[i] * reverse_alpha + colors[1].argb[i] * alpha;
		colors[0].argb[i] = (calc > 255) ? 255 : calc;
		i++;
	}
	return (colors[0].full);
}

bool set_pixel(t_bunny_pixelarray *px,
                	t_bunny_position coords,
                	uint32_t color)
{
	int* pix;
	int pos;
	t_bunny_color curr_color;

	if (coords.x >= 0 && coords.x < px->clipable.buffer.width &&
    	coords.y >= 0 && coords.y < px->clipable.buffer.height)
    {
		pix = px->pixels;
		pos = px->clipable.buffer.width * coords.y + coords.x;
		curr_color.full = color;
		if (curr_color.argb[3] == 0)
			return (true);
		else if(curr_color.argb[3] != 255)
			color = bext_set_pixel_apply_transparency(pix[pos], color);
    	pix[pos] = color;
    	return (true);
    }
	return (false);
}
