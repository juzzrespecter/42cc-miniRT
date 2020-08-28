/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:15:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/28 17:06:43 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void transform_axis(float *axis, float *world_or)
{
	float object_or[4];
	float axis_object_or[4];
	float transformation_matrix[4][4];
	int count;

	count = 0;
	while (count < 4)
		{
			axis_object_or[count] = 1 * (count == 1 || count == 3);
			object_or[count] = 1 * (count == 2 || count == 3);
			count++;
		}
	obj2world_matrix(object_or, world_or, transformation_matrix);
	vmprod(axis_object_or, transformation_matrix, axis);
	normalize(axis);
}

static float choose_nearest_t(float a, float b, float eq_sqrt)
{
	float t1;
	float t2;

	t1 = (-b + sqrt(eq_sqrt)) / (2 * a);
	t2 = (-b - sqrt(eq_sqrt)) / (2 * a);
	if (t1 < 0)
		return (t1 < t2 ? t1 : t2);
	else
		return (t2);
}

static bool collision_cy_inf(t_3dvec *ray, t_cy *cy, float *axis, float *t)
{
	float a;
	float b;
	float c;
	float eq_sqrt;

	a = a_calc (ray->dir, axis);
	b = b_calc (ray->dir, axis, ray->orig, cy->coord);
	c = c_calc (axis, ray->orig, cy->coord, cy->d / 2);
	eq_sqrt = pow (b, 2) - 4 * a * c;
	if (eq_sqrt < 0 || a < 1e-6)
		return (false);
	if (!eq_sqrt)
		*t = -b / (2 * a);
	else
		*t = choose_nearest_t(a, b, eq_sqrt);
	return (true);
}

/*static float collision_caps(t_cy *cy, float *normal, float t)
{
	float coord_2[3];
	float t_1;
	float t_denom;
	float t_2;

	coord_2 [0] = cy->coord [0] + cy->height * normal [0];
	coord_2 [1] = cy->coord [1] + cy->height * normal [1];
	coord_2 [2] = cy->coord [2] + cy->height * normal [2];
	if ((t_denom = dot (normal)))
	}*/

static void get_normal (t_cy *cy, float *point, float *axis, float *normal)
{
	float p_vec [3];
	float p_norm [3];
	float axis_dot;

	p_vec [0] = point [0] - cy->coord [0];
	p_vec [1] = point [1] - cy->coord [1];
	p_vec [2] = point [2] - cy->coord [2];
	axis_dot = dot (p_vec, axis);
	p_norm [0] = cy->coord [0] + axis_dot * axis [0];
	p_norm [1] = cy->coord [1] + axis_dot * axis [1];
	p_norm [2] = cy->coord [2] + axis_dot * axis [2];
	normal [0] = point [0] - p_norm [0];
	normal [1] = point [1] - p_norm [1];
	normal [2] = point [2] - p_norm [2];
	normalize (normal);
}

t_3dvec *collision_cylinder(t_cy *cy, t_3dvec *ray)
{
	float point[3];
	float infinite_cy_t;
	float axis[4];
	float normal[3];

	transform_axis(axis, cy->normal);
	if((collision_cy_inf(ray, cy, axis, &infinite_cy_t)) == false)
		return (NULL);
	if (infinite_cy_t < 0)
		return (NULL);
	point [0] = ray->orig [0] + infinite_cy_t * ray->dir [0];
	point [1] = ray->orig [1] + infinite_cy_t * ray->dir [1];
	point [2] = ray->orig [2] + infinite_cy_t * ray->dir [2];
	get_normal (cy, point, axis, normal);
	point_found (point, normal, cy->color, ray);
	return (ray);
}
