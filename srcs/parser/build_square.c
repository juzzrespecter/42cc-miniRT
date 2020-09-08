/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:06:09 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/08 17:54:29 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void add_sq_to_back(t_olst *olst, t_sq *sq)
{
	t_sq *sq_aux;

	sq_aux = olst->sq;
	if (!sq_aux)
		olst->sq = sq;
	else
		{
			while (sq_aux->next)
				sq_aux = sq_aux->next;
			sq_aux->next = sq;
		}
}

bool build_square(char **scene_line, t_olst *olst)
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
	sq->center = array_to_vector(coord);
	sq->orientation = v_normalize(array_to_vector(vector));
	sq->side = array_to_float(side);
	sq->color = array_to_color(color);
	sq->next = NULL;
	add_sq_to_back(olst, sq);
	return (true);
}
