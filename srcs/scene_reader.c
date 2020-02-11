/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:51:50 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 20:11:16 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_obj *new_obj(char *line)
{
	t_obj *obj;
	int i;
	int i2;

	i2 = 0;
	obj = malloc(sizeof(t_obj));
	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	obj->id = ft_substr(line, 0, i);
	obj->content = ft_split(line + i, ' ');
	obj->next = NULL;
	return (obj);
}

void add_obj_to_lst(t_obj *obj, t_obj **alst)
{
	t_obj *aux;
	
	if (!*alst)
		*alst = obj;
	else
		{
			aux = *alst;
			while (aux->next)
				aux = aux->next;
			aux->next = obj;
		}
}

t_obj *scene_reader(char *scene)
{
	int fd;
	char *line;
	t_obj *alst;

	alst = NULL;
	fd = open(scene, O_RDONLY);
	if (fd > 0)
			while (get_next_line(fd, &line) == 1)
				{
					if (*line)
						add_obj_to_lst(new_obj(line), &alst);
					free(line);
				}
	//comprobar si existen los objetos imprescindibles
	if (!(check_required_objs(alst)))
		return (NULL);
	//comprobar informacion correcta de todos los objetos
	if (!(check_input_errors(alst)))
		return (NULL);
	close(fd);
	return (alst);
}	
