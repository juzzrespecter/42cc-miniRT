/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:06:17 by danrodri          #+#    #+#             */
/*   Updated: 2020/10/03 17:18:54 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_and_out(char *to_free)
{
	free(to_free);
	return (-1);
}

static int	save_and_out(char *aux, char *b)
{
	ft_strlcpy(b, aux + 1, ft_strlen(aux + 1) + 1);
	ft_bzero(aux, ft_strlen(aux));
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	b[BUFFER_SIZE + 1] = {0};
	char		*aux;
	int			r_out;

	if (!line || fd < 0 || !BUFFER_SIZE)
		return (-1);
	if (!(*line = ft_strdup(b)))
		return (-1);
	ft_bzero(b, BUFFER_SIZE + 1);
	if ((aux = ft_strchr(*line, '\n')))
			return (save_and_out(aux, b));
	while ((r_out = read(fd, b, BUFFER_SIZE)))
	{
		aux = *line;
		if (r_out < 0)
			return (free_and_out(aux));
		if (!(*line = ft_strjoin(*line, b)))
			return (free_and_out(aux));
		free(aux);
		ft_bzero(b, BUFFER_SIZE + 1);
		if ((aux = ft_strchr(*line, '\n')))
			return (save_and_out(aux, b));
	}
	return (0);
}
