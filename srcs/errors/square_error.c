/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:24:03 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 19:10:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int square_error(t_obj *sq_obj)
{
	char *coords;
	char *vector;
	char *side;
	char *colors;

	coords = sq_obj->content[0];
	vector = sq_obj->content[1];
	side = sq_obj->content[2];
	colors = sq_obj->content[3];
	return ((!sq_obj->content[4] && coords_error(coords) && prop_error(side) \
					 && colors_error(colors) && vector_error(vector)) ? 1 : 0);
}
