/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_build_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:12:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/07 19:19:26 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void add_sp_to_back(t_sp **asp, t_sp *sp)
{
	t_sp *sp_aux;

	sp_aux = *asp;
	if (!sp_aux)
		*asp = sp;
	else
		{
			while (sp_aux->next)
				sp_aux = sp_aux->next;
			sp_aux->next = sp;
		}
}

bool sp_build_obj(char **scene_line, t_objlst *obj_lst)
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
	if (!(sp = malloc(sizeof(t_sp *))))
		return (false);
	array_char_to_float(sp->coord, coord);
	sp->d = char_to_float(d);
	char_to_color(sp->color, color);
	sp->next = NULL;
	add_sp_to_back(&obj_lst->sp, sp);
	return (true);
}
