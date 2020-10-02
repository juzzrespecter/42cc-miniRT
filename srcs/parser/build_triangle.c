/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:06:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 19:24:17 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_tr_to_back(t_objs *olst, t_tr *tr)
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

bool		build_triangle(char **scene_line, t_objs *olst)
{
	char *p1;
	char *p2;
	char *p3;
	char *color;
	t_tr *tr;

	if (!check_scene_array(scene_line, 5))
		return (false);
	p1 = scene_line[1];
	p2 = scene_line[2];
	p3 = scene_line[3];
	color = scene_line[4];
	if (!(coord_check(p1) && coord_check(p2) && \
				coord_check(p3) && color_check(color)))
		return (false);
	if (!(tr = malloc(sizeof(t_tr))))
		return (false);
	tr->p1 = array_to_vector(p1);
	tr->p2 = array_to_vector(p2);
	tr->p3 = array_to_vector(p3);
	tr->color = array_to_color(color);
	tr->next = NULL;
	add_tr_to_back(olst, tr);
	return (true);
}
