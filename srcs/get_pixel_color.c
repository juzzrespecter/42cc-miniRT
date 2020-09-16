/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:24:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/16 19:02:43 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//chapuza en linea 31, probablemente se tenga que cambiar cuando cueste un
//puto cristo renderizar una escena


//LIGHTNING LOOPS

static bool blocked_by_an_object(t_objects *o_lst, t_vector l, t_vector p)
{
	t_ray ray;

	ray.dir = v_normalize(v_sub(l, p));
	ray.origin = p;
	return (lightning_loops(&ray, o_lst));
}

static t_color diff_lightning_sum(t_light *l, t_point *p, t_color diff_lightning)
{
	float dot;
	t_vector l_dir;

	l_dir = v_normalize(v_sub(l->coord, p->coord));
	dot = ft_max(0, v_dot(l_dir, p->normal));
	diff_lightning.r += ft_min(((l->color.r / 255) * l->bright * dot) * 255, 255);
	diff_lightning.g += ft_min(((l->color.g / 255) * l->bright * dot) * 255, 255);
	diff_lightning.b += ft_min(((l->color.b / 255) * l->bright * dot) * 255, 255);	
	return (diff_lightning);
}

unsigned int get_pixel_color(t_objects *o_lst, t_point *point)
{
	t_light *light;
	t_color amb_lightning;
	t_color diff_lightning;
	t_color object_color;
	unsigned int color;

	if (point->t == -1)
		return (0);
	light = o_lst->light;
	diff_lightning.r = 0;
	diff_lightning.g = 0;
	diff_lightning.b = 0;
	color = 0;
	while (light)
		{
			if (blocked_by_an_object(o_lst, light->coord, point->coord) == false)
				diff_lightning = diff_lightning_sum(light, point, diff_lightning);
			light = light->next;
		}
	amb_lightning.r = o_lst->amb->color.r * o_lst->amb->bright;
	amb_lightning.g = o_lst->amb->color.g * o_lst->amb->bright;
	amb_lightning.b = o_lst->amb->color.b * o_lst->amb->bright;
	object_color.r = point->color.r * (ft_min(255, ((amb_lightning.r * 255) + (diff_lightning.r * 255)))) / 255; 
	object_color.g = point->color.g * (ft_min(255, ((amb_lightning.g * 255) + (diff_lightning.g * 255)))) / 255; 
	object_color.b = point->color.b * (ft_min(255, ((amb_lightning.b * 255) + (diff_lightning.b * 255)))) / 255; 
	color = ((((int)(object_color.b * 255) | ((int)(object_color.g * 255) << 8)) | ((int)(object_color.r * 255) << 16)) & 0xffffff);
	return (color);
}
