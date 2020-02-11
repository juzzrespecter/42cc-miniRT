/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:31:02 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 20:06:31 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int cylinder_error(t_obj *cy_obj)
{
	char *coords;
	char *vector;
	char *d;
	char *h;
	char *colors;

	coords = cy_obj->content[0];
	vector = cy_obj->content[1];
	d = cy_obj->content[2];
	h = cy_obj->content[3];
	colors = cy_obj->content[4];
	return ((coords_error(coords) && vector_error(vector )&& prop_error(d) &&		\
					 prop_error(h) && colors_error(colors) && !cy_obj->content[5]) ? 1 : 0);
}
