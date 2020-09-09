/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:32:56 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 20:10:38 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	c_type(va_list vars, t_flst *flags)
{
	wchar_t	c;
	char	*u8_char;
	int		count;

	count = 0;
	c = va_arg(vars, int);
	if (!flags->minus)
		count += char_width(flags);
	if (flags->l)
	{
		u8_char = u8_encoder(c);
		write(1, u8_char, ft_strlen(u8_char));
		count++;
	}
	else
		count += write(1, &c, 1);
	if (flags->minus)
		count += char_width(flags);
	return (count);
}
