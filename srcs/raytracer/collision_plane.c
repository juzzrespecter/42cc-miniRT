/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:18:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 18:09:42 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	collision_plane(t_vector normal, t_vector pl_point, t_ray *ray)
{
	double		t;
	t_vector	points_vector;
	double		eq_denom;

	if (fabs((eq_denom = v_dot(normal, ray->dir))) < 1e-4)
		return (-1);
	points_vector = v_sub(pl_point, ray->origin);
	t = v_dot(normal, points_vector) / eq_denom;
	if (t < 1e-3)
		return (-1);
	return (t);
}
