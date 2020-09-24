/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:24:51 by danrodri          #+#    #+#             */
/*   Updated: 2020/09/24 19:27:02 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	light_check(char *light)
{
	int i;

	i = 0;
	if (light[i] == '0' || light[i] == '1')
		i++;
	if (light[i] == '.' && i == 1)
		i++;
	if (light[0] == '0' && ft_isdigit(light[i]) && i == 2)
		i++;
	if (light[0] == '1' && light[i] == '0' && i == 2)
		i++;
	if ((i == 1 || i == 3) && !light[i])
		return (true);
	return (false);
}
