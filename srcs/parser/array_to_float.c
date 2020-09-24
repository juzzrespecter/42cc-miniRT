/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:31:55 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:16:40 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	d_count(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

float		array_to_float(char *array)
{
	int		count;
	int		i;
	int		dec;
	int		neg;
	float	num;

	count = 0;
	neg = 0;
	if (array[count] == '-')
		neg = 1;
	i = ft_atoi(array + neg);
	while (ft_isdigit(array[count + neg]))
		count++;
	num = i;
	if (array[count + neg] == '.')
	{
		count++;
		if ((dec = ft_atoi(array + count + neg)))
			num = ((i * pow(10, d_count(dec))) + dec) / pow(10, d_count(dec));
	}
	return (neg ? num * -1 : num);
}
