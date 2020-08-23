/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:40:39 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 19:26:51 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

void found_point(float *p_coord, float *n_vec, unsigned char *p_color, t_3dvec *ray)
{
  int count;

  count = 0;
  if (!ray->point_found || (length(p_coord) - length(ray->point_coord)) < 0)
    {
      ray->point_found = true;
	while (count < 3)
		{
			ray->point_color[count] = p_color[count];
			ray->point_coord[count] = p_coord[count];
			ray->normal_vector[count] = n_vec[count];
			count++;
		}
    }
}

//puede que sobre

void get_point(float *point_coord, float t, t_3dvec *ray)
{
	int i;

	i = 0;
	while (i < 3)
		{
			point_coord[i] = ray->orig[i] + t * ray->dir[i];
			i++;
		}
}

bool find_point_in_a_plane(float *normal, t_3dvec *ray, float d, float *point)
{
  float t;
  float ray_normal_dot_prod;

  if ((ray_normal_dot_prod = dot(normal, ray->dir)) < 1e-6)
    return (false);
  if ((t = - (dot(normal, ray->orig) + d) / ray_normal_dot_prod) < 0)
    return (false);
  point[0] = ray->orig[0] + t * ray->dir[0];
  point[1] = ray->orig[1] + t * ray->dir[1];
  point[2] = ray->orig[2] + t * ray->dir[2];
  return (true);
}