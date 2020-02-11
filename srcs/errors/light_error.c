/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:04:08 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 18:46:55 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int light_error(t_obj *light_obj)
{
	char *coords;
	char *bright;
	char *colors;

	coords = light_obj->content[0];
	bright = light_obj->content[1];
	colors = light_obj->content[2];
	return ((!light_obj->content[3] && colors_error(colors) && \
					 bright_error(bright) && coords_error(coords)) ? 1 : 0);
}
