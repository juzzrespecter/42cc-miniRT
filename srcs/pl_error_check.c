/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:34:27 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 16:40:40 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool pl_error_check(char **scene_line)
{
	char *coord;
	char *vector;
	char *color;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	vector = scene_line[2];
	color = scene_line[3];
	return (coord_check(coord) && vector_check(vector) \
					&& color_check(color) ? true : false);
}
