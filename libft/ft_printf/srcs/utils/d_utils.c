/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:12:04 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 20:02:53 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int		dec_sign_writer(char *str, t_flst *flags)
{
	int count;

	count = 0;
	if (str[0] == '-')
		count += write(1, "-", 1);
	else
	{
		if (flags->plus)
			count += write(1, "+", 1);
		if (flags->space)
			count += write(1, " ", 1);
	}
	return (count);
}

int		dec_writer(char *str, int len, t_flst *flags)
{
	int i_count;
	int z_count;
	int z_len;

	i_count = 0;
	z_count = 0;
	z_len = 0;
	if (flags->prec[0] == -1 && !ft_strncmp(str, "0", len))
		return (0);
	if (flags->width && flags->zero)
		z_len = flags->width - len;
	if (flags->prec[0] && flags->prec[1] > len)
		z_len = flags->prec[1] - len;
	if (str[0] == '-')
		i_count += dec_sign_writer(str, flags);
	if (flags->width && flags->zero && str[0] == '-')
		z_len--;
	while (z_count < z_len)
		z_count += write(1, "0", 1);
	while (str[i_count])
		i_count += write(1, &str[i_count], 1);
	return (i_count + z_count);
}

char	*dec_lenfield(va_list vars, t_flst *flags)
{
	char *i_str;

	if (flags->hh)
		return (i_str = ft_itoa((char)va_arg(vars, long long)));
	if (flags->h)
		return (i_str = ft_itoa((char)va_arg(vars, long long)));
	if (flags->l)
		return (i_str = ft_lltoa((long)va_arg(vars, long long)));
	if (flags->ll)
		return (i_str = ft_lltoa((long long)va_arg(vars, long long)));
	return (i_str = ft_itoa(va_arg(vars, int)));
}

int		dec_minfieldwidth(int len, char *str, t_flst *flags)
{
	int i_neg;
	int width;
	int count;
	int prec;

	count = 0;
	i_neg = 0;
	width = 0;
	prec = len;
	if (str[0] == '-')
		i_neg = 1;
	if (flags->width && !flags->zero)
		width = flags->width;
	if (flags->prec[0] && flags->prec[1] > len)
		prec = flags->prec[1];
	if (flags->prec[0] == -1 && !ft_strncmp(str, "0", len))
		prec = 0;
	while (count + i_neg + prec < width)
		count += write(1, " ", 1);
	return (count);
}
