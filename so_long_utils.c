/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:47:22 by timanish          #+#    #+#             */
/*   Updated: 2024/09/25 17:50:56 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	printf("%s\n", message);
	exit (1);
}

int	line_count(char *argv, t_mapdate *date)
{
	int		fd;
	char	buffer;
	int		line;

	line = 1;
	fd = open(argv, O_RDONLY);
	date->collect_item = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			line ++;
		else if (buffer == 'C')
			date->collect_item += 1;
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