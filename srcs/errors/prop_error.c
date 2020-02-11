/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prop_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:14:20 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/11 20:04:35 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int prop_error(char *prop)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (ft_isdigit(prop[i]))
		i++;
	if (!i || !(prop[i] == '.'))
		return (0);
	if (!prop[i])
		return (1);
	i++;
	while (ft_isdigit(prop[i + j]))
		j++;
	if (!j)
		return (0);
	return (!(prop[i + j]) ? 1 : 0);
}
