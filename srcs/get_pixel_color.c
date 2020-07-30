/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:24:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/30 19:43:41 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//chapuza en linea 31, probablemente se tenga que cambiar cuando cueste un
//puto cristo renderizar una escena

/*static bool blocked_by_an_object(t_objlst *obj_lst, t_3dvec *ray, float *l_coord)
{
	t_3dvec light_ray;
	int i;

	i = 0;
	while (i < 3)
		{
			light_ray.dir[i] = l_coord[i] - ray->point_coord[i];
			light_ray.orig[i] = ray->point_coord[i];
			i++;
		}
	norm(light_ray.dir);
	light_ray.point_found = false;
	search_for_collision(obj_lst, &light_ray);
	return (light_ray.point_found ? true : false);
	}*/

static void add_light_to_color(t_light *l, t_3dvec *ray, unsigned int *color)
{
	float light_ray[3];
	unsigned char color_rgb[3];
	float nl_angle;
	int i;

	i = 0;
	while (i < 3)
		{
			light_ray[i] = l->coord[i] - ray->point_coord[i];
			i++;
		}
	norm(light_ray);
	color_rgb[0] = (unsigned char)*color;
	color_rgb[1] = (*color >> 8) & 0xff;
	color_rgb[2] = (*color >> 16) & 0xff;
	nl_angle = ft_max(dot(light_ray, ray->normal_vector), 0.0);
	i = 0;
	while (i < 3)
		{
			color_rgb[i] *= (l->light * (l->color[i] / 255) * nl_angle);
			i++;
		}
	*color = color_rgb[0] + (color_rgb[1] << 8) + (color_rgb[2] << 16) & 0xffffff;
}

static unsigned int amb_light(t_amb *amb, unsigned char *color_rgb)
{
	unsigned char  amb_color[3];
	unsigned int color;
	int i;

	i = 0;
	while (i < 3)
		{
			amb_color[i] = color_rgb[i] * ((amb->color[i] / 255) * amb->light);
			i++;
		}
	color = amb_color[0] + (amb_color[1] << 8) + (amb_color[2] << 16) & 0xffffff;
	return (color);
}

unsigned int get_pixel_color(t_objlst *obj_lst, t_3dvec *ray)
{
	t_light *light;
	t_amb *amb;
	unsigned int color;

	light = obj_lst->light;
	amb = obj_lst->amb;
	color = amb_light(amb, ray->point_color);
	while (light)
		{
			//if (!blocked_by_an_object(obj_lst, ray, light->coord))
				add_light_to_color(light, ray, &color);
			light = light->next;
		}
	return (color);
}
