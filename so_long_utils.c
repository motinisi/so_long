/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:47:22 by timanish          #+#    #+#             */
/*   Updated: 2024/09/29 11:47:16 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	exit_game(t_mapdata *data)
{
	int	item;
	int	y;
	int	x;

	item = data->collect_item;
	y = data->player_y;
	x = data->player_x;
	if (data->map[y][x] == 'E' && item == 0)
	{
		write (1, "game clear\n", 11);
		free_map(data->map);
		exit(0);
	}
}
