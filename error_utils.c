/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:04:33 by timanish          #+#    #+#             */
/*   Updated: 2024/10/08 18:13:19 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	int	byte;

	byte = ft_strlen(message);
	write (2, "Error\n", 6);
	write (2, message, byte);
	exit (1);
}

void	check_hidden(char *argv)
{
	char	*filename;

	filename = ft_strrchr(argv, '/');
	if (filename == NULL)
		filename = argv;
	else
		filename++;
	if (filename[0] == '.')
		error("file error\n");
}

int	close_window(char **map)
{
	free_map(map);
	exit(0);
}

void	character_check(t_mapdata *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] != '0' && data->map[y][x] != '1'
				&& data->map[y][x] != 'C' && data->map[y][x] != 'E'
				&& data->map[y][x] != 'P' && data->map[y][x] != '\n')
				map_free_and_error(data->map, "character incorrect\n");
			x ++;
		}
		y ++;
	}
}
