/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:05:50 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 17:53:03 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void add_sp_to_back(t_olst *olst, t_sp *sp)
{
	t_sp *sp_aux;

	sp_aux = olst->sp;
	if (!sp_aux)
		olst->sp = sp;
	else
		{
			while (sp_aux->next)
				sp_aux = sp_aux->next;
			sp_aux->next = sp;
		}
}

bool build_sphere(char **scene_line, t_olst *olst)
{
	char *coord;
	char *d;
	char *color;
	t_sp *sp;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	d = scene_line[2];
	color = scene_line[3];
	if (!(coord_check(coord) && dim_check(d) && color_check(color)))
		return (false);
	if (!(sp = malloc(sizeof(t_sp))))
		return (false);
	sp->center = array_to_vector(coord);
	sp->d = array_to_float(d);
	sp->color = array_to_color(color);
	sp->next = NULL;
	add_sp_to_back(olst, sp);
	return (true);
}
