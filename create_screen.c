/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:37:58 by timanish          #+#    #+#             */
/*   Updated: 2024/09/27 18:56:22 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *argv, t_mapdata *data)
{
	char	**map;
	int		i;
	int		line;
	int		fd;

	line = line_count(argv, data);
	data->cols = line;
	fd = open(argv, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (line + 1));
	if (!map)
		return (NULL);
	i = 0;
	printf("create_screen line : %d\n", line);
	while (line)
	{
		map[i] = get_next_line(fd);
		printf("get_next_line : %d\n", i);
		if (map[i] == NULL)
			free_and_error(map, "creat map error");
		i ++;
		line --;
	}
	data->rows = rows_len(map[0]);
	map[i] = NULL;
	return (map);
}

void	read_image(t_mapdata *data)
{
	data->wall_img = mlx_xpm_file_to_image(data->mlx, WALL_IMAGE,
			&data->rows, &data->cols);
	data->player_img = mlx_xpm_file_to_image(data->mlx, PLAYER_IMAGE,
			&data->rows, &data->cols);
	data->player_run_img = mlx_xpm_file_to_image(data->mlx, PLAYER_RUN_IMAGE,
			&data->rows, &data->cols);
	data->space_img = mlx_xpm_file_to_image(data->mlx, EMPTY_IMAGE,
			&data->rows, &data->cols);
	data->collectible_img = mlx_xpm_file_to_image(data->mlx, COLLECTIBLE_IMAGE,
			&data->rows, &data->cols);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, EXIT_IMAGE,
			&data->rows, &data->cols);
}

void	drew_img(t_mapdata *data, char map, int x, int y)
{
	if (map == '0' || map == 'P')
		mlx_put_image_to_window(data->mlx, data->window,
			data->space_img, x * PIXEL, y * PIXEL);
	else if (map == '1')
		mlx_put_image_to_window(data->mlx, data->window,
			data->wall_img, x * PIXEL, y * PIXEL);
	else if (map == 'C')
		mlx_put_image_to_window(data->mlx, data->window,
			data->collectible_img, x * PIXEL, y * PIXEL);
	else if (map == 'E')
		mlx_put_image_to_window(data->mlx, data->window,
			data->exit_img, x * PIXEL, y * PIXEL);
}

void	create_map(t_mapdata *data, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			drew_img(data, map[y][x], x, y);
			x ++;
		}
		y ++;
	}
}
