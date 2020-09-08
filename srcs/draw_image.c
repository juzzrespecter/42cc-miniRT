/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 19:49:37 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/08 19:38:51 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray *build_ray(float x, float y, t_cam *cam)
{
	t_vector dir_screen;
	t_vector m_c2w[3];
	t_ray *ray;

	cam2world_matrix(cam->orientation,  m_c2w);
	if (!(ray = malloc(sizeof(t_ray))))
		return (NULL);
	ray->point_found = false;
	dir_screen.x = x;
	dir_screen.y = y;
	dir_screen.z = -1;
	dir_screen = v_normalize(dir_screen);
	ray->dir = v_normalize(vmprod(dir_screen, m_c2w));
	ray->origin = cam->coord;
	return (ray);
}

static float x_pixel(t_data *data, int x, int fov)
{
	float x_pixel;
	float NDC_pixel;
	float ratio;

	ratio = (float)data->res_x / (float)data->res_y;
	NDC_pixel = (x + 0.5) / data->res_x;
	x_pixel = (2 * NDC_pixel - 1)  * ratio * tan((fov / 2)  * M_PI / 180);
	return (x_pixel);
}

static float y_pixel(t_data *data, int y, int fov)
{
	float y_pixel;
	float NDC_pixel;

	NDC_pixel = (y + 0.5) / data->res_y;
	y_pixel = (1 - 2 * NDC_pixel) * tan((fov / 2) * M_PI / 180);
	return (y_pixel);
}

char *draw_image(t_olst *olst, t_data *data)
{
	t_ray *ray;
	int fov;
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	fov = olst->cam->fov;
	while (data->res_y > y)
	{
		while (data->res_x > x)
			{
				i = (x * (data->bits_per_pixel / 8) + (y * data->size_line));
				ray = build_ray(x_pixel(data, x, fov), y_pixel(data, y, fov), olst->cam);
				collision_searcher(olst, ray);
				if (ray->point_found)
					*(unsigned int *)(data->img + i) = get_pixel_color(olst, ray);
				free(ray);
				x++;
			}
		x = 0;
		y++;
	}
	return (data->img);
}
