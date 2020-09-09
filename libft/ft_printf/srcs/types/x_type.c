/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:08:52 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/28 19:23:33 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	hex_spaces(int len, int x, t_flst *flags)
{
	int count;

	count = 0;
	if (len < flags->prec[1])
		len = flags->prec[1];
	if (flags->prec[0] && flags->prec[1] < 1 && !x)
		len = 0;
	if (flags->width && (flags->prec[0] || !flags->zero))
		while (len + count < flags->width)
			count += write(1, " ", 1);
	return (count);
}

static int	hex_zeros(int len, t_flst *flags)
{
	int i;

	i = 0;
	if (!flags->prec[0] && flags->zero && flags->width)
		while (len + i < flags->width)
			i += write(1, "0", 1);
	if (flags->prec[1] > len)
		while (len + i < flags->prec[1])
			i += write(1, "0", 1);
	return (i);
}

int			x_type(va_list vars, char cap, t_flst *flags)
{
	int				count;
	int				hex_len;
	char			*hex_str;
	unsigned int	hex;

	count = 0;
	hex = va_arg(vars, int);
	hex_str = ft_ultoa_base(hex, "0123456789abcdef");
	if (!hex_str)
		return (0);
	if (cap == 'X')
		ft_strcap(hex_str);
	hex_len = ft_strlen(hex_str);
	if (!flags->minus)
		count += hex_spaces(hex_len, hex, flags);
	count += hex_zeros(hex_len, flags);
	if (!(!hex && flags->prec[0] && flags->prec[1] < 1))
		count += write(1, hex_str, hex_len);
	if (flags->minus)
		count += hex_spaces(hex_len, hex, flags);
	free(hex_str);
	return (count);
}
