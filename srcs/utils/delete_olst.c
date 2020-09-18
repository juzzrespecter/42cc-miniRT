/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_olst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:29:53 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/18 19:42:42 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void delete_light_sp_lst(t_objects *o_lst)
{
	t_light *light_aux;
	t_light *light;
	t_sp *sp_aux;
	t_sp *sp;

	light = o_lst->light;
	sp = o_lst->sp;
	while (light)
		{
			light_aux = light->next;
			free(light);
			light = light_aux;
		}
	while (sp)
		{
			sp_aux = sp->next;
			free(sp);
			sp = sp_aux;
		}
}

static void delete_pl_sq_lst(t_objects *o_lst)
{
	t_pl *pl_aux;
	t_pl *pl;
	t_sq *sq_aux;
	t_sq *sq;

	pl = o_lst->pl;
	sq = o_lst->sq;
	while (pl)
		{
			pl_aux = pl->next;
			free(pl);
			pl = pl_aux;
		}
	while (sq)
		{
			sq_aux = sq->next;
			free(sq);
			sq = sq_aux;
		}
}

static void delete_cy_tr_lst(t_objects *o_lst)
{
	t_cy *cy_aux;
	t_cy *cy;
	t_tr *tr_aux;
	t_tr *tr;

	cy = o_lst->cy;
	tr = o_lst->tr;
	while (cy)
		{
			cy_aux = cy->next;
			free(cy);
			cy = cy_aux;
		}
	while (tr)
		{
			tr_aux = tr->next;
			free(tr);
			tr = tr_aux;
		}
}

void	delete_olst(t_objects *o_lst)
{
	free(o_lst->amb);
	if (o_lst->light || o_lst->sp)
		delete_light_sp_lst(o_lst);
	if (o_lst->pl || o_lst->sq)
		delete_pl_sq_lst(o_lst);
	if (o_lst->cy || o_lst->tr)
		delete_cy_tr_lst(o_lst);
	free(o_lst);
}
