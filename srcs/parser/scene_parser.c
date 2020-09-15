/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:02:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/15 16:17:31 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool check_elem_list(char **line, t_rtindex *index)
{
	char *id;

	id = line[0];
	if (!ft_strncmp(id, "R", greater_length(id, "R")))
			return (build_res(line, index->o_lst));
	if (!ft_strncmp(id, "A", greater_length(id, "A")))
		return (build_amb(line, index->o_lst));
	if (!ft_strncmp(id, "c", greater_length(id, "c")))
		return (build_cam(line, index));
	if (!ft_strncmp(id, "l", greater_length(id, "l")))
		return (build_light(line, index->o_lst));
	if (!ft_strncmp(id, "sp", greater_length(id, "sp")))
		return (build_sphere(line, index->o_lst));
	if (!ft_strncmp(id, "pl", greater_length(id, "pl")))
		return (build_plane(line, index->o_lst));
	if (!ft_strncmp(id, "sq", greater_length(id, "sq")))
		return (build_square(line, index->o_lst));
	if (!ft_strncmp(id, "cy", greater_length(id, "cy")))
		return (build_cylinder(line, index->o_lst));
	if (!ft_strncmp(id, "tr", greater_length(id, "tr")))
		return (build_triangle(line, index->o_lst));
	return (false);
}

t_rtindex *scene_parser(char *scene_file)
{
	int fd;
	char *line;
	char **scene_line;
	t_rtindex *index;
	t_objects *o_lst;

	if ((fd = open(scene_file, O_RDONLY)) < 0)
		rt_failure(NULL, "Error en la apertura del archivo.");
	o_lst = calloc(1, sizeof(t_objects));
	index = calloc(1, sizeof(t_rtindex));
	if (!o_lst || !index)	
		rt_failure(index, strerror(errno));
	index->o_lst = o_lst;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (*line)
		{
			if (!(scene_line = ft_split(line, ' ')))
				rt_failure(index, strerror(errno));
			if (!check_elem_list(scene_line, index))
				rt_failure(index, "Error al leer la escena (escena no válida).");
			free(scene_line);
		}
		free(line);
	}
	if (!index->cam_lst)
		rt_failure(index, "Error: no hay cámara en la escena."); 
	return (index);
}
