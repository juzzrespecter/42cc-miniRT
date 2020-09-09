/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 19:20:25 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/26 20:24:24 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	char_width_writer(t_flst *flags)
{
	int count;

	count = 0;
	if (flags->width)
		while (count + 1 < flags->width)
			count += write(1, " ", 1);
	return (count);
}

int			c_type(va_list vars, t_flst *flags)
{
	wchar_t	c;
	int		count;

	count = 0;
	c = va_arg(vars, int);
	if (!flags->minus)
		count += char_width_writer(flags);
	count += write(1, &c, 1);
	if (flags->minus)
		count += char_width_writer(flags);
	return (count);
}
