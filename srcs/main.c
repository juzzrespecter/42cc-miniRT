/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:10:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/14 20:28:59 by danrodri         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_olst *olst;
	t_cam *cam_lst;
	t_data *data;
	t_rtindex index;

	if (!check_valid_args(argc, argv))
		rt_failure(olst, "Error al introducir los argumentos.");
	if (!(img_data = malloc(sizeof(t_data))))
		rt_failure(olst, "malloc error etc etc");
	olst = scene_parser(argv[1], cam_lst);
	data->res_x = olst->res->res_x;
	data->res_y = olst->res->res_y;
	data->mlx_ptr = mlx_init();
	index.data = data;
	index.o_lst = olst;
	index.cam_lst = cam_lst;
	index.current_cam = cam_lst;
	cam_lst->img = draw_image(olst, img_data);
	if (argc == 3)
		export_to_bmp(img_data, cam_lst);
	else
	{
		//crear imagenes para todas las camaras disponibles
		img_to_window(img_data, &index);
	}
	return (1);
}
