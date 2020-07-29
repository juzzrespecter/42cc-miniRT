/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:24:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 20:37:48 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//chapuza en linea 31, probablemente se tenga que cambiar cuando cueste un
//puto cristo renderizar una escena

static bool blocked_by_an_object(t_objlst *obj_lst, t_3dvec *ray, float *l_coord)
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
}

static void add_light_to_color(t_light *l, t_3dvec *ray, unsigned int *color)
{
	float light_ray[3];
	unsigned char color_rgb[3];
	unsigned char new_color[3];
	int i;

	i = 0;
	while (i < 3)
		{
			light_ray[i] = l->coord[i] - ray->point_coord[i];
			i++;
		}
	norm(light_ray);
	color_rgb[0] = color & 0x
	i = 0;
	while (i < 3)
		{
			color_rgb[i] =
		}
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
}

unsigned int get_pixel_color(t_objlst *obj_lst, t_3dvec *ray)
{
	//light loop
	t_light *light;
	t_amb *amb;
	unsigned int color;

	light = obj_lst->light;
	amb = obj_lst->amb;
	color = amb_light(amb, ray->point_color);
	while (light)
		{
			if (!blocked_by_an_object(obj_lst, ray, light->coord))
				add_light_to_color(light, ray, &color);
			light = light->next;
		}
}
