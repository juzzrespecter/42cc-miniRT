/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:49:37 by danrodri          #+#    #+#             */
/*   Updated: 2020/08/24 17:55:08 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_3dvec *build_ray(float x, float y, t_cam *cam)
{
	float dir_screen[3];
	t_3dvec *ray;

	if (!(ray = malloc(sizeof(t_3dvec))))
		return (NULL);
	ray->point_found = false;
	dir_screen[0] = x;
	dir_screen[1] = y;
	dir_screen[2] = -1;
	//printf("\nCoord. SCREEN SPACE: (%f) (%f) (%f)\n", dir_screen[0], dir_screen[1], dir_screen[2]);
	normalize(dir_screen);
	vmprod(dir_screen, cam->m_c2w, ray->dir);
	normalize(ray->dir);
	//printf("Coord. WORLD SPACE: (%f) (%f) (%f)\n", ray->dir[0], ray->dir[1], ray->dir[2]);
	ray->orig[0] = cam->coord[0];
	ray->orig[1] = cam->coord[1];
	ray->orig[2] = cam->coord[2];
	return (ray);
}

static float x_pixel(t_data data, int x, int fov)
{
	float x_pixel;
	float NDC_pixel;
	float ratio;

	ratio = data.x_res / data.y_res;
	NDC_pixel = (x + 0.5) / data.x_res;
	x_pixel = (2 * NDC_pixel - 1)  * ratio * tan((fov / 2)  * M_PI / 180);
	return (x_pixel);
}

static float y_pixel(t_data data, int y, int fov)
{
	float y_pixel;
	float NDC_pixel;

	NDC_pixel = (y + 0.5) / data.y_res;
	y_pixel = (1 - 2 * NDC_pixel) * tan((fov / 2) * M_PI / 180);
	return (y_pixel);
}

char *draw_image(t_objlst *obj_lst, t_data data, char *img)
{
	t_3dvec *ray;
	int fov;
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	fov = obj_lst->cam->fov;
	while (data.y_res > y)
		{
			while (data.x_res > x)
				{
					i = (x * (data.bits_per_pixel / 8) + (y * data.size_line));
					ray = build_ray(x_pixel(data, x, fov), y_pixel(data, y, fov), obj_lst->cam);
					collision_searcher(obj_lst, ray);
					if (ray->point_found)
						*(unsigned int *)(img + i) = get_pixel_color(obj_lst, ray);
					else
						*(unsigned int *)(img + i) = 0;
					free(ray);
					x++;
				}
			x = 0;
			y++;
		}
	return (img);
}
