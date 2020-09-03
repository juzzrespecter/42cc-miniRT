/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:40:39 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/03 20:27:14 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void point_found(float *p_coord, float *n_vec, unsigned char *p_color, t_3dvec *ray)
{
	int count;

	count = 0;
	if (!ray->point_found || (length(p_coord) - length(ray->point)) < 0)
	{
		ray->point_found = true;
		while (count < 3)
		{
			 ray->color[count] = p_color[count];
			 ray->point[count] = p_coord[count];
			 ray->normal[count] = n_vec[count];
			 count++;
		 }
	}
}

bool point_in_plane(float *normal, float *plane_point, t_3dvec *ray, float *point)
{
	float t;
	float points_vector[3];
	float eq_denom;

	if ((eq_denom = dot(normal, ray->dir)) < 1e-6)
		return (false);
	points_vector[0] = plane_point[0] - ray->orig[0];
	points_vector[1] = plane_point[1] - ray->orig[1];
	points_vector[2] = plane_point[2] - ray->orig[2];
	if ((t = dot(normal, points_vector) / eq_denom) < 0)
		return (false);
	point[0] = ray->orig[0] + t * ray->dir[0];
	point[1] = ray->orig[1] + t * ray->dir[1];
	point[2] = ray->orig[2] + t * ray->dir[2];
	return (true);
}
