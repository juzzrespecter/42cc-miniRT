/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_searcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:19:33 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:19:49 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void collision_searcher(t_olst *olst, t_ray *ray)
{
	if (olst->sp)
		sp_loop(olst->sp, ray);
	if (olst->pl)
		pl_loop(olst->pl, ray);
	if (olst->sq)
		sq_loop(olst->sq, ray);
	if (olst->cy)
		cy_loop(olst->cy, ray);
	if (olst->tr)
		tr_loop(olst->tr, ray);
}
