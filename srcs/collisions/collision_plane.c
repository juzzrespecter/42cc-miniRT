/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:18:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 16:19:16 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_3dvec *collision_plane(t_pl *pl, t_3dvec *ray)
{
	float point[3];
	float d;

	d = dot(pl->vector, pl->coord);
	if (!(find_point_in_a_plane(pl->vector, ray, d, point)))
		return (NULL);
	point_found(point_coord, pl->vector, pl->color, ray);
	return (ray);
}
