/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   res_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:40:23 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 16:18:57 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int	res_error(t_obj *res_obj)
{
	int x_size;
	int y_size;

	x_size = ft_atoi(res_obj->content[0]);
	y_size = ft_atoi(res_obj->content[1]);
	if (x_size < 1 || y_size < 1 || res_obj->content[2])
		return (0);
	return (1);
}
