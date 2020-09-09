/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 20:13:29 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/28 19:13:22 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	str_width_writer(int len, t_flst *flags)
{
	int i;

	i = 0;
	if (flags->prec[0] && (flags->prec[1] >= 0 && flags->prec[1] < len))
		len = flags->prec[1];
	if (flags->prec[0] == -1)
		len = 0;
	if (flags->width && (!flags->zero || flags->minus))
		while (len + i < flags->width)
			i += write(1, " ", 1);
	if (flags->width && (flags->zero && !flags->minus))
		while (len + i < flags->width)
			i += write(1, "0", 1);
	return (i);
}

static int	str_writer(void *str, int len, t_flst *flags)
{
	int		count;

	count = 0;
	if (flags->prec[0] == -1)
		return (0);
	if (flags->prec[0] && flags->prec[1] < len && flags->prec[1] > 0)
		len = flags->prec[1];
	count += write(1, str, len);
	return (count);
}

static int	nullstr(t_flst *flags)
{
	char	*str;
	int		str_len;
	int		count;

	count = 0;
	str = ft_strdup("(null)");
	str_len = 6;
	if (!flags->minus)
		count += str_width_writer(str_len, flags);
	count += str_writer(str, str_len, flags);
	if (flags->minus)
		count += str_width_writer(str_len, flags);
	free(str);
	return (count);
}

int			s_type(va_list vars, t_flst *flags)
{
	int		count;
	int		str_len;
	void	*str;

	count = 0;
	str = va_arg(vars, char*);
	if (!str)
		return (nullstr(flags));
	str_len = ft_strlen(str);
	if (!flags->minus)
		count += str_width_writer(str_len, flags);
	count += str_writer(str, str_len, flags);
	if (flags->minus)
		count += str_width_writer(str_len, flags);
	return (count);
}
