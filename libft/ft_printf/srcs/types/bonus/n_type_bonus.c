/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_type_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:34:27 by danrodri          #+#    #+#             */
/*   Updated: 2020/02/02 19:48:10 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf_bonus.h"

int	n_type(va_list args, t_flst *flags, int len)
{
	if (flags->hh)
		*(va_arg(args, char *)) = len;
	else if (flags->h)
		*(va_arg(args, short *)) = len;
	else if (flags->l)
		*(va_arg(args, long *)) = len;
	else if (flags->ll)
		*(va_arg(args, long long *)) = len;
	else
		*(va_arg(args, int *)) = len;
	return (0);
}
