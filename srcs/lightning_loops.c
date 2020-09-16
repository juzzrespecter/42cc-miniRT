/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning_loops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:54:28 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/16 18:18:34 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool lightning_loops_5(t_ray *ray, t_objects *o_lst)
{
	t_tr *tr_aux;

	tr_aux = o_lst->tr;
	while (tr_aux)
	{
		if ((collision_triangle(tr_aux, ray)) > 0)
			return (true);
		tr_aux = tr_aux->next;
	}
	return (false);
}

static bool lightning_loops_4(t_ray *ray, t_objects *o_lst)
{
	t_cy *cy_aux;

	cy_aux = o_lst->cy;
	while (cy_aux)
	{
		if ((collision_cylinder(cy_aux, ray)) > 0)
			return (true);
		cy_aux = cy_aux->next;
	}
	return (lightning_loops_5(ray, o_lst));
}

static bool lightning_loops_3(t_ray *ray, t_objects *o_lst)
{
	t_sq *sq_aux;

	sq_aux = o_lst->sq;
	while (sq_aux)
	{
		if ((collision_square(sq_aux, ray)) > 0)
			return (true);
		sq_aux = sq_aux->next;
	}
	return (lightning_loops_4(ray, o_lst));
}

static bool lightning_loops_2(t_ray *ray, t_objects *o_lst)
{
	t_pl *pl_aux;

	pl_aux = o_lst->pl;
	while (pl_aux)
	{
		if ((collision_plane(pl_aux->orientation, pl_aux->coord, ray)) > 0)
			return (true);
		pl_aux = pl_aux->next;
	}
	return (lightning_loops_3(ray, o_lst));
}

bool lightning_loops(t_ray *ray, t_objects *o_lst)
{
	t_sp	*sp_aux;
	bool si;

	sp_aux = o_lst->sp;
	while (sp_aux)
	{
		if ((collision_sphere(sp_aux, ray) > 0))
				return (true);
		sp_aux = sp_aux->next;
	}
	si = lightning_loops_2(ray, o_lst);
	return (si);
}
