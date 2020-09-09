/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:16:02 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/29 14:40:22 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	u_width_writer(int len, int u, t_flst *flags)
{
	int i;

	i = 0;
	if (flags->prec[1] > len)
		len = flags->prec[1];
	if (flags->prec[0] == -1 && !u)
		len = 0;
	if (flags->zero && flags->width)
		while (len + i < flags->width)
			i += write(1, "0", 1);
	if ((!flags->zero || flags->prec[0]) && flags->width)
		while (len + i < flags->width)
			i += write(1, " ", 1);
	return (i);
}

static int	u_prec_writer(int len, t_flst *flags)
{
	int i;

	i = 0;
	if (flags->prec[0] && flags->prec[1] > len)
		while (len + i < flags->prec[1])
			i += write(1, "0", 1);
	return (i);
}

static int	u_writer(char *str, int len, unsigned int u, t_flst *flags)
{
	int count;

	count = 0;
	if (flags->prec[0] == -1 && !u)
		return (0);
	count += write(1, str, len);
	return (count);
}

int			u_type(va_list vars, t_flst *flags)
{
	int				count;
	int				u_len;
	unsigned int	u;
	char			*u_str;

	count = 0;
	u = va_arg(vars, int);
	if (!(u_str = ft_ultoa_base(u, "0123456789")))
		return (0);
	u_len = ft_strlen(u_str);
	if (!flags->minus)
		count += u_width_writer(u_len, u, flags);
	count += u_prec_writer(u_len, flags);
	count += u_writer(u_str, u_len, u, flags);
	if (flags->minus)
		count += u_width_writer(u_len, u, flags);
	free(u_str);
	return (count);
}
