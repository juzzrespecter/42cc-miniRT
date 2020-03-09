/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3dvec_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:46:15 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/06 19:42:14 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float dot(float *vec1, float *vec2)
{
	return ((vec1[0] * vec2[0]) + (vec1[1] * vec2[1]) + (vec1[2] * vec2[2]));
}

float norm(float *vec)
{
	return (sqrt(pow(vec[0], 2) + pow(vec[1], 2) + pow(vec[2], 2)));
}

t_3dvec *build_ray(float *orig, float *p)
{
	t_3dvec *ray;
	float ray_norm;
	int i;

	if (!(ray = malloc(sizeof(t_3dvec))))
		return (NULL);
	i = 0;
	while (i < 3)
		{
			ray->orig[i] = orig[i];
			ray->dir[i] = p[i] - orig[i];
			i++;
		}
	ray_norm = norm(ray->dir);
	i = 0;
	while (i < 3)
		{
			ray->dir[i] /= ray_norm;
			i++;
		}
	return (ray);
}

float dot_dist(float *p1, float *p2)
{
	float vec[3];
	int i;

	i = 0;
	while (i < 3)
		{
			vec[i] = p2[i] - p1[i];
			i++;
		}
	return (norm(vec));
}

float *cross(float *vec1, float *vec2)
{
	float *vec3;

	if (!(vec3 = malloc(sizeof(float) * 3)))
		return (NULL);
	vec3[0] = (vec1[1] * vec2[2]) - (vec1[2] * vec2[1]);
	vec3[1] = (vec1[2] * vec2[0]) - (vec1[0] * vec2[2]);
	vec3[2] = (vec1[0] * vec2[1]) - (vec1[1] * vec2[0]);
	return (vec3);
}
