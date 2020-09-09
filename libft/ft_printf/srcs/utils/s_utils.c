/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:55:49 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 20:06:58 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	str_width(int len, t_flst *flags)
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

int	str_writer(char *str, int len, t_flst *flags)
{
	int	count;

	count = 0;
	if (flags->prec[0] == -1)
		return (0);
	if (flags->prec[0] && flags->prec[1] < len && flags->prec[1] > 0)
		len = flags->prec[1];
	count += write(1, str, len);
	return (count);
}

int	wcs_writer(wchar_t *wcs, int len, t_flst *flags)
{
	int		count;
	char	*u8_char;

	count = 0;
	if (flags->prec[0] == -1)
		return (0);
	if (flags->prec[0] && flags->prec[1] < len && flags->prec[1] > 0)
		len = flags->prec[1];
	while (wcs[count] && count < len)
	{
		u8_char = u8_encoder(wcs[count]);
		write(1, &u8_char, ft_strlen(u8_char));
		count++;
	}
	return (count);
}

int	str_nullstr(t_flst *flags)
{
	char	*str;
	int		str_len;
	int		count;

	count = 0;
	str = ft_strdup("(null)");
	str_len = 6;
	if (!flags->minus)
		count += str_width(str_len, flags);
	count += str_writer(str, str_len, flags);
	if (flags->minus)
		count += str_width(str_len, flags);
	free(str);
	return (count);
}

int	wcs_type(va_list vars, t_flst *flags)
{
	int		count;
	int		wcs_len;
	wchar_t	*wcs;

	count = 0;
	wcs = va_arg(vars, wchar_t*);
	if (!wcs)
		return (str_nullstr(flags));
	wcs_len = ft_wcslen(wcs);
	if (!flags->minus)
		count += str_width(wcs_len, flags);
	count += wcs_writer(wcs, wcs_len, flags);
	if (flags->minus)
		count += str_width(wcs_len, flags);
	return (count);
}
