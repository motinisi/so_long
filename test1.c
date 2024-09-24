/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:01:54 by timanish          #+#    #+#             */
/*   Updated: 2024/09/24 15:10:07 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *message)
{
	printf("%s\n", message);
	exit(1);
}

int	line_count(char *argv)
{
	int		fd;
	char	buffer;
	int		line;

	line = 1;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error("Failed to open file");
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			line++;
	}
	close(fd);
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
	if (fd == -1)
		error("Failed to open file");

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
			close(fd);
			return (NULL);
		}
		i++;
		line--;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	drew_img(t_gamedate *date, char map, int x, int y)
{
	if (map == '0')
		mlx_put_image_to_window(date->mlx, date->window, date->space_img, x * PIXEL, y * PIXEL);
	else if (map == '1')
		mlx_put_image_to_window(date->mlx, date->window, date->wall_img, x * PIXEL, y * PIXEL);
	else if (map == 'C')
		mlx_put_image_to_window(date->mlx, date->window, date->collectible_img, x * PIXEL, y * PIXEL);
	else if (map == 'E')
		mlx_put_image_to_window(date->mlx, date->window, date->exit_img, x * PIXEL, y * PIXEL);
	else if (map == 'P')
		mlx_put_image_to_window(date->mlx, date->window, date->player_img, x * PIXEL, y * PIXEL);
}

void	create_map(t_gamedate *date, char **map)
{
	int	x;
	int	y;

	if (map == NULL)
		error("Error: Map is NULL");

	y = 0;
	printf("create_map is ok so far\n");
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			drew_img(date, map[y][x], x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_gamedate	date;
	char		**map;

	if (argc != 2)
		error("argument error");

	map = read_map(argv[1]);
	if (map == NULL)
		error("Failed to read map");

	date.mlx = mlx_init();
	date.window = mlx_new_window(date.mlx, 600, 400, "game");

	date.wall_img = mlx_xpm_file_to_image(date.mlx, WALL_IMAGE, &date.width, &date.height);
	if (!date.wall_img)
		error("Failed to load wall_image");

	date.player_img = mlx_xpm_file_to_image(date.mlx, "player_image", &date.width, &date.height);
	if (!date.player_img)
		error("Failed to load player_image");

	date.space_img = mlx_xpm_file_to_image(date.mlx, "empty_image", &date.width, &date.height);
	if (!date.space_img)
		error("Failed to load empty_image");

	date.collectible_img = mlx_xpm_file_to_image(date.mlx, "collectible_image", &date.width, &date.height);
	if (!date.collectible_img)
		error("Failed to load collectible_image");

	date.exit_img = mlx_xpm_file_to_image(date.mlx, "exit_image", &date.width, &date.height);
	if (!date.exit_img)
		error("Failed to load exit_image");

	printf("main is ok so far\n");
	create_map(&date, map);
	return (0);
}
