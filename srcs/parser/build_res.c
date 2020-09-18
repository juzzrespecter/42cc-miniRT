/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:53 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/18 19:20:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool build_res(char **scene_line, t_rtindex *index)
{
	int res_x;
	int res_y;
	static bool err_check = false;

	if (!check_scene_array(scene_line, 3) || err_check)
			return (false);
	err_check = true;
	res_x = ft_atoi(scene_line[1]);
	res_y = ft_atoi(scene_line[2]);
	if (!(res_x > 0 && res_y > 0))
		return (false);
	index->res_x = res_x;
	index->res_y = res_y;
	return (true);
}
