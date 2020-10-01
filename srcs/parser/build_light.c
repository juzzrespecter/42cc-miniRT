/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:07 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:17:13 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_light_to_back(t_objs *olst, t_light *light)
{
	t_light	*light_aux;

	light_aux = olst->light;
	if (!light_aux)
		olst->light = light;
	else
	{
		while (light_aux->next)
			light_aux = light_aux->next;
		light_aux->next = light;
	}
}

bool		build_light(char **scene_line, t_objs *olst)
{
	char	*coord;
	char	*bright;
	char	*color;
	t_light	*light;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	bright = scene_line[2];
	color = scene_line[3];
	if (!(coord_check(coord) && light_check(bright) && color_check(color)))
		return (false);
	if (!(light = malloc(sizeof(t_light))))
		return (false);
	light->coord = array_to_vector(coord);
	light->bright = array_to_float(bright);
	light->color = array_to_color(color);
	light->next = NULL;
	add_light_to_back(olst, light);
	return (true);
}
