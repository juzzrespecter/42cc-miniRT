/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:02:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/14 20:28:55 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool check_elem_list(char **line, t_olst *olst, t_cam *cam_lst)
{
	char *id;

	id = scene_line[0];
	if (!ft_strncmp(id, "R", greater_length(id, "R")))
			return (build_res(line, olst));
	if (!ft_strncmp(id, "A", greater_length(id, "A")))
		return (build_amb(line, olst));
	if (!ft_strncmp(id, "c", greater_length(id, "c")))
		return (build_cam(line, cam_lst));
	if (!ft_strncmp(id, "l", greater_length(id, "l")))
		return (build_light(line, olst));
	if (!ft_strncmp(id, "sp", greater_length(id, "sp")))
		return (build_sphere(line, olst));
	if (!ft_strncmp(id, "pl", greater_length(id, "pl")))
		return (build_plane(line, olst));
	if (!ft_strncmp(id, "sq", greater_length(id, "sq")))
		return (build_square(line, olst));
	if (!ft_strncmp(id, "cy", greater_length(id, "cy")))
		return (build_cylinder(line, olst));
	if (!ft_strncmp(id, "tr", greater_length(id, "tr")))
		return (build_triangle(line, olst));
	return (false);
}

t_olst *scene_parser(char *scene_file, t_cam *cam_ptr)
{
	int fd;
	char *line;
	char **scene_line;
	t_olst *olst;
	t_cam *cam_lst;

	cam_lst = NULL;
	if ((fd = open(scene_file, O_RDONLY)) < 0)
		rt_failure(olst, "Error en la apertura del archivo.");
	if (!(olst = calloc(1, sizeof(t_olst))))
		rt_failure(olst, strerror(errno));
	while ((get_next_line(fd, &line)) == 1)
	{
		if (*line)
		{
			if (!(scene_line = ft_split(line, ' ')))
				rt_failure(olst, strerror(errno));
			if (!check_elem_list(scene_line, olst, cam_lst, data))
				rt_failure(olst, "Error al leer la escena (escena no válida).");
			free(scene_line);
		}
		free(line);
	}
	if (!(cam_lst = cam_ptr))
		rt_failure(olst, "Error: no hay cámara en la escena."); 
	return (olst);
}
