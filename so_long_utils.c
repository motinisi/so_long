/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:47:22 by timanish          #+#    #+#             */
/*   Updated: 2024/10/08 18:41:32 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count(char *argv, t_mapdata *data)
{
	int		fd;
	char	buffer;
	int		line;

	line = 1;
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
		all_free(data);
		exit(0);
	}
}

void	repair_map(t_mapdata *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'c')
				data->map[y][x] = 'C';
			else if (data->map[y][x] == 'e')
				data->map[y][x] = 'E';
			else if (data->map[y][x] == '*')
				data->map[y][x] = '0';
			x ++;
		}
		y ++;
	}
}

void	map_check(t_mapdata *data, int x, int y)
{
	t_mapcheck	*check;
	int			flag;

	check = (t_mapcheck *)malloc(sizeof(t_mapcheck));
	if (!check)
		free_and_error(data, "malloc failed\n");
	flag = shape_check(*data);
	// if (flag == 1)
	// 	flag_error(data->map, "map shape incorrect\n", check);
	check->collect_count = 0;
	check->exit_count = 0;
	wall_rows_check(data, check);
	wall_cols_check(data, check);
	collect_check(data, check, x, y);
	repair_map(data);
	if ((data->collect_item != check->collect_count)
		|| check->exit_count != 1 || check->collect_count == 0)
		flag = 2;
	if (flag == 2)
		flag_error(data->map, "characters incorrect\n", check);
	free(check);
}
