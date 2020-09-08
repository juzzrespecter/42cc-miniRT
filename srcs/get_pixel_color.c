/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:24:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/08 18:21:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//chapuza en linea 31, probablemente se tenga que cambiar cuando cueste un
//puto cristo renderizar una escena

/*static bool blocked_by_an_object(t_olst *olst, t_ray *ray, float *l_coord)
{
	t_ray light_ray;
	int i;

	i = 0;
	while (i < 3)
		{
			light_ray.dir[i] = l_coord[i] - ray->point_coord[i];
			light_ray.orig[i] = ray->point_coord[i];
			i++;
		}
	normalize(light_ray.dir);
	light_ray.point_found = false;
	search_for_collision(olst, &light_ray);
	return (light_ray.point_found ? true : false);
	}*/

static t_color diff_lightning_sum(t_light *l, t_ray *ray, t_color diff_lightning)
{
	float v_dot_product;
	t_vector light_vector;

	light_vector = v_normalize(v_sub(l->coord, ray->point));
	v_dot_product = ft_max(0, v_dot(light_vector, ray->normal));

	//printf("\nlcoord: (%.2f, %.2f, %.2f), raypoint: (%.2f, %.2f, %.2f)\n", l->coord.x, l->coord.y, l->coord.z, ray->point.x, ray->point.y, ray->point.z);
	//printf("lv: (%.2f, %.2f, %.2f), rn: (%.2f, %.2f, %.2f), dot (%.2f)\n\n", light_vector.x, light_vector.y, light_vector.z, ray->normal.x, ray->normal.y, ray->normal.z, v_dot_product);	
	diff_lightning.r += ((l->color.r / 255) * l->bright * v_dot_product) * 255;
	diff_lightning.g += ((l->color.g / 255) * l->bright * v_dot_product) * 255;
	diff_lightning.b += ((l->color.b / 255) * l->bright * v_dot_product) * 255;
	
	diff_lightning.r = ft_min(diff_lightning.r, 255);
	diff_lightning.g = ft_min(diff_lightning.g, 255);
	diff_lightning.b = ft_min(diff_lightning.b, 255);
	return (diff_lightning);
}

unsigned int get_pixel_color(t_olst *olst, t_ray *ray)
{
	t_light *light;
	t_amb *amb;
	t_color amb_lightning;
	t_color diff_lightning;
	t_color object_color;
	unsigned int color;

	light = olst->light;
	amb = olst->amb;
	diff_lightning.r = 0;
	diff_lightning.g = 0;
	diff_lightning.b = 0;
	color = 0;
	while (light)
		{
			//if (!blocked_by_an_object(olst, ray, light->coord))
			diff_lightning = diff_lightning_sum(light, ray, diff_lightning);
			light = light->next;
		}
	amb_lightning.r = ((amb->color.r / 255) * amb->bright) * 255;
	amb_lightning.g = ((amb->color.g / 255) * amb->bright) * 255;
	amb_lightning.b = ((amb->color.b / 255) * amb->bright) * 255;

	object_color.r = ((ray->color.r / 255) * (ft_min(255, (amb_lightning.r + diff_lightning.r)) / 255)) * 255; 
	object_color.g = ((ray->color.g / 255) * (ft_min(255, (amb_lightning.g + diff_lightning.g)) / 255)) * 255; 
	object_color.b = ((ray->color.b / 255) * (ft_min(255, (amb_lightning.b + diff_lightning.b)) / 255)) * 255; 

	color = (((object_color.b | (object_color.g << 8)) | (object_color.r << 16)) & 0xffffff);
	return (color);
}
