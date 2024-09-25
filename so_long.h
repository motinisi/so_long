/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:32:27 by timanish          #+#    #+#             */
/*   Updated: 2024/09/25 15:45:37 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# if BUFFER_SIZE > 2147483646 || BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# define WALL_IMAGE "./textures/wall.xpm"
# define PLAYER_IMAGE "./textures/players-run-1.xpm"
# define PLAYER_RUN_IMAGE "./textures/players-run-2.xpm"
# define EMPTY_IMAGE "./textures/empty.xpm"
# define COLLECTIBLE_IMAGE "./textures/collectible.xpm"
# define EXIT_IMAGE "./textures/exit.xpm"

// # define PIXEL 35
# define PIXEL 85

# if PIXEL == 85
#  undef WALL_IMAGE
#  undef PLAYER_IMAGE
#  undef PLAYER_RUN_IMAGE
#  undef EMPTY_IMAGE
#  undef COLLECTIBLE_IMAGE
#  undef EXIT_IMAGE
#  define WALL_IMAGE "./textures/85wall.xpm"
#  define PLAYER_IMAGE "./textures/85players-run-1.xpm"
#  define PLAYER_RUN_IMAGE "./textures/85players-run-2.xpm"
#  define EMPTY_IMAGE "./textures/85empty.xpm"
#  define COLLECTIBLE_IMAGE "./textures/85collectible.xpm"
#  define EXIT_IMAGE "./textures/85exit.xpm"
# endif

# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define W_KEY 119
# define ESC 65307

typedef struct s_mapdate
{
	void	*mlx;
	void	*window;
	void	*wall_img;
	void	*player_img;
	void	*player_run_img;
	void	*space_img;
	void	*collectible_img;
	void	*exit_img;
	int		width;
	int		height;
	char	**map;
	int		player_y;
	int		player_x;
	int		movecount;
}	t_mapdate;

// typedef struct s_playerdate
// {
// 	int	player_y;
// 	int	player_x;
// 	int	move_count;
// }	t_playerdate;

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*connect_buf(int fd, char *buf, char *save_buf);
char	*result_buf(char *save_buf, size_t i, char *re_buf);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*save_check(char *save_buf, char *buf);
void	error(char *message);
int		line_count(char *argv);
void	free_map(char **map);
char	**read_map(char *argv, t_mapdate *date);
void	read_image(t_mapdate *date);
void	drew_img(t_mapdate *date, char map, int x, int y);
void	create_map(t_mapdate *date, char **map);
void	key_hook_y(int keycode, t_mapdate *date);
void	key_hook_x(int keycode, t_mapdate *date);
int		keyboard_hook(int keycode, t_mapdate *date);

#endif
