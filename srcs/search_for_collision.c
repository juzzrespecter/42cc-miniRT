/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:05:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/14 19:44:43 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_point *search_for_collision(t_objlst *obj_lst, t_point *point, t_3dvec ray)
{
	t_cam *cam;

	cam = obj_lst->cam;
	if (obj_lst->sp)
		point = sp_loop(obj_lst->sp, point, cam, ray);
	if (obj_lst->pl)
		point = pl_loop(obj_lst->pl, point, cam, ray);
	if (obj_lst->sq)
		point = sq_loop(obj_lst->sq, point, cam, ray);
	if (obj_lst->cy)
		point = cy_loop(obj_lst->cy, point, cam, ray);
	if (obj_lst->tr)
		point = tr_loop(obj_lst->tr, point, cam, ray);
	return (point);
}
