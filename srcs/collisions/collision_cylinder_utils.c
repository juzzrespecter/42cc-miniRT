/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:33:32 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/26 19:30:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

float a_calc(float *ray_dir, float *axis_dir)
{
	float vector_1[3];
	float prod_1;

	prod_1 = dot(ray_dir, axis_dir);
	vector_1[0] = ray_dir[0] - (prod_1 * axis_dir[0]);
	vector_1[1] = ray_dir[1] - (prod_1 * axis_dir[1]);
	vector_1[2] = ray_dir[2] - (prod_1 * axis_dir[2]);
	return (dot(vector_1, vector_1));
}

float b_calc(float *ray_dir, float *axis_dir, float *or, float *axis_or)
{
	float vector_1[3];
	float vector_2[3];
	float vector_or[3];
	float prod_1;
	float prod_2;

	res(or, axis_or, vector_or);
	prod_1 = dot(ray_dir, axis_dir);
	prod_2 = dot(axis_dir, vector_or);
	vector_1[0] = ray_dir[0] - (prod_1 * axis_dir[0]);
	vector_1[1] = ray_dir[1] - (prod_1 * axis_dir[1]);
	vector_1[2] = ray_dir[2] - (prod_1 * axis_dir[2]);
	vector_2[0] = vector_or[0] - (prod_2 * vector_or[0]);
	vector_2[1] = vector_or[1] - (prod_2 * vector_or[1]);
	vector_2[2] = vector_or[2] - (prod_2 * vector_or[2]);
	return (2 * dot(vector_1, vector_2));
}

float c_calc(float *axis_dir, float *or, float *axis_or, float r)
{
	float vector_2[3];
	float vector_or[3];
	float prod_2;

	res(or, axis_or, vector_or);
	prod_2 = dot(axis_dir, vector_or);
	vector_2[0] = vector_or[0] - (prod_2 * vector_or[0]);
	vector_2[1] = vector_or[1] - (prod_2 * vector_or[1]);
	vector_2[2] = vector_or[2] - (prod_2 * vector_or[2]);
	return (dot(vector_2, vector_2) - pow(r, 2));
}
