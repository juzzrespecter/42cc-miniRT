/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_scene.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:58:15 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/02 18:57:28 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int greater_length(char *s1, char *s2)
{
  int s1_len;
  int s2_len;

  s1_len = ft_strlen(s1);
  s2_len = ft_strlen(s2);
  return (s1_len > s2_len ? s1_len : s2_len);
}

static bool check_elem_list(char *scene_line)
{
  char *id;

  id = scene_line[0];
  if (!ft_strncmp(id, "R", greater_length(id, "R")))
      return (res_error_check(scene_line));
  if (!ft_strncmp(id, "A", greater_length(id, "A")))
    return (a_error_check(scene_line));
  if (!ft_strncmp(id, "c", greater_length(id, "c")))
    return (c_error_check(scene_line));
  if (!ft_strncmp(id, "l", greater_length(id, "l")))
    return (l_error_check(scene_line));
  if (!ft_strncmp(id, "sp", greater_length(id, "sp")))
    return (sp_error_check(scene_line));
  if (!ft_strncmp(id, "pl", greater_length(id, "pl")))
    return (pl_error_check(scene_line));
  if (!ft_strncmp(id, "sq", greater_length(id, "sq")))
    return (sq_error_check(scene_line));
  if (!ft_strncmp(id, "cy", greater_length(id, "cy")))
    return (cy_error_check(scene_line));
  if (!ft_strncmp(id, "tr", greater_length(id, "tr")))
    return (tr_error_check(scene_line));
  return (false);
}

bool check_syntax_scene(char *scene_file)
{
	//comprobar si el fichero abre
	//comprobar la informacion del fichero
	//comprobar casos concretos (resolucion y ambiente no duplican...)
	int fd;
	int i;
	char *line;
        char **scene;
	char **scene_line;

	i = 0;
	if ((fd = open(scene_file, O_RDONLY) < 0))
		{
			printf("error al abrir el fichero.\n");
			return (false);
		}
	while (get_next_line(fd, &line) == 1)
		{
                  /*if (!(scene_line = ft_split(line, ' ')))
				return (false);
		 while (scene_line[i])
				{
					printf("%s\n", scene_line[1]);
					i++;
					}
                                        printf("====\n");*/
		}
	return (true);
}
