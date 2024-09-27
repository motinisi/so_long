/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:47:22 by timanish          #+#    #+#             */
/*   Updated: 2024/09/27 19:25:12 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	int	byte;

	byte = ft_strlen(message);
	write (2, message, byte);
	exit (1);
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

void	free_and_error(char **map, char *message)
{
	free_map(map);
	error(message);
}

int	line_count(char *argv, t_mapdata *data)
{
	int		fd;
	char	buffer;
	int		line;

	line = 1;
	printf("argv[1] ; %s\n", argv);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error("not file");
	data->collect_item = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			line ++;
		else if (buffer == 'C')
			data->collect_item += 1;
	}
	close (fd);
	return (line);
}

int	rows_len(char *str)
{
	int	i;

	i = 0;
	while ((str[i] != '\n') && (str[i] != '\0'))
		i ++;
	return (i);
}
