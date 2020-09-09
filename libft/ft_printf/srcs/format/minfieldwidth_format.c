/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minfieldwidth_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:53:26 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/02 18:51:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	minfieldwidth_format(t_flst *flags, char *fmt, va_list vars)
{
	int count;
	int aux;

	count = 0;
	if (ft_isdigit(fmt[count]))
	{
		flags->width = ft_atoi(fmt);
		while (ft_isdigit(fmt[count]))
			count++;
	}
	else if (fmt[count] == '*')
	{
		aux = va_arg(vars, int);
		if (aux < 0)
		{
			aux *= -1;
			flags->minus = true;
			flags->zero = false;
		}
		flags->width = aux;
		count++;
	}
	return (count);
}
