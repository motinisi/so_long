/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:30:04 by timanish          #+#    #+#             */
/*   Updated: 2025/12/17 00:00:00 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	map_free_and_error(char **map, char *message)
{
	free_map(map);
	error(message);
}

void	free_and_error(t_mapdata *data, char *message)
{
	all_free(data);
	error(message);
}

void	destroy_image(t_mapdata *data)
{
	if (!data || !data->mlx)
		return;

	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
	if (data->player_run_img)
		mlx_destroy_image(data->mlx, data->player_run_img);
	if (data->space_img)
		mlx_destroy_image(data->mlx, data->space_img);
	if (data->collectible_img)
		mlx_destroy_image(data->mlx, data->collectible_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
}

void	all_free(t_mapdata *data)
{
	if (!data)
		return;

	destroy_image(data);

	if (data->mlx && data->window)
		mlx_destroy_window(data->mlx, data->window);

#ifdef __linux__
	// Linux(minilibx-linux) にだけある
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
#endif

	if (data->map)
		free_map(data->map);
}
