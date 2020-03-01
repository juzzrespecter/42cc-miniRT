/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:37:46 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 16:04:26 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

bool colors_err(char *colors)
{
	int i;
	int count;

	i = 0;
	if (!(count = check_color(colors + i, 0)))
		return (false);
	i += count + 1;
	if (!(count = check_color(colors + i, 0)))
		return (false);
	i += count + 1;
	if (!(count = check_color(colors + i, 1)))
		return (false);
	i += count;
	if (colors[i])
		return (false);
	return (true);
}
