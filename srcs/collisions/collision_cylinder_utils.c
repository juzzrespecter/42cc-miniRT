/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:33:32 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/08 19:37:06 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray *cy_loop(t_cy *cy, t_ray *ray)
{
	while (cy)
	{
		collision_cylinder(cy, ray);
		cy = cy->next;
	}
	return (ray);
}

float a_calc(t_vector ray_dir, t_vector axis_dir)
{
	t_vector vector_1;
	float prod_1;

	prod_1 = v_dot(ray_dir, axis_dir);
	vector_1 = v_sub(ray_dir, v_scalar(axis_dir, prod_1));
	return (v_dot(vector_1, vector_1));
}

float b_calc(t_vector ray_dir, t_vector axis_dir, t_vector or, t_vector axis_or)
{
	t_vector vector_1;
	t_vector vector_2;
	t_vector vector_or;
	float prod_1;
	float prod_2;

	vector_or = v_sub(or, axis_or);
	prod_1 = v_dot(ray_dir, axis_dir);
	prod_2 = v_dot(axis_dir, vector_or);
	vector_1 = v_sub(ray_dir, v_scalar(axis_dir, prod_1));
	vector_2 = v_sub(vector_or, v_scalar(vector_or, prod_2));
	return (2 * v_dot(vector_1, vector_2));
}

float c_calc(t_vector axis_dir, t_vector or, t_vector axis_or, float r)
{
	t_vector vector_2;
	t_vector vector_or;
	float prod_2;

	vector_or = v_sub(or, axis_or);
	prod_2 = v_dot(axis_dir, vector_or);
	vector_2 = v_sub(vector_or, v_scalar(vector_or, prod_2));
	return (v_dot(vector_2, vector_2) - pow(r, 2));
}
