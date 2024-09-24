/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:26:06 by timanish          #+#    #+#             */
/*   Updated: 2024/09/24 19:19:26 by timanish         ###   ########.fr       */
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
// }	t_gamedate;

void	error(char *message)
{
	printf("%s\n", message);
	exit (1);
}

int	line_count(char *argv)
{
	int		fd;
	char	buffer;
	int		line;

	line = 1;
	fd = open(argv, O_RDONLY);
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			line ++;
	}
	close (fd);
	return (line);
}


char	**read_map(char *argv, t_gamedate *date)
{
	char	**map;
	int		i;
	int		line;
	int		fd;

	line = line_count(argv);
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
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		i ++;
		line --;
	}
	date->width = ft_strlen(map[0]) - 1;
	map[i] = NULL;
	return (map);
}

void	read_image(t_gamedate *date)
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

void	drew_img(t_gamedate *date, char map, int x, int y)
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
	// else if (map == 'P')
	// 	mlx_put_image_to_window(date->mlx, date->window,
	// 		date->player_img, x * PIXEL, y * PIXEL);
}

void	create_map(t_gamedate *date, char **map)
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

void	key_hook_y(int keycode, t_gamedate *date)
{
	if (keycode == W_KEY)
	{
		if (date->map[date->player_y - 1][date->player_x] != '1')
		{
			date->player_y -= 1;
			date->count ++;
		}
	}
	else if (keycode == S_KEY)
	{
		if (date->map[date->player_y + 1][date->player_x] != '1')
		{
			date->player_y += 1;
			date->count ++;
		}
	}
}

void	key_hook_x(int keycode, t_gamedate *date)
{
	if (keycode == A_KEY)
	{
		if (date->map[date->player_y][date->player_x - 1] != '1')
		{
			date->player_x -= 1;
			date->count ++;
		}	
	}
	else if (keycode == D_KEY)
	{
		if (date->map[date->player_y][date->player_x + 1] != '1')
		{
			date->player_x += 1;
			date->count ++;
		}	
	}
}

int	keyboard_hook(int keycode, t_gamedate *date)
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
	mlx_clear_window(date->mlx, date->window);
	create_map(date, date->map);
	if (date->count % 2 == 0)
		mlx_put_image_to_window(date->mlx, date->window,
			date->player_img, date->player_x * PIXEL, date->player_y * PIXEL);
	else
		mlx_put_image_to_window(date->mlx, date->window, date->player_run_img,
			date->player_x * PIXEL, date->player_y * PIXEL);
	printf("count : %d\n", date->count);
	return (0);
}

void	player_coordinate(t_gamedate *date)
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

int	main(int argc, char **argv)
{
	t_gamedate	date;

	if (argc != 2)
		error("argument error");
	date.count = 0;
	date.map = read_map(argv[1], &date);
	date.mlx = mlx_init();
	date.window = mlx_new_window(date.mlx, date.width * PIXEL,
			date.height * PIXEL, "game");
	read_image(&date);
	player_coordinate(&date);
	create_map(&date, date.map);
	printf("count : %d\n", date.count);
	mlx_put_image_to_window(date.mlx, date.window,
		date.player_img, date.player_x * PIXEL, date.player_y * PIXEL);
	mlx_key_hook(date.window, keyboard_hook, &date);
	mlx_loop(date.mlx);
	return (0);
}
