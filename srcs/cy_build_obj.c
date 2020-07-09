/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_build_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:43:10 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/09 18:06:46 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void add_cy_to_back(t_objlst *obj_lst, t_cy *cy)
{
	t_cy *cy_aux;

	cy_aux = obj_lst->cy;
	if (!cy_aux)
		obj_lst->cy = cy;
	else
		{
			while (cy_aux->next)
				cy_aux = cy_aux->next;
			cy_aux->next = cy;
		}
}

bool cy_build_obj(char **scene_line, t_objlst *obj_lst)
{
	t_cy *cy;

	if (!check_scene_array(scene_line, 6))
		return (false);
	if (!(coord_check(scene_line[1]) && vector_check(scene_line[2]) \
				&& dim_check(scene_line[3]) && dim_check(scene_line[4]) \
				&& color_check(scene_line[5])))
		return (false);
	if (!(cy = malloc(sizeof(t_cy))))
		return (false);
	array_char_to_float(cy->coord, scene_line[1]);
	array_char_to_float(cy->vector, scene_line[2]);
	cy->d = char_to_float(scene_line[3]);
	cy->h = char_to_float(scene_line[4]);
	char_to_color(cy->color, scene_line[5]);
	cy->next = NULL;
	add_cy_to_back(obj_lst, cy);
	return (true);
}
