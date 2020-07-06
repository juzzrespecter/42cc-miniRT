/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:24:51 by danrodri          #+#    #+#             */
/*   Updated: 2020/07/06 17:37:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool light_check(char *light)
{
	int i;

	i = 0;
	if (light[i] == '0' || light[i] == '1')
		i++;
	if (light[i] == '.' && i == 1)
		i++;
	if (ft_isdigit(light[i]) && i == 2)
		i++;
	if (i == 1 && !light[i])
		return (true);
	if (i == 3 && light[0] != '1' && !light[i])
		return (true);
	return (false);
}
