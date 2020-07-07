/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_char_to_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:45:54 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/07 20:24:18 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

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

float char_to_float(char *array)
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
			dec = ft_atoi(array + count + neg);
			num = ((intgr * digit_count(dec)) + dec) / digit_count(dec);
		}
	return (neg ? num * -1 : num);
}

void array_char_to_float(float coord[3], char *array)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 3)
		{
			coord[i] = char_to_float(array + count);
			while (array[count] == '.' || array[count] == '-' || ft_isdigit(array[count]))
				count++;
			if (array[count] == ',')
				count++;
			i++;
		}
}
