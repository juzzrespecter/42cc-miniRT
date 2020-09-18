/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:02:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/18 20:01:15 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool check_elem_list(char *id, char **line, t_rtindex *index, t_objects *o_lst)
{
	int	id_len;

	id_len = ft_strlen(id);
	if (!ft_strncmp(id, "R", id_len))
		return (build_res(line, index));
	if (!ft_strncmp(id, "A", id_len))
		return (build_amb(line, o_lst));
	if (!ft_strncmp(id, "c", id_len))
		return (build_cam(line, index));
	if (!ft_strncmp(id, "l", id_len))
		return (build_light(line, o_lst));
	if (!ft_strncmp(id, "sp", id_len))
		return (build_sphere(line, o_lst));
	if (!ft_strncmp(id, "pl", id_len))
		return (build_plane(line, o_lst));
	if (!ft_strncmp(id, "sq", id_len))
		return (build_square(line, o_lst));
	if (!ft_strncmp(id, "cy", id_len))
		return (build_cylinder(line, o_lst));
	if (!ft_strncmp(id, "tr", id_len))
		return (build_triangle(line, o_lst));
	return (false);
}

t_objects *scene_parser(char *scene_file, t_rtindex *index)
{
	int fd;
	char *line;
	char **scene_line;
	t_objects *o_lst;

	if ((fd = open(scene_file, O_RDONLY)) < 0)
		rt_failure(index, "Error en la apertura del archivo.");
	if (!(o_lst = ft_calloc(1, sizeof(t_objects))))
		rt_failure(index, "malloc etc...");
	index->res_x = -1;
	index->res_y = -1;
	while ((get_next_line(fd, &line)) == 1)
	{
		if (*line)
		{
			if (!(scene_line = ft_split(line, ' ')))
				rt_failure(index, "malloc etc...");
			if (!check_elem_list(scene_line[0], scene_line, index, o_lst))
				rt_failure(index, "Error al leer la escena (escena no válida).");
			free(scene_line);
		}
		free(line);
	}
	if (index->res_x == -1 || index->res_y == -1)
		rt_failure(index, "Error al leer la resolucion!");
	if (!index->cam_lst)
		rt_failure(index, "Error: no hay cámara en la escena."); 
	return (o_lst);
}
