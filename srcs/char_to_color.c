/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_to_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:24:47 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/07 18:28:14 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void char_to_color(unsigned char color[3], char *array)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i < 3)
		{
			color[i] = ft_atoi(array + count);
			while (ft_isdigit(array[count]))
				count++;
			if (array[count] == ',')
				count++;
			i++;
		}
}
