/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:05:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/15 19:56:53 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_point search_for_collision(t_objlst *obj_lst, t_3dvec ray)
{
	t_cam *cam;
	t_point point;

	cam = obj_lst->cam;
	point.found_p = false;
	if (obj_lst->sp)
		sp_loop(obj_lst->sp, &point, cam, ray);
	if (obj_lst->pl)
		pl_loop(obj_lst->pl, &point, cam, ray);
	if (obj_lst->sq)
		sq_loop(obj_lst->sq, &point, cam, ray);
	if (obj_lst->cy)
		cy_loop(obj_lst->cy, &point, cam, ray);
	if (obj_lst->tr)
		tr_loop(obj_lst->tr, &point, cam, ray);
	return (point);
}
