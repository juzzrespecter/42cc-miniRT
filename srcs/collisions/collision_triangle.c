/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:22:22 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/16 16:48:37 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//revisar el check

static bool triangle_point_check(t_tr *tr, t_vector point, t_vector normal)
{
	t_vector cross_1;
	t_vector cross_2;
	t_vector cross_3;

	cross_1 = v_cross(v_sub(tr->s_p, tr->f_p), v_sub(point, tr->f_p));
	cross_2 = v_cross(v_sub(tr->t_p, tr->s_p), v_sub(point, tr->s_p));
	cross_3 = v_cross(v_sub(tr->f_p, tr->t_p), v_sub(point, tr->t_p));
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
	return (v_normalize(v_cross(v_sub(s_p, f_p), v_sub(t_p, s_p))));
}

float	collision_triangle(t_tr *tr, t_ray *ray)
{
	float t;
	t_vector normal;
	t_vector point;

	normal = normal_triangle(tr->f_p, tr->s_p, tr->t_p);
	if ((t = collision_plane(normal, tr->f_p, ray) == -1))
		return (-1);
	point = v_add(ray->origin, v_scalar(ray->dir, t));
	if (!(triangle_point_check(tr, point, normal)))
		return (-1);
	return (t);
}
