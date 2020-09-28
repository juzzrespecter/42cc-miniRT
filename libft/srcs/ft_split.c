/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:21:48 by danrodri          #+#    #+#             */
/*   Updated: 2019/11/18 22:21:00 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_tablen(char const *s, char *delim)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (ft_strchr(delim, s[i]))
			i++;
		if (s[i] && !ft_strchr(delim, s[i]))
			len++;
		while (s[i] && !ft_strchr(delim, s[i]))
			i++;
	}
	len++;
	return (len);
}

static int		ft_slen(char const *s, char *delim, int i)
{
	int	len;

	len = 0;
	while (s[i] && !ft_strchr(delim, s[i]))
	{
		len++;
		i++;
	}
	return (len);
}

char			**ft_split(char const *s, char *delim)
{
	char	**tab;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char **) * ft_tablen(s, delim))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (ft_strchr(delim, s[i]))
			i++;
		if (s[i])
		{
			tab[j] = ft_substr(s, i, ft_slen(s, delim, i));
			j++;
		}
		while (s[i] && !ft_strchr(delim, s[i]))
			i++;
	}
	tab[j] = NULL;
	return (tab);
}
