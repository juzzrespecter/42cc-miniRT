/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:33:36 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/05 19:50:15 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


unsigned int pixel_color(t_lst *obj_lst, t_vec3d *ray)
{
}

float x_pixel(t_data *data, int x, unsigned char fov)
{
	float ratio;
	float pixel_ndc;
	float pixel_screen;
	float pixel_camera;

	ratio = (float)data->res_x / (float)res_y;
	pixel_ndc = (x + 0.5) / data->res_x;
	pixel_screen = 2 * pixel_ndc - 1;
	pixel_camera = pixel_screen * ratio * tan(((fov / 2) * M_PI) / 180);
	return (pixel_camera);
}

float y_pixel(t_data *data, int y, unsigned char fov)
{
	float ratio;
	float pixel_ndc;
	float pixel_screen;
	float pixel_camera;

	pixel_ndc = (y + 0.5) / data->res_y;
	pixel_screen = 1 - 2 * pixel_ndc;
	pixel_camera = pixel_screen * tan(((fov / 2) * M_PI) / 180);
	return (pixel_camera);
}

char *pixel_loop(t_data *data, t_lst *obj_lst)
{
	int coord[2];
	int imgdata[3];
	float pixel[3];
	t_point *point;
	char *img;

	coord[0] = 0;
	coord[1] = 0;
	img = mlx_get_data_addr(data->img_ptr, &imgdata[0], &imgdata[1], &imgdata[2]);
	while (coord[1] < data->res_y)
		{
			while (coord[0] < data->res_x)
				{
					i = coord[0] * (imgdata[0] / 8) + (coord[1] * imgdata[1]);
					pixel[0] = x_pixel(data, coord[0], obj_lst->c_lst->fov);
					pixel[1] = y_pixel(data, coord[1], obj_lst->c_lst->fov);
					pixel[2] = -1;
					if (!(t_point = search_for_collision(obj_lst, pixel, obj_lst->c_lst->coord)))
						return (NULL);
					*(unsigned int *)(img + i) = pixel_color(point);
				}
		}
	return (img)
}
