/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:21:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/28 19:49:47 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	transform_vectors(t_vector *h, t_vector *w, t_vector world_or)
{
	t_vector	object_or;
	t_matrix	matrix;
	t_vector	h_obj;
	t_vector	w_obj;

	ft_bzero(&h_obj, sizeof(t_vector));
	ft_bzero(&w_obj, sizeof(t_vector));
	ft_bzero(&object_or, sizeof(t_vector));
	h_obj.y = 1;
	w_obj.x = 1;
	object_or.z = 1;
	matrix = matrix_obj2world(object_or, world_or);
	*h = vmprod(h_obj, matrix);
	*w = vmprod(w_obj, matrix);
	*h = v_normalize(*h);
	*w = v_normalize(*w);
}

float		collision_square(t_sq *sq, t_ray *ray)
{
	t_vector	point;
	float		t;
	t_vector	pc_vector;
	t_vector	w_vector;
	t_vector	h_vector;

	if ((t = collision_plane(sq->orientation, sq->center, ray)) == -1)
		return (-1);
	point = v_add(ray->origin, v_scalar(ray->dir, t));
	transform_vectors(&h_vector, &w_vector, sq->orientation);
	pc_vector = v_sub(point, sq->center);
	if (fabs(v_dot(pc_vector, w_vector)) > sq->side / 2)
		return (-1);
	if (fabs(v_dot(pc_vector, h_vector)) > sq->side / 2)
		return (-1);
	return (t);
}
