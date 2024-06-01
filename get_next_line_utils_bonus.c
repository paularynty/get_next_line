/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:58:15 by prynty            #+#    #+#             */
/*   Updated: 2024/06/01 12:31:12 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str++)
		i++;
	return (i);
}

char	*ft_strchr(char *str, char chr)
{
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}

void	ft_bzero(char *buf, size_t size)
{
	while (size-- > 0)
		buf[size] = '\0';
}

void	ft_copy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strjoin(char *dst, char *src, size_t len)
{
	char			*joined;
	char			*ptr;
	size_t			bytes;
	unsigned int	i;

	if (!*src)
		return (dst);
	if (dst == NULL || src == NULL)
		return (NULL);
	bytes = ft_strlen(dst) + len + 1;
	joined = malloc(bytes);
	if (joined == NULL)
	{
		free(dst);
		return (NULL);
	}
	i = 0;
	ptr = dst;
	while (*dst)
		joined[i++] = *dst++;
	while (i < bytes - 1)
		joined[i++] = *src++;
	free(ptr);
	joined[i] = '\0';
	return (joined);
}
