#include "minirt.h"

static void display_error()
{
	printf("error displayed\n");
}

static int ft_isprintable(char c)
{
	if (c >= 32 && c <= 126)
		return (c);
	return (0);
}

static bool valid_ext(char *scene_name)
{
	int i;

	i = 0;
	while (ft_isprintable(scene_name[i]) && scene_name[i] != '.')
		i++;
	if (!(i && ft_strncmp(scene_name + i, ".rt", ft_strlen(scene_name + i))))
		return (false);
	return (true);
}

static void build_data(t_data *data, t_r *res)
{
	data->mlx_ptr = mlx_init();
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->res_x, data->res_y);
	data->res_x = res->res_x;
	data->res_y = res->res_y;
}

int main(int argc, char **argv)
{
	t_lst obj_lst;
	t_data data;
	char *img;

	if (!(argc == 2 || (argc == 3 && !ft_strncmp(argv[2], "--save", ft_strlen(argv[2]) ) && valid_ext(argv[1]))))
	{
		display_error();
		return (0);
	}
	init_lst(&obj_lst);
	if (!(scene_parser(argv[1], &obj_lst)))
		{
			display_error();
			return (0);
		}
	build_data(&data, obj_lst.res);
	if (!(img = get_scene(&data, &obj_lst)))
		{
			display_error();
			return (0);
		}
	if (argc == 3 )
		save_scene_to_bmp(&data);
	if (argc == 2)
		put_scene_to_window(&data);
	return (0);
}
