/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:44:38 by timanish          #+#    #+#             */
/*   Updated: 2024/09/25 18:27:57 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook_y(int keycode, t_mapdate *date)
{
	if (keycode == W_KEY)
	{
		if (date->map[date->player_y - 1][date->player_x] != '1')
		{
			date->player_y -= 1;
			date->movecount ++;
		}
	}
	else if (keycode == S_KEY)
	{
		if (date->map[date->player_y + 1][date->player_x] != '1')
		{
			date->player_y += 1;
			date->movecount ++;
		}
	}
}

void	key_hook_x(int keycode, t_mapdate *date)
{
	if (keycode == A_KEY)
	{
		if (date->map[date->player_y][date->player_x - 1] != '1')
		{
			date->player_x -= 1;
			date->movecount ++;
		}	
	}
	else if (keycode == D_KEY)
	{
		if (date->map[date->player_y][date->player_x + 1] != '1')
		{
			date->player_x += 1;
			date->movecount ++;
		}	
	}
}

void	itemcollect(t_mapdate *date)
{
	char	**map;
	int		y;
	int		x;

	map = date->map;
	y = date->player_y;
	x = date->player_x;
	if (map[y][x] == 'C')
	{
		date->collect_item -= 1;
		map[y][x] = '0';
		printf ("key_hook.c   collect%d\n", date->collect_item);
	}
}

void	exit_game(t_mapdate *date)
{
	int	item;
	int	y;
	int	x;

	item = date->collect_item;
	y = date->player_y;
	x = date->player_x;
	if (date->map[y][x] == 'E' && item == 0)
	{
		write (1, "game clear\n", 11);
		free_map(date->map);
		exit(0);
	}
}

int	keyboard_hook(int keycode, t_mapdate *date)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(date->mlx, date->window);
		exit (0);
	}
	else if (keycode == W_KEY || keycode == S_KEY)
		key_hook_y(keycode, date);
	else if (keycode == A_KEY || keycode == D_KEY)
		key_hook_x(keycode, date);
	itemcollect(date);
	exit_game(date);
	mlx_clear_window(date->mlx, date->window);
	create_map(date, date->map);
	if (date->movecount % 2 == 0)
		mlx_put_image_to_window(date->mlx, date->window, date->player_run_img,
			date->player_x * PIXEL, date->player_y * PIXEL);
	else
		mlx_put_image_to_window(date->mlx, date->window, date->player_img,
			date->player_x * PIXEL, date->player_y * PIXEL);
	printf("key_hook.c  count : %d\n", date->movecount);
	return (0);
}
