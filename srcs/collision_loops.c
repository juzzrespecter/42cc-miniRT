/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_loops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:07:01 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/03 18:10:48 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point *sp_loop(t_sp *sp, t_3dvec *ray, t_point *a_point)
{
	t_sp *aux_sp;
	t_point *aux_point;
	t_point *point;

	aux_sp = sp;
	aux_point = a_point;
	while (aux_point->next)
		aux_point = aux_point->next;
	while (sp)
		{
			if (!(point = sp_c(sp, ray)))
				return (NULL);
			if (point->p_coord)
				{
					aux_point->next = point;
					aux_point = aux_point->next;
				}
			sp = sp->next;
		}
	return (a_point);
}

t_point *sq_loop(t_sq *sq, t_3dvec *ray, t_point *a_point)
{
	t_sq *aux_sq;
	t_point *aux_point;
	t_point *point;

	aux_sq = sq;
	aux_point = a_point;
	while (aux_point->next)
		aux_point = aux_point->next;
	while (sq)
		{
			if (!(point = sq_c(sq, ray)))
				return (NULL);
			if (point->p_coord)
				{
					aux_point->next = point;
					aux_point = aux_point->next;
				}
			sq = sq->next;
		}
	return (a_point);
}

t_point *pl_loop(t_pl *pl, t_3dvec *ray, t_point *a_point)
{
	t_pl *aux_pl;
	t_point *aux_point;
	t_point *point;

	aux_pl = pl;
	aux_point = a_point;
	while (aux_point->next)
		aux_point = aux_point->next;
	while (pl)
		{
			if (!(point = pl_c(pl, ray)))
				return (NULL);
			if (point->p_coord)
				{
					aux_point->next = point;
					aux_point = aux_point->next;
				}
			pl = pl->next;
		}
	return (a_point);
}

t_point *tr_loop(t_tr *tr, t_3dvec *ray, t_point *a_point)
{
	t_tr *aux_tr;
	t_point *aux_point;
	t_point *point;

	aux_tr = tr;
	aux_point = a_point;
	while (aux_point->next)
		aux_point = aux_point->next;
	while (tr)
		{
			if (!(point = tr_c(tr, ray)))
				return (NULL);
			if (point->p_coord)
				{
					aux_point->next = point;
					aux_point = aux_point->next;
				}
			tr = tr->next;
		}
	return (a_point);
}

t_point *cy_loop(t_cy *cy, t_3dvec *ray, t_point *a_point)
{
	t_cy *aux_cy;
	t_point *aux_point;
	t_point *point;

	aux_cy = cy;
	aux_point = a_point;
	while (aux_point->next)
		aux_point = aux_point->next;
	while (cy)
		{
			if (!(point = cy_c(cy, ray)))
				return (NULL);
			if (point->p_coord)
				{
					aux_point->next = point;
					aux_point = aux_point->next;
				}
			cy = cy->next;
		}
	return (a_point);
}
