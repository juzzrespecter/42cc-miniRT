/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:25:45 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:26:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	color_check(char *color)
{
	int color_int;
	int i;
	int cont;

	i = 0;
	cont = 0;
	while (i < 3)
	{
		if (!ft_isdigit(color[cont]))
			return (false);
		color_int = ft_atoi(color + cont);
		if (color_int < 0 || color_int > 255)
			return (false);
		while (ft_isdigit(color[cont]))
			cont++;
		if (color[cont] == ',' && i != 2)
			cont++;
		i++;
	}
	return (!color[cont] ? true : false);
}
