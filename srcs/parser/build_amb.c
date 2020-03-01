/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_amb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:54:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:28:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool amb_err(char **content)
{
	int i;
	char *bright;
	char *colors;

	i = 0;
	while (content[i + 1])
		i++;
	if (i != 2)
		return (0);
	bright = content[1];
	colors = content[2];
	return ((bright_err(bright) && colors_err(colors) && !content[3]) ? true : false);
}

bool build_amb(char **content, t_lst *obj_lst)
{
	t_a *amb;

	if (!(amb_err(content)) || obj_lst->amb)
		return (false);
	if (!(amb = malloc(sizeof(t_a))))
		return (false);
	amb->bright = bright_str_to_f(content[1]);
	color_str_to_i(content[2], amb->a_color);
	obj_lst->amb = amb;
	return (true);
}
