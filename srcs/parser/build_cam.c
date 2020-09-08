/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cam.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:01:33 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/08 18:12:05 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

static void add_cam_to_back(t_olst *olst, t_cam *cam)
{
	t_cam *cam_aux;

	cam_aux = olst->cam;
	if (!cam_aux)
		olst->cam = cam;
	else
		{
			while (cam_aux->next)
				cam_aux = cam_aux->next;
			cam_aux->next = cam;
		}
}

bool build_cam(char **scene_line, t_olst *olst)
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
	cam->coord = array_to_vector(coord);
	cam->orientation = v_normalize(array_to_vector(vector));
	cam->fov = ft_atoi(fov);
	cam->next = NULL;
	add_cam_to_back(olst, cam);
	return (true);
}
