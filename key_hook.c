/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:44:38 by timanish          #+#    #+#             */
/*   Updated: 2024/09/27 13:00:14 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook_y(int keycode, t_mapdata *data)
{
	if (keycode == W_KEY)
	{
		if (data->map[data->player_y - 1][data->player_x] != '1')
		{
			data->player_y -= 1;
			data->movecount ++;
		}
	}
	else if (keycode == S_KEY)
	{
		if (data->map[data->player_y + 1][data->player_x] != '1')
		{
			data->player_y += 1;
			data->movecount ++;
		}
	}
}

void	key_hook_x(int keycode, t_mapdata *data)
{
	if (keycode == A_KEY)
	{
		if (data->map[data->player_y][data->player_x - 1] != '1')
		{
			data->player_x -= 1;
			data->movecount ++;
		}	
	}
	else if (keycode == D_KEY)
	{
		if (data->map[data->player_y][data->player_x + 1] != '1')
		{
			data->player_x += 1;
			data->movecount ++;
		}	
	}
}

void	itemcollect(t_mapdata *data)
{
	char	**map;
	int		y;
	int		x;

	map = data->map;
	y = data->player_y;
	x = data->player_x;
	if (map[y][x] == 'C')
	{
		data->collect_item -= 1;
		map[y][x] = '0';
		printf ("key_hook.c  collect%d\n", data->collect_item);
	}
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
		free_map(data->map);
		exit(0);
	}
}

int	keyboard_hook(int keycode, t_mapdata *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit (0);
	}
	else if (keycode == W_KEY || keycode == S_KEY)
		key_hook_y(keycode, data);
	else if (keycode == A_KEY || keycode == D_KEY)
		key_hook_x(keycode, data);
	itemcollect(data);
	exit_game(data);
	mlx_clear_window(data->mlx, data->window);
	create_map(data, data->map);
	if (data->movecount % 2 == 0)
		mlx_put_image_to_window(data->mlx, data->window, data->player_run_img,
			data->player_x * PIXEL, data->player_y * PIXEL);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->player_img,
			data->player_x * PIXEL, data->player_y * PIXEL);
	printf("key_hook.c  count : %d\n", data->movecount);
	return (0);
}
