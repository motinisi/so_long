/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:26:06 by timanish          #+#    #+#             */
/*   Updated: 2025/01/10 15:55:51 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mapdata	data;

	arg_cheak(argc, argv);
	data.movecount = 0;
	data.flag = 0;
	data.map = read_map(argv[1], &data);
	if (!data.map)
		error("read failed\n");
	if (player_coordinate(&data))
		map_free_and_error(data.map, "player incorrect\n");
	if (data.cols > WIN_HEIGHT_MAX || data.rows > WIN_WIDTH_MAX)
		map_free_and_error(data.map, "map is so big!\n");
	map_check(&data, data.player_x, data.player_y);
	character_check(&data);
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, data.rows * PIXEL,
			data.cols * PIXEL, "game");
	read_image(&data);
	create_map(&data, data.map);
	bonus_function(&data);
	all_free(&data);
	return (0);
}
