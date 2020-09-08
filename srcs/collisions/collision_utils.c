/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:40:39 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:22:27 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void point_found(t_vector p_coord, t_vector n_vec, t_color p_color, t_ray *ray)
{
	if (!ray->point_found || (v_mod(p_coord) - v_mod(ray->point)) < 0)
	{
		ray->point_found = true;
		ray->color = p_color;
		ray->point = p_coord;
		ray->normal = n_vec;
	}
}

bool point_in_plane(t_vector normal, t_vector plane_point, t_ray *ray, t_vector *point)
{
	float t;
	t_vector points_vector;
	float eq_denom;

	if ((eq_denom = v_dot(normal, ray->dir)) < 1e-6)
		return (false);
	points_vector = v_normalize(v_sub(plane_point, ray->origin));
	if ((t = v_dot(normal, points_vector) / eq_denom) < 0)
		return (false);
	*point = v_add(ray->origin, v_scalar(ray->dir, t));
	return (true);
}
