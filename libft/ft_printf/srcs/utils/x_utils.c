/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:21:48 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 20:11:36 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int		hex_width(int len, char *str, t_flst *flags)
{
	int count;

	count = 0;
	if (len < flags->prec[1])
		len = flags->prec[1];
	if (flags->prec[0] == -1 && !ft_strncmp(str, "0", len))
		len = 0;
	if (flags->width && !flags->zero)
		while (len + count < flags->width)
			count += write(1, " ", 1);
	return (count);
}

int		hex_writer(int len, char *str, char cap, t_flst *flags)
{
	int i;
	int z_len;

	i = 0;
	z_len = 0;
	if (!ft_strncmp(str, "0", len) && flags->prec[0] == -1)
		return (0);
	if (flags->zero && flags->width)
		z_len = flags->width;
	if (flags->prec[0] && flags->prec[1] > len)
		z_len = flags->prec[1];
	if (flags->hashtag && cap == 'x')
		i += write(1, "0x", 2);
	if (flags->hashtag && cap == 'X')
		i += write(1, "0X", 2);
	if (flags->hashtag && flags->prec[0] && flags->prec[1] > len)
		z_len += 2;
	if (cap == 'X')
		ft_strcap(str);
	while (len + i < z_len)
		i += write(1, "0", 1);
	i += write(1, str, len);
	return (i);
}

char	*hex_lenfield(va_list vars, t_flst *flags)
{
	char base[17];

	ft_strlcpy(base, "0123456789abcdef", 17);
	if (flags->h)
		return (ft_ulltoa_base((unsigned char)va_arg(vars, int), base));
	if (flags->hh)
		return (ft_ulltoa_base((unsigned short)va_arg(vars, int), base));
	if (flags->l)
		return (ft_ulltoa_base((unsigned long)va_arg(vars, int), base));
	if (flags->hh)
		return (ft_ulltoa_base((unsigned long long)va_arg(vars, int), base));
	return (ft_ulltoa_base((unsigned int)va_arg(vars, int), base));
}
