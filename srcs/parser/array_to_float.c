/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:31:55 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:08:43 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int digit_count(int n)
{
	int count;

	count = 0;
	while (n)
		{
			n /= 10;
			count++;
		}
	return (count);
}

float array_to_float(char *array)
{
	int count;
	int intgr;
	int dec;
	int neg;
	float num;

	count = 0;
	neg = 0;
	if (array[count] == '-')
		neg = 1;
	intgr = ft_atoi(array + neg);
	while (ft_isdigit(array[count + neg]))
		count++;
	num = intgr;
	if (array[count + neg] == '.')
		{
			count++;
			if ((dec = ft_atoi(array + count + neg)))
				num = ((intgr * pow(10, digit_count(dec))) + dec) / pow(10, digit_count(dec));
		}
	return (neg ? num * -1 : num);
}

