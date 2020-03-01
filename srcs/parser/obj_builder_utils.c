/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_builder_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:41:12 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 17:55:07 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float bright_str_to_f(char *br_str)
{
	return (10.0 / (float)(br_str[2] - 48));
}

void color_str_to_i(char *color_str, unsigned char *color)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
		{
			color[i] = (unsigned char)ft_atoi(color_str + j);
			while (ft_isdigit(color_str[j]))
				j++;
			j++;
			i++;
		}
}

float str_to_f(char *fp_str)
{
	int fraction;
	int ten_pow;
	int neg;
	float fp_number;
	int i;

	fp_number = (float)ft_atoi(fp_str);
	fraction = 0;
	i = 0;
	neg = 1;
	if (fp_str[i] == '-')
		{
			i++;
			neg *= -1;
		}
	while (ft_isdigit(fp_str[i]))
		i++;
	if (fp_str[i] == '.')
		{
			i++;
			if ((fraction = ft_atoi(fp_str + i)))
				{
					ten_pow = (int)pow(10, ft_strlen(fp_str + i));
					fp_number = ((fp_number * ten_pow) + (fraction * neg)) / ten_pow;
				}
		}
	return (fp_number);
}

void coord_str_to_f(char *coord_str, float *coord)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
		{
			coord[i] = str_to_f(coord_str + j);
			if (coord_str[j] == '-')
				j++;
			while (ft_isdigit(coord_str[j]))
				j++;
			if (coord_str[j] == '.')
				{
					j++;
					while (ft_isdigit(coord_str[j]))
						j++;
				}
			j++;
			i++;
		}
}
