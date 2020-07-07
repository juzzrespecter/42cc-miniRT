/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:58:15 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/07 20:27:22 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static bool check_elem_list(char **scene_line, t_objlst *obj_lst)
{
	char *id;

	id = scene_line[0];
	if (!ft_strncmp(id, "R", greater_length(id, "R")))
			return (res_build_obj(scene_line, obj_lst));
	if (!ft_strncmp(id, "A", greater_length(id, "A")))
		return (a_build_obj(scene_line, obj_lst));
	if (!ft_strncmp(id, "c", greater_length(id, "c")))
		return (c_build_obj(scene_line, obj_lst));
	if (!ft_strncmp(id, "l", greater_length(id, "l")))
		return (l_build_obj(scene_line, obj_lst));
	if (!ft_strncmp(id, "sp", greater_length(id, "sp")))
		return (sp_build_obj(scene_line, obj_lst));
	if (!ft_strncmp(id, "pl", greater_length(id, "pl")))
		return (pl_build_obj(scene_line, obj_lst));
	if (!ft_strncmp(id, "sq", greater_length(id, "sq")))
		return (sq_build_obj(scene_line, obj_lst));
	if (!ft_strncmp(id, "cy", greater_length(id, "cy")))
		return (cy_build_obj(scene_line, obj_lst));
	if (!ft_strncmp(id, "tr", greater_length(id, "tr")))
		return (tr_build_obj(scene_line, obj_lst));
	return (false);
	}

t_objlst *check_syntax_scene(char *scene_file)
{
	//comprobar si el fichero abre
	//comprobar la informacion del fichero
	//comprobar casos concretos (resolucion y ambiente no duplican...)
	//comprobar si hay camara en la escena!!
	//peta a la hora de meter los elementos creados en listas
	int fd;
	char *line;
	char **scene_line;
	t_objlst *obj_lst;

	if ((fd = open(scene_file, O_RDONLY)) < 0)
		{
			printf("error al abrir el fichero.\n");
			return (NULL);
		}
	if (!(obj_lst = malloc(sizeof(t_objlst *))))
		return (NULL);
	setup_obj_lst(obj_lst);
	while ((get_next_line(fd, &line)) == 1)
		{
			if (!(scene_line = ft_split(line, ' ')))
				return (NULL);
			printf("mirando (%s)\n", scene_line[0]);
			if (!check_elem_list(scene_line, obj_lst))
				{
					printf("error en la escena.\n");
					//delete_obj_lst(obj_lst);
					return (NULL);
				}
		}
		return (obj_lst);
}
