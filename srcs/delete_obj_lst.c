/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_obj_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:58:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/09 20:06:28 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void delete_cam_lst(t_objlst *obj_lst)
{
	t_cam *cam_aux;
	t_cam *cam;

	cam = obj_lst->cam;
	while (cam)
		{
			cam_aux = cam->next;
			free(cam);
			cam = cam_aux;
		}
}

static void delete_light_sp_lst(t_objlst *obj_lst)
{
	t_light *light_aux;
	t_light *light;
	t_sp *sp_aux;
	t_sp *sp;

	light = obj_lst->light;
	sp = obj_lst->sp;
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

static void delete_pl_sq_lst(t_objlst *obj_lst)
{
	t_pl *pl_aux;
	t_pl *pl;
	t_sq *sq_aux;
	t_sq *sq;

	pl = obj_lst->pl;
	sq = obj_lst->sq;
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

static void delete_cy_tr_lst(t_objlst *obj_lst)
{
	t_cy *cy_aux;
	t_cy *cy;
	t_tr *tr_aux;
	t_tr *tr;

	cy = obj_lst->cy;
	tr = obj_lst->tr;
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

void	delete_obj_lst(t_objlst *obj_lst)
{
	if (obj_lst->res)
		free(obj_lst->res);
	if (obj_lst->amb)
		free(obj_lst->amb);
	if (obj_lst->cam)
		delete_cam_lst(obj_lst);
	if (obj_lst->light || obj_lst->sp)
		delete_light_sp_lst(obj_lst);
	if (obj_lst->pl || obj_lst->sq)
		delete_pl_sq_lst(obj_lst);
	if (obj_lst->cy || obj_lst->tr)
		delete_cy_tr_lst(obj_lst);
	free(obj_lst);
}
