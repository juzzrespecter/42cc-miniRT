/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:02:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:31:04 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool check_elem_list(char **scene_line, t_olst *olst)
{
	char *id;

	id = scene_line[0];
	if (!ft_strncmp(id, "R", greater_length(id, "R")))
			return (build_res(scene_line, olst));
	if (!ft_strncmp(id, "A", greater_length(id, "A")))
		return (build_amb(scene_line, olst));
	if (!ft_strncmp(id, "c", greater_length(id, "c")))
		return (build_cam(scene_line, olst));
	if (!ft_strncmp(id, "l", greater_length(id, "l")))
		return (build_light(scene_line, olst));
	if (!ft_strncmp(id, "sp", greater_length(id, "sp")))
		return (build_sphere(scene_line, olst));
	if (!ft_strncmp(id, "pl", greater_length(id, "pl")))
		return (build_plane(scene_line, olst));
	if (!ft_strncmp(id, "sq", greater_length(id, "sq")))
		return (build_square(scene_line, olst));
	if (!ft_strncmp(id, "cy", greater_length(id, "cy")))
		return (build_cylinder(scene_line, olst));
	if (!ft_strncmp(id, "tr", greater_length(id, "tr")))
		return (build_triangle(scene_line, olst));
	return (false);
}

t_olst *scene_parser(char *scene_file)
{
	int fd;
	char *line;
	char **scene_line;
	t_olst *olst;

	if ((fd = open(scene_file, O_RDONLY)) < 0)
		{
			printf("error al abrir el fichero.\n");
			return (NULL);
		}
	if (!(olst = calloc(1, sizeof(t_olst))))
		return (NULL);
	while ((get_next_line(fd, &line)) == 1)
		{
		if (*line)
				{
					if (!(scene_line = ft_split(line, ' ')))
						return (NULL);
					if (!check_elem_list(scene_line, olst))
						{
							printf("error en la escena.\n");
							delete_olst(olst);
							return (NULL);
						}
					free(scene_line);
				}
			free(line);
		}
	return (olst->cam ? olst : NULL);
}
