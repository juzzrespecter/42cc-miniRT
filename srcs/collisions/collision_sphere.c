/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:20:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/25 19:41:02 by danrodri         ###   ########.fr       */
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

t_3dvec *collision_sphere(t_sp *sp, t_3dvec *ray)
{
	float oc_vector[3];
	float normal[3];
	float point[3];
	float t;
	float d;

	oc_vector[0] = sp->center[0] - ray->orig[0];
        oc_vector[1] = sp->center[1] - ray->orig[1];
        oc_vector[2] = sp->center[2] - ray->orig[2];
	if ((t = dot(oc_vector, ray->dir)) < 0 )
		return (NULL);
	if ((d = sqrt(dot(oc_vector, oc_vector) - pow(t, 2))) > sp->d / 2)
		return (NULL);
	if (d < sp->d / 2)
		t = choose_t(t, sp->d / 2, d);
	point[0] = ray->orig[0] + t * ray->dir[0];
	point[1] = ray->orig[1] + t * ray->dir[1];
	point[2] = ray->orig[2] + t * ray->dir[2];
	normal[0] = sp->center[0] - point[0];
	normal[1] = sp->center[1] - point[1];
	normal[2] = sp->center[2] - point[2];
	normalize(normal);
	point_found(point, normal, sp->color, ray);
	return (ray);
}
