/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:03:10 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:27 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_cy_to_back(t_objs *olst, t_cy *cy)
{
	t_cy	*cy_aux;

	cy_aux = olst->cy;
	if (!cy_aux)
		olst->cy = cy;
	else
	{
		while (cy_aux->next)
			cy_aux = cy_aux->next;
		cy_aux->next = cy;
	}
}

bool		build_cylinder(char **scene_line, t_objs *olst)
{
	t_cy	*cy;

	if (!check_scene_array(scene_line, 6))
		return (false);
	if (!(coord_check(scene_line[1]) && vector_check(scene_line[2]) \
				&& dim_check(scene_line[3]) && dim_check(scene_line[4]) \
				&& color_check(scene_line[5])))
		return (false);
	if (!(cy = malloc(sizeof(t_cy))))
		return (false);
	cy->coord = array_to_vector(scene_line[1]);
	cy->orientation = v_normalize(array_to_vector(scene_line[2]));
	cy->d = array_to_float(scene_line[3]);
	cy->h = array_to_float(scene_line[4]);
	cy->color = array_to_color(scene_line[5]);
	cy->next = NULL;
	add_cy_to_back(olst, cy);
	return (true);
}
