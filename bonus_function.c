/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:44:51 by timanish          #+#    #+#             */
/*   Updated: 2025/01/11 20:41:41 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_coordinate(t_mapdata *data)
{
	int	x;
	int	y;
	int	count;

	count = 0;
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
				count += 1;
			}
			x++;
		}
		y++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	player_jump(t_mapdata *data)
{
	if ((data->time_flag / 10000) % 2 == 0)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->player_run_img,
			data->player_x * PIXEL, data->player_y * PIXEL);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->window, data->player_img,
			data->player_x * PIXEL, data->player_y * PIXEL);
		if (data->time_flag == 30000)
			data->time_flag = 10000;
	}
	return (0);
}

void	search_exit(t_mapdata *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'E')
			{
				data->bonus_data->exit_x = x;
				data->bonus_data->exit_y = y;
			}
			x++;
		}
		y++;
	}
}

void	change_exit(t_mapdata *data)
{
	mlx_destroy_image(data->mlx, data->exit_img);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, OKEXIT_IMAGE,
			&data->pixel, &data->pixel);
	mlx_put_image_to_window(data->mlx, data->window, data->exit_img,
		data->bonus_data->exit_x * PIXEL, data->bonus_data->exit_y * PIXEL);
}

void	draw_prev_image(t_mapdata *data, int prev_x, int prev_y)
{
	if (data->map[prev_y][prev_x] == '0' || data->map[prev_y][prev_x] == 'E'
		|| data->map[prev_y][prev_x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->space_img, prev_x
			* PIXEL, prev_y * PIXEL);
	}
	else if (data->map[prev_y][prev_x] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->collectible_img,
			prev_x * PIXEL, prev_y * PIXEL);
	}
	else if (data->map[prev_y][prev_x] == '1')
	{
		mlx_put_image_to_window(data->mlx, data->window, data->wall_img, prev_x
			* PIXEL, prev_y * PIXEL);
	}
}

void	game_over(t_mapdata *data)
{
	free(data->enemy);
	free(data->bonus_data);
	all_free(data);
	ft_printf("GAME OVER\n");
	exit(0);
}

void	prev_put_image(t_mapdata *data, int prev_x, int prev_y)
{
	if (data->map[data->enemy->enemy_y][data->enemy->enemy_x] == '1')
		mlx_put_image_to_window(data->mlx, data->window,
			data->enemy->enemy_on_wall, data->enemy->enemy_x * PIXEL,
			data->enemy->enemy_y * PIXEL);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->enemy->enemy_img,
			data->enemy->enemy_x * PIXEL, data->enemy->enemy_y * PIXEL);
	draw_prev_image(data, prev_x, prev_y);
}

void	enemy_traking(t_mapdata *data)
{
	const int	prev_x = data->enemy->enemy_x;
	const int	prev_y = data->enemy->enemy_y;

	if (data->enemy->enemy_flag == 0)
	{
		if (data->enemy->enemy_x < data->player_x)
			data->enemy->enemy_x += 1;
		else if (data->enemy->enemy_x > data->player_x)
			data->enemy->enemy_x -= 1;
		data->enemy->enemy_flag = 1;
	}
	else if (data->enemy->enemy_flag == 1)
	{
		if (data->enemy->enemy_y < data->player_y)
			data->enemy->enemy_y += 1;
		else if (data->enemy->enemy_y > data->player_y)
			data->enemy->enemy_y -= 1;
		data->enemy->enemy_flag = 0;
	}
	if (data->enemy->enemy_x == data->player_x
		&& data->enemy->enemy_y == data->player_y)
		game_over(data);
	if (prev_x != data->enemy->enemy_x || prev_y != data->enemy->enemy_y)
		prev_put_image(data, prev_x, prev_y);
}

int	bonus_move(t_mapdata *data)
{
	data->time_flag++;
	player_jump(data);
	if (data->time_flag % 3750 == 0)
		enemy_traking(data);
	if (data->collect_item == 0 && data->bonus_data->flag != 1)
	{
		change_exit(data);
		data->bonus_data->flag = 1;
	}
	return (0);
}

int	key_move(t_mapdata *data)
{
	int	key_press_mask;

	key_press_mask = 1L << 0;
	mlx_hook(data->window, 2, key_press_mask, keyboard_hook, data);
	mlx_hook(data->window, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, bonus_move, data);
	mlx_loop(data->mlx);
	return (0);
}

void	make_enemy(t_mapdata *data)
{
	data->enemy = (t_enemy *)malloc(sizeof(t_enemy));
	data->enemy->enemy_flag = 0;
	// data->enemy->wait = 0;
	search_exit(data);
	data->enemy->enemy_x = data->bonus_data->exit_x;
	data->enemy->enemy_y = data->bonus_data->exit_y;
	printf("enemy_x : %d enemy_y : %d\n", data->enemy->enemy_x,
		data->enemy->enemy_y);
	data->enemy->enemy_img = mlx_xpm_file_to_image(data->mlx, ENEMY_IMAGE,
			&data->pixel, &data->pixel);
	mlx_put_image_to_window(data->mlx, data->window, data->enemy->enemy_img,
		data->enemy->enemy_x * PIXEL, data->enemy->enemy_y * PIXEL);
	data->enemy->enemy_on_wall = mlx_xpm_file_to_image(data->mlx, ENEMY_ON_WALL,
			&data->pixel, &data->pixel);
}

void	bonus_function(t_mapdata *data)
{
	data->bonus_data = (t_bonusdata *)malloc(sizeof(t_bonusdata));
	data->bonus_data->flag = 0;
	make_enemy(data);
	printf("FILE : %s LINE : %d\n", __FILE__, __LINE__);
	key_move(data);
	printf("This is a bonus function\n");
}
