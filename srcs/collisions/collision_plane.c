/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:18:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/16 16:28:50 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	collision_plane(t_vector normal, t_vector pl_point, t_ray *ray)
{
	float		t;
	t_vector	points_vector;
	float		eq_denom;

	if (fabs((eq_denom = v_dot(normal, ray->dir))) < 1e-6)
		return (-1);
	points_vector = v_sub(pl_point, ray->origin);
	if ((t = v_dot(normal, points_vector) / eq_denom) < 0)
		return (-1);
	return (t);
}
