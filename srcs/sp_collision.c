/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_collision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:07:20 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 19:27:19 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//view matrix para transformar el vector oc y el rayo en las coordenadas
//de la camara

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

static void get_point(float *point_coord, float t, t_3dvec *ray)
{
	int i;

	i = 0;
	while (i < 3)
		{
			point_coord[i] = ray->orig[i] + t * ray->dir[i];
			i++;
		}
}

t_3dvec *sp_collision(t_sp *sp, t_3dvec *ray)
{
	float oc_v[4];
	float point_coord[3];
	float t;
	float d;
	int i;

	i = 0;
	while (i < 3)
		{
			oc_v[i] = sp->coord[i] - ray->orig[i];
			i++;
		}
	if ((t = dot(oc_v, ray->dir)) < 0 )
		return (NULL);
	if ((d = sqrt(dot(oc_v, oc_v) + pow(t, 2))) > sp->d / 2)
		return (NULL);
	if (d < sp->d / 2)
		t = choose_t(t, sp->d / 2, d);
	get_point(point_coord, t, ray);
	found_point(point_coord, sp->color, sp->coord, ray);
	return (ray);
}
