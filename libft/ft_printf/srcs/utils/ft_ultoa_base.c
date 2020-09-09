/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:15:55 by danrodri          #+#    #+#             */
/*   Updated: 2020/01/27 19:15:59 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_len(unsigned long i, int b_len)
{
	int i_len;

	i_len = 0;
	while (i > (unsigned int)b_len - 1)
	{
		i /= (unsigned int)b_len;
		i_len++;
	}
	i_len++;
	return (i_len);
}

static char	*ft_rev_a(char *a)
{
	int		a_len;
	int		i;
	char	aux;

	a_len = ft_strlen(a);
	i = 0;
	while (i < a_len / 2)
	{
		aux = a[i];
		a[i] = a[a_len - (i + 1)];
		a[a_len - (i + 1)] = aux;
		i++;
	}
	return (a);
}

static int	ft_check_base(char *base)
{
	int count;

	count = 0;
	if (!base || ft_strlen(base) == 1)
		return (0);
	while (base[count])
	{
		if (ft_strchr(base + count + 1, base[count]))
			return (0);
		count++;
	}
	return (1);
}

char		*ft_ultoa_base(unsigned long i, char *base)
{
	char	*a;
	int		count;
	int		b_len;
	int		i_len;

	if (!ft_check_base(base))
		return (NULL);
	b_len = ft_strlen(base);
	i_len = get_len(i, b_len);
	if (!(a = malloc(sizeof(char) * (i_len + 1))))
		return (NULL);
	count = 0;
	while (count < i_len)
	{
		a[count] = base[i % b_len];
		i /= b_len;
		count++;
	}
	a[count] = 0;
	ft_rev_a(a);
	return (a);
}
