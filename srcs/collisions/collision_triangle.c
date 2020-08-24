/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:22:22 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 16:22:56 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void triangle_calculate_normal(t_tr *tr, float *normal)
{
	float first_vector[3];
	float second_vector[3];
	int count;

	count = 0;
	while (count < 3)
		{
			first_vector[count] = tr->second_coord[count] - tr->first_coord[count];
			second_vector[count] = tr->third_coord[count] - tr->second_coord[count];
			count++;
		}
	cross(first_vector, second_vector, normal);
	norm(normal);
}

static void edge_vp_cross_prod(float *v1, float *v2, float *point, float *cross_prod)
{
	float edge[3];
	float vp[3];
	int count;

	count = 0;
	while (count < 3)
		{
			edge[count] = v2[count] - v1[count];
			vp[count] = point[count] - v1[count];
			count++;
		}
	cross(edge, vp, cross_prod);
	norm(cross_prod);
}

static bool triangle_point_check(t_tr *tr, float *point, float *normal)
{
	float cross_1[3];
	float cross_2[3];
	float cross_3[3];

	edge_vp_cross_prod(tr->first_coord, tr->second_coord, point, cross_1);
	edge_vp_cross_prod(tr->second_coord, tr->third_coord, point, cross_2);
	edge_vp_cross_prod(tr->third_coord, tr->first_coord, point, cross_3);
	if ((dot(cross_1, normal) < 0))
		return (false);
	if ((dot(cross_2, normal) < 0))
		return (false);
	if ((dot(cross_3, normal) < 0))
		return (false);
	return (true);
}


t_3dvec *collision_trinagle(t_tr *tr, t_3dvec *ray)
{
	float normal[3];
	float point[3];
	float d;

	triangle_calculate_normal(tr, normal);
	if (!(find_point_in_a_plane(normal, ray, d, point)))
		return (NULL);
	if (!(triangle_point_check(tr, point, normal)))
		return (NULL);
	point_found(point, normal, tr->color, ray);
}
