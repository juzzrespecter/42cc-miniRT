/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:24:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 19:58:55 by danrodri         ###   ########.fr       */
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

static void diff_lightning_sum(t_light *l, t_ray *ray, t_color diff_lightning)
{
	float v_dot_product;
	t_vector light_vector;

	light_vector = v_normalize(v_sub(l->coord, ray->point));
	v_dot_product = ft_max(0, v_dot(light_vector, ray->normal));
	diff_lightning.r += ((l->color.r / 255) * l->bright * v_dot_product) * 255;
	diff_lightning.g += ((l->color.g / 255) * l->bright * v_dot_product) * 255;
	diff_lightning.b += ((l->color.b / 255) * l->bright * v_dot_product) * 255;

	diff_lightning.r = ft_min(diff_lightning.r, 255);
	diff_lightning.g = ft_min(diff_lightning.g, 255);
	diff_lightning.b = ft_min(diff_lightning.b, 255);
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
			diff_lightning_sum(light, ray, diff_lightning);
			light = light->next;
		}
	amb_lightning.r = ((amb->color.r / 255) * amb->bright) * 255;
	amb_lightning.g = ((amb->color.g / 255) * amb->bright) * 255;
	amb_lightning.b = ((amb->color.b / 255) * amb->bright) * 255;

	object_color.r = ((ray->color.r / 255) * (ft_min(255, (amb_lightning.r + diff_lightning.r)) / 255)) * 255; 
	object_color.g = ((ray->color.g / 255) * (ft_min(255, (amb_lightning.g + diff_lightning.g)) / 255)) * 255; 
	object_color.b = ((ray->color.b / 255) * (ft_min(255, (amb_lightning.b + diff_lightning.b)) / 255)) * 255; 

	//printf("amb: (%d)  (%d)  (%d)\n", amb_lightning.r, amb_lightning[1], amb_lightning[2]);
   	//printf("diff: (%d)  (%d)  (%d)\n", diff_lightning.r, diff_lightning[1], diff_lightning[2]);
	color = (((object_color.b | (object_color.g << 8)) | (object_color.r << 16)) & 0xffffff);
	return (color);
}
