/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:24:32 by timanish          #+#    #+#             */
/*   Updated: 2024/09/29 13:50:54 by timanish         ###   ########.fr       */
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

void	return_map(t_mapdata *data)
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

void	map_check(t_mapdata *data, int x, int y)
{
	t_mapcheck	*check;
	int			frag;

	check = (t_mapcheck *)malloc(sizeof(t_mapcheck));
	frag = shape_check(*data);
	check->collect_count = 0;
	check->exit_count = 0;
	collect_check(data, check, x, y);
	return_map(data);
	if ((data->collect_item != check->collect_count) || check->exit_count != 1)
		frag = 2;
	free(check);
	if (frag == 1)
		error("map shape incorrect");
	if (frag == 2)
		error("characters incorrect");
}
