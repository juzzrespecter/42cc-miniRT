/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:04:48 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:11:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	array_to_color(char *array)
{
	int		count;
	t_color	color;

	count = 0;
	color.r = (float)ft_atoi(array + count) / (float)255;
	while (ft_isdigit(array[count]))
		count++;
	if (array[count] == ',')
		count++;
	color.g = (float)ft_atoi(array + count) / (float)255;
	while (ft_isdigit(array[count]))
		count++;
	if (array[count] == ',')
		count++;
	color.b = (float)ft_atoi(array + count) / (float)255;
	return (color);
}
