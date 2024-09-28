/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:26:06 by timanish          #+#    #+#             */
/*   Updated: 2024/09/28 13:59:34 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	t_mapdata	data;

	arg_cheak(argc, argv);
	data.movecount = 0;
	data.map = read_map(argv[1], &data);
	player_coordinate(&data);
	if (data.cols > WIN_HEIGHT_MAX || data.rows > WIN_WIDTH_MAX)
		free_and_error(data.map, "map is so big!");
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
