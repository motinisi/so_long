/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:32:27 by timanish          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/29 14:32:47 by timanish         ###   ########.fr       */
=======
/*   Updated: 2024/09/29 16:54:23 by timanish         ###   ########.fr       */
>>>>>>> main
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
# include "libft/libft.h"


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# if BUFFER_SIZE > 2147483646 || BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

# define WIN_HEIGHT_MAX 24
# define WIN_WIDTH_MAX 96

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

typedef struct s_mapdata
{
	void	*mlx;
	void	*window;
	void	*wall_img;
	void	*player_img;
	void	*player_run_img;
	void	*space_img;
	void	*collectible_img;
	void	*exit_img;
	int		cols;
	int		rows;
	char	**map;
	int		collect_item;
	int		player_y;
	int		player_x;
	int		movecount;
}	t_mapdata;

typedef struct s_mapcheck
{
	int	collect_count;
	int	exit_count;
}	t_mapcheck;

typedef struct s_spaceimg
{
	int	space_y;
	int	space_x;
}	t_spaceimg;

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*connect_buf(int fd, char *buf, char *save_buf);
char	*result_buf(char *save_buf, size_t i, char *re_buf);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*save_check(char *save_buf, char *buf);
void	error(char *message);
int		line_count(char *argv, t_mapdata *data);
void	free_map(char **map);
char	**read_map(char *argv, t_mapdata *data);
void	read_image(t_mapdata *data);
void	drew_img(t_mapdata *data, char map, int x, int y);
void	create_map(t_mapdata *data, char **map);
void	key_hook_y(int keycode, t_mapdata *data);
void	key_hook_x(int keycode, t_mapdata *data);
int		keyboard_hook(int keycode, t_mapdata *data);
int		rows_len(char *str);
void	free_and_error(char **map, char *message);
void	arg_cheak(int argc, char **argv);
void	collect_check(t_mapdata *data, t_mapcheck *check, int x, int y);
void	return_map(t_mapdata *data);
int		shape_check(t_mapdata data);
void	map_check(t_mapdata *data, int x, int y);
void	check_hidden(char *argv);
void	exit_game(t_mapdata *data);
void	wall_rows_check(t_mapdata *data);
void	wall_cols_check(t_mapdata *data);
#endif
