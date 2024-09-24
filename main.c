/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:26:06 by timanish          #+#    #+#             */
/*   Updated: 2024/09/24 16:05:14 by timanish         ###   ########.fr       */
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


char	**read_map(char *argv)
{
	char	**map;
	int		i;
	int		line;
	int		fd;

	line = line_count(argv);
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
	map[i] = NULL;
	return (map);
}

void	drew_img(t_gamedate *date, char map, int x, int y)
{
	if (map == '0')
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
	else if (map == 'P')
		mlx_put_image_to_window(date->mlx, date->window,
			date->player_img, x * PIXEL, y * PIXEL);
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

int	main(int argc, char **argv)
{
	t_gamedate	date;
	char		**map;

	if (argc != 2)
		error("argument error");
	map = read_map(argv[1]);
	date.mlx = mlx_init();
	date.window = mlx_new_window(date.mlx, 910, 350, "game");
	date.wall_img = mlx_xpm_file_to_image(date.mlx, WALL_IMAGE,
			&date.width, &date.height);
	date.player_img = mlx_xpm_file_to_image(date.mlx, PLAYER_IMAGE,
			&date.width, &date.height);
	date.space_img = mlx_xpm_file_to_image(date.mlx, EMPTY_IMAGE,
			&date.width, &date.height);
	date.collectible_img = mlx_xpm_file_to_image(date.mlx, COLLECTIBLE_IMAGE,
			&date.width, &date.height);
	date.exit_img = mlx_xpm_file_to_image(date.mlx, EXIT_IMAGE,
			&date.width, &date.height);
	// printf("main is ok so far\n");
	create_map(&date, map);
	mlx_loop(date.mlx);
	// mlx_hook(win, 17, 0, close_window, NULL);
	return (0);
}
