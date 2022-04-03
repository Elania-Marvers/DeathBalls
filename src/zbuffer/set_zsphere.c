#include "set_zsphere.h"

void set_zsphere(t_bunny_zpixelarray		*pix,
		 t_bunny_zposition		pos,
		 double				r,
		 unsigned int			color)
{
  t_bunny_zposition paint;
  double theta, phi;
  double cir = 50;
  //double cir = (2 * M_PI * r);
  for (theta = -M_PI / 2; theta < M_PI / 2; theta += (2 * M_PI) / cir)
    {
      for (phi = -M_PI; phi < M_PI; phi += (2 * M_PI) / cir) 
	{
	  paint.x = pos.x + r * (cos(theta) * cos(phi));
	  paint.y = pos.y + r * (cos(theta) * sin(phi));
	  paint.z = pos.z + r * sin(theta);
	  set_zpixel(pix, paint, color);
	}
    }
}


