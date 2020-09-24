/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:19:36 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_pl_to_back(t_objects *olst, t_pl *pl)
{
	t_pl *pl_aux;

	pl_aux = olst->pl;
	if (!pl_aux)
		olst->pl = pl;
	else
	{
		while (pl_aux->next)
			pl_aux = pl_aux->next;
		pl_aux->next = pl;
	}
}

bool		build_plane(char **scene_line, t_objects *olst)
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
	pl->coord = array_to_vector(coord);
	pl->orientation = v_normalize(array_to_vector(vector));
	pl->color = array_to_color(color);
	pl->next = NULL;
	add_pl_to_back(olst, pl);
	return (true);
}
