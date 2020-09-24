/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dim_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:30:25 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:21:53 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	dim_check(char *dim)
{
	int cont;

	cont = 0;
	if (!ft_isdigit(dim[cont]))
		return (false);
	while (ft_isdigit(dim[cont]))
		cont++;
	if (dim[cont] == '.')
	{
		cont++;
		if (!ft_isdigit(dim[cont]))
			return (false);
		while (ft_isdigit(dim[cont]))
			cont++;
	}
	return (!dim[cont] ? true : false);
}
