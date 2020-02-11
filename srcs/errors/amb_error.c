/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:49:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 17:09:47 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int amb_error(t_obj *amb_obj)
{
	int i;
	char *bright;
	char *colors;

	if (!amb_obj->content)
		return (0);
	i = 0;
	while (amb_obj->content[i])
		i++;
	if (i != 2)
		return (0);
	bright = amb_obj->content[0];
	colors = amb_obj->content[1];
	return ((bright_error(bright) && colors_error(colors) && !amb_obj->content[2]) ? 1 : 0);
}
