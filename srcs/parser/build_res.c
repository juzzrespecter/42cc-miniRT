/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_res.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 13:35:24 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:39:39 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool res_err(char **content)
{
	int res_x;
	int res_y;

	res_x = ft_atoi(content[1]);
	res_y = ft_atoi(content[2]);
	if (!(res_x > 0 && res_y > 0 && !content[3]))
		return (false);
	return (true);
}

bool build_res(char **content, t_lst *obj_lst)
{
	t_r *res;

	if (!(res_err(content) || obj_lst->res))
		return (false);
	if (!(res = malloc(sizeof(t_r))))
		return (false);
	res->res_x = ft_atoi(content[1]);
	res->res_y = ft_atoi(content[2]);
	obj_lst->res = res;
	return (true);
}
