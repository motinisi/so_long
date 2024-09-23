/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:32:27 by timanish          #+#    #+#             */
/*   Updated: 2024/09/23 18:25:46 by timanish         ###   ########.fr       */
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

# define WALL_IMAGE "textures/wall.xpm"
# define PLAYER_IMAGE "textures/players-run-1.xpm"
# define PLAYER_RUN_IMAGE "textures/players-run-2.xpm"
# define PIXEL 32

typedef struct s_gemedate
{
	void	*mlx;
	void	*window;
	void	*wall_img;
	void	*player_img;
	void	*space_img;
	void	*collectible_img;
	void	*exit_img;
	int		width;
	int		height;
}	t_gamedate;

size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*connect_buf(int fd, char *buf, char *save_buf);
char	*result_buf(char *save_buf, size_t i, char *re_buf);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*save_check(char *save_buf, char *buf);

#endif
