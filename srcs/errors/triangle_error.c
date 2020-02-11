/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:34:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/10 19:39:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int triangle_error(t_obj *tr_obj)
{
	char *coord_f;
	char *coord_s;
	char *coord_t;
	char *colors;

	coord_f = tr_obj->content[0];
	coord_s = tr_obj->content[1];
	coord_t = tr_obj->content[2];
	colors = tr_obj->content[3];
	return ((!tr_obj->content[4] && coords_error(coord_f) && coords_error(coord_s) \
					 &&  coords_error(coord_t) && colors_error(colors)) ? 1 : 0);
}
