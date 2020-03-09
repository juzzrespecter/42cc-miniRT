/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:35:40 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/28 13:01:39 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
	void *mlx_ptr;
	void *mlx_win;
	void *mlx_img;
	unsigned int color;

	int res_x;
	int res_y;
} data;

unsigned int illuminate(unsigned int color, float bright, int u)
{
	unsigned char color_rgb[3];
	unsigned char light[3];
	unsigned char bright_rgb;

	color_rgb[0] = color & 0xff;
	color_rgb[1] = (color >> 8) & 0xff;
	color_rgb[2] = (color >> 16) & 0xff;

	bright_rgb = 255 * bright;

	light[0] = 0xff - bright_rgb;
	light[1] = 0xff - bright_rgb;
	light[2] = 0xff - bright_rgb;



	if (!u)
		{
			((color_rgb[0] - light[0]) < 0 ? (color_rgb[0] = 0) : (color_rgb[0] -= light[0]));
			((color_rgb[1] - light[1]) < 0 ? (color_rgb[1] = 0) : (color_rgb[1] -= light[1]));
			((color_rgb[2] - light[2]) < 0 ? (color_rgb[2] = 0) : (color_rgb[2] -= light[2]));
		}
	else
		{
			((color_rgb[0] + light[0]) > 255 ? (color_rgb[0] = 255) : (color_rgb[0] += light[0]));
			((color_rgb[1] + light[1]) > 255 ? (color_rgb[1] = 255) : (color_rgb[1] += light[1]));
			((color_rgb[2] + light[2]) > 255 ? (color_rgb[2] = 255) : (color_rgb[2] += light[2]));
		}
	color = color_rgb[0] + ((unsigned int)(color_rgb[1] << 8)) + ((unsigned int)(color_rgb[2] << 16));

	printf("color: %#x, light: %d %d %d, color_rgb: %d %d %d\n", color, light[0], light[1], light[2], color_rgb[0], color_rgb[1], color_rgb[2]);

	return (color);
}

void rm_light(data *data)
{
	char *img;
	int bits_per_pixel;
	int size_line;
	int endian;
	int x = 0, y = 0, i;
	unsigned int color;

	color = illuminate(data->color, 0.6, 1);
	img = mlx_get_data_addr(data->mlx_img, &bits_per_pixel, &size_line, &endian);
	while (y < data->res_y)
		{
			while (x < data->res_x)
				{
					i = (y * size_line) + (x * (bits_per_pixel / 8));
					*(unsigned int *)(img + i) = color;
					x++;
				}
			x = 0;
			y++;
		}
	img[data->res_x + data->res_y] = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);
}

void add_light(data *data)
{
	char *img;
	int bits_per_pixel;
	int size_line;
	int endian;
	int x = 0, y = 0, i;
	unsigned int color;

	color = illuminate(data->color, 0.6, 0);
	img = mlx_get_data_addr(data->mlx_img, &bits_per_pixel, &size_line, &endian);
	while (y < data->res_y)
		{
			while (x < data->res_x)
				{
					i = (y * size_line) + (x * (bits_per_pixel / 8));
					*(unsigned int *)(img + i) = color;
					x++;
				}
			x = 0;
			y++;
		}
	img[data->res_x + data->res_y] = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, 0, 0);

}

int pressed_key(int keycode, data *data)
{
	if (keycode == 125)
		exit(1);
	if (keycode == 123)
			rm_light(data);
	if (keycode == 124)
			add_light(data);
	return (2);
}

void build_data(data *data, unsigned int color)
{
	data->res_x = 1000;
	data->res_y = 1000;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->res_x, data->res_y, "test");
	data->mlx_img = mlx_new_image(data->mlx_ptr, data->res_x, data->res_y);
	data->color = color;
}

int main()
{
	unsigned int color;
	data data;

	color = rand() % 0xffffff;

	build_data(&data, color);

	mlx_key_hook(data.mlx_win, &pressed_key, &data);
	mlx_loop(data.mlx_ptr);
}
