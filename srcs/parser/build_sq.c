/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:00:23 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 16:00:25 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool sq_err(char **content)
{
	char *coords;
	char *vector;
	char *side;
	char *colors;

	coords = content[1];
	vector = content[2];
	side = content[3];
	colors = content[4];
	return ((!content[5] && coords_err(coords) && prop_err(side) \
					 && colors_err(colors) && vector_err(vector)) ? true : false);
}

bool build_sq(char **content, t_lst *obj_lst)
{
	t_sq *sq;
	t_sq *sq_aux;

	if (!(sq_err(content)))
		return (false);
	if (!(sq = malloc(sizeof(t_sq))))
		return (false);
	coord_str_to_f(content[1], sq->coord);
	coord_str_to_f(content[2], sq->v_norm);
	sq->size = str_to_f(content[3]);
	color_str_to_i(content[4], sq->color);
	sq->next = NULL;
	if (!obj_lst->sq_lst)
		obj_lst->sq_lst = sq;
	else
		{
			sq_aux = obj_lst->sq_lst;
			while (sq_aux->next)
				sq_aux = sq_aux->next;
			sq_aux->next = sq;
		}
	return (true);
}
