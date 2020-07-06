/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_error_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:01:15 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 18:57:58 by danrodri         ###   ########.fr       */
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

bool c_error_check(char **scene_line)
{
	char *coord;
	char *vector;
	char *fov;

	if (!check_scene_array(scene_line, 4))
		return (false);
	coord = scene_line[1];
	vector = scene_line[2];
	fov = scene_line[3];
	printf("estado del tema: coord (%d), vector (%d), fov (%d)\n", coord_check(coord), vector_check(vector), fov_check(fov));
	return (coord_check(coord) && vector_check(vector) \
										 && fov_check(fov) ? true : false);
}
