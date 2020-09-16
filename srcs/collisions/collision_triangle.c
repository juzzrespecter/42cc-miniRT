/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:22:22 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/14 17:41:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//revisar el check

static bool triangle_point_check(t_tr *tr, t_vector point, t_vector normal)
{
	t_vector cross_1;
	t_vector cross_2;
	t_vector cross_3;

	cross_1 = v_cross(v_sub(tr->second_point, tr->first_point), v_sub(point, tr->first_point));
	cross_2 = v_cross(v_sub(tr->third_point, tr->second_point), v_sub(point, tr->second_point));
	cross_3 = v_cross(v_sub(tr->first_point, tr->third_point), v_sub(point, tr->third_point));
	cross_1 = v_normalize(cross_1);
	cross_2 = v_normalize(cross_2);
	cross_3 = v_normalize(cross_3);
	if ((v_dot(cross_1, normal) < 0))
		return (false);
	if ((v_dot(cross_2, normal) < 0))
		return (false);
	if ((v_dot(cross_3, normal) < 0))
		return (false);
	printf("ojo!\n");
	return (true);
}

t_vector normal_triangle(t_vector f_p, t_vector s_p, t_vector t_p)
{
	return (v_normalize(v_cross(v_sub(s_p, f_p), v_sub(t_p, s_p))))
}

float	collision_triangle(t_tr *tr, t_ray *ray)
{
	float t;
	t_vector normal;
	t_vector point;

	normal = normal_triangle(tr->first_point, tr->second_point, tr->third_point);
	if ((t = collision_plane(normal, tr->first_point, ray) == -1))
		return (-1);
	point = v_add(ray->origin, v_scalar(ray->dir, t);
	if (!(triangle_point_check(tr, point, normal)))
		return (-1);
	return (t);
}
