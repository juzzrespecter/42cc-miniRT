/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:15:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/25 19:32:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void transform_axis(float *origin_point, float *axis, float *world_or)
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

static void (float *ray_dir, float *axis_dir)
{
	float dir_rest[3];
	float dir_prod;

	dir_prod = dot(ray_dir, axis_dir);
	dir_res[0] = ray_dir[0] - (dir_prod * axis_dir[0]);
	dir_res[1] = ray_dir[1] - (dir_prod * axis_dir[1]);
	dir_res[2] = ray_dir[2] - (dir_prod * axis_dir[2]);
	return (dot(dir_rest, dir_rest));
}

static bool foo(float *ray_dir, float *axis_dir, t_cy *cy, float *point)
{
	float axis[4];
	float or_vector[3]
	float dir_res [3];
	float orig_res [3];
	float eq_sqrt;

	transform_matrix(cy->coord, axis, cy->normal);
	or_vector[0] = ray->orig[0] - cy->coord[0];
	or_vector[1] = ray->orig[1] - cy->coord[1];
	or_vector[2] = ray->orig[2] - cy->coord[2];

	if (eq_sqrt < 0)
		return (false);
	if (!eq_sqrt)
		{
			//una colision
		}
	else
		{
			//dos colisiones
		}
}

t_3dvec *collision_cylinder(t_cy *cy, t_3dvec *ray)
{
	float point[3];
	//colision con el cilindro (infinito)
	//	no hay colision -> fin de la funcion
	//  hay una colision (una t)
	//  hay dos colisiones (dos t)

	//comprobar los limites del cilindro (las tapas)
	return (ray);
}
