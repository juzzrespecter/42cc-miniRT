/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:43:24 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 18:39:41 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int fov_error(char *fov)
{
	int fov_value;
	int i;

	i = 0;
	while (ft_isdigit(fov[i]) && fov[i])
		i++;
	if (!i || fov[i])
		return (0);
	fov_value = ft_atoi(fov);
	if (fov_value < 0 || fov_value > 180)
		return (0);
	return (1);
}

int camera_error(t_obj *cam_obj)
{
	char *coords;
	char *fov;
	char *vector;

	coords = cam_obj->content[0];
	vector = cam_obj->content[1];
	fov = cam_obj->content[2];
	return ((!cam_obj->content[3] && coords_error(coords) && fov_error(fov) && \
					 vector_error(vector)) ? 1 : 0);
}
