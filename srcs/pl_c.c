/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:19:19 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/04 15:57:18 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point *pl_c(t_pl *pl, t_3dvec *ray)
{
	t_point *point;
	float op_vec[3];
	float denom;
	float d;
	int i;

	if (!(point = malloc(sizeof(t_point))))
		return (NULL);
	point->p_coord = NULL;
	point->color = 0;
	point->next = NULL;
	denom = dot(ray->dir, pl->v_norm);
	if (denom < ROUND_ERR)
		return (point);
	i = 0;
	while (i < 3)
		{
			op_vec[i] = pl->coord[i] - ray->orig[i];
			i++;
		}
	d = dot(op_vec, pl->v_norm) / denom;
	if (d < 0)
		return (point);
	if (!(point->p_coord = malloc(sizeof(float) * 3)))
		return (NULL);
	i = 0;
	while (i < 3)
		{
			point->p_coord[i] = ray->orig[i] + (d * ray->dir[i]);
			i++;
		}
	point->color = rgb_conv(pl->color);
	return (point);
}
