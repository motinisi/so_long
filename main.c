/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:26:06 by timanish          #+#    #+#             */
/*   Updated: 2024/09/25 20:14:52 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct s_gemedate
// {
// 	void	*mlx;
// 	void	*window;
// 	void	*wall_img;
// 	void	*player_img;
// 	int		width;
// 	int		height;
// }	t_mapdate;

void	player_coordinate(t_mapdate *date)
{
	int	x;
	int	y;

	y = 0;
	while (date->map[y] != NULL)
	{
		x = 0;
		while (date->map[y][x] != '\0')
		{
			if (date->map[y][x] == 'P')
			{
				date->player_x = x;
				date->player_y = y;
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
		error("argument error");
	if (ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".ber", 5))
		error("map must be '.ber'");
}

// void	map_cheak(t_mapdate date)
// {
// 	t_angle	angle;
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (date.map[y] != NULL)
// 	{
// 		x = 0;
// 		while (date->map[y][x] != '\0')
		
// 		y ++;
// 	}
// }

int	main(int argc, char **argv)
{
	t_mapdate	date;

	if (argc != 2)
		error("argument error");
	arg_cheak(argc, argv);
	date.movecount = 0;
	date.map = read_map(argv[1], &date);
	// map_cheak(date);
	date.mlx = mlx_init();
	date.window = mlx_new_window(date.mlx, date.width * PIXEL,
			date.height * PIXEL, "game");
	read_image(&date);
	player_coordinate(&date);
	create_map(&date, date.map);
	printf ("collect:%d\n", date.collect_item);
	mlx_put_image_to_window(date.mlx, date.window,
		date.player_run_img, date.player_x * PIXEL, date.player_y * PIXEL);
	mlx_key_hook(date.window, keyboard_hook, &date);
	mlx_loop(date.mlx);
	free_map(date.map);
	return (0);
}
