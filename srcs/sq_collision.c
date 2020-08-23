#include "../inc/minirt.h"

t_3dvec *sq_collision(t_sq *sq, t_3dvec *ray)
{
  float point[3];
  float center_point_vector[3];
  float width_vector[4];
  float height_vector[4];
  float transformation_matrix[4][4];

  if (!(find_point_in_a_plane(sq->vector, ray, dot(sq->vector, sq->coord), point)))
    return (NULL);
  width_vector[0] = 1;
  width_vector[1] = 0;
  width_vector[2] = 0;
  width_vector [3] = 1;
  height_vector[0] = 0;
  height_vector[1] = 1;
  height_vector[2] = 0;
  height_vector[3] = 1;
  //obtenemos la matriz de transformacion
  //width_matrix * transformation_matrix
  //height_matrix * transformation_matrix

}
