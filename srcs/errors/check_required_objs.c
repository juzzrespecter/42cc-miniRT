/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_required_objs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:49:44 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 14:17:59 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

bool check_required_objs(t_obj *lst)
{
	int got_res;
	int got_amb;
	int got_camera;
	int got_light;

	got_res = 0;
	got_amb = 0;
	got_camera = 0;
	got_light = 0;
	while (lst)
		{
			if (!ft_strncmp(lst->id, "R", ft_strlen(lst->id)))
				got_res++;
			if (!ft_strncmp(lst->id, "A", ft_strlen(lst->id)))
				got_amb++;
			if (!ft_strncmp(lst->id, "c", ft_strlen(lst->id)))
				got_camera++;
			if (!ft_strncmp(lst->id, "l", ft_strlen(lst->id)))
				got_light++;
			lst = lst->next;
		}
	return ((got_res == 1 && got_amb == 1 && got_light && got_camera) ? 1 : 0);
}
