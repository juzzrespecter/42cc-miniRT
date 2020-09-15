/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:24:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 19:46:02 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//chapuza en linea 31, probablemente se tenga que cambiar cuando cueste un
//puto cristo renderizar una escena

static bool blocked_by_an_object(t_objects *o_lst, t_ray *ray, t_vector l_coord)
{
	t_ray light_ray;

	light_ray->dir = v_normalize(v_sub(l_coord, ray->point));
	search_for_collision(olst, &light_ray);
	return (light_ray.point_found ? true : false);
}

static t_color diff_lightning_sum(t_light *l, t_ray *ray, t_color diff_lightning)
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
	return (diff_lightning);
}

unsigned int get_pixel_color(t_objects *o_lst, t_ray *ray)
{
	t_light *light;
	t_color amb_lightning;
	t_color diff_lightning;
	t_color object_color;
	unsigned int color;

	light = o_lst->light;
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
	amb_lightning.r = ((o_lst->amb->color.r / 255) * o_lst->amb->bright) * 255;
	amb_lightning.g = ((o_lst->amb->color.g / 255) * o_lst->amb->bright) * 255;
	amb_lightning.b = ((o_lst->amb->color.b / 255) * o_lst->amb->bright) * 255;

	object_color.r = ((ray->color.r / 255) * (ft_min(255, (amb_lightning.r + diff_lightning.r)) / 255)) * 255; 
	object_color.g = ((ray->color.g / 255) * (ft_min(255, (amb_lightning.g + diff_lightning.g)) / 255)) * 255; 
	object_color.b = ((ray->color.b / 255) * (ft_min(255, (amb_lightning.b + diff_lightning.b)) / 255)) * 255; 

	color = (((object_color.b | (object_color.g << 8)) | (object_color.r << 16)) & 0xffffff);
	return (color);
}
