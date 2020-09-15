/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 20:21:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 19:42:50 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray *build_ray(float x, float y, t_cam *cam)
{
	t_vector dir_screen;
	t_ray *ray;

	if (!(ray = malloc(sizeof(t_ray))))
		return (NULL);
	ray->point_found = false;
	dir_screen.x = x;
	dir_screen.y = y;
	dir_screen.z = 1;
	dir_screen = v_normalize(dir_screen);
	ray->dir = v_normalize(vmprod(dir_screen, cam->matrix));
	ray->origin = cam->coord;
	return (ray);
}

static float x_pixel(t_rtindex *index, int x, int fov)
{
	float x_pixel;
	float NDC_pixel;
	float ratio;

	ratio = (float)index->res_x / (float)index->res_y;
	NDC_pixel = (x + 0.5) / index->res_x;
	x_pixel = (2 * NDC_pixel - 1)  * ratio * tan((fov / 2)  * M_PI / 180);
	return (x_pixel);
}

static float y_pixel(t_rtindex *index, int y, int fov)
{
	float y_pixel;
	float NDC_pixel;

	NDC_pixel = (y + 0.5) / index->res_y;
	y_pixel = (1 - 2 * NDC_pixel) * tan((fov / 2) * M_PI / 180);
	return (y_pixel);
}

t_ray *collision_loops(t_objects *o_lst, t_ray *ray)
{
	bool found_point;

	found_point = false;
	if (sp_loop(o_lst->sp, ray))
		found_point = true;
	if (pl_loop(o_lst->pl, ray))
		found_point = true;
	if (sq_loop(o_lst->sq, ray))
		found_point = true;
	if (tr_loop(o_lst->tr, ray))
		found_point = true;
	if (cy_loop(o_lst->cy, ray))
		found_point = true;
	return (found_point ? ray : NULL);
}

char *ray_tracer(t_rtindex *index, t_cam *cam)
{
	t_ray *ray;
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	cam->img_ptr = mlx_new_image(index->mlx_ptr, index->res_x, index->res_y);
	cam->img = mlx_get_data_addr(cam->img_ptr, &cam->bpp, &cam->sl, &cam->endian);
	if (!cam->img)
		rt_failure(index, "error en img mlx etc etc");
	while (index->res_y > y)
	{
		while (index->res_x > x)
			{
				i = (x * (cam->bpp / 8) + (y * cam->sl));
				ray = build_ray(x_pixel(index, x, cam->fov), y_pixel(index, y, cam->fov), cam);
				collision_loops(index->o_lst, ray);
				if (ray->point_found)
					*(unsigned int *)(cam->img + i) = get_pixel_color(index->o_lst, ray);
				free(ray);
				x++;
			}
		x = 0;
		y++;
	}
	return (cam->img);
}
