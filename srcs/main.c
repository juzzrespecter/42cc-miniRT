/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:10:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:29:00 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool check_scene_name(char *scene)
{
	int i;

	i = 0;
	while (scene[i] && scene[i] != '.')
		i++;
	if (i && !ft_strncmp(scene + i, ".rt", 4))
		return (true);
	return (false);
}

static bool check_valid_args(int argc, char **argv)
{
	if (argc == 2 && check_scene_name(argv[1]))
		return (true);
	if (argc == 3 && check_scene_name(argv[1]) && !ft_strncmp(argv[2], "--save", 7))
		return (true);
	return (false);
}

static int esc(int keycode, t_data *data)
{
	
	//esc == 53
	if (keycode == 53)
	{
		printf("chapando la cosa...\n");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		exit(EXIT_SUCCESS);
	}
 return (1);
 }

static void img_to_window(t_data *data)
{
	void *win_ptr = mlx_new_window(data->mlx_ptr, data->res_x, data->res_y, "test");
	printf("en windows mgmt!\n");
	data->win_ptr = win_ptr;
	mlx_put_image_to_window(data->mlx_ptr, win_ptr, data->img_ptr, 0, 0);
	mlx_key_hook(win_ptr, &esc, data);
//	mlx_mouse_hook()
	mlx_loop(data->mlx_ptr);
	}

static bool get_image_data(t_data *img_data, int res_x, int res_y)
{
	int bpp;
	int sl;
	int endian;

	img_data->mlx_ptr = mlx_init();
	img_data->res_x = res_x;
	img_data->res_y = res_y;
	img_data->img_ptr = mlx_new_image(img_data->mlx_ptr, res_x, res_y);
	img_data->img = mlx_get_data_addr(img_data->img_ptr, &bpp, &sl, &endian);
	if (!img_data->img)
			return (false);
	img_data->bits_per_pixel = bpp;
	img_data->size_line = sl;
	img_data->endian = endian;
	return (true);
}

int main(int argc, char **argv)
{
	t_olst *olst;
	t_data img_data;

	if (!check_valid_args(argc, argv))
		{
			printf("error al introducir los argumentos.\n");
			exit(1);
		}
	if (!(olst = scene_parser(argv[1])))
		{
			printf("error al leer la escena.\n");
			exit(1);
		}
	if (!(get_image_data(&img_data, olst->res->res_x, olst->res->res_y)))
		{
			printf("error al crear la imagen.\n");
			delete_olst(olst);
			exit(1);
	}
	img_data.img = draw_image(olst, &img_data);
	if (argc == 3)
	{
		image_save_bmp(&img_data);
		delete_olst(olst);
		// delete data struct
	}
	if (argc == 2)
		img_to_window(&img_data);
	return (1);
}
