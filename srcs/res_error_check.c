/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:30:20 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 18:40:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool res_error_check(char **scene_line)
{
	int x_res;
	int y_res;

	if (!check_scene_array(scene_line, 3))
			return (false);
	x_res = ft_atoi(scene_line[1]);
	y_res = ft_atoi(scene_line[2]);
	return ((x_res > 0 && y_res > 0) ? true : false);
}
