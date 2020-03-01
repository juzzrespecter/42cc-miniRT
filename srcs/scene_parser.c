/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:07:35 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:45:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void init_lst(t_lst *obj_lst)
{
	obj_lst->res = NULL;
	obj_lst->amb = NULL;
	obj_lst->c_lst = NULL;
	obj_lst->l_lst = NULL;
	obj_lst->sp_lst = NULL;
	obj_lst->sq_lst = NULL;
	obj_lst->pl_lst = NULL;
	obj_lst->cy_lst = NULL;
	obj_lst->tr_lst = NULL;
}

static int largest_str(char *s1, char *s2)
{
	int len_s1;
	int len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return ((len_s1 > len_s2) ? len_s1 : len_s2);
}

static bool check_obj_id(char *id, char **content, t_lst *obj_lst)
{
			if (!ft_strncmp(id, "R", largest_str(id, "R")))
				return (build_res(content, obj_lst));
			if (!ft_strncmp(id, "A", largest_str(id, "A")))
				return (build_amb(content, obj_lst));
			if (!ft_strncmp(id, "c", largest_str(id, "c")))
				return (build_cam(content, obj_lst));
			if (!ft_strncmp(id, "l", largest_str(id, "l")))
				return (build_l(content, obj_lst));
			if (!ft_strncmp(id, "sp", largest_str(id, "sp")))
				return (build_sp(content, obj_lst));
			if (!ft_strncmp(id, "sq", largest_str(id, "sq")))
				return (build_sq(content, obj_lst));
			if (!ft_strncmp(id, "pl", largest_str(id, "pl")))
				return (build_pl(content, obj_lst));
			if (!ft_strncmp(id, "cy", largest_str(id, "cy")))
				return (build_cy(content, obj_lst));
			if (!ft_strncmp(id, "tr", largest_str(id, "tr")))
				return (build_tr(content, obj_lst));
			return (false);
}

static bool add_obj_to_lst(char *line, t_lst *obj_lst)
{
	char **content;
	char *id;

	content = ft_split(line, ' ');
	free(line);
	if (!content)
		return (false);
	id = content[0];
	if (!(check_obj_id(id, content, obj_lst)))
		{
			free(content);
			return (false);
		}
	free(content);
	return (true);
}

static bool check_required_obj(t_lst *obj_lst)
{
	return ((obj_lst->amb && obj_lst->res && obj_lst->c_lst) ? true : false);
}

bool scene_parser(char *scene, t_lst *obj_lst)
{
	int fd;
	char *line;

	if ((fd = open(scene, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
		{
			if (*line)
				if (!(add_obj_to_lst(line, obj_lst)))
					return (false);
		}
	close(fd);
	return ((check_required_obj(obj_lst)) ? true : false);
}
