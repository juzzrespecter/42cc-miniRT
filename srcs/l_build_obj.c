/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_build_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:12:54 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/07 19:07:26 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static void add_light_to_back(t_light **alight, t_light *light)
{
	t_light *light_aux;

	light_aux = *alight;
	if (!light_aux)
		*alight = light;
	else
		{
			while (light_aux->next)
				light_aux = light_aux->next;
			light_aux->next = light;
		}
}

bool l_build_obj(char **scene_line, t_objlst *obj_lst)
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
	if (!(light = malloc(sizeof(t_light *))))
		return (false);
	array_char_to_float(light->coord, coord);
	light->light = char_to_float(bright);
	char_to_color(light->color, color);
	light->next = NULL;
	add_light_to_back(&obj_lst->light, light);
	return (true);
}
