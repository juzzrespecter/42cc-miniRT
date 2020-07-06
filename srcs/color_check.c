/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:25:45 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 17:18:40 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool color_check(char *color)
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
			color_int = ft_atoi(color);
			if (color_int < 0 || color_int > 255)
				return (false);
			while (ft_isdigit(color[cont]))
				cont++;
			if (color[cont] == ',' && i != 2)
				cont++;
			else
				return (false);
			i++;
		}
	return (!color[cont] ? true : false);
}
