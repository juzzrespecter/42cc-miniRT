/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:13:06 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:14:03 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int check_one_coord(char *coords, int last)
{

	int i;
	int j;

	i = 0;
	j = 0;
	if (coords[i] == '-')
		i++;
	while (ft_isdigit(coords[i]) && coords[i])
		i++;
	if (!i)
		return (0);
	if (coords[i] != '.')
		return (((!coords[i] && last) || (coords[i] == ',' && !last)) ? i : 0);
	i++;
	while (ft_isdigit(coords[i + j]) && coords[i + j])
		j++;
	if (!j)
		return (0);
	return (((!coords[i + j] && last) || (coords[i + j] == ',' && !last)) ? i + j : 0);
}

bool coords_err(char *coords)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!(count = check_one_coord(coords + i, 0)))
		return (false);
	i += count + 1;
	if (!(count = check_one_coord(coords + i, 0)))
		return (false);
	i += count + 1;
	if (!(count = check_one_coord(coords + i, 1)))
		return (false);
	i += count;
	if (coords[i])
		return (false);
	return (true);
}
