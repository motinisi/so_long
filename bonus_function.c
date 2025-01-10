/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:44:51 by timanish          #+#    #+#             */
/*   Updated: 2025/01/10 16:03:30 by timanish         ###   ########.fr       */
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
			x ++;
		}
		y ++;
	}
	if (count == 1)
		return (0);
	return (1);
}

int	player_jump(t_mapdata *data)
{
	if ((data->flag / 10000) % 2 == 0)
	{
		mlx_put_image_to_window(data->mlx, data->window, data->player_run_img,
			data->player_x * PIXEL, data->player_y * PIXEL);
		data->flag ++;
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->window,
			data->player_img, data->player_x * PIXEL, data->player_y * PIXEL);
		data->flag ++;
		if (data->flag == 30000)
			data->flag = 10000;
	}
	return (0);
}

int	key_move(t_mapdata *data)
{
	int	key_press_mask;

	key_press_mask = 1L << 0;
	mlx_hook(data->window, 2, key_press_mask, keyboard_hook, data);
	// mlx_key_hook(data->window, keyboard_hook, data);
	mlx_hook(data->window, 17, 0, close_window, data);
	if (data->collect_item == 0)
		mlx_put
	mlx_loop_hook(data->mlx, player_jump, data);
	mlx_loop(data->mlx);
	return (0);
}

void	bonus_function(t_mapdata *data)
{
	printf("FILE : %s LINE : %d\n", __FILE__, __LINE__);
	printf("collect_item: %d\n", data->collect_item);
	key_move(data);
	printf("This is a bonus function\n");
}
