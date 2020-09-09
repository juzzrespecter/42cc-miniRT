/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:45:19 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 18:45:23 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int			x_type(va_list vars, char cap, t_flst *flags)
{
	int				count;
	int				hex_len;
	char			*hex_str;

	count = 0;
	if (!(hex_str = hex_lenfield(vars, flags)))
		return (0);
	hex_len = ft_strlen(hex_str);
	if (!flags->minus)
		count += hex_width(hex_len, hex_str, flags);
	count += hex_writer(hex_len, hex_str, cap, flags);
	if (flags->minus)
		count += hex_width(hex_len, hex_str, flags);
	free(hex_str);
	return (count);
}
