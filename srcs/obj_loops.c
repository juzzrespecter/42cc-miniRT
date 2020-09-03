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

#include "../inc/minirt.h"

t_3dvec *sp_loop(t_sp *sp, t_3dvec *ray)
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

t_3dvec *pl_loop(t_pl *pl, t_3dvec *ray)
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

t_3dvec *sq_loop(t_sq *sq, t_3dvec *ray)
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

t_3dvec *cy_loop(t_cy *cy, t_3dvec *ray)
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

t_3dvec *tr_loop(t_tr *tr, t_3dvec *ray)
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
