/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:15:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/26 20:14:31 by danrodri         ###   ########.fr       */
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

static float choose_nearest_t(float a, float b, float eq_sqrt)
{
	float t1;
	float t2;

	t1 = (-b + sqrt(eq_sqrt)) / (2 * a);
	t2 = (-b - sqrt(eq_sqrt)) / (2 * a);
	return (t1 < t2 ? t1 : t2);
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
	if (eq_sqrt < 0)
		return (false);
	if (!eq_sqrt)
		&t = -b / (2 * a);
	else
		&t = choose_nearest_t(a, b, eq_sqrt);
	return (true);
}

t_3dvec *collision_cylinder(t_cy *cy, t_3dvec *ray)
{
	float point[3];
	float infinite_cy_t;
	float axis[4];
	float normal[3];

	transform_axis(cy->coord, axis, cy->normal);
	if((collision_cy_inf(ray, cy, axis, &infinite_cy_t)) == false)
		return (NULL);
	if ((collision_cy_cap(void)))
		return (...);
	//buscar las colisiones entre los planos que forman los limites del
	//cilindro, que forman una cota. Para aaceptar la colision, esta ha de
	//estar dentro de la cota, si no estuviera, comprobar si la colision
	//en los planos se situa dentro de los circulos que forman la base y
	//y el techo del cilindro. Si lo son, se acepta la colision; si no,
	//se descarta.
}
