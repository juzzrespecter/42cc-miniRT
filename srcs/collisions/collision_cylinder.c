/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 18:44:01 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/17 20:00:12 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector normal_cylinder(t_cy *cy, t_vector point)
{
	t_vector normal;
	t_vector op;
	t_vector axis_point;

	op = v_sub(point, cy->coord);
	axis_point = v_add(cy->coord, v_scalar(cy->orientation, v_dot(cy->orientation, op)));
	normal = v_normalize(v_sub(point, axis_point));
	return (normal);
}

//dot_1(t1) > 0 && dot_2(t1) < 0 punto en el cuerpo
//dot_1(t1) < 0 && dot_2(t1) < 0 && dot_1(t2) > 0 punto interior visto por la base
//dot_1(t1) > 0 && dot_2(t1) > 0 && dot_2(t2) < 0 punto interior visto por el techo
//dot_1(t1) < 0 || dot_2(t1) > 0 no hay colision

float cylinder_height(t_cy *cy, float t1, float t2, t_ray *ray)
{
	t_vector p2;
	t_vector point_1;
	t_vector point_2;
	t_vector axis;
	float dot_11, dot_12;
	float dot_21, dot_22;

	p2 = v_add(cy->coord, v_scalar(cy->orientation, cy->h));
	axis = v_sub(p2, cy->coord);
	point_1 = v_add(ray->origin, v_scalar(ray->dir, t1));
	dot_11 = v_dot(v_sub(point_1, cy->coord), axis);
	dot_12 = v_dot(v_sub(point_1, p2), axis);
	if (dot_11 > 0 && dot_12 < 0)
		return (t1);
	point_2 = v_add(ray->origin, v_scalar(ray->dir, t2));
	dot_21 = v_dot(v_sub(point_2, cy->coord), axis);
	dot_22 = v_dot(v_sub(point_2, p2), axis);
	if ((dot_11 < 0 && dot_21 > 0 && dot_12 < 0) || (dot_21 > 0 && dot_22 < 0 && dot_11 < 0))
		return (t2);
	return (-1);
}

float collision_cylinder(t_cy *cy, t_ray *ray)
{
	float t1;
	float t2;
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
		return (-1);
	t1 = ((-1 * aux.b) - sqrt(sqrt_ec)) / (2 * aux.a);
	t2 = ((-1 * aux.b) + sqrt(sqrt_ec)) / (2 * aux.a);
	return (cylinder_height(cy, t1, t2, ray));
}
