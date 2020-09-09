/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 18:46:51 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/01 17:41:51 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	flag_format(t_flst *flags, char *fmt)
{
	int count;

	count = 0;
	while (ft_strchr("0-", fmt[count]))
	{
		if (fmt[count] == '-')
			flags->minus = true;
		if (fmt[count] == '0')
			flags->zero = true;
		count++;
	}
	if (flags->minus)
		flags->zero = false;
	return (count);
}
