/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:06:17 by danrodri          #+#    #+#             */
/*   Updated: 2019/12/02 13:37:10 by danrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_nl(char *buff)
{
	int	nl_pos;

	nl_pos = 0;
	while (buff[nl_pos] && buff[nl_pos] != '\n')
		nl_pos++;
	if (buff[nl_pos] == '\n')
		return (nl_pos);
	return (-1);
}

static void		get_buffer(char *lost_buff, char *buff, int nl_pos)
{
	ft_strlcpy(lost_buff, buff, nl_pos);
	ft_strlcpy(buff, buff + nl_pos + 1, BUFFER_SIZE - nl_pos);
}

static void		save_line(char **line, char *lost_buff, char *buff)
{
	int		nl_pos;
	char	buff_aux[BUFFER_SIZE + 1];

	if ((nl_pos = check_nl(buff)) == -1)
		*line = ft_strjoin(*line, buff);
	else
	{
		ft_strlcpy(lost_buff, buff, BUFFER_SIZE + 1);
		get_buffer(buff_aux, lost_buff, nl_pos);
		*line = ft_strjoin(*line, buff_aux);
	}
}

static size_t	read_line(char **line, char *lost_buff, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*line_aux;
	int		nl_pos;
	int		r_out;

	ft_memset(buff, 0, BUFFER_SIZE + 1);
	while ((nl_pos = check_nl(buff)) == -1)
	{
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		r_out = read(fd, buff, BUFFER_SIZE);
		if (!r_out)
			return (0);
		if (r_out < 0)
			return (-1);
		line_aux = *line;
		save_line(line, lost_buff, buff);
		free(line_aux);
		if (!*line)
			return (-1);
	}
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	lost_buff[BUFFER_SIZE + 1] = {0};
	char		buff_aux[BUFFER_SIZE + 1];
	int			nl_pos;

	if (!line || fd < 0 || !BUFFER_SIZE)
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (*lost_buff)
	{
		free(*line);
		if ((nl_pos = check_nl(lost_buff)) >= 0)
		{
			get_buffer(buff_aux, lost_buff, nl_pos);
			*line = ft_strdup(buff_aux);
			return (*line ? 1 : -1);
		}
		else
		{
			if (!(*line = ft_strdup(lost_buff)))
				return (-1);
			ft_memset(lost_buff, 0, BUFFER_SIZE + 1);
		}
	}
	return (read_line(line, lost_buff, fd));
}
