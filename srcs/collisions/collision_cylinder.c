/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:44:01 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 18:29:10 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray *cy_loop(t_cy *cy, t_ray *ray)
{
	bool found_point;

	found_point = false;
	while (cy)
	{
		if (collision_cylinder(cy, ray))
			found_point = true;
		cy = cy->next;
	}
	return (found_point ? ray : NULL);
}

t_vector cy_normal(t_vector point, t_cy *cy)
{
	t_vector normal;
	t_vector op;
	t_vector axis_point;

	op = v_sub(point, cy->coord);
	axis_point = v_add(cy->coord, v_scalar(cy->orientation, v_dot(cy->orientation, op)));
	normal = v_normalize(v_sub(point, axis_point));
	return (normal);
}

t_ray *collision_cylinder(t_cy *cy, t_ray *ray)
{
	t_vector point;
	t_vector normal;
	float t;
	float sqrt_ec;
	t_cyaux aux;

	ft_bzero(&aux, sizeof(t_cyaux));
	aux.oc = v_sub(ray->origin, cy->coord);
	aux.dot_adir = v_dot(cy->orientation, ray->dir);
	aux.dot_aoc = v_dot(cy->orientation, aux.oc);
	aux.a_adir = v_scalar(cy->orientation, aux.dot_adir);
	aux.a_aoc = v_scalar(cy->orientation, aux.dot_aoc);
	aux.v1 = v_sub(ray->dir, aux.a_adir);
	aux.v2 = v_sub(aux.oc, aux.a_aoc);
	aux.a = v_dot(aux.v1, aux.v1);
	aux.b = 2 * v_dot(aux.v1, aux.v2);
	aux.c = v_dot(aux.v2, aux.v2) - cy->d;
	sqrt_ec = (aux.b * aux.b)- (4 * aux.a * aux.c);
	if (sqrt_ec < 0)
		return (NULL);
	t = (- aux.b - sqrt(sqrt_ec)) / (2 * aux.a);
	point = v_add(ray->origin, v_scalar(ray->dir, t));
	normal = cy_normal(point, cy);
	point_found(point, normal, cy->color, ray);
	return (ray);
}
