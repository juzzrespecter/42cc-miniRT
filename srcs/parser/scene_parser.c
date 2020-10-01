/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:02:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 21:08:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool		obj_lst(char *id, char **line, t_rt *index, t_objs *o_lst)
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

static void		process_line(char *line, int fd, t_objs *o_lst, t_rt *index)
{
	char	**scene_line;

	if (*line)
	{
		if (!(scene_line = ft_split(line, " \n\t\r\f\v")))
		{
			free(line);
			close(fd);
			exit_failure(index, "Error: malloc error.");
		}
		if (!obj_lst(scene_line[0], scene_line, index, o_lst))
		{
			ft_split_free(scene_line);
			free(line);
			close(fd);
			exit_failure(index, "Error: wrong format.");
		}
		ft_split_free(scene_line);
	}
	free(line);
}

t_objs			*scene_parser(char *scene_file, t_rt *index)
{
	int		fd;
	char	*line;
	int		out;
	t_objs	*o_lst;

	if ((fd = open(scene_file, O_RDONLY)) < 0)
		exit_failure(index, "Error: failed to open scene file.");
	if (!(o_lst = ft_calloc(1, sizeof(t_objs))))
	{
		close(fd);
		exit_failure(index, "Error: malloc error.");
	}
	while ((out = get_next_line(fd, &line)) == 1)
		process_line(line, fd, o_lst, index);
	close(fd);
	if (out == -1)
		exit_failure(index, "Error: couldn't read scene file.");
	return (o_lst);
}
