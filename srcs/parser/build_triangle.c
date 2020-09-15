/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:06:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 17:57:13 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void add_tr_to_back(t_objects *olst, t_tr *tr)
{
	t_tr *tr_aux;

	tr_aux = olst->tr;
	if (!tr_aux)
		olst->tr = tr;
	else
		{
			while (tr_aux->next)
				tr_aux = tr_aux->next;
			tr_aux->next = tr;
		}
}

bool build_triangle(char **scene_line, t_objects *olst)
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
	tr->first_point = array_to_vector(first_point);
	tr->second_point = array_to_vector(second_point);
	tr->third_point = array_to_vector(third_point);
	tr->color = array_to_color(color);
	tr->next = NULL;
	add_tr_to_back(olst, tr);
	return (true);
}
