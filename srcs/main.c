/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:10:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/02 18:41:24 by danrodri         ###   ########.fr       */
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
	if (!check_valid_args(argc, argv))
		{
			printf("error al introducir los argumentos.\n");
			exit(1);
		}
	if (!check_syntax_scene(argv[1]))
		{
			printf("error al leer la escena.\n");
			exit(1);
		}
}
