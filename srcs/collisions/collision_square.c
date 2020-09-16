/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:21:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/16 16:30:14 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void transform_vectors(t_vector *height, t_vector *width, t_vector world_or)
{
	t_vector object_or;
	t_matrix matrix;
	t_vector height_obj;
	t_vector width_obj;

	ft_bzero(&height_obj, sizeof(t_vector));
	ft_bzero(&width_obj, sizeof(t_vector));
	ft_bzero(&object_or, sizeof(t_vector));
	height_obj.y = 1;
	width_obj.x = 1;
	object_or.z = 1;
	matrix = matrix_obj2world(object_or, world_or);
	*height = vmprod(height_obj, matrix);
	*width = vmprod(width_obj, matrix);
	*height = v_normalize(*height);
	*width = v_normalize(*width);
}

float	collision_square(t_sq *sq, t_ray *ray)
{
	t_vector point;
	float t;
	t_vector pc_vector;
	t_vector width_vector;
	t_vector height_vector;

	if ((t = collision_plane(sq->orientation, sq->center, ray)) == -1)
		return (-1);
	point = v_add(ray->origin, v_scalar(ray->dir, t));
	transform_vectors(&height_vector, &width_vector, sq->orientation);
	pc_vector = v_sub(point, sq->center);
	if (fabs(v_dot(pc_vector, width_vector)) > sq->side / 2)
		return (-1);
	if (fabs(v_dot(pc_vector, height_vector)) > sq->side / 2)
		return (-1);
	return (t);
}
