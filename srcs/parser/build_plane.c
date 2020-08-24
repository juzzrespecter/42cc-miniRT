/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 18:15:09 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void add_pl_to_back(t_objlst *obj_lst, t_pl *pl)
{
	t_pl *pl_aux;

	pl_aux = obj_lst->pl;
	if (!pl_aux)
		obj_lst->pl = pl;
	else
		{
			while (pl_aux->next)
				pl_aux = pl_aux->next;
			pl_aux->next = pl;
		}
}

bool build_plane(char **scene_line, t_objlst *obj_lst)
{
	char *coord;
	char *vector;
	char *color;
	t_pl *pl;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	vector = scene_line[2];
	color = scene_line[3];
	if (!(coord_check(coord) && vector_check(vector) && color_check(color)))
		return (false);
	if (!(pl = malloc(sizeof(t_pl))))
		return (false);
	array_char_to_float(pl->coord, coord);
	array_char_to_float(pl->normal, vector);
	char_to_color(pl->color, color);
	pl->next = NULL;
	add_pl_to_back(obj_lst, pl);
	return (true);
}
