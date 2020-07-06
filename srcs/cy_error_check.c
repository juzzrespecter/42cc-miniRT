/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:41:05 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 16:43:14 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool cy_error_check(char **scene_line)
{
	char *coord;
	char *vector;
	char *d;
	char *h;
	char  *color;

	if (!check_scene_array(scene_line, 6))
		return (false);
	coord = scene_line[1];
	vector = scene_line[2];
	d = scene_line[3];
	h = scene_line[4];
	color = scene_line[5];
	return (coord_check(coord) && vector_check(vector) && dim_check(d)	\
					&& dim_check(h) && color_check(color) ? true : false);
}
