/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_olst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:29:53 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 18:59:10 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void delete_olst_last(t_objects *o_lst)
{
	t_tr *tr;

	while (o_lst->tr)
	{
		tr = o_lst->tr->next;
		free(o_lst->tr);
		o_lst->tr = tr;
	}
}

static void delete_olst_more(t_objects *o_lst)
{
	t_pl *pl;
	t_sq *sq;
	t_cy *cy;

	while (o_lst->pl)
	{
		pl = o_lst->pl->next;
		free(pl);
		o_lst->pl = pl;
	}
	while (o_lst->sq)
	{
		sq = o_lst->sq->next;
		free(o_lst->sq);
		o_lst->sq = sq;
	}
	while (o_lst->cy)
	{
		cy = o_lst->cy->next;
		free(o_lst->cy);
		o_lst->cy = cy;
	}
	delete_olst_last(o_lst);
}

void	delete_olst(t_objects *o_lst)
{
	t_light *light;
	t_sp *sp;

	if (o_lst->amb)
		free(o_lst->amb);
	while (o_lst->light)
	{
		light = o_lst->light->next;
		free(o_lst->light);
		o_lst->light = light;
	}
	while (o_lst->sp)
	{
		sp = o_lst->sp->next;
		free(o_lst->sp);
		o_lst->sp = sp;
	}
	delete_olst_more(o_lst);
}
