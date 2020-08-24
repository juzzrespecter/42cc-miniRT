/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_amb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:00:52 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 17:28:28 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool build_amb(char **scene_line, t_objlst *obj_lst)
{
	char *light;
	char *color;
	t_amb *amb;

	if (!check_scene_array(scene_line, 3) || obj_lst->amb)
		return (false);
	light = scene_line[1];
	color = scene_line[2];
	if (!(light_check(light) && color_check(color)))
		return (false);
	if (!(amb = malloc(sizeof(t_amb))))
		return (false);
	amb->bright = char_to_float(light);
	char_to_color(amb->color, color);
	obj_lst->amb = amb;
	return (true);
}
