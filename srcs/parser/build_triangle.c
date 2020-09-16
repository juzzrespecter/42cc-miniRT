/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:06:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/16 16:38:10 by danrodri         ###   ########.fr       */
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
	char *f_p;
	char *s_p;
	char *t_p;
	char *color;
	t_tr *tr;

	if (!check_scene_array(scene_line, 5))
		return (false);
	f_p = scene_line[1];
	s_p = scene_line[2];
	t_p = scene_line[3];
	color = scene_line[4];
	if (!(coord_check(f_p) && coord_check(s_p) \
				 && coord_check(t_p)  && color_check(color)))
		return (false);
	if (!(tr = malloc(sizeof(t_tr))))
		return (false);
	tr->f_p = array_to_vector(f_p);
	tr->s_p = array_to_vector(s_p);
	tr->t_p = array_to_vector(t_p);
	tr->color = array_to_color(color);
	tr->next = NULL;
	add_tr_to_back(olst, tr);
	return (true);
}
