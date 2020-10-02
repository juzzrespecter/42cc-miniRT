/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_square.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:21:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 18:08:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*static bool	check_height(t_sq *sq, t_vector pc, t_matrix matrix)
{
	t_vector	height;
	t_vector	height_dir;
	double		height_len;

	ft_bzero(&height_dir, sizeof(t_vector));	
	height_dir.y = 1;
	height_dir = v_normalize(vmprod(height_dir, matrix));
	height = v_scalar(height_dir, sq->side / 2);
	height_len = sqrt(v_dot(height, height));
	if (fabs(v_dot(pc, height_dir)) > height_len)
		return (false);
	return (true);	
}*/

/*static bool	check_width(t_sq *sq, t_vector pc, t_matrix matrix)
{
	t_vector	width_dir;
	t_vector	width;
	double		width_len;

	ft_bzero(&width_dir, sizeof(t_vector));
	width_dir.x = 1;
	width_dir = v_normalize(vmprod(width_dir, matrix));
	width = v_scalar(width_dir, sq->side / 2);
	width_len = sqrt(v_dot(width, width));
	if (fabs(v_dot(pc, width_dir)) > width_len)
		return (false);
	return (true);
}*/

static t_matrix	init_matrix(t_vector orientation)
{
	t_vector	aux;

	ft_bzero(&aux, sizeof(t_vector));
	aux.z = 1;
	return (matrix_obj2world(aux, orientation));
}

static void	init_tr(t_tr *tr, t_vector *v1, t_vector *v2, t_vector *v3)
{
	tr->p1.x = v1->x;
	tr->p1.y = v1->y;
	tr->p1.z = v1->z;
	tr->p2.x = v2->x;
	tr->p2.y = v2->y;
	tr->p2.z = v2->z;
	tr->p3.x = v3->x;
	tr->p3.y = v3->y;
	tr->p3.z = v3->z;
}

static void	sq_to_tr(t_tr *tr1, t_tr *tr2, t_sq *sq)
{
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;
	t_vector	v4;
	t_matrix	matrix;

	matrix = init_matrix(sq->orientation);
	v1.x = sq->side / 2;
	v1.y = sq->side / 2;
	v1.z = 0;
	v2.x = sq->side / 2;
	v2.y = sq->side / 2;
	v2.z = 0;
	v3.x = sq->side / 2;
	v3.y = sq->side / 2;
	v3.z = 0;
	v1 = v_add(vmprod(v1, matrix), sq->center);
	v2 = v_add(vmprod(v2, matrix), sq->center);
	v3 = v_add(vmprod(v3, matrix), sq->center);
	init_tr(tr1, &v1, &v2, &v3);
	init_tr(tr2, &v3, &v4, &v1);
}

double		collision_square(t_sq *sq, t_ray *ray)
{
	double		t1;
	double		t2;
	t_tr		tr1;
	t_tr		tr2;

	ft_bzero(&tr1, sizeof(t_tr));	
	ft_bzero(&tr2, sizeof(t_tr));
	sq_to_tr(&tr1, &tr2, sq);
	t1 = collision_triangle(&tr1, ray);
	t2 = collision_triangle(&tr2, ray);
	if (t1 == -1 && t2 == -1)
		return (-1);
	return (t1 == -1 ? t2 : t1);
}

/*double		collision_square(t_sq *sq, t_ray *ray)
{
	t_vector	point;
	double		t;
	t_vector	pc;
	t_vector	aux;
	t_matrix	matrix;

	if ((t = collision_plane(sq->orientation, sq->center, ray)) == -1)
		return (-1);
	ft_bzero(&aux, sizeof(t_vector));
	aux.z = 1;
	matrix = matrix_obj2world(aux, sq->orientation);
	point = v_add(ray->origin, v_scalar(ray->dir, t));
	pc = v_sub(point, sq->center);
	if (!check_height(sq, pc, matrix) || !check_width(sq, pc, matrix))
		return (-1);
	return (t);
}*/
