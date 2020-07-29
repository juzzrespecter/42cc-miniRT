/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 17:40:39 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 19:26:51 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

static void save_p_info(float *coord, unsigned char *color, float *obj_c, t_3dvec *ray)
{
	int i;

	i = 0;
	ray->point_found = true;
	while (i < 3)
		{
			ray->point_color[i] = color[i];
			ray->point_coord[i] = coord[i];
			ray->normal_vector[i] = coord[i] - obj_c[i];
			i++;
		}
	norm(ray->normal_vector);
}

void found_point(float *p_coord, unsigned char *p_color, float *obj_c, t_3dvec *ray)
{
	if (!ray->point_found)
		save_p_info(p_coord, p_color, obj_c, ray);
	else
		{
			if ((length(p_coord) - length(ray->point_coord)) < 0)
				save_p_info(p_coord, p_color, obj_c, ray);
		}
}
