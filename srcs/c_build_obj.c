/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_build_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 19:02:20 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/29 16:12:53 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static bool fov_check(char *fov)
{
	int fov_int;
	int i;

	i = 0;
	if (!ft_isdigit(fov[i]))
		return (false);
	fov_int = ft_atoi(fov);
	if (fov_int < 0 || fov_int > 180)
		return (false);
	while (ft_isdigit(fov[i]))
		i++;
	return (!fov[i] ? true : false);
}

static void add_cam_to_back(t_objlst *obj_lst, t_cam *cam)
{
	t_cam *cam_aux;

	cam_aux = obj_lst->cam;
	if (!cam_aux)
		obj_lst->cam = cam;
	else
		{
			while (cam_aux->next)
				cam_aux = cam_aux->next;
			cam_aux->next = cam;
		}
}

bool c_build_obj(char **scene_line, t_objlst *obj_lst)
{
	char *coord;
	char *vector;
	char *fov;
	t_cam *cam;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	vector = scene_line[2];
	fov = scene_line[3];
	if (!(coord_check(coord) && vector_check(vector) && fov_check(fov)))
		return (false);
	if (!(cam = malloc(sizeof(t_cam))))
		return (false);
	array_char_to_float(cam->coord, coord);
	array_char_to_float(cam->vector, vector);
	cam->fov = ft_atoi(fov);
	cam2world_matrix(cam->vector, cam->coord, cam->c2w_m);
	cam->next = NULL;
	add_cam_to_back(obj_lst, cam);
	return (true);
}
