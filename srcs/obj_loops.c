/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_loops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:32:52 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/15 19:57:08 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void sp_loop(t_sp *sp, t_point *point, t_cam *cam, t_3dvec ray)
{
	t_sp *sp_aux;

	sp_aux = sp;
	while (sp_aux)
		{
			sp_collision(sp_aux, point, cam, ray);
			sp_aux = sp_aux->next;
		}
}

void pl_loop(t_pl *pl, t_point *point, t_cam *cam, t_3dvec ray)
{
	t_pl *pl_aux;

	pl_aux = pl;
	while (pl_aux)
		{
			//			pl_collision(pl_aux, point, cam, ray);
			pl_aux = pl_aux->next;
		}
}

void sq_loop(t_sq *sq, t_point *point, t_cam *cam, t_3dvec ray)
{
	t_sq *sq_aux;

	sq_aux = sq;
	while (sq_aux)
		{
			//			sq_collision(sq_aux, point, cam, ray);
			sq_aux = sq_aux->next;
		}
}

void cy_loop(t_cy *cy, t_point *point, t_cam *cam, t_3dvec ray)
{
	t_cy *cy_aux;

	cy_aux = cy;
	while (cy_aux)
		{
			//			cy_collision(cy_aux, point, cam, ray);
			cy_aux = cy_aux->next;
		}
}

void tr_loop(t_tr *tr, t_point *point, t_cam *cam, t_3dvec ray)
{
	t_tr *tr_aux;

	tr_aux = tr;
	while (tr_aux)
		{
			//			tr_collision(tr_aux, point, cam, ray);
			tr_aux = tr_aux->next;
		}
}
