/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:49:37 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/29 13:14:38 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	prec_format(t_flst *flags, char *fmt, va_list vars)
{
	int count;

	count = 0;
	if (fmt[count] == '.')
	{
		flags->prec[0] = 1;
		count++;
		if (ft_isdigit(fmt[count]))
		{
			flags->prec[1] = ft_atoi(fmt + count);
			while (ft_isdigit(fmt[count]))
				count++;
		}
		if (fmt[count] == '*')
		{
			flags->prec[1] = va_arg(vars, int);
			count++;
		}
		if (flags->prec[0] && !flags->prec[1])
			flags->prec[0] = -1;
		if (flags->prec[1] >= 0)
			flags->zero = false;
	}
	return (count);
}
