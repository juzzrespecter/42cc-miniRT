/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:37:46 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 17:09:42 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int check_color(char *colors, int nocomma)
{
	int i;

	i = 0;
	while (ft_isdigit(colors[i]) && colors[i])
		i++;
	if (i < 1 || i > 3)
		return (0);
	if (colors[i] != ',' && !nocomma)
		return (0);
	return (i);
}

int colors_error(char *colors)
{
	int i;
	int count;

	i = 0;
	if (!(count = check_color(colors + i, 0)))
		return (0);
	i += count + 1;
	if (!(count = check_color(colors + i, 0)))
		return (0);
	i += count + 1;
	if (!(count = check_color(colors + i, 1)))
		return (0);
	i += count;
	if (colors[i])
		return (0);
	return (1);
}
