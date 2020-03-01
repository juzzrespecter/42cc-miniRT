/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bright_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:56:39 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 16:02:52 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool bright_err(char *bright)
{
	int i;

	i = 0;
	while (bright[i] && i < 3)
		{
			if (i == 0 && !(bright[i] == '0' || bright[i] == '1'))
				return (false);
			if (i == 1 && (bright[i] != '.'))
				break;
			if (i == 2 && bright[0] == '0' && !(bright[i] >= '0' && bright[i] <= '9'))
				return (false);
			if (i == 2 && bright[0] == '1' && !(bright[i] == '0'))
				return (false);
			i++;
		}
	if (!(i == 1 || i == 3))
		return (false);
	if (i == 1)
		i++;
	return ((!bright[i]) ? true : false);
}
