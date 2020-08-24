/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:06:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 18:18:35 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

bool build_triangle(char **scene_line, t_objlst *obj_lst)
{
	char *first_point;
	char *second_point;
	char *third_point;
	char *color;
	t_tr *tr;

	if (!check_scene_array(scene_line, 5))
		return (false);
	first_point = scene_line[1];
	second_point = scene_line[2];
	third_point = scene_line[3];
	color = scene_line[4];
	if (!(coord_check(first_point) && coord_check(second_point) \
				 && coord_check(third_point)  && color_check(color)))
		return (false);
	if (!(tr = malloc(sizeof(t_tr))))
		return (false);
	array_char_to_float(tr->first_point, first_point);
	array_char_to_float(tr->second_point, second_point);
	array_char_to_float(tr->third_point, third_point);
	char_to_color(tr->color, color);
	tr->next = NULL;
	add_tr_to_back(obj_lst, tr);
	return (true);
}
