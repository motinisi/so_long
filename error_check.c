/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:24:32 by timanish          #+#    #+#             */
/*   Updated: 2024/09/29 16:53:48 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_cheak(int argc, char **argv)
{
	if (argc != 2)
		error("argument is incorrect\n");
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 5))
		error("map must be '.ber'\n");
	check_hidden(argv[1]);
}

void	collect_check(t_mapdata *data, t_mapcheck *check, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->rows || y >= data->cols)
		free_and_error(data->map, "The map is not walled off\n");
	if (data->map[y][x] == '1' || data->map[y][x] == '*'
		|| data->map[y][x] == 'c' || data->map[y][x] == 'e')
		return ;
	if (data->map[y][x] == 'C')
	{
		check->collect_count += 1;
		data->map[y][x] = 'c';
	}
	else if (data->map[y][x] == 'E')
	{
		check->exit_count += 1;
		data->map[y][x] = 'e';
	}
	else if (data->map[y][x] == '0')
		data->map[y][x] = '*';
	collect_check(data, check, x + 1, y);
	collect_check(data, check, x - 1, y);
	collect_check(data, check, x, y + 1);
	collect_check(data, check, x, y - 1);
}

int	shape_check(t_mapdata data)
{
	int	i;

	i = data.cols - 1;
	while (i >= 0)
	{
		if (rows_len(data.map[i]) != data.rows)
			return (1);
		i --;
	}
	if (data.cols == data.rows)
		return (1);
	return (0);
}

void	wall_rows_check(t_mapdata *data)
{
	char	*fst_rows;
	char	*last_rows;

	fst_rows = data->map[0];
	while (*fst_rows != '\n')
	{
		if (*fst_rows != '1')
			free_and_error(data->map, "wall incorrect\n");
		fst_rows ++;
	}
	last_rows = data->map[data->cols - 1];
	while (*last_rows)
	{
		if (*last_rows != '1')
			free_and_error(data->map, "wall incorrect\n");
		last_rows ++;
	}
}

void	wall_cols_check(t_mapdata *data)
{
	int	i;

	i = data->cols;
	while (--i >= 0)
	{
		if (data->map[i][0] != '1')
			free_and_error(data->map, "wall incorrect\n");
	}
	i = data->cols;
	while (--i >= 0)
	{
		if (data->map[i][data->rows - 1] != '1')
			free_and_error(data->map, "wall incorrect\n");
	}
}

