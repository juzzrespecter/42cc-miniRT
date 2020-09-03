/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_searcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:19:33 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/03 19:20:14 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void collision_searcher(t_objlst *obj_lst, t_3dvec *ray)
{
	if (obj_lst->sp)
		sp_loop(obj_lst->sp, ray);
	if (obj_lst->pl)
		pl_loop(obj_lst->pl, ray);
	if (obj_lst->sq)
		sq_loop(obj_lst->sq, ray);
	if (obj_lst->cy)
		cy_loop(obj_lst->cy, ray);
	if (obj_lst->tr)
		tr_loop(obj_lst->tr, ray);
}
