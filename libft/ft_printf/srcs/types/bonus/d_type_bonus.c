/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_type_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:44:18 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 18:44:22 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int			d_type(va_list vars, t_flst *flags)
{
	int		count;
	int		i_len;
	char	*i_str;

	count = 0;
	i_str = dec_lenfield(vars, flags);
	if (!(i_str))
		return (0);
	i_len = ft_strlen(i_str);
	if (i_str[0] == '-')
		i_len -= 1;
	if (!flags->minus)
		count += dec_minfieldwidth(i_len, i_str, flags);
	count += dec_writer(i_str, i_len, flags);
	if (flags->minus)
		count += dec_minfieldwidth(i_len, i_str, flags);
	free(i_str);
	return (count);
}
