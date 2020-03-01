/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 18:33:36 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 18:03:33 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int get_pixel(float *pixel, t_obj *obj_lst)
{

}

void pixel_loop(t_obj *obj_lst, t_data *data, int bits_per_pixel, int size_line)
{
	int x;
	int y;
	int i;
	float pixel[3];

	x = 0;
	y = 0;
	while (y < res_y)
		{
			while (x < res_x)
				{
					pixel[0] = (2 * ((x + 0.5) / data->res_x) - 1)
				}
		}
}

void get_scene(t_data *data, t_lst *obj_lst)
{
	int bits_per_pixel;
	int size_line;
	int endian;

	data->img_ptr = mlx_new_image(data->mlx_ptr, data->res_x, data->res_y);
	data->img = mlx_get_data_addr(data->img_ptr, &bits_per_size, &size_line, &endian);
	pixel_loop(obj_lst, data, bits_per_pixel, size_line);
}
