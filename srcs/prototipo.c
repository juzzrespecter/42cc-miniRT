#include "../includes/minirt.h"

int key_hook(int keycode, void *param)
{
	(void)param;
	printf("keycode: (%d)\n", keycode);
	return (0);
}

static void display_error()
{
	printf("lol\n");
}

static void *open_window(t_obj *lst, void *mlx_ptr)
{
	void *win_ptr;
	int x_size;
	int y_size;

	while (ft_strncmp(lst->id, "R", 1))
		lst = lst->next;
	x_size = ft_atoi(lst->content[0]);
	y_size = ft_atoi(lst->content[1]);
	return (win_ptr = mlx_new_window(mlx_ptr, x_size, y_size, "test"));
}

int mouse_hook(int button, int x, int y, void *param)
{
	(void)button;
	(void)x;
	(void)y;
	void **ptrs;
	void *win;
	void *mlx;

	ptrs = param;
	mlx = ptrs[0];
	win = ptrs[1];
	printf("esto que\n");
	mlx_destroy_window(mlx, win);
	return (0);
}

static void test_events(void *mlx_ptr, void *win_ptr)
{
	int i;
	void **ptrs;

	ptrs = malloc(sizeof(void *) * 2);
	ptrs[0] = mlx_ptr;
	ptrs[1] = win_ptr;
	mlx_key_hook(win_ptr, &key_hook, ptrs);
	mlx_mouse_hook(win_ptr, &mouse_hook, ptrs);
	i = mlx_loop(mlx_ptr);
	printf("(%i)\n", i);
}

int main(int argc, char **argv)
{
	void *mlx_ptr;
	void *win_ptr;
	t_obj *obj_lst;
	//lectura del .rt
	//comprobación de errores
	//...
	if (argc != 2)
	{
		printf(":-(\n");
		return (0);
	}
	printf("test\n");
	if (!(obj_lst = scene_reader(argv[1])))
		{
			display_error();
			return (0);
		}
	mlx_ptr = mlx_init();
	win_ptr = open_window(obj_lst, mlx_ptr);
	test_events(mlx_ptr, win_ptr);
	//test para abrir ventana
}
