/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:00:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:33:59 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool tr_err(char **content)
{
	char *coord_f;
	char *coord_s;
	char *coord_t;
	char *colors;

	coord_f = content[1];
	coord_s = content[2];
	coord_t = content[3];
	colors = content[4];
	return ((!content[5] && coords_err(coord_f) && coords_err(coord_s) \
					 &&  coords_err(coord_t) && colors_err(colors)) ? 1 : 0);
}

bool build_tr(char **content, t_lst *obj_lst)
{
	t_tr *tr;
	t_tr *tr_aux;

	if (!(tr_err(content)))
		return (false);
	if (!(tr = malloc(sizeof(t_tr))))
		return (false);
	coord_str_to_f(content[1], tr->p1);
	coord_str_to_f(content[2], tr->p2);
	coord_str_to_f(content[3], tr->p3);
	color_str_to_i(content[4], tr->color);
	tr->next = NULL;
	if (!obj_lst->tr_lst)
		obj_lst->tr_lst = tr;
	else
		{
			tr_aux = obj_lst->tr_lst;
			while (tr_aux->next)
				tr_aux = tr_aux->next;
			tr_aux->next = tr;
		}
	return (true);
}
