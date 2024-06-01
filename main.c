/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prynty <prynty@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:48:00 by prynty            #+#    #+#             */
/*   Updated: 2024/06/01 12:55:30 by prynty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	line = get_next_line(fd);
	while (*(++argv))
	{
		fd = open(*argv, O_RDONLY);
		if (fd < 0)
		{
			printf("Failed to open file\n");
			return (1);
		}
		printf("\nOpened file %s\n", *argv);
		while (line != NULL)
		{
			printf("Next line = %s", line);
			free (line);
		}
		printf("\n");
		close(fd);
	}
	return (0);
}
