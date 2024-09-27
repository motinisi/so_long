/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:26:06 by timanish          #+#    #+#             */
/*   Updated: 2024/09/27 17:23:20 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct s_gemedata
// {
// 	void	*mlx;
// 	void	*window;
// 	void	*wall_img;
// 	void	*player_img;
// 	int		width;
// 	int		rows;
// }	t_mapdata;

void	player_coordinate(t_mapdata *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				return ;
			}
			x ++;
		}
		y ++;
	}
}

void	arg_cheak(int argc, char **argv)
{
	if (argc != 2)
		error("argument error\n");
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 5))
		error("map must be '.ber'\n");
}

void	collect_check(t_mapdata *data, t_mapcheck *check, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->rows || y >= data->cols)
	{
		free_map(data->map);
		error("map collect error");
	}
	// printf ("x : %d,  y : %d\n", x, y);
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

int	form_check(t_mapdata data)
{
	int	i;

	i = data.cols - 1;
	while (i >= 0)
	{
		if (rows_len(data.map[i]) != data.rows)
			return (1);
		i --;
	}
	return (0);
}

void	map_check(t_mapdata *data, int x, int y)
{
	t_mapcheck	*check;
	int			frag;

	check = (t_mapcheck *)malloc(sizeof(t_mapcheck));
	frag = form_check(*data);
	check->collect_count = 0;
	check->exit_count = 0;
	printf ("rows : %d, cols : %d\n", data->rows, data->cols);
	collect_check(data, check, x, y);
	printf("map check : %d\n", y);
	return_map(data);
	if ((data->collect_item != check->collect_count) || check->exit_count != 1)
		frag = 1;
	free(check);
	if (frag == 1)
		error("map frag error");
}

int	main(int argc, char **argv)
{
	t_mapdata	data;

	arg_cheak(argc, argv);
	data.movecount = 0;
	data.map = read_map(argv[1], &data);
	player_coordinate(&data);
	map_check(&data, data.player_x, data.player_y);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, data.rows * PIXEL,
			data.cols * PIXEL, "game");
	read_image(&data);
	create_map(&data, data.map);
	mlx_put_image_to_window(data.mlx, data.window,
		data.player_run_img, data.player_x * PIXEL, data.player_y * PIXEL);
	mlx_key_hook(data.window, keyboard_hook, &data);
	mlx_loop(data.mlx);
	free_map(data.map);
	return (0);
}
