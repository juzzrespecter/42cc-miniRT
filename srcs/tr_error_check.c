/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:43:34 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 19:15:49 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool tr_error_check(char **scene_line)
{
	char *first_coord;
	char *second_coord;
	char *third_coord;
	char *color;

	if (!check_scene_array(scene_line, 5))
		return (false);
	first_coord = scene_line[1];
	second_coord = scene_line[2];
	third_coord = scene_line[3];
	color = scene_line[4];
	printf("estado del tema: coord (%d), coord (%d), coord (%d), color (%d)\n", coord_check(first_coord), coord_check(second_coord), coord_check(third_coord), color_check(color));
	return (coord_check(first_coord) && coord_check(second_coord) \
										 && coord_check(third_coord)  && color_check(color) ? true : false);
}
