/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_type_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:44:44 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/03 18:44:45 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int			u_type(va_list vars, t_flst *flags)
{
	int				count;
	int				u_len;
	char			*u_str;

	count = 0;
	if (!(u_str = u_lenfield(vars, flags)))
		return (0);
	u_len = ft_strlen(u_str);
	if (!flags->minus)
		count += u_width(u_len, u_str, flags);
	count += u_writer(u_str, u_len, flags);
	if (flags->minus)
		count += u_width(u_len, u_str, flags);
	free(u_str);
	return (count);
}
