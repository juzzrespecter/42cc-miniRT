/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:59:46 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:33:00 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool light_err(char **content)
{
	char *coords;
	char *bright;
	char *colors;

	coords = content[1];
	bright = content[2];
	colors = content[3];
	return ((!content[4] && colors_err(colors) && \
					 bright_err(bright) && coords_err(coords)) ? true : false);
}

bool build_l(char **content, t_lst *obj_lst)
{
	t_l *light;
	t_l *light_aux;

	if (!(light_err(content)))
		return (false);
	if (!(light = malloc(sizeof(t_c))))
		return (false);
	coord_str_to_f(content[1], light->coord);
	light->bright = bright_str_to_f(content[2]);
	color_str_to_i(content[3], light->l_color);
	light->next = NULL;
	if (!obj_lst->l_lst)
		obj_lst->l_lst = light;
	else
		{
			light_aux = obj_lst->l_lst;
			while (light_aux->next)
				light_aux = light_aux->next;
			light_aux->next = light;
		}
	return (true);
}
