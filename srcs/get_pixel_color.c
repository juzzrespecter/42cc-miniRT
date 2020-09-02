/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:24:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/02 19:12:35 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	normalize(light_ray.dir);
	light_ray.point_found = false;
	search_for_collision(obj_lst, &light_ray);
	return (light_ray.point_found ? true : false);
	}*/

static void diff_lightning_sum(t_light *l, t_3dvec *ray, unsigned char *diff_lightning)
{
	float dot_product;
	float light_vector[3];

	light_vector[0] = l->coord[0] - ray->point[0];
	light_vector[1] = l->coord[1] - ray->point[1];
	light_vector[2] = l->coord[2] - ray->point[2];

	dot_product = ft_max(0, dot(light_vector, ray->normal));
	diff_lightning[0] += ((l->color[0] / 255) * l->bright * dot_product) * 255;
	diff_lightning[1] += ((l->color[1] / 255) * l->bright * dot_product) * 255;
	diff_lightning[2] += ((l->color[2] / 255) * l->bright * dot_product) * 255;

	diff_lightning[0] = ft_min(diff_lightning[0], 255);
	diff_lightning[1] = ft_min(diff_lightning[1], 255);
	diff_lightning[2] = ft_min(diff_lightning[2], 255);
}

unsigned int get_pixel_color(t_objlst *obj_lst, t_3dvec *ray)
{
	t_light *light;
	t_amb *amb;
	unsigned char amb_lightning[3];
	unsigned char diff_lightning[3];
	unsigned char object_color[3];
	unsigned int color;

	light = obj_lst->light;
	amb = obj_lst->amb;
	diff_lightning[0] = 0;
	diff_lightning[1] = 0;
	diff_lightning[2] = 0;
	color = 0;
	while (light)
		{
			//if (!blocked_by_an_object(obj_lst, ray, light->coord))
			diff_lightning_sum(light, ray, diff_lightning);
			light = light->next;
		}
	amb_lightning[0] = ((amb->color[0] / 255) * amb->bright) * 255;
	amb_lightning[1] = ((amb->color[1] / 255) * amb->bright) * 255;
	amb_lightning[2] = ((amb->color[2] / 255) * amb->bright) * 255;

	object_color[0] = ((ray->color[0] / 255) * (ft_min(255, (amb_lightning[0] + diff_lightning[0])) / 255)) * 255; 
	object_color[1] = ((ray->color[1] / 255) * (ft_min(255, (amb_lightning[1] + diff_lightning[1])) / 255)) * 255; 
	object_color[2] = ((ray->color[2] / 255) * (ft_min(255, (amb_lightning[2] + diff_lightning[2])) / 255)) * 255; 

	//printf("amb: (%d)  (%d)  (%d)\n", amb_lightning[0], amb_lightning[1], amb_lightning[2]);
   	//printf("diff: (%d)  (%d)  (%d)\n", diff_lightning[0], diff_lightning[1], diff_lightning[2]);
	color = (((object_color[2] | (object_color[1] << 8)) | (object_color[0] << 16)) & 0xffffff);
	return (color);
}
