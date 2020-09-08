/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:18:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/08 19:38:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray *pl_loop(t_pl *pl, t_ray *ray)
{
	while (pl)
	{
		collision_plane(pl, ray);
		pl = pl->next;
	}
	return (ray);
}

t_ray *collision_plane(t_pl *pl, t_ray *ray)
{
	t_vector point;

	if (!(point_in_plane(pl->orientation, pl->coord, ray, &point)))
		return (NULL);
	point_found(point, pl->orientation, pl->color, ray);
	return (ray);
}
