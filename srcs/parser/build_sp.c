/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:00:12 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 16:00:13 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool sphere_err(char **content)
{
	char *coords;
	char *d;
	char *colors;

	coords = content[1];
	d = content[2];
	colors = content[3];
	return ((!content[4] && coords_err(coords) && prop_err(d) && \
					 colors_err(colors)) ? true : false);
}

bool build_sp(char **content, t_lst *obj_lst)
{
	t_sp *sp;
	t_sp *sp_aux;

	if (!sphere_err(content))
		return (false);
	if (!(sp = malloc(sizeof(t_sp))))
		return (false);
	coord_str_to_f(content[1], sp->coord);
	sp->d = str_to_f(content[2]);
	color_str_to_i(content[3], sp->color);
	sp->next = NULL;
	if (!obj_lst->sp_lst)
		obj_lst->sp_lst = sp;
	else
		{
			sp_aux = obj_lst->sp_lst;
			while (sp_aux->next)
				sp_aux = sp_aux->next;
			sp_aux->next = sp;

		}
	return (true);
}
