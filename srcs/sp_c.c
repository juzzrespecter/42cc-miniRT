/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:16:11 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/03 19:17:44 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point *one_collision(float sqrt_ec, t_point *point, t_3dvec *ray, float *oc_vec)
{
	float d;
	int i;

	d = -(dot(ray->dir, oc_vec));
	i = 0;
	while (i < 3)
		{
			point->p_coord[i] = ray->orig[i] + (d * ray->dir[i]);
			i++;
		}
	point->color = rgb_conv(sp->color);
	return (point);
}

t_point *two_collisions(float sqrt_ec, t_point *point, t_3dvec *ray, float *oc_vec)
{
	float d_a;
	float d_b;
	float d;
	int i;

	i = 0;
	d_a = -(dot(rayo.dir, oc)) - sqrt(sqrt_ec);
	d_b = -(dot(rayo.dir, oc)) + sqrt(sqrt_ec);
	if (d_a < d_b)
		d = d_a;
	else
		d = d_b;
	while (i < 3)
		{
			point->p_coord[i] = ray->orig[i] + (d * ray->dir[i]);
			i++;
		}
	point->color = rgb_conv(sp->color);
	return (point);
}

t_point *sp_c(t_sp *sp, t_3dvec *ray)
{
	t_point *point;
	float oc_vec[3];
	float sqrt_ec;
	int i;

	if (!(point = malloc(sizeof(t_point))))
		return (NULL);
	point->p_coord = NULL;
	point->color = 0;
	point->next = NULL;
	i = 0;
	while (i < 3)
		{
			oc_vec[i] = ray->coord[i] - sp->coord[i];
			i++;
		}
	sqrt_ec = pow(dot(ray->dir, oc_vec), 2) - (pow(norm(oc_vec), 2) - pow(sp->d / 2, 2));
	if (sqrt_ec < 0)
		return (point);
	if (!(point->p_coord = malloc(sizeof(float) * 3)))
				return (NULL);
	if (!sqrt_ec)
		return (one_collision(point, sqrt_ec, ray, oc_vec));
	else
		return (two_collisions(point, sqrt_ec, ray, oc_vec));
}
