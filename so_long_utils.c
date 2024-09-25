/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:47:22 by timanish          #+#    #+#             */
/*   Updated: 2024/09/25 15:47:44 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	printf("%s\n", message);
	exit (1);
}

int	line_count(char *argv)
{
	int		fd;
	char	buffer;
	int		line;

	line = 1;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			line ++;
	}
	close (fd);
	return (line);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i ++;
	}
	free(map);
}