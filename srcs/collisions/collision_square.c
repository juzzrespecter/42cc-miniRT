/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:21:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/02 19:30:28 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void transform_vectors(float *height, float *width, float *world_or)
{
	float object_or[4];
	float transformation_matrix[4][4];
	float height_obj[4];
	float width_obj[4];
	int count;

	count = 0;
	while (count < 4)
		{
			height_obj[count] = 1 * (count == 1 || count == 3);
			width_obj[count] = 1 * (count == 0 || count == 3);
			object_or[count] = 1 * (count == 2 || count == 3);
			count++;
		}
	obj2world_matrix(object_or, world_or, transformation_matrix);
	vmprod(height_obj, transformation_matrix, height);
	vmprod(width_obj, transformation_matrix, width);
	normalize(height);
	normalize(width);
}

t_3dvec *collision_square(t_sq *sq, t_3dvec *ray)
{
	float point[3];
	float pc_vector[3];
	float width_vector[4];
	float height_vector[4];

	if (!(point_in_plane(sq->normal, ray, dot(sq->normal, sq->center), point)))
		return (NULL);
	transform_vectors(height_vector, width_vector, sq->normal);
	pc_vector[0] = point[0] - sq->center[0];
	pc_vector[1] = point[1] - sq->center[1];
	pc_vector[2] = point[2] - sq->center[2];
	if (fabs(dot(pc_vector, width_vector)) > sq->side / 2)
		return (NULL);
	if (fabs(dot(pc_vector, height_vector)) > sq->side / 2)
		return (NULL);
	point_found(point, sq->normal, sq->color, ray);
	return (ray);
}
