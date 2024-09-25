/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:37:58 by timanish          #+#    #+#             */
/*   Updated: 2024/09/25 16:41:29 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *argv, t_mapdate *date)
{
	char	**map;
	int		i;
	int		line;
	int		fd;

	line = line_count(argv, date);
	date->height = line;
	fd = open(argv, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (line + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (line)
	{
		map[i] = get_next_line(fd);
		if (map[i] == NULL)
			return (free_map(map), NULL);
		i ++;
		line --;
	}
	date->width = ft_strlen(map[0]) - 1;
	map[i] = NULL;
	return (map);
}

void	read_image(t_mapdate *date)
{
	date->wall_img = mlx_xpm_file_to_image(date->mlx, WALL_IMAGE,
			&date->width, &date->height);
	date->player_img = mlx_xpm_file_to_image(date->mlx, PLAYER_IMAGE,
			&date->width, &date->height);
	date->player_run_img = mlx_xpm_file_to_image(date->mlx, PLAYER_RUN_IMAGE,
			&date->width, &date->height);
	date->space_img = mlx_xpm_file_to_image(date->mlx, EMPTY_IMAGE,
			&date->width, &date->height);
	date->collectible_img = mlx_xpm_file_to_image(date->mlx, COLLECTIBLE_IMAGE,
			&date->width, &date->height);
	date->exit_img = mlx_xpm_file_to_image(date->mlx, EXIT_IMAGE,
			&date->width, &date->height);
}

void	drew_img(t_mapdate *date, char map, int x, int y)
{
	if (map == '0' || map == 'P')
		mlx_put_image_to_window(date->mlx, date->window,
			date->space_img, x * PIXEL, y * PIXEL);
	else if (map == '1')
		mlx_put_image_to_window(date->mlx, date->window,
			date->wall_img, x * PIXEL, y * PIXEL);
	else if (map == 'C')
		mlx_put_image_to_window(date->mlx, date->window,
			date->collectible_img, x * PIXEL, y * PIXEL);
	else if (map == 'E')
		mlx_put_image_to_window(date->mlx, date->window,
			date->exit_img, x * PIXEL, y * PIXEL);
}

void	create_map(t_mapdate *date, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			drew_img(date, map[y][x], x, y);
			x ++;
		}
		y ++;
	}
}