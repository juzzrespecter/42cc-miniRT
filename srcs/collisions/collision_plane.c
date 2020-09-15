/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:18:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 17:26:26 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray *pl_loop(t_pl *pl, t_ray *ray)
{
	bool found_point;

	found_point = false;
	while (pl)
	{
		if (collision_plane(pl, ray))
			found_point = true;
		pl = pl->next;
	}
	return (found_point ? ray : NULL);
}

t_ray *collision_plane(t_pl *pl, t_ray *ray)
{
	t_vector point;

	if (!(point_in_plane(pl->orientation, pl->coord, ray, &point)))
		return (NULL);
	point_found(point, pl->orientation, pl->color, ray);
	return (ray);
}
