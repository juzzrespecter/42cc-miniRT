/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:57:04 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:04:44 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool fov_err(char *fov_str)
{
	unsigned char fov;
	int i;

	i = 0;
	while (ft_isdigit(fov_str[i]) && fov_str[i])
		i++;
	if (!i || fov_str[i])
		return (false);
	fov = (unsigned char)ft_atoi(fov_str);
	if (fov < 0 || fov > 180)
		return (false);
	return (true);
}

static bool cam_err(char **content)
{
	char *coords;
	char *fov;
	char *vector;

	coords = content[1];
	vector = content[2];
	fov = content[3];
	return ((!content[4] && coords_err(coords) && fov_err(fov) && \
					 vector_err(vector)) ? true : false);
}

bool build_cam(char **content, t_lst *obj_lst)
{
	t_c *cam;
	t_c *cam_aux;

	if (!(cam_err(content)))
		return (false);
	if (!(cam = malloc(sizeof(t_c))))
		return (false);
	coord_str_to_f(content[1], cam->coord);
	coord_str_to_f(content[2], cam->view);
	cam->fov = ft_atoi(content[3]);
	cam->next = NULL;
	if (!obj_lst->c_lst)
		obj_lst->c_lst = cam;
	else
		{
			cam_aux = obj_lst->c_lst;
			while (cam_aux->next)
				cam_aux = cam_aux->next;
			cam_aux->next = cam;
		}
	return (true);
}
