/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:15:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/08 19:36:15 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector transform_axis(t_vector world_or)
{
	t_vector object_or;
	t_vector axis_object_or;
	t_vector axis;
	t_vector transformation_matrix[3];

	ft_bzero(&object_or, sizeof(t_vector));
	ft_bzero(&axis_object_or, sizeof(t_vector));
	object_or.z = 1;
	axis_object_or.y = 1;
	obj2world_matrix(object_or, world_or, transformation_matrix);
	axis = v_normalize(vmprod(axis_object_or, transformation_matrix));
	return (axis);
}

static float choose_nearest_t(float a, float b, float eq_sqrt)
{
	float far_t;
	float near_t;

	far_t = (-b + sqrt(eq_sqrt)) / (2 * a);
	near_t = (-b - sqrt(eq_sqrt)) / (2 * a);
	return (near_t > 0 ? near_t : far_t);
}

static bool collision_cy_inf(t_ray *ray, t_cy *cy, t_vector axis, float *t)
{
	float a;
	float b;
	float c;
	float eq_sqrt;

	a = a_calc(ray->dir, axis);
	b = b_calc(ray->dir, axis, ray->origin, cy->coord);
	c = c_calc(axis, ray->origin, cy->coord, cy->d / 2);
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

static t_vector get_normal(t_cy *cy, t_vector point, t_vector axis)
{
	t_vector p_norm;
	t_vector normal;
	float axis_dot;

	axis_dot = v_dot(v_sub(point, cy->coord), axis);
	p_norm = v_add(cy->coord, v_scalar(axis, axis_dot));
	normal = v_normalize(v_sub(point, p_norm));
	return (normal);
}

t_ray *collision_cylinder(t_cy *cy, t_ray *ray)
{
	t_vector point;
	float infinite_cy_t;
	t_vector axis;
	t_vector normal;

	axis = transform_axis(cy->orientation);
	printf("axis: (%.2f, %.2f, %.2f).\n", axis.x, axis.y, axis.z);
	if((collision_cy_inf(ray, cy, axis, &infinite_cy_t)) == false)
		return (NULL);
	if (infinite_cy_t < 0)
		return (NULL);
	point = v_add(ray->origin, v_scalar(ray->dir, infinite_cy_t));
	normal = get_normal(cy, point, axis);
	point_found(point, normal, cy->color, ray);
	return (ray);
}
