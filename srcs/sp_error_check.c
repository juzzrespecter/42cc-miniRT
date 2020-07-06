/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:16:09 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 19:42:06 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minirt.h"

bool sp_error_check(char **scene_line)
{
	char *coord;
	char *d;
	char *color;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	d = scene_line[2];
	color = scene_line[3];
		printf("SPHERE: cestado del tema: coord (%d), dim (%d), color (%d)\n", coord_check(coord), dim_check(d), color_check(color));
	return (coord_check(coord) && dim_check(d) && color_check(color) ? true : false);
}
