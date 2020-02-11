/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:58:43 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 19:00:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int plane_error(t_obj *pl_obj)
{
	char *coords;
	char *colors;
	char *vector;

	coords = pl_obj->content[0];
	vector = pl_obj->content[1];
	colors = pl_obj->content[2];
	return ((!pl_obj->content[3] && coords_error(coords) && colors_error(colors) && \
					 vector_error(vector)) ? 1 : 0);
}
