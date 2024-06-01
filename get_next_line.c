/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:55:28 by prynty            #+#    #+#             */
/*   Updated: 2024/06/01 15:22:31 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init(char **next_line, char **nl, char *buf, int fd)
{
	if (fd < 0)
		return (0);
	*next_line = malloc(1);
	if (*next_line == NULL)
		return (0);
	**next_line = '\0';
	*nl = ft_strchr(buf, '\n');
	return (1);
}

static int	read_to_buf(int fd, char *buf, char **next_line)
{
	ssize_t	bytes_read;

	ft_bzero(buf, BUFFER_SIZE + 1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(*next_line);
		return (-1);
	}
	if (bytes_read == 0)
	{
		if (**next_line == '\0')
		{
			free(*next_line);
			return (-1);
		}
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*nl;
	int			read_result;

	if (init(&line, &nl, buf, fd) == 0)
		return (NULL);
	while (nl == NULL)
	{
		line = ft_strjoin(line, buf, ft_strlen(buf));
		if (!line)
			return (NULL);
		read_result = read_to_buf(fd, buf, &line);
		if (read_result == -1)
			return (NULL);
		if (read_result == 0)
			return (line);
		nl = ft_strchr(buf, '\n');
	}
	line = ft_strjoin(line, buf, (nl - buf) + 1);
	if (!line)
		return (NULL);
	ft_copy(buf, nl + 1);
	return (line);
}
