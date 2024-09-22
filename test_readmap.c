/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timanish <timanish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:37:30 by timanish          #+#    #+#             */
/*   Updated: 2024/09/22 14:37:39 by timanish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TILE_SIZE 32

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*wall_img;
	void	*player_img;
	int		width;
	int		height;
}	t_game;

// マップファイルの読み込み
char	**read_map(const char *filename)
{
	int		fd;
	char	**map;
	char	*line;
	char	buffer[1];
	int		i = 0;
	int		j = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open map file\n");
		return (NULL);
	}

	map = (char **)malloc(sizeof(char *) * 100); // 仮の行数（最大100行）
	if (!map)
		return (NULL);

	line = (char *)malloc(1024); // 仮の行サイズ
	if (!line)
		return (NULL);

	while (read(fd, buffer, 1) > 0)
	{
		if (buffer[0] == '\n')  // 行の終わり
		{
			line[j] = '\0';  // 行の終端を設定
			map[i] = line;   // 1行をマップに保存
			i++;
			line = (char *)malloc(1024);  // 次の行のために新しいメモリを確保
			j = 0;  // 行のインデックスをリセット
		}
		else
		{
			line[j] = buffer[0];  // 文字を行に追加
			j++;
		}
	}
	map[i] = NULL;  // マップの終わりにNULLを追加

	close(fd);  // ファイルを閉じる
	return (map);
}

// マップに基づいてスプライトを描画
void	draw_map(t_game *game, char **map)
{
	int		x;
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1')  // 壁の描画
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
			else if (map[y][x] == 'P')  // プレイヤーの描画
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
