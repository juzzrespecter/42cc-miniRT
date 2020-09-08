/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:20:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:37:11 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float choose_t(float t, float r, float d)
{
	float near_t;
	float far_t;
	float hc_t;

	hc_t = sqrt(pow(r, 2) + pow(d, 2));
	near_t = t - hc_t;
	far_t = t + hc_t;
	return ((near_t) > 0 ? near_t : far_t);
}

t_ray *collision_sphere(t_sp *sp, t_ray *ray)
{
	t_vector oc_vector;
	t_vector normal;
	t_vector point;
	float t;
	float d;

	oc_vector = v_sub(sp->center, ray->origin);
	if ((t = v_dot(oc_vector, ray->dir)) < 0 )
		return (NULL);
	if ((d = sqrt(v_dot(oc_vector, oc_vector) - pow(t, 2))) > sp->d / 2)
		return (NULL);
	if (d < sp->d / 2)
		t = choose_t(t, sp->d / 2, d);
	point = v_add(ray->origin, v_scalar(ray->dir, t));
	normal = v_normalize(v_sub(point, sp->center));
	point_found(point, normal, sp->color, ray);
	return (ray);
}
