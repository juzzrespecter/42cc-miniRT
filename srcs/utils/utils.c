/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 19:55:53 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/01 21:12:01 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_max(double a, double b)
{
	return ((a > b) ? a : b);
}

double	ft_min(double a, double b)
{
	return ((a < b) ? a : b);
}

void	ft_split_free(char **table)
{
	int count;

	count = 0;
	while (table[count])
	{
		free(table[count]);
		count++;
	}
	free(table);
}
