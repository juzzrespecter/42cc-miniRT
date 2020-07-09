/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_build_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:58:37 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/09 18:07:13 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void add_tr_to_back(t_objlst *obj_lst, t_tr *tr)
{
	t_tr *tr_aux;

	tr_aux = obj_lst->tr;
	if (!tr_aux)
		obj_lst->tr = tr;
	else
		{
			while (tr_aux->next)
				tr_aux = tr_aux->next;
			tr_aux->next = tr;
		}
}

bool tr_build_obj(char **scene_line, t_objlst *obj_lst)
{
	char *first_coord;
	char *second_coord;
	char *third_coord;
	char *color;
	t_tr *tr;

	if (!check_scene_array(scene_line, 5))
		return (false);
	first_coord = scene_line[1];
	second_coord = scene_line[2];
	third_coord = scene_line[3];
	color = scene_line[4];
	if (!(coord_check(first_coord) && coord_check(second_coord) \
				 && coord_check(third_coord)  && color_check(color)))
		return (false);
	if (!(tr = malloc(sizeof(t_tr))))
		return (false);
	array_char_to_float(tr->first_coord, first_coord);
	array_char_to_float(tr->second_coord, second_coord);
	array_char_to_float(tr->third_coord, third_coord);
	char_to_color(tr->color, color);
	tr->next = NULL;
	add_tr_to_back(obj_lst, tr);
	return (true);
}
