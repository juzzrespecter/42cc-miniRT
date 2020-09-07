/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:32:25 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/07 20:07:39 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector array_to_vector(char *array)
{
	int count;
	t_vector vector;

	count = 0;
	vector.x = array_to_float(array + count);
	while (array[count] == '.' || array[count] == '-' || ft_isdigit(array[count]))
		count++;
	if (array[count] == ',')
		count++;
	vector.y = array_to_float(array + count);
	while (array[count] == '.' || array[count] == '-' || ft_isdigit(array[count]))
		count++;
	if (array[count] == ',')
		count++;
	vector.z = array_to_float(array + count);
	return (vector);
}
