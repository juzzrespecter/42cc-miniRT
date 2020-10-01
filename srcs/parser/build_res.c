/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:53 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/28 21:42:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_res(char *res)
{
	int	count;

	count = 0;
	while (ft_isdigit(res[count]))
		count++;
	return ((count && !res[count]) ? true : false);
}

bool		build_res(char **scene_line, t_rt *index)
{
	int			res_x;
	int			res_y;
	static bool	err_check = false;

	if (!check_scene_array(scene_line, 3) || err_check)
		return (false);
	err_check = true;
	if (!check_res(scene_line[1]) || !check_res(scene_line[2]))
		return (false);
	res_x = ft_atoi(scene_line[1]);
	res_y = ft_atoi(scene_line[2]);
	if (!(res_x > 0 && res_y > 0))
		return (false);
	index->res_x = res_x;
	index->res_y = res_y;
	return (true);
}
