/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:06:09 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 18:16:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void add_sq_to_back(t_objlst *obj_lst, t_sq *sq)
{
	t_sq *sq_aux;

	sq_aux = obj_lst->sq;
	if (!sq_aux)
		obj_lst->sq = sq;
	else
		{
			while (sq_aux->next)
				sq_aux = sq_aux->next;
			sq_aux->next = sq;
		}
}

bool build_square(char **scene_line, t_objlst *obj_lst)
{
	char *coord;
	char *vector;
	char *side;
	char *color;
	t_sq *sq;

	if (!check_scene_array(scene_line, 5))
		return (false);
	coord = scene_line[1];
	vector = scene_line[2];
	side = scene_line[3];
	color = scene_line[4];
	if (!(coord_check(coord) && vector_check(vector) && dim_check(side) \
				 && color_check(color)))
		return (false);
	if (!(sq = malloc(sizeof(t_sq))))
		return (false);
	array_char_to_float(sq->center, coord);
	array_char_to_float(sq->normal, vector);
	sq->side = char_to_float(side);
	char_to_color(sq->color, color);
	sq->next = NULL;
	add_sq_to_back(obj_lst, sq);
	return (true);
}
