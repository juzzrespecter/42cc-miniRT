/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:10:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/28 21:31:41 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_name(char *scene)
{
	int	i;

	i = 0;
	while (scene[i] && scene[i] != '.')
		i++;
	return ((i && !ft_strncmp(scene + i, ".rt", 4)) ? true : false);
}

static bool	check_valid_args(int argc, char **argv)
{
	if (argc == 2 && check_name(argv[1]))
		return (true);
	if (argc == 3 && check_name(argv[1]) && !ft_strncmp(argv[2], "--save", 7))
		return (true);
	return (false);
}

static bool	res_verification(t_rtindex *index)
{
	int	res_x;
	int	res_y;

	if (index->res_x == -1 || index->res_y == -1)
		return (false);
	mlx_get_screen_size(index->mlx_ptr, &res_x, &res_y);
	index->res_x = (index->res_x > res_x) ? res_x : index->res_x;
	index->res_y = (index->res_y > res_y) ? res_y : index->res_y;
	return (true);
}

int			main(int argc, char **argv)
{
	t_rtindex	*index;

	if (!check_valid_args(argc, argv))
		rt_failure(NULL, "Error al introducir los argumentos.");
	if (!(index = ft_calloc(1, sizeof(t_rtindex))))
		rt_failure(NULL, "malloc error etc...");
	index->cam_lst = NULL;
	index->res_x = -1;
	index->res_y = -1;
	index->o_lst = scene_parser(argv[1], index);
	if (!(index->current_cam = index->cam_lst))
		rt_failure(index, "Error: no camera defined in the scene.");
	index->mlx_ptr = mlx_init();
	if (!(res_verification(index)))
		rt_failure(index, "Error: no resolution defined.");
	index->current_cam->img = ray_tracer(index, index->current_cam);
	if (argc == 3)
		export_to_bmp(index);
	else
	{
		window_generate_images(index);
		img_to_window(index);
	}
	return (1);
}
