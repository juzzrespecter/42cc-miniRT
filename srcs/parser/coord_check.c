/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:26:24 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:20:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	float_check(char *coord)
{
	int	cont;

	cont = 0;
	if (coord[cont] == '-')
		cont++;
	if (!ft_isdigit(coord[cont]))
		return (0);
	while (ft_isdigit(coord[cont]))
		cont++;
	if (coord[cont] == '.')
	{
		cont++;
		if (!ft_isdigit(coord[cont]))
			return (0);
		while (ft_isdigit(coord[cont]))
			cont++;
	}
	return (cont);
}

bool		coord_check(char *coord)
{
	int	i;
	int	sum;
	int	cont;

	i = 0;
	cont = 0;
	while (i < 3)
	{
		sum = 0;
		if (!(sum = float_check(coord + cont)))
			return (false);
		cont += sum;
		if (coord[cont] == ',' && i != 2)
			cont++;
		i++;
	}
	return (!coord[cont] ? true : false);
}
