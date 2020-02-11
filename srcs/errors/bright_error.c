/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bright_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:03:10 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 18:42:08 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int bright_error(char *bright)
{
	int i;

	i = 0;
	while (bright[i] && i < 3)
		{
			if (i == 0 && !(bright[i] == '0' || bright[i] == '1'))
				return (0);
			if (i == 1 && (bright[i] != '.'))
				break;
			if (i == 2 && bright[0] == '0' && !(bright[i] >= '0' && bright[i] <= '9'))
				return (0);
			if (i == 2 && bright[0] == '1' && !(bright[i] == '0'))
				return (0);
			i++;
		}
	if (!(i == 1 || i == 3))
		return (0);
	if (i == 1)
		i++;
	return ((!bright[i]) ? 1 : 0);
}
