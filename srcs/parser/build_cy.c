/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:59:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:05:26 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool cy_err(char **content)
{
	char *coords;
	char *vector;
	char *d;
	char *h;
	char *colors;

	coords = content[1];
	vector = content[2];
	d = content[3];
	h = content[4];
	colors = content[5];
	return ((coords_err(coords) && vector_err(vector )&& prop_err(d) &&		\
					 prop_err(h) && colors_err(colors) && !content[6]) ? true : false);
}

bool build_cy(char **content, t_lst *obj_lst)
{
	t_cy *cy;
	t_cy *cy_aux;

	if (!(cy_err(content)))
		return (false);
	if (!(cy = malloc(sizeof(t_cy))))
		return (false);
	coord_str_to_f(content[1], cy->coord);
	coord_str_to_f(content[2], cy->v_norm);
	cy->d = str_to_f(content[3]);
	cy->h = str_to_f(content[4]);
	color_str_to_i(content[5], cy->color);
	cy->next = NULL;
	if (!obj_lst->cy_lst)
		obj_lst->cy_lst = cy;
	else
		{
			cy_aux = obj_lst->cy_lst;
			while (cy_aux->next)
				cy_aux = cy_aux->next;
			cy_aux->next = cy;
		}
	return (true);
}
