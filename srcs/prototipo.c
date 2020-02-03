#include "../includes/minirt.h"

int key_hook(int keycode, void *param)
{
	(void)param;
	printf("keycode: %c\n", keycode);
	return (0);
}

int main(int argc, char **argv)
{
	//lectura del .rt
	//comprobación de errores
	//...
	if (argc != 2)
	{
		printf(":-(\n");
		return (0);
	}
	printf("test\n");
	scene_reader(argv[1]);
}
