/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_for_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:05:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/21 17:45:08 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void search_for_collision(t_objlst *obj_lst, t_3dvec *ray)
{
	t_cam *cam;

	cam = obj_lst->cam;
	if (obj_lst->sp)
		sp_loop(obj_lst->sp, cam, ray);
	if (obj_lst->pl)
		pl_loop(obj_lst->pl, cam, ray);
	if (obj_lst->sq)
		sq_loop(obj_lst->sq, cam, ray);
	if (obj_lst->cy)
		cy_loop(obj_lst->cy, cam, ray);
	if (obj_lst->tr)
		tr_loop(obj_lst->tr, cam, ray);
}
