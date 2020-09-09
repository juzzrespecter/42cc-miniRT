/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 17:39:49 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 20:11:45 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int		u_width(int len, char *str, t_flst *flags)
{
	int i;

	i = 0;
	if (flags->prec[1] > len)
		len = flags->prec[1];
	if (flags->prec[0] == -1 && !ft_strncmp(str, "0", len))
		len = 0;
	if ((!flags->zero || flags->prec[0]) && flags->width)
		while (len + i < flags->width)
			i += write(1, " ", 1);
	return (i);
}

int		u_writer(char *str, int len, t_flst *flags)
{
	int count;
	int z_len;

	z_len = 0;
	count = 0;
	if (flags->prec[0] == -1 && !ft_strncmp(str, "0", len))
		return (0);
	if (flags->zero && flags->width)
		z_len = flags->width;
	if (flags->prec[0] && flags->prec[1] > len)
		z_len = flags->prec[1];
	while (count + len < z_len)
		count += write(1, "0", 1);
	count += write(1, str, len);
	return (count);
}

char	*u_lenfield(va_list vars, t_flst *flags)
{
	char base[11];

	ft_strlcpy(base, "01234567890", 11);
	if (flags->h)
		return (ft_ulltoa_base((unsigned char)va_arg(vars, int), base));
	if (flags->h)
		return (ft_ulltoa_base((unsigned short)va_arg(vars, int), base));
	if (flags->h)
		return (ft_ulltoa_base((unsigned long)va_arg(vars, int), base));
	if (flags->h)
		return (ft_ulltoa_base((unsigned long long)va_arg(vars, int), base));
	return (ft_ulltoa_base((unsigned int)va_arg(vars, int), base));
}
