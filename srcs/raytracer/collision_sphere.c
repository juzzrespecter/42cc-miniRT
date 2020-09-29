/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:20:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 18:09:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	choose_t(double t, double r, double d)
{
	double	near_t;
	double	far_t;
	double	hc_t;

	hc_t = sqrt(pow(r, 2) - pow(d, 2));
	near_t = t - hc_t;
	far_t = t + hc_t;
	return ((near_t) > 0 ? near_t : far_t);
}

double			collision_sphere(t_sp *sp, t_ray *ray)
{
	t_vector	oc_vector;
	double		t;
	double		d;

	oc_vector = v_sub(sp->center, ray->origin);
	if ((t = v_dot(oc_vector, ray->dir)) < 0)
		return (-1);
	if ((d = sqrt(v_dot(oc_vector, oc_vector) - pow(t, 2))) > sp->d / 2)
		return (-1);
	if (d < sp->d / 2)
		t = choose_t(t, sp->d / 2, d);
	return (t);
}
