/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_loops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:32:52 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/03 19:18:41 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray *sp_loop(t_sp *sp, t_ray *ray)
{
	t_sp *sp_aux;

	sp_aux = sp;
	while (sp_aux)
		{
			collision_sphere(sp_aux, ray);
			sp_aux = sp_aux->next;
		}
	return (ray);
}

t_ray *pl_loop(t_pl *pl, t_ray *ray)
{
	t_pl *pl_aux;

	pl_aux = pl;
	while (pl_aux)
		{
			collision_plane(pl_aux, ray);
			pl_aux = pl_aux->next;
		}
	return (ray);
}

t_ray *sq_loop(t_sq *sq, t_ray *ray)
{
	t_sq *sq_aux;

	sq_aux = sq;
	while (sq_aux)
		{
			collision_square(sq_aux, ray);
			sq_aux = sq_aux->next;
		}
	return (ray);
}

t_ray *cy_loop(t_cy *cy, t_ray *ray)
{
	t_cy *cy_aux;

	cy_aux = cy;
	while (cy_aux)
		{
			collision_cylinder(cy_aux, ray);
			cy_aux = cy_aux->next;
		}
	return (ray);
}

t_ray *tr_loop(t_tr *tr, t_ray *ray)
{
	t_tr *tr_aux;

	tr_aux = tr;
	while (tr_aux)
		{
			//collision_triangle(tr_aux, ray);
			tr_aux = tr_aux->next;
		}
	return (ray);
}
