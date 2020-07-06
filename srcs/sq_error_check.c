/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sq_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:38:28 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 19:12:11 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool sq_error_check(char **scene_line)
{
	char *coord;
	char *vector;
	char *side;
	char *color;

	if (!check_scene_array(scene_line, 5))
		return (false);
	coord = scene_line[1];
	vector = scene_line[2];
	side = scene_line[3];
	color = scene_line[4];
	printf("estado del tema: coord (%d), vector (%d), dim (%d), color (%d)\n", coord_check(coord), vector_check(vector), dim_check(side), color_check(color));
	return (coord_check(coord) && vector_check(vector) && dim_check(side)	\
										 && color_check(color) ? true : false);
}
