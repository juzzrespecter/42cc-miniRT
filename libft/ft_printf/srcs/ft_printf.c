/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 17:00:38 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/01 17:42:33 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	reset_flags(t_flst *flags)
{
	flags->minus = false;
	flags->zero = false;
	flags->prec[0] = 0;
	flags->prec[1] = 0;
	flags->width = 0;
}

static int	get_flags(t_flst *flags, char *fmt, va_list args)
{
	int count;

	count = 0;
	count += flag_format(flags, fmt);
	count += minfieldwidth_format(flags, fmt + count, args);
	count += prec_format(flags, fmt + count, args);
	return (count);
}

static int	choose_your_fighter(char spec, va_list args, t_flst *flags)
{
	if (spec == 'd' || spec == 'i')
		return (d_type(args, flags));
	if (spec == 'x' || spec == 'X')
		return (x_type(args, spec, flags));
	if (spec == 'u')
		return (u_type(args, flags));
	if (spec == 's')
		return (s_type(args, flags));
	if (spec == 'c')
		return (c_type(args, flags));
	if (spec == 'p')
		return (p_type(args, flags));
	if (spec == '%')
		return (per_type(flags));
	return (0);
}

int			ft_printf(char *fmt, ...)
{
	t_flst	flags;
	va_list	args;
	int		count;
	int		len;

	len = 0;
	count = 0;
	va_start(args, fmt);
	while (fmt[count])
	{
		if (fmt[count] == '%')
		{
			count++;
			reset_flags(&flags);
			count += get_flags(&flags, fmt + count, args);
			len += choose_your_fighter(fmt[count], args, &flags);
		}
		else
			len += write(1, &fmt[count], 1);
		count++;
	}
	va_end(args);
	return (len);
}
