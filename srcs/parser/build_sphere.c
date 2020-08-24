/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:05:50 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 18:16:21 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void add_sp_to_back(t_objlst *obj_lst, t_sp *sp)
{
	t_sp *sp_aux;

	sp_aux = obj_lst->sp;
	if (!sp_aux)
		obj_lst->sp = sp;
	else
		{
			while (sp_aux->next)
				sp_aux = sp_aux->next;
			sp_aux->next = sp;
		}
}

bool build_sphere(char **scene_line, t_objlst *obj_lst)
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
	array_char_to_float(sp->center, coord);
	sp->d = char_to_float(d);
	char_to_color(sp->color, color);
	sp->next = NULL;
	add_sp_to_back(obj_lst, sp);
	return (true);
}
