/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:22:22 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 18:09:11 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	collision_true(t_tr *tr, t_vector point, t_vector normal)
{
	t_vector	cross_1;
	t_vector	cross_2;
	t_vector	cross_3;

	cross_1 = v_cross(v_sub(tr->p2, tr->p1), v_sub(point, tr->p1));
	cross_2 = v_cross(v_sub(tr->p3, tr->p2), v_sub(point, tr->p2));
	cross_3 = v_cross(v_sub(tr->p1, tr->p3), v_sub(point, tr->p3));
	cross_1 = v_normalize(cross_1);
	cross_2 = v_normalize(cross_2);
	cross_3 = v_normalize(cross_3);
	if ((v_dot(cross_1, normal) < 0))
		return (false);
	if ((v_dot(cross_2, normal) < 0))
		return (false);
	if ((v_dot(cross_3, normal) < 0))
		return (false);
	return (true);
}

t_vector	normal_triangle(t_vector p1, t_vector p2, t_vector p3)
{
	return (v_normalize(v_cross(v_sub(p2, p1), v_sub(p3, p2))));
}

double		collision_triangle(t_tr *tr, t_ray *ray)
{
	double		t;
	t_vector	normal;
	t_vector	point;

	normal = normal_triangle(tr->p1, tr->p2, tr->p3);
	t = collision_plane(normal, tr->p1, ray);
	if (t == -1)
		return (-1);
	point = v_add(ray->origin, v_scalar(ray->dir, t));
	if (!(collision_true(tr, point, normal)))
		return (-1);
	return (t);
}
