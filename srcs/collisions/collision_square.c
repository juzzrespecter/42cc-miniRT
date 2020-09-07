/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:21:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:20:34 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void transform_vectors(t_vector *height, t_vector *width, t_vector world_or)
{
	t_vector object_or;
	t_vector transformation_matrix[3];
	t_vector height_obj;
	t_vector width_obj;

	ft_bzero(&height_obj, sizeof(t_vector));
	ft_bzero(&width_obj, sizeof(t_vector));
	ft_bzero(&object_or, sizeof(t_vector));
	height_obj.y = 1;
	width_obj.x = 1;
	object_or.z = 1;
	obj2world_matrix(object_or, world_or, transformation_matrix);
	*height = vmprod(height_obj, transformation_matrix);
	*width = vmprod(width_obj, transformation_matrix);
	*height = v_normalize(*height);
	*width = v_normalize(*width);
}

t_ray *collision_square(t_sq *sq, t_ray *ray)
{
	t_vector point;
	t_vector pc_vector;
	t_vector width_vector;
	t_vector height_vector;

	if (!(point_in_plane(sq->orientation, sq->center, ray, &point)))
		return (NULL);
	transform_vectors(&height_vector, &width_vector, sq->orientation);
	pc_vector = v_sub(point, sq->center);
	if (fabs(v_dot(pc_vector, width_vector)) > sq->side / 2)
		return (NULL);
	if (fabs(v_dot(pc_vector, height_vector)) > sq->side / 2)
		return (NULL);
	point_found(point, sq->orientation, sq->color, ray);
	return (ray);
}
