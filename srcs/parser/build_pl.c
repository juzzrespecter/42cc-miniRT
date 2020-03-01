/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_pl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:59:59 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:06:15 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool pl_err(char **content)
{
	char *coords;
	char *colors;
	char *vector;

	coords = content[1];
	vector = content[2];
	colors = content[3];
	return ((!content[4] && coords_err(coords) && colors_err(colors) && \
					 vector_err(vector)) ? true : false);
}

bool build_pl(char **content, t_lst *obj_lst)
{
	t_pl *plane;
	t_pl *plane_aux;

	if (!(pl_err(content)))
		return (false);
	if (!(plane = malloc(sizeof(t_pl))))
		return (false);
	coord_str_to_f(content[1], plane->coord);
	coord_str_to_f(content[2], plane->v_norm);
	color_str_to_i(content[3], plane->color);
	plane->next = NULL;
	if (!obj_lst->pl_lst)
		obj_lst->pl_lst = plane;
	else
		{
			plane_aux = obj_lst->pl_lst;
			while (plane_aux->next)
				plane_aux = plane_aux->next;
			plane_aux->next = plane;
		}
	return (true);
}
