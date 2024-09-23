/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:26:06 by timanish          #+#    #+#             */
/*   Updated: 2024/09/23 19:04:01 by timanish         ###   ########.fr       */
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


char	**read_map(int fd, char *argv)
{
	char	**map;
	int		i;
	int		line;

	line = line_count(argv);
	map = (char **)malloc(sizeof(char *) * line + 1);
	if (map)
		return (NULL);
	i = 0;
	while (line)
	{
		map[i] = get_next_line(fd);
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
	int			fd;
	char		**map;

	if (argc != 2)
		error("argument error");
	fd = open(argv[1], O_RDONLY);
	map = read_map(fd, argv[1]);
	date.mlx = mlx_init();
	date.window = mlx_new_window(date.mlx, 600, 400, "game");
	//明日はここから始めよう
	date.wall_img = mlx_xpm_file_to_image(date.mlx, "wall_image", )

	return (0);
}
