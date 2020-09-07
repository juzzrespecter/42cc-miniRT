/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:04:53 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 17:52:13 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool build_res(char **scene_line, t_olst *olst)
{
	t_res *res;
	int res_x;
	int res_y;

	if (!check_scene_array(scene_line, 3) || olst->res)
			return (false);
	res_x = ft_atoi(scene_line[1]);
	res_y = ft_atoi(scene_line[2]);
	if (!(res_x > 0 && res_y > 0))
		return (false);
	if (!(res = malloc(sizeof(t_res))))
		return (false);
	res->res_x = res_x;
	res->res_y = res_y;
	olst->res = res;
	return (true);
}
