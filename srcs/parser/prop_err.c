/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prop_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:03:04 by danrodri          #+#    #+#             */
/*   Updated: 2020/03/01 16:03:19 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool prop_err(char *prop)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_isdigit(prop[i]))
		i++;
	if (!i || !(prop[i] == '.'))
		return (false);
	if (!prop[i])
		return (true);
	i++;
	while (ft_isdigit(prop[i + j]))
		j++;
	if (!j)
		return (0);
	return (!(prop[i + j]) ? true : false);
}
