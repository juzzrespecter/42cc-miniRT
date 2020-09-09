/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:12:09 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/29 15:06:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	per_type(t_flst *flags)
{
	int count;

	count = 0;
	if ((!flags->minus && !flags->zero) && flags->width)
		while (count + 1 < flags->width)
			count += write(1, " ", 1);
	if (!flags->minus && flags->zero && flags->width)
		while (count + 1 < flags->width)
			count += write(1, "0", 1);
	count += write(1, "%", 1);
	if (flags->minus && flags->width)
		while (count < flags->width)
			count += write(1, " ", 1);
	return (count);
}
