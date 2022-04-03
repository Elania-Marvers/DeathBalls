#include "tri_to_bidimensional.h"

t_bunny_position	tri_to_bidimensional(t_bunny_zposition pos_3d, // coordonnées pos
					     t_bunny_position flee_point) // centre écrans
{
  double			z_calc;
  t_bunny_accurate_position	acc_pos_2d;
  t_bunny_position pos_2d;

  z_calc = Z_DEPTH_COEF(pos_3d.z); // Calculate z coefficient
  acc_pos_2d.x = z_calc * (pos_3d.x - flee_point.x); // Apply x perspective
  acc_pos_2d.y = z_calc * (pos_3d.y - flee_point.y); // Apply y perspective
  acc_pos_2d.x += ((double) flee_point.x); // Move x coordinate to center
  acc_pos_2d.y += ((double) flee_point.y); // Move y coordinate to center
  pos_2d.x = acc_pos_2d.x;
  pos_2d.y = acc_pos_2d.y;
  return (pos_2d);
}
