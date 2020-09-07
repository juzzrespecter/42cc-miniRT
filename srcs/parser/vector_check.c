/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:29:53 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 19:33:06 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int normalized_float_check(char *vector)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	if (vector[i] == '-')
		neg = 1;
	if (vector[i + neg] == '0' || vector[i + neg] == '1')
		i++;
	if (vector[i + neg] == '.' && i == 1)
		i++;
	if (vector[neg] == '0' && ft_isdigit(vector[i + neg]) && i == 2)
		i++;
	if (vector[neg] == '1' && vector[i + neg] == '0' && i == 2)
		i++;
	if (i == 1 || i == 3)
		return (i + neg);
	return (0);
}

bool vector_check(char *vector)
{
	int i;
	int cont;
	int sum;

	i = 0;
	cont = 0;
	while (i < 3)
		{
		 sum = 0;
			if (!(sum = normalized_float_check(vector + cont)))
				return (false);
			cont += sum;
			if (vector[cont] == ',' && i != 2)
				cont++;
			i++;
		}
	return (!vector[cont] ? true : false);
}
