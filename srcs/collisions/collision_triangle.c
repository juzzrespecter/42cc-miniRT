/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:22:22 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/10 19:32:12 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray *tr_loop(t_tr *tr, t_ray *ray)
{
	while (tr)
	{
		collision_triangle(tr, ray);
		tr = tr->next;
	}
	return (ray);
}

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
	return (true);
}

t_ray *collision_triangle(t_tr *tr, t_ray *ray)
{
	t_vector normal;
	t_vector point;

	normal = v_cross(v_sub(tr->second_point, tr->first_point), v_sub(tr->third_point, tr->second_point));
	normal = v_normalize(normal);
	printf("normal: (%.2f, %.2f, %.2f)\n", normal.x, normal.y, normal.z);
	if (!(point_in_plane(normal, tr->first_point, ray, &point)))
		return (NULL);
	if (!(triangle_point_check(tr, point, normal)))
		return (NULL);
	point_found(point, normal, tr->color, ray);
	return (ray);
}
