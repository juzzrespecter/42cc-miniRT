/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_type_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 18:37:41 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/02 18:20:33 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int			s_type(va_list vars, t_flst *flags)
{
	int		count;
	int		str_len;
	char	*str;

	count = 0;
	if (flags->l)
		return (wcs_type(vars, flags));
	str = va_arg(vars, char*);
	if (!str)
		return (str_nullstr(flags));
	str_len = ft_strlen(str);
	if (!flags->minus)
		count += str_width(str_len, flags);
	count += str_writer(str, str_len, flags);
	if (flags->minus)
		count += str_width(str_len, flags);
	return (count);
}
