/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:32:25 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:15:01 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	array_to_vector(char *s)
{
	int			count;
	t_vector	vector;

	count = 0;
	vector.x = array_to_float(s + count);
	while (s[count] == '.' || s[count] == '-' || ft_isdigit(s[count]))
		count++;
	if (s[count] == ',')
		count++;
	vector.y = array_to_float(s + count);
	while (s[count] == '.' || s[count] == '-' || ft_isdigit(s[count]))
		count++;
	if (s[count] == ',')
		count++;
	vector.z = array_to_float(s + count);
	return (vector);
}
