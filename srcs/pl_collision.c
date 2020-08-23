#include "../inc/minirt.h"

t_3dvec *pl_collision(t_pl *pl, t_3dvec *ray)
{
  float point[3];
  float d;

  d = dot(pl->vector, pl->coord);
  if (!(find_point_in_a_plane(pl->vector, ray, d, point)))
    return (NULL);
  found_point(point_coord, pl->vector, pl->color, ray);
  return (ray);
}
