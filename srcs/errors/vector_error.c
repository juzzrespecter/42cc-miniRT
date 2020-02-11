/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:49:23 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 18:39:32 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int norm_coord_error(char *coords, int last)
{
	int i;

	i = 0;
	while (coords[i] && coords[i] != ',' && i < 4)
		{
			if (i == 0 && !(coords[i] == '0' || coords[i] == '1'))
				return (0);
			if (i == 1 && (coords[i] != '.'))
				break;
			if (i == 2 && coords[0] == '0' && !(coords[i] >= '0' && coords[i] <= '9'))
				return (0);
			if (i == 2 && coords[0] == '1' && !(coords[i] == '0'))
				return (0);
			i++;
		}
	if (!(i == 1 || i == 3))
		return (0);
	return (((coords[i] == ',' && !last) || (!coords[i] && last)) ? i : 0);
}

int vector_error(char *vector)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!(count = norm_coord_error(vector + i, 0)))
		return (0);
	i += count + 1;
	if (!(count = norm_coord_error(vector + i, 0)))
		return (0);
	i += count + 1;
	if (!(count = norm_coord_error(vector + i, 1)))
		return (0);
	i += count;
	return (1);
}
