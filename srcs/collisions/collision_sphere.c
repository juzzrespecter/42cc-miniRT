/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:20:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/28 19:48:05 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	choose_t(float t, float r, float d)
{
	float	near_t;
	float	far_t;
	float	hc_t;

	hc_t = sqrt(pow(r, 2) - pow(d, 2));
	near_t = t - hc_t;
	far_t = t + hc_t;
	return ((near_t) > 0 ? near_t : far_t);
}

float			collision_sphere(t_sp *sp, t_ray *ray)
{
	t_vector	oc_vector;
	float		t;
	float		d;

	oc_vector = v_sub(sp->center, ray->origin);
	if ((t = v_dot(oc_vector, ray->dir)) < 0)
		return (-1);
	if ((d = sqrt(v_dot(oc_vector, oc_vector) - pow(t, 2))) > sp->d / 2)
		return (-1);
	if (d < sp->d / 2)
		t = choose_t(t, sp->d / 2, d);
	return (t);
}
