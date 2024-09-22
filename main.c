/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:26:06 by timanish          #+#    #+#             */
/*   Updated: 2024/09/22 19:54:04 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct s_gemedate
// {
// 	void	*mlx;
// 	void	*win;
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


char	**read_map(int fd, int line)
{
	char	**map;
	int		i;

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

void	create_map(t_gamedate *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window()
		}
	}
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		error("argument error");
	fd = open(argv[1], O_RDONLY);


	return (0);
}
