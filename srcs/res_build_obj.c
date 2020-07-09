/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_build_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:57:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/09 18:04:59 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool res_build_obj(char **scene_line, t_objlst *obj_lst)
{
	t_res *res;
	int x_res;
	int y_res;

	if (!check_scene_array(scene_line, 3) || obj_lst->res)
			return (false);
	x_res = ft_atoi(scene_line[1]);
	y_res = ft_atoi(scene_line[2]);
	if (!(x_res > 0 && y_res > 0))
		return (false);
	if (!(res = malloc(sizeof(t_res))))
		return (false);
	res->x_res = x_res;
	res->y_res = y_res;
	obj_lst->res = res;
	return (true);
}
