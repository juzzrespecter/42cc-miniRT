/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:32:49 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/01 18:41:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	char_width(t_flst *flags)
{
	int count;

	count = 0;
	if (flags->width)
		while (count + 1 < flags->width)
			count += write(1, " ", 1);
	return (count);
}
