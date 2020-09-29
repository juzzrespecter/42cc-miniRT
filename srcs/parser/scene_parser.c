/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:02:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/29 19:44:26 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	obj_lst(char *id, char **line, t_rtindex *index, t_objects *o_lst)
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

t_objects	*scene_parser(char *scene_file, t_rtindex *index)
{
	int			fd;
	char		*line;
	char		**scene_line;
	int 		out;
	t_objects	*o_lst;

	if ((fd = open(scene_file, O_RDONLY)) < 0)
		rt_failure(index, "Error: failed to open scene file.");
	if (!(o_lst = ft_calloc(1, sizeof(t_objects))))
		rt_failure(index, "Error: malloc failed to assign dynamic memory.");
	while ((out = get_next_line(fd, &line)) == 1)
	{
		if (*line)
		{
			if (!(scene_line = ft_split(line, " \n\t\r\f\v")))
				rt_failure(index, "Error: malloc failed to assign dynamic memory.");
			if (!obj_lst(scene_line[0], scene_line, index, o_lst))
				rt_failure(index, "Error: wrong scene format.");
			free(scene_line);
		}
		free(line);
	}
	if (out == -1)
		rt_failure(index, "Error: failed to read the scene file.");
	return (o_lst);
}
