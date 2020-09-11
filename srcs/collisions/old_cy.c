/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:15:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/10 19:32:08 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
static t_vector transform_axis(t_vector world_or)
{
	t_vector object_or;
	t_vector axis;
	t_vector transformation_matrix[3];

	ft_bzero(&object_or, sizeof(t_vector));
	ft_bzero(&axis, sizeof(t_vector));
	object_or.z = 1;
	axis.y = 1;
//	printf("\ntr: axis: (%.2f, %.2f, %.2f), objecto: (%.2f, %.2f, %.2f), worldo: (%.2f, %.2f, %.2f)\n", axis.x, axis.y, axis.z, object_or.x, object_or.y, object_or.z, world_or.x, world_or.y, world_or.z);
	obj2world_matrix(object_or, world_or, transformation_matrix);
	axis = v_normalize(vmprod(axis, transformation_matrix));
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
//	printf("on cyinf: a (%.2f), b (%.2f), c (%.2f)\n", a, b, c);

	if (eq_sqrt < 0 || a < 1e-6)
		return (false);
	if (!eq_sqrt)
		*t = -b / (2 * a);
	else
		*t = choose_nearest_t(a, b, eq_sqrt);
	return (true);
}

static float collision_caps(t_cy *cy, float *normal, float t)
{
	float coord_2[3];
	float t_1;
	float t_denom;
	float t_2;

	coord_2 [0] = cy->coord [0] + cy->height * normal [0];
	coord_2 [1] = cy->coord [1] + cy->height * normal [1];
	coord_2 [2] = cy->coord [2] + cy->height * normal [2];
	if ((t_denom = dot (normal)))
	}

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
//	printf("axis: (%.2f, %.2f, %.2f).\n\n", axis.x, axis.y, axis.z);
	if((collision_cy_inf(ray, cy, axis, &infinite_cy_t)) == false)
		return (NULL);
//	printf("col on line TRUE\n");
	if (infinite_cy_t < 0)
		return (NULL);
//	printf("col on scene TRUE\n\n");
	point = v_add(ray->origin, v_scalar(ray->dir, infinite_cy_t));
	normal = get_normal(cy, point, axis);
	point_found(point, normal, cy->color, ray);
	return (ray);
} 

float a(t_vector axis, t_vector dir)
{
	return (v_dot(axis, axis) - (pow(v_dot(axis, dir), 2))); 
}

float b(t_vector axis, t_vector oc, t_vector dir)
{
	return ((v_dot(axis, axis) * v_dot(oc, dir)) \
			- (v_dot(axis, oc) * v_dot(axis, dir)));
}

float c(t_vector axis, t_vector oc, float r)
{
	return ((v_dot(axis, axis) * v_dot(oc, oc)) - pow(v_dot(axis, oc), 2) \
			- (pow(r, 2) * v_dot(axis, axis)));
}

t_vector calc_normal(t_cy *cy, t_vector point)
{
	t_vector normal;
	t_vector center;
	t_vector t_matrix[3];
	t_vector axis_objspace;

	ft_bzero(&axis_objspace, sizeof(t_vector));
	axis_objspace.y = 1;
	obj2world_matrix(cy->orientation, axis_objspace, t_matrix);
	point = vmprod(point, t_matrix);
	point = v_sub(point, cy->coord);
	center = v_scalar(axis_objspace, point.y);
	normal = v_sub(point, center);
	return (normal);
}*/

t_ray *collision_cylinder(t_cy *cy, t_ray *ray)
{
	//calculos hechos por el muchacho Inigo Quilez:
	t_vector pa = cy->coord;
	t_vector pb = v_add(pa, v_scalar(cy->orientation, cy->h));
	t_vector axis = v_sub(pb, pa);
	t_vector oc = v_sub(ray->origin, pa);

	t_vector point;
	t_vector normal;

	float d_axis = v_dot(axis, axis);
	float d_adir = v_dot(axis, ray->dir);
	float d_aoc = v_dot(axis, oc);

	float a = d_axis - d_adir * d_adir;
	float b = d_axis * v_dot(oc, ray->dir) - d_aoc * d_adir;
	float c = d_axis * v_dot(oc, oc) - d_aoc * d_aoc - (cy->d / 2) * (cy->d / 2) * d_axis;

	float h = b * b - a * c;

	printf("h (%.2f).\n", h);
	if (h < 0) return (NULL);
	h = sqrt(h);

	float t = (-b-h) / a;

	float y = d_aoc + t * d_adir;
	printf("t: (%.2f) y: (%.2f)\n\n", t, y);
	if (y > 0 && y < d_axis)
	{
		point = v_add(ray->origin, v_scalar(ray->dir, t));
		normal = v_scalar(v_scalar(v_sub(v_add(oc, v_scalar(ray->dir, t)), v_scalar(axis, y)), 1 / d_axis), 1 /  cy->d /2);
		point_found(point, normal, cy->color, ray);
	}
	else
	{
		float t2 = (((y < 0) ? 0 : d_axis) - d_aoc) / d_adir;
		if (fabs(b + a * t2) < h)
		{
			point = v_add(ray->origin, v_scalar(ray->dir, t));
			//normal = v_scalar(v_scalar(axis, sign(y)), 1 / d_axis);
			normal = v_scalar(v_scalar(v_sub(v_add(oc, v_scalar(ray->dir, t)), v_scalar(axis, y)), 1 / d_axis), 1 /  cy->d /2);
			point_found(point, normal, cy->color, ray);
		}
		return (NULL);
	}
	return (ray);
}
