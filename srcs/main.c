/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:10:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/13 16:38:09 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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

int main(int argc, char **argv)
{
	t_objlst *obj_lst;
	t_data data;
	char *img;

	if (!check_valid_args(argc, argv))
		{
			printf("error al introducir los argumentos.\n");
			exit(1);
		}
	if (!(obj_lst = check_syntax_scene(argv[1])))
		{
			printf("error al leer la escena.\n");
			exit(1);
		}
	data.mlx_ptr = mlx_init();
	data.img_ptr = mlx_new_image(data.mlx_ptr, obj_lst->res->x_res, obj_lst->res->y_res);
	data.x_res = obj_lst->res->x_res;
	data.y_res = obj_lst->res->y_res;
	if (!(img = mlx_get_data_addr(data.img_ptr, &data.bits_per_pixel, &data.size_line, &data.endian)))
		{
			printf("error al crear la imagen.\n");
			delete_obj_lst(obj_lst);
			exit(1);
		}
	img = draw_image(obj_lst, data, img);
}
