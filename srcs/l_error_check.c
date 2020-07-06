/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_error_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:08:30 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 16:14:16 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool l_error_check(char **scene_line)
{
	char *coord;
	char *light;
	char *color;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[0];
	light = scene_line[1];
	color = scene_line[2];
	return (coord_check(coord) && light_check(light) &&\
					color_check(color) ? true : false);
}
