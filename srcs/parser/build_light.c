/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 18:13:12 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void add_light_to_back(t_objlst *obj_lst, t_light *light)
{
	t_light *light_aux;

	light_aux = obj_lst->light;
	if (!light_aux)
		obj_lst->light = light;
	else
		{
			while (light_aux->next)
				light_aux = light_aux->next;
			light_aux->next = light;
		}
}

bool build_light(char **scene_line, t_objlst *obj_lst)
{
	char *coord;
	char *bright;
	char *color;
	t_light *light;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	bright = scene_line[2];
	color = scene_line[3];
	if (!(coord_check(coord) && light_check(bright) &&  color_check(color)))
			return (false);
	if (!(light = malloc(sizeof(t_light))))
		return (false);
	array_char_to_float(light->coord, coord);
	light->bright = char_to_float(bright);
	char_to_color(light->color, color);
	light->next = NULL;
	add_light_to_back(obj_lst, light);
	return (true);
}
