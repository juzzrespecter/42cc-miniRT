/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:15:27 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/29 13:04:20 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ptr_width_writer(int len, unsigned long addr, t_flst *flags)
{
	int i;

	i = 0;
	if (!addr && flags->prec[0] == -1)
		len = 0;
	if (flags->prec[0] && flags->prec[1] > len)
		len = flags->prec[1];
	len += 2;
	if (flags->width)
		while (len + i < flags->width)
			i += write(1, " ", 1);
	return (i);
}

static int	ptr_prec_writer(int len, t_flst *flags)
{
	int i;

	i = 0;
	if (flags->prec[0] && flags->prec[1] > len)
		while (len + i < flags->prec[1])
			i += write(1, "0", 1);
	return (i);
}

static int	ptr_writer(int len, char *str, t_flst *flags)
{
	int i;

	if (!ft_strncmp(str, "0", len) && flags->prec[0] == -1)
		return (0);
	i = write(1, str, len);
	return (i);
}

int			p_type(va_list vars, t_flst *flags)
{
	int				count;
	int				addr_len;
	unsigned long	addr;
	char			*addr_str;

	count = 0;
	addr = va_arg(vars, unsigned long);
	if (!(addr_str = ft_ultoa_base(addr, "0123456789abcdef")))
		return (0);
	addr_len = ft_strlen(addr_str);
	if (!flags->minus)
		count += ptr_width_writer(addr_len, addr, flags);
	count += write(1, "0x", 2);
	count += ptr_prec_writer(addr_len, flags);
	count += ptr_writer(addr_len, addr_str, flags);
	if (flags->minus)
		count += ptr_width_writer(addr_len, addr, flags);
	free(addr_str);
	return (count);
}
