#include "includes/minirt.h"

int main()
{
	char **tabla;
	char *cadena = "            test    de    espacios     ";
	int i;

	i = 0;
	tabla = ft_split(cadena, ' ');
	while (tabla[i])
	{
		printf("%s\n",tabla[i]);
		free(tabla[i]);
	}
	free(tabla);
}
