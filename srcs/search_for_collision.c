/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:52:19 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/03 18:15:09 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_point *choose_collision(t_point *a_point, float *cam_orig)
{
	float dist_a;
	float dist_b;
	t_point *point;
	t_point *point_aux;

	point = a_point;
	point_aux = a_point;
	if (!point->p_coord)
		return (point);
	while (point_aux->next)
		{
			dist_a = dot_dist(point_aux->p_coord, cam_orig);
			dist_b = dot_dist(point_aux->next->p_coord, cam_orig);
			if (dist_a < dist_b)
				point = point_aux;
			else
				point = point_aux->next;
		}
	return (point);
}

t_point *search_for_collision(t_lst *obj_lst, float *pixel, float *cam_orig)
{
	t_point *a_point;
	t_point *point;
	t_vec3d *ray;

	if (!(a_point = malloc(sizeof(t_point)) && ray = build_ray(cam_orig, pixel)))
		return (NULL);
	a_point->p_coord = NULL;
	a_point->color = 0;
	a_point->next = NULL;
	if (!(sp_loop(sp_lst, ray, a_point)))
			return (NULL);
	if (!(sq_loop(sp_lst, ray, a_point)))
			return (NULL);
	if (!(tr_loop(sp_lst, ray, a_point)))
			return (NULL);
	if (!(cy_loop(sp_lst, ray, a_point)))
			return (NULL);
	if (!(pl_loop(sp_lst, ray, a_point)))
			return (NULL);
	point = choose_collision(a_point, obj_lst->c_lst->coord);
	return (point);
}
