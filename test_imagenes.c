#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testlib.h"




void change_img(data *data);

/*int loop(data *data)
{
	int i;
	i = mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (1);
}*/

void ilum_test(data *data)
{
	unsigned int color, color_ilum;
	float ilum = 0.6;
	int color_str[3] = {255, 255, 255};
	int y = 0, x = 0, i = 0;
	int bits_per_pixel, endian, size_line;
	char *img;

	img = mlx_get_data_addr(data->img_ptr, &bits_per_pixel, &size_line, &endian);
	color = (color_str[0] + (color_str[1] << 8) + (color_str[2] << 16) ) & 0xffffff;
	while (y < data->res_y / 2)
		{
			while (x < data->res_x)
				{
					i = x * (bits_per_pixel / 8) + (y * size_line);
					*(unsigned int *)(img + i) = color;
					x++;
				}
			y++;
			x = 0;
			}
			img[data->res_x + data->res_y] = 0;
			color_str[0] += ilum * color_str[0];
			color_str[1] += ilum * color_str[1];
			color_str[2] += ilum * color_str[2];
			color_ilum = (color_str[0] + (color_str[1] << 8) + (color_str[2] << 16) ) & 0xffffff;
			//printf("%#x, %#x\n", color, color_ilum);
			while (y < data->res_y)
		{
			while (x < data->res_x)
				{
					i = x * (bits_per_pixel / 8) + (y * size_line);
					*(unsigned int *)(img + i) = color_ilum;
					x++;
				}
			y++;
			x = 0;
			}
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);

}

int key(int keycode, data *data)
{
	printf("key: %d\n", keycode);
	if (keycode == 32)
		{
			mlx_destroy_image(data->mlx_ptr, data->img_ptr);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			exit(1);
		}
	if (keycode == 49)
		change_img(data);
	if (keycode == 0)
		ilum_test(data);
	if (keycode == 124)
		{
			data->cam.pos[0]++;
			test(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
		}
	if (keycode == 126)
		{
			data->cam.pos[1]++;
			test(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
		}
	if (keycode == 123)
		{
			data->cam.pos[0]--;
			test(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
		}
	if (keycode == 125)
		{
			data->cam.pos[1]--;
			test(data);
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
		}
	return (1);
}

void change_img(data *data)
{
	int y = 0, x = 0, color, i = 0;
	int bits_per_pixel, endian, size_line;
	char *img;

	img = mlx_get_data_addr(data->img_ptr, &bits_per_pixel, &size_line, &endian);
	//color = rand() % 0xffffff;
	color = 0xff0000;
	while (y < data->res_y)
		{
			while (x < data->res_x)
				{
					i = x * (bits_per_pixel / 8) + (y * size_line);
					*(unsigned int *)(img + i) = color;
					x++;
				}
			y++;
			x = 0;
			}
	img[data->res_x + data->res_y] = 0;
}

int main()
{
	void *mlx_ptr = mlx_init();
	void *img_ptr;
	void *win_ptr;
	data data;
	int res_x = 1000;
	int res_y = 1000;

	img_ptr = mlx_new_image(mlx_ptr, res_x, res_y);
	win_ptr = mlx_new_window(mlx_ptr, res_x, res_y, "ye");

	data.res_x = res_x;
	data.res_y = res_y;

	/*while (y < res_y)
		{
			while (x < res_x)
				{
					//printf("%d * (%d / 8) + (%d * %d) : %d\n",x, bits_per_pixel, y, size_line,  i);
					i = x * (bits_per_pixel / 8) + (y * size_line);
					//color = rand() % 0xffffff;
					*(unsigned int *)(img + i) = color;
					img[x + 0 + (res_y * y)] = (color >> 24) & 0xff;
					img[x + 1 + (res_y * y)] = (color >> 16) & 0xff;
					img[x + 2 + (res_y * y)] = (color >> 8) & 0xff;
					img[x + 3 + (res_y * y)] = color & 0xff;
					x++;
				}
			y++;
			x = 0;
			}
			img[res_x + res_y] = 0;*/

	data.mlx_ptr = mlx_ptr;
	data.win_ptr = win_ptr;
	data.img_ptr = img_ptr;

	data.cam.vector[0] = 0;
	data.cam.vector[1] = 0;
	data.cam.vector[2] = 1;

	data.cam.fov = 45;

	data.cam.pos[0] = 0;
	data.cam.pos[1] = 0;
	data.cam.pos[2] = 0;

	test(&data);
	mlx_key_hook(data.win_ptr, &key, &data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	//mlx_loop_hook(data.mlx_ptr, &loop, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
